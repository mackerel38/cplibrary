---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/waveletmatrix.hpp
    title: Wavelet Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/yosupo_range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"structure/waveletmatrix.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct wavelet_matrix {\n\
    \  int n;\n  int lg;\n  vector<int> mid;\n  vector<vector<int>> pref;\n\n  wavelet_matrix()\
    \ : n(0), lg(0) {}\n  wavelet_matrix(const vector<int>& v) { build(v); }\n\n \
    \ void build(const vector<int>& v) {\n    n = (int)v.size();\n    int mx = 0;\n\
    \    for (int x : v) mx = max(mx, x);\n    lg = 0;\n    while ((1LL << lg) <=\
    \ mx) lg++;\n    if (lg == 0) lg = 1;\n    mid.assign(lg, 0);\n    pref.assign(lg,\
    \ vector<int>(n + 1, 0));\n    vector<int> cur = v;\n    vector<int> nxt(n);\n\
    \    for (int lv = lg - 1; lv >= 0; lv--) {\n      int zero = 0;\n      for (int\
    \ i = 0; i < n; i++) {\n        int f = (cur[i] >> lv) & 1;\n        pref[lv][i\
    \ + 1] = pref[lv][i] + (f == 0);\n      }\n      zero = pref[lv][n];\n      mid[lv]\
    \ = zero;\n      int p0 = 0, p1 = zero;\n      for (int i = 0; i < n; i++) {\n\
    \        int f = (cur[i] >> lv) & 1;\n        if (f == 0)\n          nxt[p0++]\
    \ = cur[i];\n        else\n          nxt[p1++] = cur[i];\n      }\n      cur.swap(nxt);\n\
    \    }\n  }\n\n  int kth(int l, int r, int k) const {\n    int ans = 0;\n    for\
    \ (int lv = lg - 1; lv >= 0; lv--) {\n      int zl = pref[lv][l];\n      int zr\
    \ = pref[lv][r];\n      int zc = zr - zl;\n      if (k < zc) {\n        l = zl;\n\
    \        r = zr;\n      } else {\n        k -= zc;\n        int ol = l - zl;\n\
    \        int orr = r - zr;\n        l = mid[lv] + ol;\n        r = mid[lv] + orr;\n\
    \        ans |= (1 << lv);\n      }\n    }\n    return ans;\n  }\n};\n#line 4\
    \ \"verify/yosupo_range_kth_smallest.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int N, Q;\n  cin >>\
    \ N >> Q;\n  vector<int> a(N);\n  for (int i = 0; i < N; i++) cin >> a[i];\n \
    \ wavelet_matrix wm(a);\n  for (int i = 0; i < Q; i++) {\n    int l, r, k;\n \
    \   cin >> l >> r >> k;\n    cout << wm.kth(l, r, k) << \"\\n\";\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"structure/waveletmatrix.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<int> a(N);\n  for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n  wavelet_matrix wm(a);\n  for (int i = 0; i < Q; i++) {\n\
    \    int l, r, k;\n    cin >> l >> r >> k;\n    cout << wm.kth(l, r, k) << \"\\\
    n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/waveletmatrix.hpp
  isVerificationFile: true
  path: verify/yosupo_range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2026-03-12 02:13:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_range_kth_smallest.test.cpp
- /verify/verify/yosupo_range_kth_smallest.test.cpp.html
title: verify/yosupo_range_kth_smallest.test.cpp
---

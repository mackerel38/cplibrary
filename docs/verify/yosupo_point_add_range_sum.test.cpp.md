---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/BIT.hpp
    title: "Fenwick\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 2 \"structure/BIT.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ BIT {\n  int n;\n  vector<T> d;\n  BIT() : n(0) {}\n  BIT(int n_) { init(n_);\
    \ }\n  void init(int n_) {\n    n = n_;\n    d.assign(n + 1, T());\n  }\n  void\
    \ add(int i, T x) {\n    for (i++; i <= n; i += i & -i) d[i] += x;\n  }\n  T sum(int\
    \ r) const {\n    T s = T();\n    for (; r > 0; r -= r & -r) s += d[r];\n    return\
    \ s;\n  }\n  T sum(int l, int r) const { return sum(r) - sum(l); }\n  int lower_bound(T\
    \ x) const {\n    if (x <= T()) return 0;\n    int i = 0;\n    int k = 1;\n  \
    \  while ((k << 1) <= n) k <<= 1;\n    for (; k > 0; k >>= 1) {\n      int ni\
    \ = i + k;\n      if (ni <= n && d[ni] < x) {\n        x -= d[ni];\n        i\
    \ = ni;\n      }\n    }\n    return i;\n  }\n};\n#line 3 \"verify/yosupo_point_add_range_sum.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n, q;\n  cin >> n >> q;\n  BIT<long long> fw(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    long long a;\n    cin >> a;\n    fw.add(i, a);\n  }\n  while (q--) {\n\
    \    int t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      long long x;\n\
    \      cin >> p >> x;\n      fw.add(p, x);\n    } else {\n      int l, r;\n  \
    \    cin >> l >> r;\n      cout << fw.sum(l, r) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../structure/BIT.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n, q;\n  cin >> n >> q;\n  BIT<long long> fw(n);\n\
    \  for (int i = 0; i < n; i++) {\n    long long a;\n    cin >> a;\n    fw.add(i,\
    \ a);\n  }\n  while (q--) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n  \
    \    int p;\n      long long x;\n      cin >> p >> x;\n      fw.add(p, x);\n \
    \   } else {\n      int l, r;\n      cin >> l >> r;\n      cout << fw.sum(l, r)\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/BIT.hpp
  isVerificationFile: true
  path: verify/yosupo_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 04:02:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_point_add_range_sum.test.cpp
- /verify/verify/yosupo_point_add_range_sum.test.cpp.html
title: verify/yosupo_point_add_range_sum.test.cpp
---

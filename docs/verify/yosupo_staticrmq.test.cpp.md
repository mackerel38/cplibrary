---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/sparsetable.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo_staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 2 \"structure/sparsetable.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T, class Cmp = less<T>>\nstruct sparse_table {\n  int\
    \ n;\n  vector<T> a;\n  vector<vector<int>> st;\n  Cmp cmp;\n\n  sparse_table()\
    \ : n(0), cmp() {}\n  sparse_table(const vector<T>& v, Cmp cmp = Cmp()) { build(v,\
    \ cmp); }\n\n  void build(const vector<T>& v, Cmp cmp_ = Cmp()) {\n    cmp = cmp_;\n\
    \    a = v;\n    n = (int)a.size();\n    if (n == 0) return;\n    int lg = 1;\n\
    \    while ((1 << lg) <= n) lg++;\n    st.assign(lg, vector<int>(n, 0));\n   \
    \ for (int i = 0; i < n; i++) st[0][i] = i;\n    for (int k = 1; k < lg; k++)\
    \ {\n      int len = 1 << k;\n      int half = len >> 1;\n      for (int i = 0;\
    \ i + len <= n; i++) {\n        int x = st[k - 1][i];\n        int y = st[k -\
    \ 1][i + half];\n        st[k][i] = this->cmp(a[y], a[x]) ? y : x;\n      }\n\
    \    }\n  }\n\n  int argmin(int l, int r) const {\n    int len = r - l;\n    int\
    \ k = 31 - __builtin_clz(len);\n    int x = st[k][l];\n    int y = st[k][r - (1\
    \ << k)];\n    return this->cmp(a[y], a[x]) ? y : x;\n  }\n\n  T query(int l,\
    \ int r) const { return a[argmin(l, r)]; }\n};\n#line 3 \"verify/yosupo_staticrmq.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int N,\
    \ Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for (int i = 0; i < N; i++)\
    \ cin >> a[i];\n  sparse_table<long long> st(a);\n  for (int i = 0; i < Q; i++)\
    \ {\n    int l, r;\n    cin >> l >> r;\n    cout << st.query(l, r) << \"\\n\"\
    ;\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    structure/sparsetable.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  sparse_table<long long> st(a);\n\
    \  for (int i = 0; i < Q; i++) {\n    int l, r;\n    cin >> l >> r;\n    cout\
    \ << st.query(l, r) << \"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/sparsetable.hpp
  isVerificationFile: true
  path: verify/yosupo_staticrmq.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 17:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_staticrmq.test.cpp
- /verify/verify/yosupo_staticrmq.test.cpp.html
title: verify/yosupo_staticrmq.test.cpp
---

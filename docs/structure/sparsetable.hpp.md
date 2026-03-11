---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_staticrmq.test.cpp
    title: verify/yosupo_staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/sparsetable.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, class Cmp = less<T>>\nstruct sparse_table\
    \ {\n  int n;\n  vector<T> a;\n  vector<vector<int>> st;\n  Cmp cmp;\n\n  sparse_table()\
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
    \ int r) const { return a[argmin(l, r)]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, class Cmp = less<T>>\nstruct sparse_table {\n  int n;\n  vector<T>\
    \ a;\n  vector<vector<int>> st;\n  Cmp cmp;\n\n  sparse_table() : n(0), cmp()\
    \ {}\n  sparse_table(const vector<T>& v, Cmp cmp = Cmp()) { build(v, cmp); }\n\
    \n  void build(const vector<T>& v, Cmp cmp_ = Cmp()) {\n    cmp = cmp_;\n    a\
    \ = v;\n    n = (int)a.size();\n    if (n == 0) return;\n    int lg = 1;\n   \
    \ while ((1 << lg) <= n) lg++;\n    st.assign(lg, vector<int>(n, 0));\n    for\
    \ (int i = 0; i < n; i++) st[0][i] = i;\n    for (int k = 1; k < lg; k++) {\n\
    \      int len = 1 << k;\n      int half = len >> 1;\n      for (int i = 0; i\
    \ + len <= n; i++) {\n        int x = st[k - 1][i];\n        int y = st[k - 1][i\
    \ + half];\n        st[k][i] = this->cmp(a[y], a[x]) ? y : x;\n      }\n    }\n\
    \  }\n\n  int argmin(int l, int r) const {\n    int len = r - l;\n    int k =\
    \ 31 - __builtin_clz(len);\n    int x = st[k][l];\n    int y = st[k][r - (1 <<\
    \ k)];\n    return this->cmp(a[y], a[x]) ? y : x;\n  }\n\n  T query(int l, int\
    \ r) const { return a[argmin(l, r)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sparsetable.hpp
  requiredBy: []
  timestamp: '2026-03-11 17:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_staticrmq.test.cpp
documentation_of: //structure/sparsetable.hpp
layout: document
title: Sparse Table
---

Definition
Sparse Table により静的 RMQ を処理する。最小値の問い合わせを O(1) で処理する。

Complexity
構築は O(n log n)、クエリは O(1)。

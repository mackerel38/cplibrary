---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum_2.test.cpp
    title: verify/yosupo_point_add_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct BIT {\n  int n;\n  vector<T> d;\n\n  BIT()\
    \ : n(0) {}\n  BIT(int n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n\
    \    d.assign(n + 1, T());\n  }\n\n  void add(int i, T x) {\n    for (int p =\
    \ i + 1; p <= n; p += p & -p) d[p] += x;\n  }\n\n  T sum(int r) const {\n    T\
    \ res = T();\n    for (int p = r; p > 0; p -= p & -p) res += d[p];\n    return\
    \ res;\n  }\n\n  T sum(int l, int r) const { return sum(r) - sum(l); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct BIT {\n  int n;\n  vector<T> d;\n\n  BIT() : n(0) {}\n  BIT(int\
    \ n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n    d.assign(n + 1,\
    \ T());\n  }\n\n  void add(int i, T x) {\n    for (int p = i + 1; p <= n; p +=\
    \ p & -p) d[p] += x;\n  }\n\n  T sum(int r) const {\n    T res = T();\n    for\
    \ (int p = r; p > 0; p -= p & -p) res += d[p];\n    return res;\n  }\n\n  T sum(int\
    \ l, int r) const { return sum(r) - sum(l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2026-03-11 03:20:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_add_range_sum_2.test.cpp
documentation_of: structure/BIT.hpp
layout: document
title: "Fenwick\u6728"
---
Definition
一点加算と区間和を扱うデータ構造。

Complexity
初期化は O(n)、一点更新は O(log n)、区間和は O(log n)。

sum(r) は半開区間 [0, r) の和を返す。
sum(l, r) は半開区間 [l, r) の和を返す。

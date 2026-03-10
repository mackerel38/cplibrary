---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum.test.cpp
    title: verify/yosupo_point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum_2.test.cpp
    title: verify/yosupo_point_add_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct BIT {\n  int n;\n  vector<T> d;\n  BIT()\
    \ : n(0) {}\n  BIT(int n_) { init(n_); }\n  void init(int n_) {\n    n = n_;\n\
    \    d.assign(n + 1, T());\n  }\n  void add(int i, T x) {\n    for (i++; i <=\
    \ n; i += i & -i) d[i] += x;\n  }\n  T sum(int r) const {\n    T s = T();\n  \
    \  for (; r > 0; r -= r & -r) s += d[r];\n    return s;\n  }\n  T sum(int l, int\
    \ r) const { return sum(r) - sum(l); }\n  int lower_bound(T x) const {\n    if\
    \ (x <= T()) return 0;\n    int i = 0;\n    int k = 1;\n    while ((k << 1) <=\
    \ n) k <<= 1;\n    for (; k > 0; k >>= 1) {\n      int ni = i + k;\n      if (ni\
    \ <= n && d[ni] < x) {\n        x -= d[ni];\n        i = ni;\n      }\n    }\n\
    \    return i;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct BIT {\n  int n;\n  vector<T> d;\n  BIT() : n(0) {}\n  BIT(int\
    \ n_) { init(n_); }\n  void init(int n_) {\n    n = n_;\n    d.assign(n + 1, T());\n\
    \  }\n  void add(int i, T x) {\n    for (i++; i <= n; i += i & -i) d[i] += x;\n\
    \  }\n  T sum(int r) const {\n    T s = T();\n    for (; r > 0; r -= r & -r) s\
    \ += d[r];\n    return s;\n  }\n  T sum(int l, int r) const { return sum(r) -\
    \ sum(l); }\n  int lower_bound(T x) const {\n    if (x <= T()) return 0;\n   \
    \ int i = 0;\n    int k = 1;\n    while ((k << 1) <= n) k <<= 1;\n    for (; k\
    \ > 0; k >>= 1) {\n      int ni = i + k;\n      if (ni <= n && d[ni] < x) {\n\
    \        x -= d[ni];\n        i = ni;\n      }\n    }\n    return i;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2026-03-11 04:02:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_add_range_sum.test.cpp
  - verify/yosupo_point_add_range_sum_2.test.cpp
documentation_of: //structure/BIT.hpp
layout: document
redirect_from:
- /library/structure/BIT.hpp
- /library/structure/BIT.hpp.html
title: structure/BIT.hpp
---

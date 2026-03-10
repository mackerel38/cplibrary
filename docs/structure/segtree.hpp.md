---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum.test.cpp
    title: verify/yosupo_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct segtree\
    \ {\n  int n;\n  int size;\n  vector<S> d;\n\n  segtree() : n(0), size(1), d(1,\
    \ e()) {}\n  segtree(int n_) { init(n_); }\n  segtree(const vector<S>& v) { build(v);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    size = 1;\n    while (size < n)\
    \ size <<= 1;\n    d.assign(2 * size, e());\n  }\n\n  void build(const vector<S>&\
    \ v) {\n    init((int)v.size());\n    for (int i = 0; i < n; i++) d[size + i]\
    \ = v[i];\n    for (int i = size - 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i\
    \ + 1]);\n  }\n\n  void set(int p, S x) {\n    int i = p + size;\n    d[i] = x;\n\
    \    while (i > 1) {\n      i >>= 1;\n      d[i] = op(d[2 * i], d[2 * i + 1]);\n\
    \    }\n  }\n\n  S get(int p) const { return d[p + size]; }\n\n  S prod(int l,\
    \ int r) const {\n    S sml = e(), smr = e();\n    int left = l + size, right\
    \ = r + size;\n    while (left < right) {\n      if (left & 1) sml = op(sml, d[left++]);\n\
    \      if (right & 1) smr = op(d[--right], smr);\n      left >>= 1;\n      right\
    \ >>= 1;\n    }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return\
    \ d[1]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n  int n;\n  int size;\n\
    \  vector<S> d;\n\n  segtree() : n(0), size(1), d(1, e()) {}\n  segtree(int n_)\
    \ { init(n_); }\n  segtree(const vector<S>& v) { build(v); }\n\n  void init(int\
    \ n_) {\n    n = n_;\n    size = 1;\n    while (size < n) size <<= 1;\n    d.assign(2\
    \ * size, e());\n  }\n\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[size + i] = v[i];\n    for (int i = size -\
    \ 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i + 1]);\n  }\n\n  void set(int p,\
    \ S x) {\n    int i = p + size;\n    d[i] = x;\n    while (i > 1) {\n      i >>=\
    \ 1;\n      d[i] = op(d[2 * i], d[2 * i + 1]);\n    }\n  }\n\n  S get(int p) const\
    \ { return d[p + size]; }\n\n  S prod(int l, int r) const {\n    S sml = e(),\
    \ smr = e();\n    int left = l + size, right = r + size;\n    while (left < right)\
    \ {\n      if (left & 1) sml = op(sml, d[left++]);\n      if (right & 1) smr =\
    \ op(d[--right], smr);\n      left >>= 1;\n      right >>= 1;\n    }\n    return\
    \ op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 03:11:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_add_range_sum.test.cpp
documentation_of: structure/segtree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
Definition
区間演算を扱う完全二分木で、配列に対する一点更新と区間クエリを高速に処理する。

Complexity
構築は O(n)、一点更新は O(log n)、区間積は O(log n)。

この実装はモノイド (S, op, e) を前提とする。
prod(l, r) は半開区間 [l, r) の積を返す。
all_prod() は全体の積を返す。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_affine_range_sum_large_array.test.cpp
    title: verify/yosupo_range_affine_range_sum_large_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/dynamiclazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), S (*make)(long\
    \ long), class F,\n          S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\n\
    struct dynamic_lazysegtree {\n  struct node {\n    S val;\n    F lz;\n    int\
    \ l;\n    int r;\n    bool has;\n  };\n\n  long long n;\n  vector<node> nd;\n\
    \  int root;\n\n  dynamic_lazysegtree() : n(0), root(-1) {}\n  dynamic_lazysegtree(long\
    \ long n_) { init(n_); }\n\n  void init(long long n_) {\n    n = n_;\n    nd.clear();\n\
    \    root = -1;\n  }\n\n  int new_node(long long len) {\n    nd.push_back({make(len),\
    \ id(), -1, -1, false});\n    return (int)nd.size() - 1;\n  }\n\n  void set(long\
    \ long p, S x) { root = set(root, 0, n, p, x); }\n\n  S get(long long p) { return\
    \ prod(p, p + 1); }\n\n  S prod(long long l, long long r) { return prod(root,\
    \ 0, n, l, r); }\n\n  S all_prod() { return root == -1 ? make(n) : nd[root].val;\
    \ }\n\n  void apply(long long l, long long r, F f) {\n    root = apply(root, 0,\
    \ n, l, r, f);\n  }\n\n  int set(int v, long long l, long long r, long long p,\
    \ S x) {\n    if (v == -1) v = new_node(r - l);\n    if (r - l == 1) {\n     \
    \ nd[v].val = x;\n      nd[v].lz = id();\n      nd[v].has = false;\n      return\
    \ v;\n    }\n    push(v, l, r);\n    long long m = (l + r) >> 1;\n    if (p <\
    \ m) {\n      nd[v].l = set(nd[v].l, l, m, p, x);\n    } else {\n      nd[v].r\
    \ = set(nd[v].r, m, r, p, x);\n    }\n    pull(v, l, r);\n    return v;\n  }\n\
    \n  int apply(int v, long long l, long long r, long long ql, long long qr, F f)\
    \ {\n    if (qr <= l || r <= ql) return v;\n    if (v == -1) v = new_node(r -\
    \ l);\n    if (ql <= l && r <= qr) {\n      all_apply(v, f);\n      return v;\n\
    \    }\n    push(v, l, r);\n    long long m = (l + r) >> 1;\n    nd[v].l = apply(nd[v].l,\
    \ l, m, ql, qr, f);\n    nd[v].r = apply(nd[v].r, m, r, ql, qr, f);\n    pull(v,\
    \ l, r);\n    return v;\n  }\n\n  S prod(int v, long long l, long long r, long\
    \ long ql, long long qr) {\n    if (qr <= l || r <= ql) return e();\n    if (v\
    \ == -1) {\n      long long len = min(r, qr) - max(l, ql);\n      if (len <= 0)\
    \ return e();\n      return make(len);\n    }\n    if (ql <= l && r <= qr) return\
    \ nd[v].val;\n    push(v, l, r);\n    long long m = (l + r) >> 1;\n    S lv =\
    \ prod(nd[v].l, l, m, ql, qr);\n    S rv = prod(nd[v].r, m, r, ql, qr);\n    return\
    \ op(lv, rv);\n  }\n\n  void all_apply(int v, F f) {\n    nd[v].val = mapping(f,\
    \ nd[v].val);\n    if (nd[v].has) {\n      nd[v].lz = composition(f, nd[v].lz);\n\
    \    } else {\n      nd[v].lz = f;\n      nd[v].has = true;\n    }\n  }\n\n  void\
    \ push(int v, long long l, long long r) {\n    if (!nd[v].has || r - l == 1) return;\n\
    \    long long m = (l + r) >> 1;\n    if (nd[v].l == -1) nd[v].l = new_node(m\
    \ - l);\n    if (nd[v].r == -1) nd[v].r = new_node(r - m);\n    all_apply(nd[v].l,\
    \ nd[v].lz);\n    all_apply(nd[v].r, nd[v].lz);\n    nd[v].lz = id();\n    nd[v].has\
    \ = false;\n  }\n\n  void pull(int v, long long l, long long r) {\n    long long\
    \ m = (l + r) >> 1;\n    S lv = nd[v].l == -1 ? make(m - l) : nd[nd[v].l].val;\n\
    \    S rv = nd[v].r == -1 ? make(r - m) : nd[nd[v].r].val;\n    nd[v].val = op(lv,\
    \ rv);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), S (*make)(long long), class F,\n        \
    \  S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct dynamic_lazysegtree\
    \ {\n  struct node {\n    S val;\n    F lz;\n    int l;\n    int r;\n    bool\
    \ has;\n  };\n\n  long long n;\n  vector<node> nd;\n  int root;\n\n  dynamic_lazysegtree()\
    \ : n(0), root(-1) {}\n  dynamic_lazysegtree(long long n_) { init(n_); }\n\n \
    \ void init(long long n_) {\n    n = n_;\n    nd.clear();\n    root = -1;\n  }\n\
    \n  int new_node(long long len) {\n    nd.push_back({make(len), id(), -1, -1,\
    \ false});\n    return (int)nd.size() - 1;\n  }\n\n  void set(long long p, S x)\
    \ { root = set(root, 0, n, p, x); }\n\n  S get(long long p) { return prod(p, p\
    \ + 1); }\n\n  S prod(long long l, long long r) { return prod(root, 0, n, l, r);\
    \ }\n\n  S all_prod() { return root == -1 ? make(n) : nd[root].val; }\n\n  void\
    \ apply(long long l, long long r, F f) {\n    root = apply(root, 0, n, l, r, f);\n\
    \  }\n\n  int set(int v, long long l, long long r, long long p, S x) {\n    if\
    \ (v == -1) v = new_node(r - l);\n    if (r - l == 1) {\n      nd[v].val = x;\n\
    \      nd[v].lz = id();\n      nd[v].has = false;\n      return v;\n    }\n  \
    \  push(v, l, r);\n    long long m = (l + r) >> 1;\n    if (p < m) {\n      nd[v].l\
    \ = set(nd[v].l, l, m, p, x);\n    } else {\n      nd[v].r = set(nd[v].r, m, r,\
    \ p, x);\n    }\n    pull(v, l, r);\n    return v;\n  }\n\n  int apply(int v,\
    \ long long l, long long r, long long ql, long long qr, F f) {\n    if (qr <=\
    \ l || r <= ql) return v;\n    if (v == -1) v = new_node(r - l);\n    if (ql <=\
    \ l && r <= qr) {\n      all_apply(v, f);\n      return v;\n    }\n    push(v,\
    \ l, r);\n    long long m = (l + r) >> 1;\n    nd[v].l = apply(nd[v].l, l, m,\
    \ ql, qr, f);\n    nd[v].r = apply(nd[v].r, m, r, ql, qr, f);\n    pull(v, l,\
    \ r);\n    return v;\n  }\n\n  S prod(int v, long long l, long long r, long long\
    \ ql, long long qr) {\n    if (qr <= l || r <= ql) return e();\n    if (v == -1)\
    \ {\n      long long len = min(r, qr) - max(l, ql);\n      if (len <= 0) return\
    \ e();\n      return make(len);\n    }\n    if (ql <= l && r <= qr) return nd[v].val;\n\
    \    push(v, l, r);\n    long long m = (l + r) >> 1;\n    S lv = prod(nd[v].l,\
    \ l, m, ql, qr);\n    S rv = prod(nd[v].r, m, r, ql, qr);\n    return op(lv, rv);\n\
    \  }\n\n  void all_apply(int v, F f) {\n    nd[v].val = mapping(f, nd[v].val);\n\
    \    if (nd[v].has) {\n      nd[v].lz = composition(f, nd[v].lz);\n    } else\
    \ {\n      nd[v].lz = f;\n      nd[v].has = true;\n    }\n  }\n\n  void push(int\
    \ v, long long l, long long r) {\n    if (!nd[v].has || r - l == 1) return;\n\
    \    long long m = (l + r) >> 1;\n    if (nd[v].l == -1) nd[v].l = new_node(m\
    \ - l);\n    if (nd[v].r == -1) nd[v].r = new_node(r - m);\n    all_apply(nd[v].l,\
    \ nd[v].lz);\n    all_apply(nd[v].r, nd[v].lz);\n    nd[v].lz = id();\n    nd[v].has\
    \ = false;\n  }\n\n  void pull(int v, long long l, long long r) {\n    long long\
    \ m = (l + r) >> 1;\n    S lv = nd[v].l == -1 ? make(m - l) : nd[nd[v].l].val;\n\
    \    S rv = nd[v].r == -1 ? make(r - m) : nd[nd[v].r].val;\n    nd[v].val = op(lv,\
    \ rv);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamiclazysegtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 20:49:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_range_affine_range_sum_large_array.test.cpp
documentation_of: //structure/dynamiclazysegtree.hpp
layout: document
title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
Definition
区間更新と区間取得をサポートする動的セグメント木。

Complexity
各操作 O(log N)

巨大な N に対して必要なノードのみ確保する。初期値は `make(len)` で表現し、空ノードの区間長に応じた単位元を返す設計。

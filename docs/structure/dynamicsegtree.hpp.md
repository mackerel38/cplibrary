---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_set_range_composite_large_array.test.cpp
    title: verify/yosupo_point_set_range_composite_large_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/dynamicsegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct dynamic_segtree\
    \ {\n  struct node {\n    S val;\n    int l;\n    int r;\n  };\n\n  long long\
    \ n;\n  vector<node> nd;\n  int root;\n\n  dynamic_segtree() : n(0), root(-1)\
    \ {}\n  dynamic_segtree(long long n_) { init(n_); }\n\n  void init(long long n_)\
    \ {\n    n = n_;\n    nd.clear();\n    root = -1;\n  }\n\n  int new_node() {\n\
    \    nd.push_back({e(), -1, -1});\n    return (int)nd.size() - 1;\n  }\n\n  void\
    \ set(long long p, S x) { root = set(root, 0, n, p, x); }\n\n  S get(long long\
    \ p) { return prod(p, p + 1); }\n\n  S prod(long long l, long long r) { return\
    \ prod(root, 0, n, l, r); }\n\n  S all_prod() { return root == -1 ? e() : nd[root].val;\
    \ }\n\n  int set(int v, long long l, long long r, long long p, S x) {\n    if\
    \ (v == -1) v = new_node();\n    if (r - l == 1) {\n      nd[v].val = x;\n   \
    \   return v;\n    }\n    long long m = (l + r) >> 1;\n    if (p < m) {\n    \
    \  nd[v].l = set(nd[v].l, l, m, p, x);\n    } else {\n      nd[v].r = set(nd[v].r,\
    \ m, r, p, x);\n    }\n    S lv = nd[v].l == -1 ? e() : nd[nd[v].l].val;\n   \
    \ S rv = nd[v].r == -1 ? e() : nd[nd[v].r].val;\n    nd[v].val = op(lv, rv);\n\
    \    return v;\n  }\n\n  S prod(int v, long long l, long long r, long long ql,\
    \ long long qr) {\n    if (v == -1 || qr <= l || r <= ql) return e();\n    if\
    \ (ql <= l && r <= qr) return nd[v].val;\n    long long m = (l + r) >> 1;\n  \
    \  S lv = prod(nd[v].l, l, m, ql, qr);\n    S rv = prod(nd[v].r, m, r, ql, qr);\n\
    \    return op(lv, rv);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct dynamic_segtree {\n  struct node\
    \ {\n    S val;\n    int l;\n    int r;\n  };\n\n  long long n;\n  vector<node>\
    \ nd;\n  int root;\n\n  dynamic_segtree() : n(0), root(-1) {}\n  dynamic_segtree(long\
    \ long n_) { init(n_); }\n\n  void init(long long n_) {\n    n = n_;\n    nd.clear();\n\
    \    root = -1;\n  }\n\n  int new_node() {\n    nd.push_back({e(), -1, -1});\n\
    \    return (int)nd.size() - 1;\n  }\n\n  void set(long long p, S x) { root =\
    \ set(root, 0, n, p, x); }\n\n  S get(long long p) { return prod(p, p + 1); }\n\
    \n  S prod(long long l, long long r) { return prod(root, 0, n, l, r); }\n\n  S\
    \ all_prod() { return root == -1 ? e() : nd[root].val; }\n\n  int set(int v, long\
    \ long l, long long r, long long p, S x) {\n    if (v == -1) v = new_node();\n\
    \    if (r - l == 1) {\n      nd[v].val = x;\n      return v;\n    }\n    long\
    \ long m = (l + r) >> 1;\n    if (p < m) {\n      nd[v].l = set(nd[v].l, l, m,\
    \ p, x);\n    } else {\n      nd[v].r = set(nd[v].r, m, r, p, x);\n    }\n   \
    \ S lv = nd[v].l == -1 ? e() : nd[nd[v].l].val;\n    S rv = nd[v].r == -1 ? e()\
    \ : nd[nd[v].r].val;\n    nd[v].val = op(lv, rv);\n    return v;\n  }\n\n  S prod(int\
    \ v, long long l, long long r, long long ql, long long qr) {\n    if (v == -1\
    \ || qr <= l || r <= ql) return e();\n    if (ql <= l && r <= qr) return nd[v].val;\n\
    \    long long m = (l + r) >> 1;\n    S lv = prod(nd[v].l, l, m, ql, qr);\n  \
    \  S rv = prod(nd[v].r, m, r, ql, qr);\n    return op(lv, rv);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamicsegtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 18:00:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_set_range_composite_large_array.test.cpp
documentation_of: //structure/dynamicsegtree.hpp
layout: document
title: Dynamic Segment Tree
---

Definition
必要なノードだけ生成する動的セグメント木。区間積と一点更新を扱う。

Complexity
各操作は O(log N)。

使い方
`dynamic_segtree<S, op, e> seg(n);` で区間 [0, n) を扱う。
`seg.init(n);` で再初期化する。
`seg.set(p, x);` で位置 p の値を x に更新する。
`seg.get(p);` で位置 p の値を取得する。
`seg.prod(l, r);` で [l, r) の区間積を取得する。
`seg.all_prod();` で全区間の積を取得する。空の場合は `e()`。
`seg.new_node();` と内部用の `set`/`prod` は再帰実装の補助で、通常は呼ばない。

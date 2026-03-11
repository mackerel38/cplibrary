---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_persistent_range_affine_range_sum.test.cpp
    title: verify/yosupo_persistent_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/persistentlazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nstruct persistent_lazysegtree\
    \ {\n  struct node {\n    S val;\n    F lz;\n    int l;\n    int r;\n    bool\
    \ has;\n  };\n\n  int n;\n  vector<node> nd;\n  vector<int> root;\n\n  persistent_lazysegtree()\
    \ : n(0) {}\n  persistent_lazysegtree(int n_) { init(n_); }\n  persistent_lazysegtree(const\
    \ vector<S>& v) { build(v); }\n\n  void init(int n_) {\n    n = n_;\n    nd.clear();\n\
    \    root.clear();\n    root.push_back(build_empty(0, n));\n  }\n\n  void build(const\
    \ vector<S>& v) {\n    n = (int)v.size();\n    nd.clear();\n    root.clear();\n\
    \    root.push_back(build_vec(0, n, v));\n  }\n\n  int apply(int ver, int l, int\
    \ r, F f) {\n    int nr = apply(root[ver], 0, n, l, r, f);\n    root.push_back(nr);\n\
    \    return (int)root.size() - 1;\n  }\n\n  int set(int ver, int p, S x) {\n \
    \   int nr = set(root[ver], 0, n, p, x);\n    root.push_back(nr);\n    return\
    \ (int)root.size() - 1;\n  }\n\n  int replace_range(int ver_a, int ver_b, int\
    \ l, int r) {\n    int nr = replace_range(root[ver_a], root[ver_b], 0, n, l, r);\n\
    \    root.push_back(nr);\n    return (int)root.size() - 1;\n  }\n\n  S get(int\
    \ ver, int p) { return prod(ver, p, p + 1); }\n\n  S prod(int ver, int l, int\
    \ r) { return prod(root[ver], 0, n, l, r, id()); }\n\n  int new_node(S val, F\
    \ lz, int l, int r, bool has) {\n    nd.push_back({val, lz, l, r, has});\n   \
    \ return (int)nd.size() - 1;\n  }\n\n  int build_empty(int l, int r) {\n    if\
    \ (r - l == 1) return new_node(e(), id(), -1, -1, false);\n    int m = (l + r)\
    \ >> 1;\n    int lc = build_empty(l, m);\n    int rc = build_empty(m, r);\n  \
    \  return new_node(op(nd[lc].val, nd[rc].val), id(), lc, rc, false);\n  }\n\n\
    \  int build_vec(int l, int r, const vector<S>& v) {\n    if (r - l == 1) return\
    \ new_node(v[l], id(), -1, -1, false);\n    int m = (l + r) >> 1;\n    int lc\
    \ = build_vec(l, m, v);\n    int rc = build_vec(m, r, v);\n    return new_node(op(nd[lc].val,\
    \ nd[rc].val), id(), lc, rc, false);\n  }\n\n  int clone(int v) {\n    nd.push_back(nd[v]);\n\
    \    return (int)nd.size() - 1;\n  }\n\n  void all_apply(int v, F f) {\n    nd[v].val\
    \ = mapping(f, nd[v].val);\n    if (nd[v].has) {\n      nd[v].lz = composition(f,\
    \ nd[v].lz);\n    } else {\n      nd[v].lz = f;\n      nd[v].has = true;\n   \
    \ }\n  }\n\n  void push(int v, int l, int r) {\n    if (r - l == 1) return;\n\
    \    if (!nd[v].has) return;\n    F f = nd[v].lz;\n    int lc = nd[v].l;\n   \
    \ int rc = nd[v].r;\n    lc = clone(lc);\n    rc = clone(rc);\n    all_apply(lc,\
    \ f);\n    all_apply(rc, f);\n    nd[v].l = lc;\n    nd[v].r = rc;\n    nd[v].lz\
    \ = id();\n    nd[v].has = false;\n  }\n\n  int apply(int v, int l, int r, int\
    \ ql, int qr, F f) {\n    if (qr <= l || r <= ql) return v;\n    v = clone(v);\n\
    \    if (ql <= l && r <= qr) {\n      all_apply(v, f);\n      return v;\n    }\n\
    \    push(v, l, r);\n    int m = (l + r) >> 1;\n    int lc = apply(nd[v].l, l,\
    \ m, ql, qr, f);\n    int rc = apply(nd[v].r, m, r, ql, qr, f);\n    nd[v].l =\
    \ lc;\n    nd[v].r = rc;\n    nd[v].val = op(nd[lc].val, nd[rc].val);\n    return\
    \ v;\n  }\n\n  int set(int v, int l, int r, int p, S x) {\n    v = clone(v);\n\
    \    if (r - l == 1) {\n      nd[v].val = x;\n      nd[v].lz = id();\n      nd[v].has\
    \ = false;\n      return v;\n    }\n    push(v, l, r);\n    int m = (l + r) >>\
    \ 1;\n    if (p < m) {\n      nd[v].l = set(nd[v].l, l, m, p, x);\n    } else\
    \ {\n      nd[v].r = set(nd[v].r, m, r, p, x);\n    }\n    nd[v].val = op(nd[nd[v].l].val,\
    \ nd[nd[v].r].val);\n    return v;\n  }\n\n  S prod(int v, int l, int r, int ql,\
    \ int qr, F acc) {\n    if (qr <= l || r <= ql) return e();\n    if (ql <= l &&\
    \ r <= qr) return mapping(acc, nd[v].val);\n    int m = (l + r) >> 1;\n    F nxt\
    \ = acc;\n    if (nd[v].has) nxt = composition(acc, nd[v].lz);\n    S lv = prod(nd[v].l,\
    \ l, m, ql, qr, nxt);\n    S rv = prod(nd[v].r, m, r, ql, qr, nxt);\n    return\
    \ op(lv, rv);\n  }\n\n  int replace_range(int a, int b, int l, int r, int ql,\
    \ int qr) {\n    if (qr <= l || r <= ql) return a;\n    if (ql <= l && r <= qr)\
    \ return b;\n    a = clone(a);\n    b = clone(b);\n    push(a, l, r);\n    push(b,\
    \ l, r);\n    int m = (l + r) >> 1;\n    int lc = replace_range(nd[a].l, nd[b].l,\
    \ l, m, ql, qr);\n    int rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);\n\
    \    nd[a].l = lc;\n    nd[a].r = rc;\n    nd[a].val = op(nd[lc].val, nd[rc].val);\n\
    \    return a;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\nstruct persistent_lazysegtree {\n  struct\
    \ node {\n    S val;\n    F lz;\n    int l;\n    int r;\n    bool has;\n  };\n\
    \n  int n;\n  vector<node> nd;\n  vector<int> root;\n\n  persistent_lazysegtree()\
    \ : n(0) {}\n  persistent_lazysegtree(int n_) { init(n_); }\n  persistent_lazysegtree(const\
    \ vector<S>& v) { build(v); }\n\n  void init(int n_) {\n    n = n_;\n    nd.clear();\n\
    \    root.clear();\n    root.push_back(build_empty(0, n));\n  }\n\n  void build(const\
    \ vector<S>& v) {\n    n = (int)v.size();\n    nd.clear();\n    root.clear();\n\
    \    root.push_back(build_vec(0, n, v));\n  }\n\n  int apply(int ver, int l, int\
    \ r, F f) {\n    int nr = apply(root[ver], 0, n, l, r, f);\n    root.push_back(nr);\n\
    \    return (int)root.size() - 1;\n  }\n\n  int set(int ver, int p, S x) {\n \
    \   int nr = set(root[ver], 0, n, p, x);\n    root.push_back(nr);\n    return\
    \ (int)root.size() - 1;\n  }\n\n  int replace_range(int ver_a, int ver_b, int\
    \ l, int r) {\n    int nr = replace_range(root[ver_a], root[ver_b], 0, n, l, r);\n\
    \    root.push_back(nr);\n    return (int)root.size() - 1;\n  }\n\n  S get(int\
    \ ver, int p) { return prod(ver, p, p + 1); }\n\n  S prod(int ver, int l, int\
    \ r) { return prod(root[ver], 0, n, l, r, id()); }\n\n  int new_node(S val, F\
    \ lz, int l, int r, bool has) {\n    nd.push_back({val, lz, l, r, has});\n   \
    \ return (int)nd.size() - 1;\n  }\n\n  int build_empty(int l, int r) {\n    if\
    \ (r - l == 1) return new_node(e(), id(), -1, -1, false);\n    int m = (l + r)\
    \ >> 1;\n    int lc = build_empty(l, m);\n    int rc = build_empty(m, r);\n  \
    \  return new_node(op(nd[lc].val, nd[rc].val), id(), lc, rc, false);\n  }\n\n\
    \  int build_vec(int l, int r, const vector<S>& v) {\n    if (r - l == 1) return\
    \ new_node(v[l], id(), -1, -1, false);\n    int m = (l + r) >> 1;\n    int lc\
    \ = build_vec(l, m, v);\n    int rc = build_vec(m, r, v);\n    return new_node(op(nd[lc].val,\
    \ nd[rc].val), id(), lc, rc, false);\n  }\n\n  int clone(int v) {\n    nd.push_back(nd[v]);\n\
    \    return (int)nd.size() - 1;\n  }\n\n  void all_apply(int v, F f) {\n    nd[v].val\
    \ = mapping(f, nd[v].val);\n    if (nd[v].has) {\n      nd[v].lz = composition(f,\
    \ nd[v].lz);\n    } else {\n      nd[v].lz = f;\n      nd[v].has = true;\n   \
    \ }\n  }\n\n  void push(int v, int l, int r) {\n    if (r - l == 1) return;\n\
    \    if (!nd[v].has) return;\n    F f = nd[v].lz;\n    int lc = nd[v].l;\n   \
    \ int rc = nd[v].r;\n    lc = clone(lc);\n    rc = clone(rc);\n    all_apply(lc,\
    \ f);\n    all_apply(rc, f);\n    nd[v].l = lc;\n    nd[v].r = rc;\n    nd[v].lz\
    \ = id();\n    nd[v].has = false;\n  }\n\n  int apply(int v, int l, int r, int\
    \ ql, int qr, F f) {\n    if (qr <= l || r <= ql) return v;\n    v = clone(v);\n\
    \    if (ql <= l && r <= qr) {\n      all_apply(v, f);\n      return v;\n    }\n\
    \    push(v, l, r);\n    int m = (l + r) >> 1;\n    int lc = apply(nd[v].l, l,\
    \ m, ql, qr, f);\n    int rc = apply(nd[v].r, m, r, ql, qr, f);\n    nd[v].l =\
    \ lc;\n    nd[v].r = rc;\n    nd[v].val = op(nd[lc].val, nd[rc].val);\n    return\
    \ v;\n  }\n\n  int set(int v, int l, int r, int p, S x) {\n    v = clone(v);\n\
    \    if (r - l == 1) {\n      nd[v].val = x;\n      nd[v].lz = id();\n      nd[v].has\
    \ = false;\n      return v;\n    }\n    push(v, l, r);\n    int m = (l + r) >>\
    \ 1;\n    if (p < m) {\n      nd[v].l = set(nd[v].l, l, m, p, x);\n    } else\
    \ {\n      nd[v].r = set(nd[v].r, m, r, p, x);\n    }\n    nd[v].val = op(nd[nd[v].l].val,\
    \ nd[nd[v].r].val);\n    return v;\n  }\n\n  S prod(int v, int l, int r, int ql,\
    \ int qr, F acc) {\n    if (qr <= l || r <= ql) return e();\n    if (ql <= l &&\
    \ r <= qr) return mapping(acc, nd[v].val);\n    int m = (l + r) >> 1;\n    F nxt\
    \ = acc;\n    if (nd[v].has) nxt = composition(acc, nd[v].lz);\n    S lv = prod(nd[v].l,\
    \ l, m, ql, qr, nxt);\n    S rv = prod(nd[v].r, m, r, ql, qr, nxt);\n    return\
    \ op(lv, rv);\n  }\n\n  int replace_range(int a, int b, int l, int r, int ql,\
    \ int qr) {\n    if (qr <= l || r <= ql) return a;\n    if (ql <= l && r <= qr)\
    \ return b;\n    a = clone(a);\n    b = clone(b);\n    push(a, l, r);\n    push(b,\
    \ l, r);\n    int m = (l + r) >> 1;\n    int lc = replace_range(nd[a].l, nd[b].l,\
    \ l, m, ql, qr);\n    int rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);\n\
    \    nd[a].l = lc;\n    nd[a].r = rc;\n    nd[a].val = op(nd[lc].val, nd[rc].val);\n\
    \    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/persistentlazysegtree.hpp
  requiredBy: []
  timestamp: '2026-03-12 00:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_persistent_range_affine_range_sum.test.cpp
documentation_of: //structure/persistentlazysegtree.hpp
layout: document
title: "\u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
Definition
区間更新と区間取得を永続化した遅延セグメント木。

Complexity
更新: O(log N)
取得: O(log N)

ポイント
- 作用素の合成と単位元を用意する
- 更新ごとに新しい版を作成する
- 過去の版は参照専用で保持される
- 版同士の区間コピーに対応できる

使い方
- `persistent_lazysegtree<S, op, e, F, mapping, composition, id> seg(v);`
- `seg.apply(ver, l, r, f);` で新しい版を作成
- `seg.prod(ver, l, r);` で区間取得
- `seg.set(ver, p, x);` で一点更新
- `seg.replace_range(ver_a, ver_b, l, r);` で区間を別の版からコピー

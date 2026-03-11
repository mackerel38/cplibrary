---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/persistentsegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct persistent_segtree\
    \ {\n  struct node {\n    S val;\n    int l;\n    int r;\n  };\n\n  int n;\n \
    \ vector<node> nd;\n  vector<int> root;\n\n  persistent_segtree() : n(0) {}\n\
    \  persistent_segtree(int n_) { init(n_); }\n  persistent_segtree(const vector<S>&\
    \ v) { build(v); }\n\n  void init(int n_) {\n    n = n_;\n    nd.clear();\n  \
    \  root.clear();\n    root.push_back(build_empty(0, n));\n  }\n\n  void build(const\
    \ vector<S>& v) {\n    n = (int)v.size();\n    nd.clear();\n    root.clear();\n\
    \    root.push_back(build_vec(0, n, v));\n  }\n\n  int update(int ver, int p,\
    \ S x) {\n    int nr = update(root[ver], 0, n, p, x);\n    root.push_back(nr);\n\
    \    return (int)root.size() - 1;\n  }\n\n  S get(int ver, int p) { return get(root[ver],\
    \ 0, n, p); }\n\n  S prod(int ver, int l, int r) { return prod(root[ver], 0, n,\
    \ l, r); }\n\n  int new_node(S val, int l, int r) {\n    nd.push_back({val, l,\
    \ r});\n    return (int)nd.size() - 1;\n  }\n\n  int build_empty(int l, int r)\
    \ {\n    if (r - l == 1) return new_node(e(), -1, -1);\n    int m = (l + r) >>\
    \ 1;\n    int lc = build_empty(l, m);\n    int rc = build_empty(m, r);\n    return\
    \ new_node(op(nd[lc].val, nd[rc].val), lc, rc);\n  }\n\n  int build_vec(int l,\
    \ int r, const vector<S>& v) {\n    if (r - l == 1) return new_node(v[l], -1,\
    \ -1);\n    int m = (l + r) >> 1;\n    int lc = build_vec(l, m, v);\n    int rc\
    \ = build_vec(m, r, v);\n    return new_node(op(nd[lc].val, nd[rc].val), lc, rc);\n\
    \  }\n\n  int update(int v, int l, int r, int p, S x) {\n    if (r - l == 1) return\
    \ new_node(x, -1, -1);\n    int m = (l + r) >> 1;\n    int lc = nd[v].l;\n   \
    \ int rc = nd[v].r;\n    if (p < m) {\n      lc = update(lc, l, m, p, x);\n  \
    \  } else {\n      rc = update(rc, m, r, p, x);\n    }\n    return new_node(op(nd[lc].val,\
    \ nd[rc].val), lc, rc);\n  }\n\n  S get(int v, int l, int r, int p) {\n    if\
    \ (r - l == 1) return nd[v].val;\n    int m = (l + r) >> 1;\n    if (p < m) return\
    \ get(nd[v].l, l, m, p);\n    return get(nd[v].r, m, r, p);\n  }\n\n  S prod(int\
    \ v, int l, int r, int ql, int qr) {\n    if (qr <= l || r <= ql) return e();\n\
    \    if (ql <= l && r <= qr) return nd[v].val;\n    int m = (l + r) >> 1;\n  \
    \  S lv = prod(nd[v].l, l, m, ql, qr);\n    S rv = prod(nd[v].r, m, r, ql, qr);\n\
    \    return op(lv, rv);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct persistent_segtree {\n  struct node\
    \ {\n    S val;\n    int l;\n    int r;\n  };\n\n  int n;\n  vector<node> nd;\n\
    \  vector<int> root;\n\n  persistent_segtree() : n(0) {}\n  persistent_segtree(int\
    \ n_) { init(n_); }\n  persistent_segtree(const vector<S>& v) { build(v); }\n\n\
    \  void init(int n_) {\n    n = n_;\n    nd.clear();\n    root.clear();\n    root.push_back(build_empty(0,\
    \ n));\n  }\n\n  void build(const vector<S>& v) {\n    n = (int)v.size();\n  \
    \  nd.clear();\n    root.clear();\n    root.push_back(build_vec(0, n, v));\n \
    \ }\n\n  int update(int ver, int p, S x) {\n    int nr = update(root[ver], 0,\
    \ n, p, x);\n    root.push_back(nr);\n    return (int)root.size() - 1;\n  }\n\n\
    \  S get(int ver, int p) { return get(root[ver], 0, n, p); }\n\n  S prod(int ver,\
    \ int l, int r) { return prod(root[ver], 0, n, l, r); }\n\n  int new_node(S val,\
    \ int l, int r) {\n    nd.push_back({val, l, r});\n    return (int)nd.size() -\
    \ 1;\n  }\n\n  int build_empty(int l, int r) {\n    if (r - l == 1) return new_node(e(),\
    \ -1, -1);\n    int m = (l + r) >> 1;\n    int lc = build_empty(l, m);\n    int\
    \ rc = build_empty(m, r);\n    return new_node(op(nd[lc].val, nd[rc].val), lc,\
    \ rc);\n  }\n\n  int build_vec(int l, int r, const vector<S>& v) {\n    if (r\
    \ - l == 1) return new_node(v[l], -1, -1);\n    int m = (l + r) >> 1;\n    int\
    \ lc = build_vec(l, m, v);\n    int rc = build_vec(m, r, v);\n    return new_node(op(nd[lc].val,\
    \ nd[rc].val), lc, rc);\n  }\n\n  int update(int v, int l, int r, int p, S x)\
    \ {\n    if (r - l == 1) return new_node(x, -1, -1);\n    int m = (l + r) >> 1;\n\
    \    int lc = nd[v].l;\n    int rc = nd[v].r;\n    if (p < m) {\n      lc = update(lc,\
    \ l, m, p, x);\n    } else {\n      rc = update(rc, m, r, p, x);\n    }\n    return\
    \ new_node(op(nd[lc].val, nd[rc].val), lc, rc);\n  }\n\n  S get(int v, int l,\
    \ int r, int p) {\n    if (r - l == 1) return nd[v].val;\n    int m = (l + r)\
    \ >> 1;\n    if (p < m) return get(nd[v].l, l, m, p);\n    return get(nd[v].r,\
    \ m, r, p);\n  }\n\n  S prod(int v, int l, int r, int ql, int qr) {\n    if (qr\
    \ <= l || r <= ql) return e();\n    if (ql <= l && r <= qr) return nd[v].val;\n\
    \    int m = (l + r) >> 1;\n    S lv = prod(nd[v].l, l, m, ql, qr);\n    S rv\
    \ = prod(nd[v].r, m, r, ql, qr);\n    return op(lv, rv);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/persistentsegtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 22:30:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: //structure/persistentsegtree.hpp
layout: document
title: "\u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
Definition
点更新と区間取得を永続化したセグメント木。

Complexity
更新: O(log N)
取得: O(log N)

ポイント
- 更新ごとに新しい版を作成する
- 過去の版の参照が可能
- 共有部分は同じノードを再利用する

使い方
- `persistent_segtree<S, op, e> seg(v);` で初期化
- `seg.update(ver, p, x);` で新しい版を作成
- `seg.get(ver, p);` で値取得
- `seg.prod(ver, l, r);` で区間取得

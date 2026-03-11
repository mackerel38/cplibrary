---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_parallel_unionfind.test.cpp
    title: verify/yosupo_range_parallel_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/rangeparallel_unionfind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class Ops>\nstruct range_parallel_unionfind\
    \ {\n  using T = typename Ops::T;\n  int n, lg;\n  vector<int> p0, sz0;\n  vector<T>\
    \ sum;\n  T cur;\n  vector<vector<int>> p, sz;\n\n  range_parallel_unionfind()\
    \ : n(0), lg(0), cur(Ops::zero()) {}\n  range_parallel_unionfind(int n_) { init(n_);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    lg = 1;\n    while ((1 << lg) <=\
    \ n) lg++;\n    p0.resize(n);\n    sz0.assign(n, 1);\n    iota(p0.begin(), p0.end(),\
    \ 0);\n    sum.assign(n, Ops::zero());\n    cur = Ops::zero();\n    p.assign(lg,\
    \ {});\n    sz.assign(lg, {});\n    for (int l = 1; l < lg; l++) {\n      int\
    \ cnt = n - (1 << l) + 1;\n      p[l].resize(cnt);\n      sz[l].assign(cnt, 1);\n\
    \      iota(p[l].begin(), p[l].end(), 0);\n    }\n  }\n\n  void set_values(const\
    \ vector<T>& v) {\n    sum = v;\n    cur = Ops::zero();\n  }\n\n  int leader(int\
    \ x) {\n    if (p0[x] == x) return x;\n    return p0[x] = leader(p0[x]);\n  }\n\
    \n  bool merge0(int a, int b) {\n    a = leader(a);\n    b = leader(b);\n    if\
    \ (a == b) return false;\n    if (sz0[a] < sz0[b]) swap(a, b);\n    p0[b] = a;\n\
    \    sz0[a] += sz0[b];\n    cur = Ops::add(cur, Ops::mul(sum[a], sum[b]));\n \
    \   sum[a] = Ops::add(sum[a], sum[b]);\n    return true;\n  }\n\n  int leader_level(int\
    \ l, int x) {\n    if (p[l][x] == x) return x;\n    return p[l][x] = leader_level(l,\
    \ p[l][x]);\n  }\n\n  bool merge_level(int l, int a, int b) {\n    a = leader_level(l,\
    \ a);\n    b = leader_level(l, b);\n    if (a == b) return false;\n    if (sz[l][a]\
    \ < sz[l][b]) swap(a, b);\n    p[l][b] = a;\n    sz[l][a] += sz[l][b];\n    return\
    \ true;\n  }\n\n  void unite_block(int l, int a, int b) {\n    if (a == b) return;\n\
    \    if (l == 0) {\n      merge0(a, b);\n      return;\n    }\n    if (!merge_level(l,\
    \ a, b)) return;\n    int half = 1 << (l - 1);\n    unite_block(l - 1, a, b);\n\
    \    unite_block(l - 1, a + half, b + half);\n  }\n\n  void merge_range(int a,\
    \ int b, int k) {\n    for (int l = 0; k > 0; l++) {\n      if (k & 1) {\n   \
    \     unite_block(l, a, b);\n        a += 1 << l;\n        b += 1 << l;\n    \
    \  }\n      k >>= 1;\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class Ops>\nstruct range_parallel_unionfind {\n  using T = typename Ops::T;\n\
    \  int n, lg;\n  vector<int> p0, sz0;\n  vector<T> sum;\n  T cur;\n  vector<vector<int>>\
    \ p, sz;\n\n  range_parallel_unionfind() : n(0), lg(0), cur(Ops::zero()) {}\n\
    \  range_parallel_unionfind(int n_) { init(n_); }\n\n  void init(int n_) {\n \
    \   n = n_;\n    lg = 1;\n    while ((1 << lg) <= n) lg++;\n    p0.resize(n);\n\
    \    sz0.assign(n, 1);\n    iota(p0.begin(), p0.end(), 0);\n    sum.assign(n,\
    \ Ops::zero());\n    cur = Ops::zero();\n    p.assign(lg, {});\n    sz.assign(lg,\
    \ {});\n    for (int l = 1; l < lg; l++) {\n      int cnt = n - (1 << l) + 1;\n\
    \      p[l].resize(cnt);\n      sz[l].assign(cnt, 1);\n      iota(p[l].begin(),\
    \ p[l].end(), 0);\n    }\n  }\n\n  void set_values(const vector<T>& v) {\n   \
    \ sum = v;\n    cur = Ops::zero();\n  }\n\n  int leader(int x) {\n    if (p0[x]\
    \ == x) return x;\n    return p0[x] = leader(p0[x]);\n  }\n\n  bool merge0(int\
    \ a, int b) {\n    a = leader(a);\n    b = leader(b);\n    if (a == b) return\
    \ false;\n    if (sz0[a] < sz0[b]) swap(a, b);\n    p0[b] = a;\n    sz0[a] +=\
    \ sz0[b];\n    cur = Ops::add(cur, Ops::mul(sum[a], sum[b]));\n    sum[a] = Ops::add(sum[a],\
    \ sum[b]);\n    return true;\n  }\n\n  int leader_level(int l, int x) {\n    if\
    \ (p[l][x] == x) return x;\n    return p[l][x] = leader_level(l, p[l][x]);\n \
    \ }\n\n  bool merge_level(int l, int a, int b) {\n    a = leader_level(l, a);\n\
    \    b = leader_level(l, b);\n    if (a == b) return false;\n    if (sz[l][a]\
    \ < sz[l][b]) swap(a, b);\n    p[l][b] = a;\n    sz[l][a] += sz[l][b];\n    return\
    \ true;\n  }\n\n  void unite_block(int l, int a, int b) {\n    if (a == b) return;\n\
    \    if (l == 0) {\n      merge0(a, b);\n      return;\n    }\n    if (!merge_level(l,\
    \ a, b)) return;\n    int half = 1 << (l - 1);\n    unite_block(l - 1, a, b);\n\
    \    unite_block(l - 1, a + half, b + half);\n  }\n\n  void merge_range(int a,\
    \ int b, int k) {\n    for (int l = 0; k > 0; l++) {\n      if (k & 1) {\n   \
    \     unite_block(l, a, b);\n        a += 1 << l;\n        b += 1 << l;\n    \
    \  }\n      k >>= 1;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/rangeparallel_unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-11 16:43:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_range_parallel_unionfind.test.cpp
documentation_of: //structure/rangeparallel_unionfind.hpp
layout: document
title: Range Parallel Union-Find
---

Definition
2つの同じ長さの区間に対して、対応する頂点をすべて併合する操作を高速に行う Union-Find。各連結成分の和を保持し、同一成分内のペアの積の総和を更新できる。

Complexity
各操作はならし O(log N α(N))。

使い方

- `range_parallel_unionfind<Ops> uf(n);` で作成する。
- `uf.init(n);` で再初期化する。
- `Ops::T` は値型、`Ops::zero()` は零元、`Ops::add(a, b)` と `Ops::mul(a, b)` を定義する。
- `uf.set_values(v);` で各頂点の値配列 v を設定する。
- `uf.merge_range(a, b, k);` で区間 [a, a+k) と [b, b+k) を対応する位置ごとに併合する。
- `uf.leader(x);` は頂点 x の代表元を返す。
- `uf.merge0(a, b);` は単一要素 a と b を併合し、成功時に `uf.cur` と `uf.sum` を更新する。
- `uf.cur` は連結成分内のペア積の合計値を保持する。
- `uf.sum[r]` は代表元 r の成分和を保持する。
- `uf.leader_level(l, x)` と `uf.merge_level(l, a, b)` は長さ `2^l` のブロック（開始位置で識別）に対する内部操作で、通常は `merge_range` を使えばよい。
- `uf.unite_block(l, a, b)` は長さ `2^l` のブロック [a, a+2^l) と [b, b+2^l) を対応併合する。

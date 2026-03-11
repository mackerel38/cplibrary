---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential.test.cpp
    title: verify/yosupo_unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
    title: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/weightedunionfind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, class Op>\nstruct weighted_unionfind\
    \ {\n  int n;\n  vector<int> p;\n  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind()\
    \ : n(0) {}\n  weighted_unionfind(int n_) { init(n_); }\n\n  void init(int n_)\
    \ {\n    n = n_;\n    p.resize(n);\n    sz.assign(n, 1);\n    w.assign(n, Op::id());\n\
    \    iota(p.begin(), p.end(), 0);\n  }\n\n  T mul(const T &a, const T &b) { return\
    \ Op::op(a, b); }\n  T inv(const T &a) { return Op::inv(a); }\n\n  int leader(int\
    \ x) {\n    if (p[x] == x) return x;\n    int r = leader(p[x]);\n    w[x] = mul(w[p[x]],\
    \ w[x]);\n    return p[x] = r;\n  }\n\n  T weight(int x) {\n    leader(x);\n \
    \   return w[x];\n  }\n\n  bool same(int a, int b) { return leader(a) == leader(b);\
    \ }\n\n  T diff(int a, int b) { return mul(inv(weight(b)), weight(a)); }\n\n \
    \ bool get(int a, int b, T &out) {\n    if (!same(a, b)) return false;\n    out\
    \ = diff(a, b);\n    return true;\n  }\n\n  bool merge(int a, int b, T x) {\n\
    \    int ra = leader(a);\n    int rb = leader(b);\n    T wa = w[a];\n    T wb\
    \ = w[b];\n    if (ra == rb) return mul(inv(wb), wa) == x;\n    if (sz[ra] < sz[rb])\
    \ {\n      p[ra] = rb;\n      sz[rb] += sz[ra];\n      w[ra] = mul(mul(wb, x),\
    \ inv(wa));\n    } else {\n      p[rb] = ra;\n      sz[ra] += sz[rb];\n      w[rb]\
    \ = mul(mul(wa, inv(x)), inv(wb));\n    }\n    return true;\n  }\n\n  int size(int\
    \ x) { return sz[leader(x)]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, class Op>\nstruct weighted_unionfind {\n  int n;\n  vector<int> p;\n\
    \  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind() : n(0) {}\n  weighted_unionfind(int\
    \ n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n    p.resize(n);\n\
    \    sz.assign(n, 1);\n    w.assign(n, Op::id());\n    iota(p.begin(), p.end(),\
    \ 0);\n  }\n\n  T mul(const T &a, const T &b) { return Op::op(a, b); }\n  T inv(const\
    \ T &a) { return Op::inv(a); }\n\n  int leader(int x) {\n    if (p[x] == x) return\
    \ x;\n    int r = leader(p[x]);\n    w[x] = mul(w[p[x]], w[x]);\n    return p[x]\
    \ = r;\n  }\n\n  T weight(int x) {\n    leader(x);\n    return w[x];\n  }\n\n\
    \  bool same(int a, int b) { return leader(a) == leader(b); }\n\n  T diff(int\
    \ a, int b) { return mul(inv(weight(b)), weight(a)); }\n\n  bool get(int a, int\
    \ b, T &out) {\n    if (!same(a, b)) return false;\n    out = diff(a, b);\n  \
    \  return true;\n  }\n\n  bool merge(int a, int b, T x) {\n    int ra = leader(a);\n\
    \    int rb = leader(b);\n    T wa = w[a];\n    T wb = w[b];\n    if (ra == rb)\
    \ return mul(inv(wb), wa) == x;\n    if (sz[ra] < sz[rb]) {\n      p[ra] = rb;\n\
    \      sz[rb] += sz[ra];\n      w[ra] = mul(mul(wb, x), inv(wa));\n    } else\
    \ {\n      p[rb] = ra;\n      sz[ra] += sz[rb];\n      w[rb] = mul(mul(wa, inv(x)),\
    \ inv(wb));\n    }\n    return true;\n  }\n\n  int size(int x) { return sz[leader(x)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/weightedunionfind.hpp
  requiredBy: []
  timestamp: '2026-03-11 16:11:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_unionfind_with_potential.test.cpp
  - verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: //structure/weightedunionfind.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union-Find"
---

Definition
重み付き Union-Find は各要素にポテンシャルを持たせ、同一連結成分内での差分を扱える素集合データ構造。要素 u, v と値 x に対して a_u = a_v + x を統合し、既存の情報と矛盾しないか判定できる。連結であれば a_u - a_v を取得できる。

Complexity
各操作はならし O(α(n))。

使い方

- `weighted_unionfind<T, Op> uf(n);` で要素数 n の集合を作る。
- `Op::id()` は単位元、`Op::op(a, b)` は結合、`Op::inv(a)` は逆元を返す。
- `uf.init(n);` で再初期化する。
- `uf.leader(x);` で x の代表元を返す。
- `uf.weight(x);` で x のポテンシャルを返す（代表元からの累積）。
- `uf.same(a, b);` で同一集合か判定する。
- `uf.diff(a, b);` で `a - b` に相当する差分を返す。
- `uf.get(a, b, out);` で同一集合なら差分を out に入れて true を返す。
- `uf.merge(a, b, x);` で `diff(a, b) = x` の制約を追加し、矛盾があれば false。
- `uf.size(x);` で x が属する集合のサイズを返す。
- `uf.mul(a, b)` と `uf.inv(a)` は `Op::op` と `Op::inv` の薄いラッパーで内部用。

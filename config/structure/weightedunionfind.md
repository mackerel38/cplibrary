---
title: 重み付き Union-Find
documentation_of: //structure/weightedunionfind.hpp
---

Definition
重み付き Union-Find は各要素にポテンシャルを持たせ、同一連結成分内での差分を扱える素集合データ構造。要素 u, v と値 x に対して a_u = a_v + x を統合し、既存の情報と矛盾しないか判定できる。連結であれば a_u - a_v を取得できる。

Complexity
各操作はならし O(α(n))。

使い方
`weighted_unionfind<T, Op> uf(n);` で要素数 n の集合を作る。
`Op::id()` は単位元、`Op::op(a, b)` は結合、`Op::inv(a)` は逆元を返す。
`uf.init(n);` で再初期化する。
`uf.leader(x);` で x の代表元を返す。
`uf.weight(x);` で x のポテンシャルを返す（代表元からの累積）。
`uf.same(a, b);` で同一集合か判定する。
`uf.diff(a, b);` で `a - b` に相当する差分を返す。
`uf.get(a, b, out);` で同一集合なら差分を out に入れて true を返す。
`uf.merge(a, b, x);` で `diff(a, b) = x` の制約を追加し、矛盾があれば false。
`uf.size(x);` で x が属する集合のサイズを返す。
`uf.mul(a, b)` と `uf.inv(a)` は `Op::op` と `Op::inv` の薄いラッパーで内部用。

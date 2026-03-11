---
title: 動的遅延セグメント木
documentation_of: //structure/dynamiclazysegtree.hpp
---
Definition
区間更新と区間取得をサポートする動的セグメント木。

Complexity
各操作 O(log N)

概要
巨大な N に対して必要なノードのみ確保する。初期値は `make(len)` で表現し、空ノードの区間長に応じた単位元を返す設計。

ポイント
- 必要なノードだけ確保するので巨大な N でも使える
- 初期値は `make(len)` で区間長に依存した単位元を用意する
- 空ノードのクエリは区間長に応じた値を返す

使い方
- `dynamic_lazysegtree<S, op, e, make, F, mapping, composition, id> seg(n);`
- `seg.apply(l, r, f);` で区間更新
- `seg.prod(l, r);` で区間取得

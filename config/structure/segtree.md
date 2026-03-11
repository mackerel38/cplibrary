---
title: セグメント木
documentation_of: //structure/segtree.hpp
---

Definition
区間に対する結合演算を扱うセグメント木。

Complexity
更新: O(log N)
区間クエリ: O(log N)

概要
モノイドに対して区間クエリと更新を行う。

使い方
`segtree<S, op, e> seg(n);` でサイズ n を作る。
`segtree<S, op, e> seg(v);` で配列 v から構築する。
`seg.init(n);` で再初期化する。
`seg.build(v);` で配列 v から再構築する。
`seg.set(p, x);` で位置 p を x に更新する。
`seg.get(p);` で位置 p の値を取得する。
`seg.prod(l, r);` で [l, r) の積を取得する。
`seg.all_prod();` で全区間の積を取得する。
`seg.max_right(l, f);` は `f(op(a[l],...,a[r-1]))` が true を保つ最大の r を返す。
`seg.min_left(r, f);` は `f(op(a[l],...,a[r-1]))` が true を保つ最小の l を返す。
`f(e())` が true であり、単調性が必要。

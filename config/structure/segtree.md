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
`segtree<S, op, e> seg(n);`
`seg.set(i, x);`
`seg.prod(l, r);`

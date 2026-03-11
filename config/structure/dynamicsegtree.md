---
title: Dynamic Segment Tree
documentation_of: //structure/dynamicsegtree.hpp
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

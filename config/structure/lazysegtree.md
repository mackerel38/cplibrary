---
title: Lazy Segment Tree
documentation_of: //structure/lazysegtree.hpp
---

Definition
遅延伝搬付きセグメント木。区間更新と区間取得を扱う。

Complexity
各操作は O(log N)。

使い方

- `lazysegtree<S, op, e, F, mapping, composition, id> seg(n);` で作成する。
- `seg.init(n);` で再初期化する。
- `seg.build(v);` で配列 v から構築する。
- `seg.set(p, x);` で位置 p の値を x に更新する。
- `seg.get(p);` で位置 p の値を取得する。
- `seg.prod(l, r);` で [l, r) の区間積を取得する。
- `seg.all_prod();` で全区間の積を取得する。
- `seg.apply(p, f);` で位置 p に作用素 f を適用する。
- `seg.apply(l, r, f);` で [l, r) に作用素 f を適用する。
- `mapping(f, x)` は要素 x に作用素 f を適用した結果を返す。
- `composition(f, g)` は作用素 g の後に f を適用した合成を返す。
- `id()` は作用素の単位元。
- `update`, `all_apply`, `push` は内部用の補助関数。

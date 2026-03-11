---
title: 永続セグメント木
documentation_of: //structure/persistentsegtree.hpp
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

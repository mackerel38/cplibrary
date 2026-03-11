---
title: 永続遅延セグメント木
documentation_of: //structure/persistentlazysegtree.hpp
---
Definition
区間更新と区間取得を永続化した遅延セグメント木。

Complexity
更新: O(log N)
取得: O(log N)

ポイント
- 作用素の合成と単位元を用意する
- 更新ごとに新しい版を作成する
- 過去の版は参照専用で保持される
- 版同士の区間コピーに対応できる

使い方
- `persistent_lazysegtree<S, op, e, F, mapping, composition, id> seg(v);`
- `seg.apply(ver, l, r, f);` で新しい版を作成
- `seg.prod(ver, l, r);` で区間取得
- `seg.set(ver, p, x);` で一点更新
- `seg.replace_range(ver_a, ver_b, l, r);` で区間を別の版からコピー

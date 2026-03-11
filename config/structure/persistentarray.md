---
title: 永続配列
documentation_of: //structure/persistentarray.hpp
---
Definition
過去の版を保持しながら一点更新と一点取得を行う配列。

Complexity
更新: O(log N)
取得: O(log N)

概要
更新ごとに新しい版を作り、各版に対して値の取得ができる。

ポイント
- 版ごとに配列の状態を保持できる
- 更新は一点のみで、新しい版が作られる
- 取得は任意の版と位置を指定する

使い方
- `persistent_array<T> a(n, def);` で初期化
- `a.set(ver, idx, x);` で新しい版を作成
- `a.get(ver, idx);` で取得

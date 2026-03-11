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

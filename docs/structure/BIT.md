---
title: Fenwick木
documentation_of: //structure/BIT.hpp
---
Definition
一点加算と区間和を扱うデータ構造。

Complexity
初期化は O(n)、一点更新は O(log n)、区間和は O(log n)。

sum(r) は半開区間 [0, r) の和を返す。
sum(l, r) は半開区間 [l, r) の和を返す。

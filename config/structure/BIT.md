---
title: Binary Indexed Tree
documentation_of: //structure/BIT.hpp
---

Definition
BIT（Binary Indexed Tree）。

Complexity
加算: O(log N)
区間和: O(log N)

概要
1点加算と区間和を扱うデータ構造。
0-indexed で管理し、`sum(l, r)` は [l, r) の和を返す。

使い方
`BIT<long long> fw(n);`
`fw.add(i, x);`
`fw.sum(l, r);`

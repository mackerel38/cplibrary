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

- `BIT<long long> fw(n);` でサイズ n を作る。
- `fw.init(n);` で再初期化する。
- `fw.add(i, x);` で a[i] に x を加算する。
- `fw.sum(r);` で [0, r) の和を返す。
- `fw.sum(l, r);` で [l, r) の和を返す。
- `fw.lower_bound(x);` で prefix sum が x 以上となる最小の index を返す。存在しない場合は n を返す。

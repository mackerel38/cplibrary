---
title: Range Affine Range Sum
documentation_of: //structure/range_affine_range_sum.hpp
---

Definition
区間に一次変換 a_i = b*a_i + c を適用し、区間和を取得する遅延セグメント木。

Complexity
各操作は O(log N)。

使い方

- `range_affine_range_sum<MOD> seg(n);` で長さ n を作る。
- `range_affine_range_sum<MOD> seg(a);` で配列 a から構築する。
- `seg.init(n);` で再初期化する。
- `seg.build(a);` で配列 a から再構築する。
- `seg.set(p, x);` で位置 p を x に更新する。
- `seg.get(p);` で位置 p の値を取得する。
- `seg.prod(l, r);` で [l, r) の区間和を取得する。
- `seg.apply(l, r, b, c);` で [l, r) に一次変換を適用する。
- `MOD` の既定値は 998244353。

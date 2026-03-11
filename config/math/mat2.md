---
title: 2x2 行列
documentation_of: //math/mat2.hpp
---

Definition
2x2 行列を扱う。要素の演算は外部で与える。行列積、単位行列、逆行列を提供する。

Complexity
行列積・逆行列は O(1)。

使い方
`mat2<Ops> m(a00, a01, a10, a11);` で行列を作る。
`mat2<Ops> id = mat2<Ops>::id();` で単位行列を作る。
`mat2<Ops>::op(x, y);` で行列積 x*y を返す。
`mat2<Ops>::inv(x);` で逆行列を返す。
`x == y` で要素ごとの一致を判定する。
`Ops::zero(), Ops::one(), Ops::add, Ops::sub, Ops::mul, Ops::neg, Ops::inv` を定義する。

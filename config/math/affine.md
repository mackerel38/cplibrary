---
title: Affine
documentation_of: //math/affine.hpp
---

Definition
一次関数 f(x)=ax+b を表す。

Complexity
各操作は O(1)。

使い方
`affine<T> f(a, b);` で f(x)=ax+b を作る。
`f.eval(x);` で f(x) を計算する。
`affine_add(f, g);` で f+g を返す。
`affine_compose(f, g);` で f∘g を返す。

---
title: modint
documentation_of: //math/modint.hpp
---

Definition
法 MOD 上の整数型。加減乗、冪、逆元、入出力を提供する。

Complexity
各演算は O(1)、冪と逆元は O(log MOD)。

使い方

- `using mint = modint<MOD>;` で型を定義する。
- `mint x = 5;` のように初期化できる（負数も正規化される）。
- `mint::raw(v);` で正規化なしに値 v を持つ要素を作る。
- `x += y, x -= y, x *= y` で加減乗する。
- `x + y, x - y, x * y` で新しい値を返す。
- `-x` で加法逆元を返す。
- `mint::pow(a, e);` で a^e を計算する。
- `mint::inv(a);` で a の逆元を返す（MOD が素数を仮定）。
- `cin >> x;` と `cout << x;` で入出力できる。

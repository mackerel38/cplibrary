---
title: 乱数生成
documentation_of: //utility/randgen.hpp
---
Definition
`mt19937_64` を用いた乱数生成ユーティリティ。

Complexity
各生成は O(1)

ポイント
- `chrono::steady_clock` 由来の seed で初期化
- 整数・実数・シャッフルをまとめて提供
- 区間は [l, r) を前提

使い方
- `randgen rg;` で生成器を作る
- `rg.u64();` で 64bit 乱数
- `rg.i(l, r);` で int の [l, r) 乱数
- `rg.ll(l, r);` で long long の [l, r) 乱数
- `rg.real(l, r);` で実数の [l, r) 乱数
- `rg.shuffle_vec(v);` で配列をシャッフル

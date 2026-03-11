---
title: Wavelet Matrix
documentation_of: //structure/waveletmatrix.hpp
---
Definition
整数列に対して区間の k 番目に小さい値を求める。

Complexity
構築: O(N log V)
クエリ: O(log V)

ポイント
- 値のビットで階層分割する
- 区間の k 番目を高速に取得できる
- 値域 V に対して対数時間

使い方
- `wavelet_matrix wm(v);` で構築
- `wm.kth(l, r, k);` で [l, r) の k 番目に小さい値を取得

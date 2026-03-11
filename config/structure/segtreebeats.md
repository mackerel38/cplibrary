---
title: セグメント木 Beats
documentation_of: //structure/segtreebeats.hpp
---
Definition
区間 chmin, chmax, add, sum を扱うセグメント木。

Complexity
各操作はならし O(log N)

ポイント
- 区間の最大値・最小値を保持して高速化する
- chmin/chmax/add/sum を同時に扱える
- ならし計算量で高速に動作する

使い方
- `segtreebeats seg(v);` で初期化
- `seg.range_chmin(l, r, x);` で区間 chmin
- `seg.range_chmax(l, r, x);` で区間 chmax
- `seg.range_add(l, r, x);` で区間 add
- `seg.range_sum(l, r);` で区間和

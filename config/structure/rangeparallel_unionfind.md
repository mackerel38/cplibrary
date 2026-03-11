---
title: Range Parallel Union-Find
documentation_of: //structure/rangeparallel_unionfind.hpp
---

Definition
2つの同じ長さの区間に対して、対応する頂点をすべて併合する操作を高速に行う Union-Find。各連結成分の和を保持し、同一成分内のペアの積の総和を更新できる。

Complexity
各操作はならし O(log N α(N))。

使い方
`range_parallel_unionfind<Ops> uf(n);` で作成する。
`uf.init(n);` で再初期化する。
`Ops::T` は値型、`Ops::zero()` は零元、`Ops::add(a, b)` と `Ops::mul(a, b)` を定義する。
`uf.set_values(v);` で各頂点の値配列 v を設定する。
`uf.merge_range(a, b, k);` で区間 [a, a+k) と [b, b+k) を対応する位置ごとに併合する。
`uf.leader(x);` は頂点 x の代表元を返す。
`uf.merge0(a, b);` は単一要素 a と b を併合し、成功時に `uf.cur` と `uf.sum` を更新する。
`uf.cur` は連結成分内のペア積の合計値を保持する。
`uf.sum[r]` は代表元 r の成分和を保持する。
`uf.leader_level(l, x)` と `uf.merge_level(l, a, b)` は長さ `2^l` のブロック（開始位置で識別）に対する内部操作で、通常は `merge_range` を使えばよい。
`uf.unite_block(l, a, b)` は長さ `2^l` のブロック [a, a+2^l) と [b, b+2^l) を対応併合する。

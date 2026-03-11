---
title: Dijkstra
documentation_of: //graph/dijkstra.hpp
---

Definition
非負重みの最短距離を求める。距離と直前の頂点を返す。

Complexity
O((N+M) log N)。

使い方
`dijkstra_result res = dijkstra(g, s);` で始点 s からの最短距離を計算する。
`res.dist[v]` は s から v までの最短距離。到達不可は `1LL << 62`。
`res.prev[v]` は最短路で v の直前頂点。始点は -1。
`restore_path_vertices(s, t, res.prev)` と併用して経路を復元する。
重みは非負である必要がある。

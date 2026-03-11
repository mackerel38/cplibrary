---
title: Restore Shortest Path
documentation_of: //graph/restore_shortestpath.hpp
---

Definition
直前配列から最短経路の頂点列・辺列を復元する。

Complexity
経路長を L として O(L)。

使い方
`restore_path_vertices(s, t, prev)` は s から t までの頂点列を返す。到達不可なら空配列。
`restore_path_edges(s, t, prev)` は s から t までの辺列 `(u, v)` を返す。到達不可なら空配列。
`prev` は `dijkstra` などで得られる直前頂点配列を渡す。

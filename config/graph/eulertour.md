---
title: Euler Tour
documentation_of: //graph/eulertour.hpp
---

Definition
木の Euler Tour により各頂点の入時刻・出時刻、親、深さ、順序配列、Euler 列、深さ列、初出位置を得る。

Complexity
O(n)。

使い方

- `euler_tour et; et.build(g, root);` で木 g（隣接リスト）を根 root から走査する。
- `et.in[v]` は v の入時刻（0..n-1）。
- `et.out[v]` は v の出時刻（0..n）。
- `et.order[t]` は入時刻 t の頂点。
- `et.parent[v]` は親、`et.depth[v]` は深さ。
- `et.euler` は Euler 列（長さ 2n-1）、`et.depth_euler` は対応する深さ列。
- `et.first[v]` は `et.euler` における v の初出位置。
- `et.dfs(g, s);` は内部用の DFS で、通常は `build` から呼ぶ。

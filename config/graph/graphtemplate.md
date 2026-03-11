---
title: Graph Template
documentation_of: //graph/graphtemplate.hpp
---

Definition
有向重み付きグラフの基本構造。隣接リストと辺追加を提供する。

Complexity
辺追加は O(1)。

ポイント
- 隣接リスト形式の有向重み付きグラフ
- 辺追加が軽量
- `graph::edge` に行き先と重みを持つ

使い方

- `graph g(n);` で頂点数 n のグラフを作る。
- `g.init(n);` で再初期化する。
- `g.add_edge(a, b, w);` で a -> b の重み w 辺を追加する。
- `g[i]` で頂点 i の隣接辺列 `vector<graph::edge>` を参照できる。
- `graph::edge` は `to` と `w` を持つ。

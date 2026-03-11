---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_shortest_path.test.cpp
    title: verify/yosupo_shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct graph {\n  struct edge {\n    int to;\n    long long\
    \ w;\n  };\n\n  int n;\n  vector<vector<edge>> g;\n\n  graph() : n(0) {}\n  graph(int\
    \ n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n    g.assign(n, {});\n\
    \  }\n\n  void add_edge(int a, int b, long long w) { g[a].push_back({b, w}); }\n\
    \n  vector<edge>& operator[](int i) { return g[i]; }\n  const vector<edge>& operator[](int\
    \ i) const { return g[i]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct graph\
    \ {\n  struct edge {\n    int to;\n    long long w;\n  };\n\n  int n;\n  vector<vector<edge>>\
    \ g;\n\n  graph() : n(0) {}\n  graph(int n_) { init(n_); }\n\n  void init(int\
    \ n_) {\n    n = n_;\n    g.assign(n, {});\n  }\n\n  void add_edge(int a, int\
    \ b, long long w) { g[a].push_back({b, w}); }\n\n  vector<edge>& operator[](int\
    \ i) { return g[i]; }\n  const vector<edge>& operator[](int i) const { return\
    \ g[i]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphtemplate.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2026-03-11 17:01:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_shortest_path.test.cpp
documentation_of: //graph/graphtemplate.hpp
layout: document
title: Graph Template
---

Definition
有向重み付きグラフの基本構造。隣接リストと辺追加を提供する。

Complexity
辺追加は O(1)。

使い方
`graph g(n);` で頂点数 n のグラフを作る。
`g.init(n);` で再初期化する。
`g.add_edge(a, b, w);` で a -> b の重み w 辺を追加する。
`g[i]` で頂点 i の隣接辺列 `vector<graph::edge>` を参照できる。
`graph::edge` は `to` と `w` を持つ。

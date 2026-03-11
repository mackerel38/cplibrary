---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_shortest_path.test.cpp
    title: verify/yosupo_shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"graph/graphtemplate.hpp\"\nusing namespace std;\n\nstruct\
    \ graph {\n  struct edge {\n    int to;\n    long long w;\n  };\n\n  int n;\n\
    \  vector<vector<edge>> g;\n\n  graph() : n(0) {}\n  graph(int n_) { init(n_);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    g.assign(n, {});\n  }\n\n  void\
    \ add_edge(int a, int b, long long w) { g[a].push_back({b, w}); }\n\n  vector<edge>&\
    \ operator[](int i) { return g[i]; }\n  const vector<edge>& operator[](int i)\
    \ const { return g[i]; }\n};\n#line 6 \"graph/dijkstra.hpp\"\n\nstruct dijkstra_result\
    \ {\n  vector<long long> dist;\n  vector<int> prev;\n};\n\ninline dijkstra_result\
    \ dijkstra(const graph& g, int s) {\n  const long long INF = (1LL << 62);\n  dijkstra_result\
    \ res;\n  res.dist.assign(g.n, INF);\n  res.prev.assign(g.n, -1);\n  priority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>,\n                 greater<pair<long\
    \ long, int>>>\n      pq;\n  res.dist[s] = 0;\n  pq.push({0, s});\n  while (!pq.empty())\
    \ {\n    auto [d, v] = pq.top();\n    pq.pop();\n    if (d != res.dist[v]) continue;\n\
    \    for (auto& e : g[v]) {\n      long long nd = d + e.w;\n      if (nd < res.dist[e.to])\
    \ {\n        res.dist[e.to] = nd;\n        res.prev[e.to] = v;\n        pq.push({nd,\
    \ e.to});\n      }\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"graph/graphtemplate.hpp\"\n\nstruct dijkstra_result {\n  vector<long long>\
    \ dist;\n  vector<int> prev;\n};\n\ninline dijkstra_result dijkstra(const graph&\
    \ g, int s) {\n  const long long INF = (1LL << 62);\n  dijkstra_result res;\n\
    \  res.dist.assign(g.n, INF);\n  res.prev.assign(g.n, -1);\n  priority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>,\n                 greater<pair<long\
    \ long, int>>>\n      pq;\n  res.dist[s] = 0;\n  pq.push({0, s});\n  while (!pq.empty())\
    \ {\n    auto [d, v] = pq.top();\n    pq.pop();\n    if (d != res.dist[v]) continue;\n\
    \    for (auto& e : g[v]) {\n      long long nd = d + e.w;\n      if (nd < res.dist[e.to])\
    \ {\n        res.dist[e.to] = nd;\n        res.prev[e.to] = v;\n        pq.push({nd,\
    \ e.to});\n      }\n    }\n  }\n  return res;\n}\n"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2026-03-11 17:02:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_shortest_path.test.cpp
documentation_of: //graph/dijkstra.hpp
layout: document
title: Dijkstra
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

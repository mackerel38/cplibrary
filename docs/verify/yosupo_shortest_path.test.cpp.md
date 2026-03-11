---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: graph/restore_shortestpath.hpp
    title: Restore Shortest Path
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/yosupo_shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"graph/dijkstra.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"graph/graphtemplate.hpp\"\
    \nusing namespace std;\n\nstruct graph {\n  struct edge {\n    int to;\n    long\
    \ long w;\n  };\n\n  int n;\n  vector<vector<edge>> g;\n\n  graph() : n(0) {}\n\
    \  graph(int n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n    g.assign(n,\
    \ {});\n  }\n\n  void add_edge(int a, int b, long long w) { g[a].push_back({b,\
    \ w}); }\n\n  vector<edge>& operator[](int i) { return g[i]; }\n  const vector<edge>&\
    \ operator[](int i) const { return g[i]; }\n};\n#line 6 \"graph/dijkstra.hpp\"\
    \n\nstruct dijkstra_result {\n  vector<long long> dist;\n  vector<int> prev;\n\
    };\n\ninline dijkstra_result dijkstra(const graph& g, int s) {\n  const long long\
    \ INF = (1LL << 62);\n  dijkstra_result res;\n  res.dist.assign(g.n, INF);\n \
    \ res.prev.assign(g.n, -1);\n  priority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>,\n                 greater<pair<long long, int>>>\n      pq;\n \
    \ res.dist[s] = 0;\n  pq.push({0, s});\n  while (!pq.empty()) {\n    auto [d,\
    \ v] = pq.top();\n    pq.pop();\n    if (d != res.dist[v]) continue;\n    for\
    \ (auto& e : g[v]) {\n      long long nd = d + e.w;\n      if (nd < res.dist[e.to])\
    \ {\n        res.dist[e.to] = nd;\n        res.prev[e.to] = v;\n        pq.push({nd,\
    \ e.to});\n      }\n    }\n  }\n  return res;\n}\n#line 3 \"graph/restore_shortestpath.hpp\"\
    \nusing namespace std;\n\ninline vector<int> restore_path_vertices(int s, int\
    \ t, const vector<int>& prev) {\n  vector<int> vs;\n  if (t < 0) return vs;\n\
    \  int v = t;\n  while (v != -1) {\n    vs.push_back(v);\n    if (v == s) break;\n\
    \    v = prev[v];\n  }\n  if (vs.back() != s) return {};\n  reverse(vs.begin(),\
    \ vs.end());\n  return vs;\n}\n\ninline vector<pair<int, int>> restore_path_edges(int\
    \ s, int t,\n                                                 const vector<int>&\
    \ prev) {\n  vector<int> vs = restore_path_vertices(s, t, prev);\n  vector<pair<int,\
    \ int>> es;\n  if (vs.empty()) return es;\n  for (int i = 1; i < (int)vs.size();\
    \ i++) {\n    es.push_back({vs[i - 1], vs[i]});\n  }\n  return es;\n}\n#line 4\
    \ \"verify/yosupo_shortest_path.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, M, s, t;\n  cin >> N >> M >> s >> t;\n  graph g(N);\n\
    \  for (int i = 0; i < M; i++) {\n    int a, b;\n    long long c;\n    cin >>\
    \ a >> b >> c;\n    g.add_edge(a, b, c);\n  }\n  auto res = dijkstra(g, s);\n\
    \  if (res.dist[t] >= (1LL << 61)) {\n    cout << -1 << \"\\n\";\n    return 0;\n\
    \  }\n  auto es = restore_path_edges(s, t, res.prev);\n  cout << res.dist[t] <<\
    \ \" \" << (int)es.size() << \"\\n\";\n  for (auto& e : es) {\n    cout << e.first\
    \ << \" \" << e.second << \"\\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"graph/dijkstra.hpp\"\n#include \"graph/restore_shortestpath.hpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int N, M, s, t;\n\
    \  cin >> N >> M >> s >> t;\n  graph g(N);\n  for (int i = 0; i < M; i++) {\n\
    \    int a, b;\n    long long c;\n    cin >> a >> b >> c;\n    g.add_edge(a, b,\
    \ c);\n  }\n  auto res = dijkstra(g, s);\n  if (res.dist[t] >= (1LL << 61)) {\n\
    \    cout << -1 << \"\\n\";\n    return 0;\n  }\n  auto es = restore_path_edges(s,\
    \ t, res.prev);\n  cout << res.dist[t] << \" \" << (int)es.size() << \"\\n\";\n\
    \  for (auto& e : es) {\n    cout << e.first << \" \" << e.second << \"\\n\";\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/graphtemplate.hpp
  - graph/restore_shortestpath.hpp
  isVerificationFile: true
  path: verify/yosupo_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 17:02:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_shortest_path.test.cpp
- /verify/verify/yosupo_shortest_path.test.cpp.html
title: verify/yosupo_shortest_path.test.cpp
---

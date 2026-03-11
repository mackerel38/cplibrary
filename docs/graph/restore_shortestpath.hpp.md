---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"graph/restore_shortestpath.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ninline vector<int> restore_path_vertices(int s, int t,\
    \ const vector<int>& prev) {\n  vector<int> vs;\n  if (t < 0) return vs;\n  int\
    \ v = t;\n  while (v != -1) {\n    vs.push_back(v);\n    if (v == s) break;\n\
    \    v = prev[v];\n  }\n  if (vs.back() != s) return {};\n  reverse(vs.begin(),\
    \ vs.end());\n  return vs;\n}\n\ninline vector<pair<int, int>> restore_path_edges(int\
    \ s, int t,\n                                                 const vector<int>&\
    \ prev) {\n  vector<int> vs = restore_path_vertices(s, t, prev);\n  vector<pair<int,\
    \ int>> es;\n  if (vs.empty()) return es;\n  for (int i = 1; i < (int)vs.size();\
    \ i++) {\n    es.push_back({vs[i - 1], vs[i]});\n  }\n  return es;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ninline vector<int>\
    \ restore_path_vertices(int s, int t, const vector<int>& prev) {\n  vector<int>\
    \ vs;\n  if (t < 0) return vs;\n  int v = t;\n  while (v != -1) {\n    vs.push_back(v);\n\
    \    if (v == s) break;\n    v = prev[v];\n  }\n  if (vs.back() != s) return {};\n\
    \  reverse(vs.begin(), vs.end());\n  return vs;\n}\n\ninline vector<pair<int,\
    \ int>> restore_path_edges(int s, int t,\n                                   \
    \              const vector<int>& prev) {\n  vector<int> vs = restore_path_vertices(s,\
    \ t, prev);\n  vector<pair<int, int>> es;\n  if (vs.empty()) return es;\n  for\
    \ (int i = 1; i < (int)vs.size(); i++) {\n    es.push_back({vs[i - 1], vs[i]});\n\
    \  }\n  return es;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_shortestpath.hpp
  requiredBy: []
  timestamp: '2026-03-11 17:02:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_shortest_path.test.cpp
documentation_of: //graph/restore_shortestpath.hpp
layout: document
title: Restore Shortest Path
---

Definition
直前配列から最短経路の頂点列・辺列を復元する。

Complexity
経路長を L として O(L)。

使い方

- `restore_path_vertices(s, t, prev)` は s から t までの頂点列を返す。到達不可なら空配列。
- `restore_path_edges(s, t, prev)` は s から t までの辺列 `(u, v)` を返す。到達不可なら空配列。
- `prev` は `dijkstra` などで得られる直前頂点配列を渡す。

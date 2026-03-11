---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/eulertour.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct euler_tour {\n  int n;\n  int root;\n  int timer;\n  vector<int>\
    \ in, out, order, parent, depth;\n  vector<int> euler, depth_euler, first;\n\n\
    \  euler_tour() : n(0), root(0), timer(0) {}\n\n  void build(const vector<vector<int>>&\
    \ g, int r = 0) {\n    n = (int)g.size();\n    root = r;\n    timer = 0;\n   \
    \ in.assign(n, -1);\n    out.assign(n, -1);\n    parent.assign(n, -1);\n    depth.assign(n,\
    \ 0);\n    order.resize(n);\n    euler.clear();\n    depth_euler.clear();\n  \
    \  first.assign(n, -1);\n    euler.reserve(2 * n - 1);\n    depth_euler.reserve(2\
    \ * n - 1);\n    dfs(g, root);\n  }\n\n  void dfs(const vector<vector<int>>& g,\
    \ int s) {\n    struct frame {\n      int v;\n      int p;\n      int idx;\n \
    \   };\n    vector<frame> st;\n    st.push_back({s, -1, 0});\n    parent[s] =\
    \ -1;\n    depth[s] = 0;\n    in[s] = timer;\n    order[timer] = s;\n    timer++;\n\
    \    euler.push_back(s);\n    depth_euler.push_back(0);\n    first[s] = 0;\n \
    \   while (!st.empty()) {\n      auto& fr = st.back();\n      int v = fr.v;\n\
    \      if (fr.idx == (int)g[v].size()) {\n        out[v] = timer;\n        st.pop_back();\n\
    \        if (!st.empty()) {\n          int p = st.back().v;\n          euler.push_back(p);\n\
    \          depth_euler.push_back(depth[p]);\n        }\n        continue;\n  \
    \    }\n      int to = g[v][fr.idx];\n      fr.idx++;\n      if (to == fr.p) continue;\n\
    \      parent[to] = v;\n      depth[to] = depth[v] + 1;\n      in[to] = timer;\n\
    \      order[timer] = to;\n      timer++;\n      st.push_back({to, v, 0});\n \
    \     euler.push_back(to);\n      depth_euler.push_back(depth[to]);\n      if\
    \ (first[to] == -1) first[to] = (int)euler.size() - 1;\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct euler_tour\
    \ {\n  int n;\n  int root;\n  int timer;\n  vector<int> in, out, order, parent,\
    \ depth;\n  vector<int> euler, depth_euler, first;\n\n  euler_tour() : n(0), root(0),\
    \ timer(0) {}\n\n  void build(const vector<vector<int>>& g, int r = 0) {\n   \
    \ n = (int)g.size();\n    root = r;\n    timer = 0;\n    in.assign(n, -1);\n \
    \   out.assign(n, -1);\n    parent.assign(n, -1);\n    depth.assign(n, 0);\n \
    \   order.resize(n);\n    euler.clear();\n    depth_euler.clear();\n    first.assign(n,\
    \ -1);\n    euler.reserve(2 * n - 1);\n    depth_euler.reserve(2 * n - 1);\n \
    \   dfs(g, root);\n  }\n\n  void dfs(const vector<vector<int>>& g, int s) {\n\
    \    struct frame {\n      int v;\n      int p;\n      int idx;\n    };\n    vector<frame>\
    \ st;\n    st.push_back({s, -1, 0});\n    parent[s] = -1;\n    depth[s] = 0;\n\
    \    in[s] = timer;\n    order[timer] = s;\n    timer++;\n    euler.push_back(s);\n\
    \    depth_euler.push_back(0);\n    first[s] = 0;\n    while (!st.empty()) {\n\
    \      auto& fr = st.back();\n      int v = fr.v;\n      if (fr.idx == (int)g[v].size())\
    \ {\n        out[v] = timer;\n        st.pop_back();\n        if (!st.empty())\
    \ {\n          int p = st.back().v;\n          euler.push_back(p);\n         \
    \ depth_euler.push_back(depth[p]);\n        }\n        continue;\n      }\n  \
    \    int to = g[v][fr.idx];\n      fr.idx++;\n      if (to == fr.p) continue;\n\
    \      parent[to] = v;\n      depth[to] = depth[v] + 1;\n      in[to] = timer;\n\
    \      order[timer] = to;\n      timer++;\n      st.push_back({to, v, 0});\n \
    \     euler.push_back(to);\n      depth_euler.push_back(depth[to]);\n      if\
    \ (first[to] == -1) first[to] = (int)euler.size() - 1;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulertour.hpp
  requiredBy: []
  timestamp: '2026-03-11 17:16:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: //graph/eulertour.hpp
layout: document
title: Euler Tour
---

Definition
木の Euler Tour により各頂点の入時刻・出時刻、親、深さ、順序配列、Euler 列、深さ列、初出位置を得る。

Complexity
O(n)。

使い方
`euler_tour et; et.build(g, root);` で木 g（隣接リスト）を根 root から走査する。
`et.in[v]` は v の入時刻（0..n-1）。
`et.out[v]` は v の出時刻（0..n）。
`et.order[t]` は入時刻 t の頂点。
`et.parent[v]` は親、`et.depth[v]` は深さ。
`et.euler` は Euler 列（長さ 2n-1）、`et.depth_euler` は対応する深さ列。
`et.first[v]` は `et.euler` における v の初出位置。
`et.dfs(g, s);` は内部用の DFS で、通常は `build` から呼ぶ。

#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "graph/graphtemplate.hpp"

struct dijkstra_result {
  vector<long long> dist;
  vector<int> prev;
};

inline dijkstra_result dijkstra(const graph& g, int s) {
  const long long INF = (1LL << 62);
  dijkstra_result res;
  res.dist.assign(g.n, INF);
  res.prev.assign(g.n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  res.dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (d != res.dist[v]) continue;
    for (auto& e : g[v]) {
      long long nd = d + e.w;
      if (nd < res.dist[e.to]) {
        res.dist[e.to] = nd;
        res.prev[e.to] = v;
        pq.push({nd, e.to});
      }
    }
  }
  return res;
}

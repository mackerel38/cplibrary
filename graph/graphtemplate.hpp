#pragma once
#include <bits/stdc++.h>
using namespace std;

struct graph {
  struct edge {
    int to;
    long long w;
  };

  int n;
  vector<vector<edge>> g;

  graph() : n(0) {}
  graph(int n_) { init(n_); }

  void init(int n_) {
    n = n_;
    g.assign(n, {});
  }

  void add_edge(int a, int b, long long w) { g[a].push_back({b, w}); }

  vector<edge>& operator[](int i) { return g[i]; }
  const vector<edge>& operator[](int i) const { return g[i]; }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

inline vector<int> restore_path_vertices(int s, int t, const vector<int>& prev) {
  vector<int> vs;
  if (t < 0) return vs;
  int v = t;
  while (v != -1) {
    vs.push_back(v);
    if (v == s) break;
    v = prev[v];
  }
  if (vs.back() != s) return {};
  reverse(vs.begin(), vs.end());
  return vs;
}

inline vector<pair<int, int>> restore_path_edges(int s, int t,
                                                 const vector<int>& prev) {
  vector<int> vs = restore_path_vertices(s, t, prev);
  vector<pair<int, int>> es;
  if (vs.empty()) return es;
  for (int i = 1; i < (int)vs.size(); i++) {
    es.push_back({vs[i - 1], vs[i]});
  }
  return es;
}

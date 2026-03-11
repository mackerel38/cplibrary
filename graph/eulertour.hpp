#pragma once
#include <bits/stdc++.h>
using namespace std;

struct euler_tour {
  int n;
  int root;
  int timer;
  vector<int> in, out, order, parent, depth;
  vector<int> euler, depth_euler, first;

  euler_tour() : n(0), root(0), timer(0) {}

  void build(const vector<vector<int>>& g, int r = 0) {
    n = (int)g.size();
    root = r;
    timer = 0;
    in.assign(n, -1);
    out.assign(n, -1);
    parent.assign(n, -1);
    depth.assign(n, 0);
    order.resize(n);
    euler.clear();
    depth_euler.clear();
    first.assign(n, -1);
    euler.reserve(2 * n - 1);
    depth_euler.reserve(2 * n - 1);
    dfs(g, root);
  }

  void dfs(const vector<vector<int>>& g, int s) {
    struct frame {
      int v;
      int p;
      int idx;
    };
    vector<frame> st;
    st.push_back({s, -1, 0});
    parent[s] = -1;
    depth[s] = 0;
    in[s] = timer;
    order[timer] = s;
    timer++;
    euler.push_back(s);
    depth_euler.push_back(0);
    first[s] = 0;
    while (!st.empty()) {
      auto& fr = st.back();
      int v = fr.v;
      if (fr.idx == (int)g[v].size()) {
        out[v] = timer;
        st.pop_back();
        if (!st.empty()) {
          int p = st.back().v;
          euler.push_back(p);
          depth_euler.push_back(depth[p]);
        }
        continue;
      }
      int to = g[v][fr.idx];
      fr.idx++;
      if (to == fr.p) continue;
      parent[to] = v;
      depth[to] = depth[v] + 1;
      in[to] = timer;
      order[timer] = to;
      timer++;
      st.push_back({to, v, 0});
      euler.push_back(to);
      depth_euler.push_back(depth[to]);
      if (first[to] == -1) first[to] = (int)euler.size() - 1;
    }
  }
};

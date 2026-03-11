#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "graph/cartesiantree.hpp"
#include "graph/eulertour.hpp"

template <class T, class Cmp = less<T>>
struct sparse_table {
  int n;
  vector<T> a;
  cartesian_tree<T, Cmp> ct;
  vector<int> first;
  vector<int> euler;
  vector<int> depth;
  int B;
  vector<int> block_min;
  vector<vector<int>> block_tbl;
  vector<vector<int>> st;

  sparse_table() : n(0), B(16) {}
  sparse_table(const vector<T>& v, Cmp cmp = Cmp()) : n(0), B(16) {
    build(v, cmp);
  }

  void build(const vector<T>& v, Cmp cmp = Cmp()) {
    a = v;
    n = (int)a.size();
    if (B <= 0) B = 16;
    ct.build(a, cmp);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      int p = ct.parent[i];
      if (p != -1) {
        g[p].push_back(i);
        g[i].push_back(p);
      }
    }
    euler_tour et;
    et.build(g, ct.root);
    first = et.first;
    euler = et.euler;
    depth = et.depth_euler;
    build_blocks();
  }

  void build_blocks() {
    int m = (int)euler.size();
    int nb = (m + B - 1) / B;
    block_min.assign(nb, -1);
    block_tbl.assign(nb, vector<int>(B * B, 0));
    for (int b = 0; b < nb; b++) {
      int l = b * B;
      int r = min(m, l + B);
      int len = r - l;
      for (int i = 0; i < len; i++) {
        int best = l + i;
        for (int j = i; j < len; j++) {
          int idx = l + j;
          if (depth[idx] < depth[best]) best = idx;
          block_tbl[b][i * B + j] = best;
        }
      }
      for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
          if (i > j || i >= len || j >= len) block_tbl[b][i * B + j] = l;
        }
      }
      int minpos = l;
      for (int i = l; i < r; i++) {
        if (depth[i] < depth[minpos]) minpos = i;
      }
      block_min[b] = minpos;
    }
    int lg = 1;
    while ((1 << lg) <= nb) lg++;
    st.assign(lg, vector<int>(nb, -1));
    for (int i = 0; i < nb; i++) st[0][i] = block_min[i];
    for (int k = 1; k < lg; k++) {
      int len = 1 << k;
      int half = len >> 1;
      for (int i = 0; i + len <= nb; i++) {
        int aidx = st[k - 1][i];
        int bidx = st[k - 1][i + half];
        st[k][i] = depth[aidx] < depth[bidx] ? aidx : bidx;
      }
    }
  }

  int rmq_idx(int l, int r) const {
    if (l > r) swap(l, r);
    int bl = l / B;
    int br = r / B;
    if (bl == br) {
      int ll = l % B;
      int rr = r % B;
      return block_tbl[bl][ll * B + rr];
    }
    int left_idx = block_tbl[bl][(l % B) * B + (B - 1)];
    int right_idx = block_tbl[br][0 * B + (r % B)];
    int best = depth[left_idx] < depth[right_idx] ? left_idx : right_idx;
    if (bl + 1 <= br - 1) {
      int L = bl + 1;
      int R = br - 1;
      int len = R - L + 1;
      int k = 31 - __builtin_clz(len);
      int aidx = st[k][L];
      int bidx = st[k][R - (1 << k) + 1];
      int mid = depth[aidx] < depth[bidx] ? aidx : bidx;
      best = depth[best] < depth[mid] ? best : mid;
    }
    return best;
  }

  int argmin(int l, int r) const {
    int u = l;
    int v = r - 1;
    int fu = first[u];
    int fv = first[v];
    int idx = rmq_idx(fu, fv);
    return euler[idx];
  }

  T query(int l, int r) const { return a[argmin(l, r)]; }
};

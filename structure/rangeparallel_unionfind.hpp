#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class Ops>
struct range_parallel_unionfind {
  using T = typename Ops::T;
  int n, lg;
  vector<int> p0, sz0;
  vector<T> sum;
  T cur;
  vector<vector<int>> p, sz;

  range_parallel_unionfind() : n(0), lg(0), cur(Ops::zero()) {}
  range_parallel_unionfind(int n_) { init(n_); }

  void init(int n_) {
    n = n_;
    lg = 1;
    while ((1 << lg) <= n) lg++;
    p0.resize(n);
    sz0.assign(n, 1);
    iota(p0.begin(), p0.end(), 0);
    sum.assign(n, Ops::zero());
    cur = Ops::zero();
    p.assign(lg, {});
    sz.assign(lg, {});
    for (int l = 1; l < lg; l++) {
      int cnt = n - (1 << l) + 1;
      p[l].resize(cnt);
      sz[l].assign(cnt, 1);
      iota(p[l].begin(), p[l].end(), 0);
    }
  }

  void set_values(const vector<T>& v) {
    sum = v;
    cur = Ops::zero();
  }

  int leader(int x) {
    if (p0[x] == x) return x;
    return p0[x] = leader(p0[x]);
  }

  bool merge0(int a, int b) {
    a = leader(a);
    b = leader(b);
    if (a == b) return false;
    if (sz0[a] < sz0[b]) swap(a, b);
    p0[b] = a;
    sz0[a] += sz0[b];
    cur = Ops::add(cur, Ops::mul(sum[a], sum[b]));
    sum[a] = Ops::add(sum[a], sum[b]);
    return true;
  }

  int leader_level(int l, int x) {
    if (p[l][x] == x) return x;
    return p[l][x] = leader_level(l, p[l][x]);
  }

  bool merge_level(int l, int a, int b) {
    a = leader_level(l, a);
    b = leader_level(l, b);
    if (a == b) return false;
    if (sz[l][a] < sz[l][b]) swap(a, b);
    p[l][b] = a;
    sz[l][a] += sz[l][b];
    return true;
  }

  void unite_block(int l, int a, int b) {
    if (a == b) return;
    if (l == 0) {
      merge0(a, b);
      return;
    }
    if (!merge_level(l, a, b)) return;
    int half = 1 << (l - 1);
    unite_block(l - 1, a, b);
    unite_block(l - 1, a + half, b + half);
  }

  void merge_range(int a, int b, int k) {
    for (int l = 0; k > 0; l++) {
      if (k & 1) {
        unite_block(l, a, b);
        a += 1 << l;
        b += 1 << l;
      }
      k >>= 1;
    }
  }
};

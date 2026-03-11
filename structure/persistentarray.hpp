#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct persistent_array {
  struct node {
    T val;
    int l;
    int r;
  };

  long long n;
  T def;
  vector<node> nd;
  vector<int> root;

  persistent_array() : n(0), def(T()) {}
  persistent_array(long long n_, T def_ = T()) { init(n_, def_); }
  persistent_array(const vector<T>& v, T def_ = T()) { build(v, def_); }

  void init(long long n_, T def_ = T()) {
    n = n_;
    def = def_;
    nd.clear();
    root.clear();
    root.push_back(-1);
  }

  void build(const vector<T>& v, T def_ = T()) {
    init((long long)v.size(), def_);
    for (long long i = 0; i < (long long)v.size(); i++) set(0, i, v[i]);
  }

  int set(int ver, long long p, T x) {
    int nr = set(root[ver], 0, n, p, x);
    root.push_back(nr);
    return (int)root.size() - 1;
  }

  T get(int ver, long long p) { return get(root[ver], 0, n, p); }

  int new_node(T val, int l, int r) {
    nd.push_back({val, l, r});
    return (int)nd.size() - 1;
  }

  int set(int v, long long l, long long r, long long p, T x) {
    if (r - l == 1) return new_node(x, -1, -1);
    long long m = (l + r) >> 1;
    int nl = -1, nr = -1;
    if (v != -1) {
      nl = nd[v].l;
      nr = nd[v].r;
    }
    if (p < m) {
      nl = set(nl, l, m, p, x);
    } else {
      nr = set(nr, m, r, p, x);
    }
    return new_node(def, nl, nr);
  }

  T get(int v, long long l, long long r, long long p) {
    if (v == -1) return def;
    if (r - l == 1) return nd[v].val;
    long long m = (l + r) >> 1;
    if (p < m) return get(nd[v].l, l, m, p);
    return get(nd[v].r, m, r, p);
  }
};

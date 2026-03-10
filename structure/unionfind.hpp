#pragma once
#include <bits/stdc++.h>
using namespace std;

struct unionfind {
  int n;
  vector<int> p;
  vector<int> sz;

  unionfind() : n(0) {}
  unionfind(int n_) { init(n_); }

  void init(int n_) {
    n = n_;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int leader(int x) {
    if (p[x] == x) return x;
    return p[x] = leader(p[x]);
  }

  bool same(int a, int b) { return leader(a) == leader(b); }

  bool merge(int a, int b) {
    a = leader(a);
    b = leader(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }

  int size(int x) { return sz[leader(x)]; }
};

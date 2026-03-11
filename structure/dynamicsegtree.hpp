#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct dynamic_segtree {
  struct node {
    S val;
    int l;
    int r;
  };

  long long n;
  vector<node> nd;
  int root;

  dynamic_segtree() : n(0), root(-1) {}
  dynamic_segtree(long long n_) { init(n_); }

  void init(long long n_) {
    n = n_;
    nd.clear();
    root = -1;
  }

  int new_node() {
    nd.push_back({e(), -1, -1});
    return (int)nd.size() - 1;
  }

  void set(long long p, S x) { root = set(root, 0, n, p, x); }

  S get(long long p) { return prod(p, p + 1); }

  S prod(long long l, long long r) { return prod(root, 0, n, l, r); }

  S all_prod() { return root == -1 ? e() : nd[root].val; }

  int set(int v, long long l, long long r, long long p, S x) {
    if (v == -1) v = new_node();
    if (r - l == 1) {
      nd[v].val = x;
      return v;
    }
    long long m = (l + r) >> 1;
    if (p < m) {
      nd[v].l = set(nd[v].l, l, m, p, x);
    } else {
      nd[v].r = set(nd[v].r, m, r, p, x);
    }
    S lv = nd[v].l == -1 ? e() : nd[nd[v].l].val;
    S rv = nd[v].r == -1 ? e() : nd[nd[v].r].val;
    nd[v].val = op(lv, rv);
    return v;
  }

  S prod(int v, long long l, long long r, long long ql, long long qr) {
    if (v == -1 || qr <= l || r <= ql) return e();
    if (ql <= l && r <= qr) return nd[v].val;
    long long m = (l + r) >> 1;
    S lv = prod(nd[v].l, l, m, ql, qr);
    S rv = prod(nd[v].r, m, r, ql, qr);
    return op(lv, rv);
  }
};

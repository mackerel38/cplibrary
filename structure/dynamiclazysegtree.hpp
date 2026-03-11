#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)(), S (*make)(long long), class F,
          S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct dynamic_lazysegtree {
  struct node {
    S val;
    F lz;
    int l;
    int r;
    bool has;
  };

  long long n;
  vector<node> nd;
  int root;

  dynamic_lazysegtree() : n(0), root(-1) {}
  dynamic_lazysegtree(long long n_) { init(n_); }

  void init(long long n_) {
    n = n_;
    nd.clear();
    root = -1;
  }

  int new_node(long long len) {
    nd.push_back({make(len), id(), -1, -1, false});
    return (int)nd.size() - 1;
  }

  void set(long long p, S x) { root = set(root, 0, n, p, x); }

  S get(long long p) { return prod(p, p + 1); }

  S prod(long long l, long long r) { return prod(root, 0, n, l, r); }

  S all_prod() { return root == -1 ? make(n) : nd[root].val; }

  void apply(long long l, long long r, F f) {
    root = apply(root, 0, n, l, r, f);
  }

  int set(int v, long long l, long long r, long long p, S x) {
    if (v == -1) v = new_node(r - l);
    if (r - l == 1) {
      nd[v].val = x;
      nd[v].lz = id();
      nd[v].has = false;
      return v;
    }
    push(v, l, r);
    long long m = (l + r) >> 1;
    if (p < m) {
      nd[v].l = set(nd[v].l, l, m, p, x);
    } else {
      nd[v].r = set(nd[v].r, m, r, p, x);
    }
    pull(v, l, r);
    return v;
  }

  int apply(int v, long long l, long long r, long long ql, long long qr, F f) {
    if (qr <= l || r <= ql) return v;
    if (v == -1) v = new_node(r - l);
    if (ql <= l && r <= qr) {
      all_apply(v, f);
      return v;
    }
    push(v, l, r);
    long long m = (l + r) >> 1;
    nd[v].l = apply(nd[v].l, l, m, ql, qr, f);
    nd[v].r = apply(nd[v].r, m, r, ql, qr, f);
    pull(v, l, r);
    return v;
  }

  S prod(int v, long long l, long long r, long long ql, long long qr) {
    if (qr <= l || r <= ql) return e();
    if (v == -1) {
      long long len = min(r, qr) - max(l, ql);
      if (len <= 0) return e();
      return make(len);
    }
    if (ql <= l && r <= qr) return nd[v].val;
    push(v, l, r);
    long long m = (l + r) >> 1;
    S lv = prod(nd[v].l, l, m, ql, qr);
    S rv = prod(nd[v].r, m, r, ql, qr);
    return op(lv, rv);
  }

  void all_apply(int v, F f) {
    nd[v].val = mapping(f, nd[v].val);
    if (nd[v].has) {
      nd[v].lz = composition(f, nd[v].lz);
    } else {
      nd[v].lz = f;
      nd[v].has = true;
    }
  }

  void push(int v, long long l, long long r) {
    if (!nd[v].has || r - l == 1) return;
    long long m = (l + r) >> 1;
    if (nd[v].l == -1) nd[v].l = new_node(m - l);
    if (nd[v].r == -1) nd[v].r = new_node(r - m);
    all_apply(nd[v].l, nd[v].lz);
    all_apply(nd[v].r, nd[v].lz);
    nd[v].lz = id();
    nd[v].has = false;
  }

  void pull(int v, long long l, long long r) {
    long long m = (l + r) >> 1;
    S lv = nd[v].l == -1 ? make(m - l) : nd[nd[v].l].val;
    S rv = nd[v].r == -1 ? make(r - m) : nd[nd[v].r].val;
    nd[v].val = op(lv, rv);
  }
};

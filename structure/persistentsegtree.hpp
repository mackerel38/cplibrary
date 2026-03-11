#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct persistent_segtree {
  struct node {
    S val;
    int l;
    int r;
  };

  int n;
  vector<node> nd;
  vector<int> root;

  persistent_segtree() : n(0) {}
  persistent_segtree(int n_) { init(n_); }
  persistent_segtree(const vector<S>& v) { build(v); }

  void init(int n_) {
    n = n_;
    nd.clear();
    root.clear();
    root.push_back(build_empty(0, n));
  }

  void build(const vector<S>& v) {
    n = (int)v.size();
    nd.clear();
    root.clear();
    root.push_back(build_vec(0, n, v));
  }

  int update(int ver, int p, S x) {
    int nr = update(root[ver], 0, n, p, x);
    root.push_back(nr);
    return (int)root.size() - 1;
  }

  S get(int ver, int p) { return get(root[ver], 0, n, p); }

  S prod(int ver, int l, int r) { return prod(root[ver], 0, n, l, r); }

  int new_node(S val, int l, int r) {
    nd.push_back({val, l, r});
    return (int)nd.size() - 1;
  }

  int build_empty(int l, int r) {
    if (r - l == 1) return new_node(e(), -1, -1);
    int m = (l + r) >> 1;
    int lc = build_empty(l, m);
    int rc = build_empty(m, r);
    return new_node(op(nd[lc].val, nd[rc].val), lc, rc);
  }

  int build_vec(int l, int r, const vector<S>& v) {
    if (r - l == 1) return new_node(v[l], -1, -1);
    int m = (l + r) >> 1;
    int lc = build_vec(l, m, v);
    int rc = build_vec(m, r, v);
    return new_node(op(nd[lc].val, nd[rc].val), lc, rc);
  }

  int update(int v, int l, int r, int p, S x) {
    if (r - l == 1) return new_node(x, -1, -1);
    int m = (l + r) >> 1;
    int lc = nd[v].l;
    int rc = nd[v].r;
    if (p < m) {
      lc = update(lc, l, m, p, x);
    } else {
      rc = update(rc, m, r, p, x);
    }
    return new_node(op(nd[lc].val, nd[rc].val), lc, rc);
  }

  S get(int v, int l, int r, int p) {
    if (r - l == 1) return nd[v].val;
    int m = (l + r) >> 1;
    if (p < m) return get(nd[v].l, l, m, p);
    return get(nd[v].r, m, r, p);
  }

  S prod(int v, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return e();
    if (ql <= l && r <= qr) return nd[v].val;
    int m = (l + r) >> 1;
    S lv = prod(nd[v].l, l, m, ql, qr);
    S rv = prod(nd[v].r, m, r, ql, qr);
    return op(lv, rv);
  }
};

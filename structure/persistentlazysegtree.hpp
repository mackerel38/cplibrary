#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct persistent_lazysegtree {
  struct node {
    S val;
    F lz;
    int l;
    int r;
    bool has;
  };

  int n;
  vector<node> nd;
  vector<int> root;

  persistent_lazysegtree() : n(0) {}
  persistent_lazysegtree(int n_) { init(n_); }
  persistent_lazysegtree(const vector<S>& v) { build(v); }

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

  int apply(int ver, int l, int r, F f) {
    int nr = apply(root[ver], 0, n, l, r, f);
    root.push_back(nr);
    return (int)root.size() - 1;
  }

  int set(int ver, int p, S x) {
    int nr = set(root[ver], 0, n, p, x);
    root.push_back(nr);
    return (int)root.size() - 1;
  }

  int replace_range(int ver_a, int ver_b, int l, int r) {
    int nr = replace_range(root[ver_a], root[ver_b], 0, n, l, r);
    root.push_back(nr);
    return (int)root.size() - 1;
  }

  S get(int ver, int p) { return prod(ver, p, p + 1); }

  S prod(int ver, int l, int r) { return prod(root[ver], 0, n, l, r, id()); }

  int new_node(S val, F lz, int l, int r, bool has) {
    nd.push_back({val, lz, l, r, has});
    return (int)nd.size() - 1;
  }

  int build_empty(int l, int r) {
    if (r - l == 1) return new_node(e(), id(), -1, -1, false);
    int m = (l + r) >> 1;
    int lc = build_empty(l, m);
    int rc = build_empty(m, r);
    return new_node(op(nd[lc].val, nd[rc].val), id(), lc, rc, false);
  }

  int build_vec(int l, int r, const vector<S>& v) {
    if (r - l == 1) return new_node(v[l], id(), -1, -1, false);
    int m = (l + r) >> 1;
    int lc = build_vec(l, m, v);
    int rc = build_vec(m, r, v);
    return new_node(op(nd[lc].val, nd[rc].val), id(), lc, rc, false);
  }

  int clone(int v) {
    nd.push_back(nd[v]);
    return (int)nd.size() - 1;
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

  void push(int v, int l, int r) {
    if (r - l == 1) return;
    if (!nd[v].has) return;
    F f = nd[v].lz;
    int lc = nd[v].l;
    int rc = nd[v].r;
    lc = clone(lc);
    rc = clone(rc);
    all_apply(lc, f);
    all_apply(rc, f);
    nd[v].l = lc;
    nd[v].r = rc;
    nd[v].lz = id();
    nd[v].has = false;
  }

  int apply(int v, int l, int r, int ql, int qr, F f) {
    if (qr <= l || r <= ql) return v;
    v = clone(v);
    if (ql <= l && r <= qr) {
      all_apply(v, f);
      return v;
    }
    push(v, l, r);
    int m = (l + r) >> 1;
    int lc = apply(nd[v].l, l, m, ql, qr, f);
    int rc = apply(nd[v].r, m, r, ql, qr, f);
    nd[v].l = lc;
    nd[v].r = rc;
    nd[v].val = op(nd[lc].val, nd[rc].val);
    return v;
  }

  int set(int v, int l, int r, int p, S x) {
    v = clone(v);
    if (r - l == 1) {
      nd[v].val = x;
      nd[v].lz = id();
      nd[v].has = false;
      return v;
    }
    push(v, l, r);
    int m = (l + r) >> 1;
    if (p < m) {
      nd[v].l = set(nd[v].l, l, m, p, x);
    } else {
      nd[v].r = set(nd[v].r, m, r, p, x);
    }
    nd[v].val = op(nd[nd[v].l].val, nd[nd[v].r].val);
    return v;
  }

  S prod(int v, int l, int r, int ql, int qr, F acc) {
    if (qr <= l || r <= ql) return e();
    if (ql <= l && r <= qr) return mapping(acc, nd[v].val);
    int m = (l + r) >> 1;
    F nxt = acc;
    if (nd[v].has) nxt = composition(acc, nd[v].lz);
    S lv = prod(nd[v].l, l, m, ql, qr, nxt);
    S rv = prod(nd[v].r, m, r, ql, qr, nxt);
    return op(lv, rv);
  }

  int replace_range(int a, int b, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return a;
    if (ql <= l && r <= qr) return b;
    a = clone(a);
    b = clone(b);
    push(a, l, r);
    push(b, l, r);
    int m = (l + r) >> 1;
    int lc = replace_range(nd[a].l, nd[b].l, l, m, ql, qr);
    int rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);
    nd[a].l = lc;
    nd[a].r = rc;
    nd[a].val = op(nd[lc].val, nd[rc].val);
    return a;
  }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
  int n;
  int sz;
  int lg;
  vector<S> d;
  segtree() : n(0), sz(1), lg(0), d(1, e()) {}
  segtree(int n_) { init(n_); }
  segtree(const vector<S>& v) { build(v); }
  void init(int n_) {
    n = n_;
    sz = 1;
    lg = 0;
    while (sz < n) {
      sz <<= 1;
      lg++;
    }
    d.assign(2 * sz, e());
  }
  void build(const vector<S>& v) {
    init((int)v.size());
    for (int i = 0; i < n; i++) d[sz + i] = v[i];
    for (int i = sz - 1; i >= 1; i--) d[i] = op(d[i << 1], d[i << 1 | 1]);
  }
  void set(int p, S x) {
    p += sz;
    d[p] = x;
    for (int i = 1; i <= lg; i++) {
      int k = p >> i;
      d[k] = op(d[k << 1], d[k << 1 | 1]);
    }
  }
  S get(int p) const { return d[p + sz]; }
  S prod(int l, int r) const {
    S sml = e();
    S smr = e();
    l += sz;
    r += sz;
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  S all_prod() const { return d[1]; }
  template <class F>
  int max_right(int l, F f) const {
    if (l == n) return n;
    S sm = e();
    l += sz;
    do {
      while ((l & 1) == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < sz) {
          l <<= 1;
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - sz;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return n;
  }
  template <class F>
  int min_left(int r, F f) const {
    if (r == 0) return 0;
    S sm = e();
    r += sz;
    do {
      r--;
      while (r > 1 && (r & 1)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < sz) {
          r = r << 1 | 1;
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - sz;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};

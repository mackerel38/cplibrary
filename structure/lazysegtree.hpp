#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazysegtree {
  int n;
  int sz;
  int lg;
  vector<S> d;
  vector<F> lz;

  lazysegtree() : n(0), sz(1), lg(0) {
    d.assign(1, e());
    lz.assign(1, id());
  }
  lazysegtree(int n_) { init(n_); }
  lazysegtree(const vector<S>& v) { build(v); }

  void init(int n_) {
    n = n_;
    sz = 1;
    lg = 0;
    while (sz < n) {
      sz <<= 1;
      lg++;
    }
    d.assign(2 * sz, e());
    lz.assign(sz, id());
  }

  void build(const vector<S>& v) {
    init((int)v.size());
    for (int i = 0; i < n; i++) d[sz + i] = v[i];
    for (int i = sz - 1; i >= 1; i--) update(i);
  }

  void set(int p, S x) {
    p += sz;
    for (int i = lg; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= lg; i++) update(p >> i);
  }

  S get(int p) {
    p += sz;
    for (int i = lg; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    if (l == r) return e();
    l += sz;
    r += sz;
    for (int i = lg; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    S sml = e();
    S smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    p += sz;
    for (int i = lg; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= lg; i++) update(p >> i);
  }

  void apply(int l, int r, F f) {
    if (l == r) return;
    l += sz;
    r += sz;
    for (int i = lg; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    int l2 = l;
    int r2 = r;
    while (l < r) {
      if (l & 1) all_apply(l++, f);
      if (r & 1) all_apply(--r, f);
      l >>= 1;
      r >>= 1;
    }
    l = l2;
    r = r2;
    for (int i = 1; i <= lg; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  void update(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }

  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < sz) lz[k] = composition(f, lz[k]);
  }

  void push(int k) {
    all_apply(k << 1, lz[k]);
    all_apply(k << 1 | 1, lz[k]);
    lz[k] = id();
  }
};

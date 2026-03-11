#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "math/affine.hpp"
#include "math/modint.hpp"
#include "structure/lazysegtree.hpp"

template <long long MOD = 998244353>
struct range_affine_range_sum {
  using mint = modint<MOD>;
  struct S {
    mint sum;
    int len;
  };
  using F = affine<mint>;

  static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
  static S e() { return {mint(0), 0}; }
  static S mapping(F f, S x) {
    return {f.a * x.sum + f.b * mint(x.len), x.len};
  }
  static F composition(F f, F g) { return affine_compose(f, g); }
  static F id() { return F(); }

  lazysegtree<S, op, e, F, mapping, composition, id> seg;

  range_affine_range_sum() {}
  range_affine_range_sum(int n) { init(n); }
  range_affine_range_sum(const vector<mint>& a) { build(a); }

  void init(int n) {
    vector<S> v(n);
    for (int i = 0; i < n; i++) v[i] = {mint(0), 1};
    seg.build(v);
  }

  void build(const vector<mint>& a) {
    int n = (int)a.size();
    vector<S> v(n);
    for (int i = 0; i < n; i++) v[i] = {a[i], 1};
    seg.build(v);
  }

  void set(int p, mint x) { seg.set(p, {x, 1}); }
  mint get(int p) { return seg.get(p).sum; }
  mint prod(int l, int r) { return seg.prod(l, r).sum; }
  void apply(int l, int r, F f) { seg.apply(l, r, f); }
  void apply(int l, int r, mint b, mint c) { seg.apply(l, r, F(b, c)); }
};

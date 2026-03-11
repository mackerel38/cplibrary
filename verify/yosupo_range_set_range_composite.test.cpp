#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"
#include "structure/lazysegtree.hpp"
#include "math/affine.hpp"
#include "math/modint.hpp"
#include <bits/stdc++.h>
using namespace std;

using mint = modint<998244353>;
using aff = affine<mint>;

struct S {
  aff f;
  int len;
};

struct F {
  aff f;
  bool has;
};

aff aff_pow(aff f, long long n) {
  if (n == 0) return aff(mint(1), mint(0));
  mint a = f.a;
  mint b = f.b;
  mint ap = mint::pow(a, n);
  mint s;
  if (a.v == 1) {
    s = mint(n);
  } else {
    s = (ap - mint(1)) * mint::inv(a - mint(1));
  }
  return aff(ap, b * s);
}

S op(S a, S b) { return {affine_compose(b.f, a.f), a.len + b.len}; }
S e() { return {aff(mint(1), mint(0)), 0}; }

S mapping(F f, S x) {
  if (!f.has) return x;
  return {aff_pow(f.f, x.len), x.len};
}

F composition(F f, F g) { return f.has ? f : g; }
F id() { return {aff(mint(1), mint(0)), false}; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<S> v(N);
  for (int i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    v[i] = {aff(mint(a), mint(b)), 1};
  }
  lazysegtree<S, op, e, F, mapping, composition, id> seg(v);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      long long c, d;
      cin >> l >> r >> c >> d;
      seg.apply(l, r, F{aff(mint(c), mint(d)), true});
    } else {
      int l, r;
      long long x;
      cin >> l >> r >> x;
      S res = seg.prod(l, r);
      mint ans = res.f.eval(mint(x));
      cout << ans.v << "\n";
    }
  }
  return 0;
}

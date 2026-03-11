#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"
#include <bits/stdc++.h>
using namespace std;

#include "math/affine.hpp"
#include "math/modint.hpp"
#include "structure/dynamiclazysegtree.hpp"

using mint = modint<998244353>;

struct S {
  mint sum;
  long long len;
};

using F = affine<mint>;

S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
S e() { return {mint(0), 0}; }
S make(long long len) { return {mint(0), len}; }
S mapping(F f, S x) { return {f.a * x.sum + f.b * mint(x.len), x.len}; }
F composition(F f, F g) { return affine_compose(f, g); }
F id() { return F(); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N;
  int Q;
  if (!(cin >> N >> Q)) return 0;
  dynamic_lazysegtree<S, op, e, make, F, mapping, composition, id> seg(N);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      long long l, r;
      long long b, c;
      cin >> l >> r >> b >> c;
      seg.apply(l, r, F(mint(b), mint(c)));
    } else {
      long long l, r;
      cin >> l >> r;
      cout << seg.prod(l, r).sum.v << "\n";
    }
  }
  return 0;
}

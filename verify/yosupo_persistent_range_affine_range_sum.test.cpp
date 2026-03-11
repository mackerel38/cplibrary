#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"
#include "structure/persistentlazysegtree.hpp"
#include "math/affine.hpp"
#include "math/modint.hpp"
#include <bits/stdc++.h>
using namespace std;

using mint = modint<998244353>;
using F = affine<mint>;

struct S {
  mint sum;
  int len;
};

S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
S e() { return {mint(0), 0}; }
S mapping(F f, S x) { return {f.a * x.sum + f.b * mint(x.len), x.len}; }
F composition(F f, F g) { return affine_compose(f, g); }
F id() { return F(); }

using seg_t = persistent_lazysegtree<S, op, e, F, mapping, composition, id>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<S> v(N);
  for (int i = 0; i < N; i++) {
    mint x;
    cin >> x;
    v[i] = {x, 1};
  }
  seg_t seg(v);
  vector<int> ver(Q, -1);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int k, l, r;
      long long b, c;
      cin >> k >> l >> r >> b >> c;
      int base = (k == -1) ? 0 : ver[k];
      ver[i] = seg.apply(base, l, r, F(mint(b), mint(c)));
    } else if (t == 1) {
      int k, s, l, r;
      cin >> k >> s >> l >> r;
      int base = (k == -1) ? 0 : ver[k];
      int src = (s == -1) ? 0 : ver[s];
      ver[i] = seg.replace_range(base, src, l, r);
    } else {
      int k, l, r;
      cin >> k >> l >> r;
      int base = (k == -1) ? 0 : ver[k];
      mint ans = seg.prod(base, l, r).sum;
      cout << ans.v << "\n";
    }
  }
  return 0;
}

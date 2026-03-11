#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "math/affine.hpp"
#include "math/modint.hpp"
#include "structure/segtree.hpp"

static const long long MOD = 998244353;
using mint = modint<MOD>;
using F = affine<mint>;

F op(F x, F y) {
  return affine_compose(y, x);
}
F e() { return F(mint(1), mint(0)); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<F> v(N);
  for (int i = 0; i < N; i++) {
    mint a, b;
    cin >> a >> b;
    v[i] = F(a, b);
  }
  segtree<F, op, e> st(v);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      mint c, d;
      cin >> p >> c >> d;
      st.set(p, F(c, d));
    } else {
      int l, r;
      mint x;
      cin >> l >> r >> x;
      F f = st.prod(l, r);
      cout << f.eval(x) << "\n";
    }
  }
  return 0;
}

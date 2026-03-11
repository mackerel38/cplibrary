#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "math/affine.hpp"
#include "math/modint.hpp"
#include "structure/lazysegtree.hpp"

static const long long MOD = 998244353;
using mint = modint<MOD>;
using F = affine<mint>;

struct S {
  mint sum;
  int len;
};

S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
S e() { return {mint(0), 0}; }
S mapping(F f, S x) { return {f.a * x.sum + f.b * mint(x.len), x.len}; }
F composition(F f, F g) { return affine_compose(f, g); }
F id() { return F(mint(1), mint(0)); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<S> v(N);
  for (int i = 0; i < N; i++) {
    mint a;
    cin >> a;
    v[i] = {a, 1};
  }
  lazysegtree<S, op, e, F, mapping, composition, id> st(v);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      mint b, c;
      cin >> l >> r >> b >> c;
      st.apply(l, r, F(b, c));
    } else {
      int idx;
      cin >> idx;
      auto res = st.get(idx);
      cout << res.sum << "\n";
    }
  }
  return 0;
}

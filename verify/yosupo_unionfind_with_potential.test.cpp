#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "math/modint.hpp"
#include "structure/weightedunionfind.hpp"

static const long long MOD = 998244353;
using mint = modint<MOD>;

struct mod_add {
  static mint id() { return mint(0); }
  static mint op(mint a, mint b) { return a + b; }
  static mint inv(mint a) { return -a; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  weighted_unionfind<mint, mod_add> uf(N);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int u, v;
      mint x;
      cin >> u >> v >> x;
      cout << (uf.merge(u, v, x) ? 1 : 0) << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      mint ans;
      if (uf.get(u, v, ans)) {
        cout << ans << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}

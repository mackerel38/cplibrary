#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include "math/mat2.hpp"
#include "math/modint.hpp"
#include "structure/weightedunionfind.hpp"

static const long long MOD = 998244353;

struct mod_ops {
  using T = modint<MOD>;
  static T zero() { return T(0); }
  static T one() { return T(1); }
  static T add(T a, T b) { return a + b; }
  static T sub(T a, T b) { return a - b; }
  static T mul(T a, T b) { return a * b; }
  static T inv(T a) { return T::inv(a); }
  static T neg(T a) { return -a; }
};

using mat = mat2<mod_ops>;

struct mat_group {
  static mat id() { return mat::id(); }
  static mat op(const mat &a, const mat &b) { return mat::op(a, b); }
  static mat inv(const mat &a) { return mat::inv(a); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  weighted_unionfind<mat, mat_group> uf(N);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int u, v;
      long long x00, x01, x10, x11;
      cin >> u >> v >> x00 >> x01 >> x10 >> x11;
      mat x(x00, x01, x10, x11);
      cout << (uf.merge(u, v, x) ? 1 : 0) << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      mat ans;
      if (uf.get(u, v, ans)) {
        cout << ans.a00 << " " << ans.a01 << " " << ans.a10 << " "
             << ans.a11 << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include "math/mat2.hpp"
#include "structure/weightedunionfind.hpp"

static const long long MOD = 998244353;

struct mod_ops {
  using T = long long;
  static T zero() { return 0; }
  static T one() { return 1; }
  static T add(T a, T b) {
    T v = a + b;
    if (v >= MOD) v -= MOD;
    return v;
  }
  static T sub(T a, T b) {
    T v = a - b;
    if (v < 0) v += MOD;
    return v;
  }
  static T mul(T a, T b) { return a * b % MOD; }
  static T modpow(T a, T e) {
    T r = 1;
    while (e > 0) {
      if (e & 1) r = r * a % MOD;
      a = a * a % MOD;
      e >>= 1;
    }
    return r;
  }
  static T inv(T a) { return modpow(a, MOD - 2); }
  static T neg(T a) { return a == 0 ? 0 : MOD - a; }
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

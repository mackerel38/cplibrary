#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "structure/weightedunionfind.hpp"

static const long long MOD = 998244353;

struct mod_add {
  static long long id() { return 0; }
  static long long op(long long a, long long b) {
    long long v = a + b;
    if (v >= MOD) v -= MOD;
    return v;
  }
  static long long inv(long long a) { return a == 0 ? 0 : MOD - a; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  weighted_unionfind<long long, mod_add> uf(N);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int u, v;
      long long x;
      cin >> u >> v >> x;
      x %= MOD;
      cout << (uf.merge(u, v, x) ? 1 : 0) << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      long long ans;
      if (uf.get(u, v, ans)) {
        cout << ans << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}

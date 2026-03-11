#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "math/modint.hpp"
#include "structure/rangeparallel_unionfind.hpp"

static const long long MOD = 998244353;
using mint = modint<MOD>;

struct mod_ops {
  using T = mint;
  static T zero() { return T(0); }
  static T add(T a, T b) { return a + b; }
  static T mul(T a, T b) { return a * b; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<mint> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  range_parallel_unionfind<mod_ops> uf(N);
  uf.set_values(x);
  for (int i = 0; i < Q; i++) {
    int k, a, b;
    cin >> k >> a >> b;
    uf.merge_range(a, b, k);
    cout << uf.cur << "\n";
  }
  return 0;
}

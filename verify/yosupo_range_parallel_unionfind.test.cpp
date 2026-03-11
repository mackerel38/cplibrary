#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "structure/rangeparallel_unionfind.hpp"

static const long long MOD = 998244353;

struct mod_ops {
  using T = long long;
  static T zero() { return 0; }
  static T add(T a, T b) {
    T v = a + b;
    if (v >= MOD) v -= MOD;
    return v;
  }
  static T mul(T a, T b) { return a * b % MOD; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<long long> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    x[i] %= MOD;
  }
  range_parallel_unionfind<mod_ops> uf(N);
  uf.set_values(x);
  for (int i = 0; i < Q; i++) {
    int k, a, b;
    cin >> k >> a >> b;
    uf.merge_range(a, b, k);
    cout << uf.cur % MOD << "\n";
  }
  return 0;
}

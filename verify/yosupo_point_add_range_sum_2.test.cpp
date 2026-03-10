#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../structure/BIT.hpp"

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  if (!(cin >> n >> q)) return 0;
  BIT<ll> fw(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    fw.add(i, x);
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      ll x;
      cin >> p >> x;
      fw.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << '\n';
    }
  }
  return 0;
}

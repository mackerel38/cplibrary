#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "structure/segtree.hpp"

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  if (!(cin >> n >> q)) return 0;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  segtree<ll, op, e> seg(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << seg.prod(l, r) << '\n';
  }
  return 0;
}

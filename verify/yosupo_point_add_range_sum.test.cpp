#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../structure/segtree.hpp"

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
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      ll x;
      cin >> p >> x;
      seg.set(p, seg.get(p) + x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r) << '\n';
    }
  }
  return 0;
}

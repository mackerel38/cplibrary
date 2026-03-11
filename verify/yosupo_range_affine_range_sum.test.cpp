#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "structure/range_affine_range_sum.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  if (!(cin >> n >> q)) return 0;
  using seg_t = range_affine_range_sum<998244353>;
  using mint = seg_t::mint;
  vector<mint> a(n);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = mint(x);
  }
  seg_t seg(a);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      long long b, c;
      cin >> l >> r >> b >> c;
      seg.apply(l, r, mint(b), mint(c));
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r) << '\n';
    }
  }
  return 0;
}

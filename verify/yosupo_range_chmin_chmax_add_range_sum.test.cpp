#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "structure/segtreebeats.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  segtreebeats seg(a);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      long long b;
      cin >> l >> r >> b;
      seg.range_chmin(l, r, b);
    } else if (t == 1) {
      int l, r;
      long long b;
      cin >> l >> r >> b;
      seg.range_chmax(l, r, b);
    } else if (t == 2) {
      int l, r;
      long long b;
      cin >> l >> r >> b;
      seg.range_add(l, r, b);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.range_sum(l, r) << "\n";
    }
  }
  return 0;
}

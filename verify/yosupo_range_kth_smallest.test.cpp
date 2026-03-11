#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "structure/waveletmatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  wavelet_matrix wm(a);
  for (int i = 0; i < Q; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << wm.kth(l, r, k) << "\n";
  }
  return 0;
}

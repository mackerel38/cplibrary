#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "structure/sparsetable.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  sparse_table<long long> st(a);
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r) << "\n";
  }
  return 0;
}

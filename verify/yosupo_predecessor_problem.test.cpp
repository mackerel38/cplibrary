#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "structure/treap.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  string T;
  cin >> T;

  treap<int> tr;
  for (int i = 0; i < N; i++) {
    if (T[i] == '1') tr.insert(i);
  }

  for (int i = 0; i < Q; i++) {
    int c, k;
    cin >> c >> k;
    if (c == 0) {
      tr.insert(k);
    } else if (c == 1) {
      tr.erase(k);
    } else if (c == 2) {
      cout << (tr.contains(k) ? 1 : 0) << '\n';
    } else if (c == 3) {
      int v;
      if (tr.lower_bound(k, v))
        cout << v << '\n';
      else
        cout << -1 << '\n';
    } else if (c == 4) {
      int v;
      if (tr.prev_eq(k, v))
        cout << v << '\n';
      else
        cout << -1 << '\n';
    }
  }
  return 0;
}

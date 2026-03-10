#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "structure/treap.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  treap<long long> tr;
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    tr.insert(a);
  }

  for (int i = 0; i < Q; i++) {
    int t;
    long long x;
    cin >> t >> x;
    if (t == 0) {
      tr.insert(x);
    } else if (t == 1) {
      tr.erase(x);
    } else if (t == 2) {
      long long v;
      if (tr.kth((int)(x - 1), v))
        cout << v << '\n';
      else
        cout << -1 << '\n';
    } else if (t == 3) {
      cout << tr.count_le(x) << '\n';
    } else if (t == 4) {
      long long v;
      if (tr.prev_eq(x, v))
        cout << v << '\n';
      else
        cout << -1 << '\n';
    } else if (t == 5) {
      long long v;
      if (tr.lower_bound(x, v))
        cout << v << '\n';
      else
        cout << -1 << '\n';
    }
  }
  return 0;
}

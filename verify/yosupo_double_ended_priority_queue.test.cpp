#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "structure/bipq.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  bipq<long long> pq;
  for (int i = 0; i < N; i++) {
    long long x;
    cin >> x;
    pq.push(x);
  }

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      long long x;
      cin >> x;
      pq.push(x);
    } else if (t == 1) {
      cout << pq.pop_min() << '\n';
    } else if (t == 2) {
      cout << pq.pop_max() << '\n';
    }
  }
  return 0;
}

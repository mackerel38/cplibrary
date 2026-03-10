#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../structure/hashmap.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  if (!(cin >> q)) return 0;
  hashmap<long long, long long> mp;
  while (q--) {
    int t;
    long long k;
    cin >> t >> k;
    if (t == 0) {
      long long v;
      cin >> v;
      mp.set(k, v);
    } else {
      cout << mp.get(k, 0LL) << '\n';
    }
  }
  return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "structure/unionfind.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  unionfind uf(N);
  for (int i = 0; i < Q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      uf.merge(u, v);
    } else {
      cout << (uf.same(u, v) ? 1 : 0) << '\n';
    }
  }
  return 0;
}

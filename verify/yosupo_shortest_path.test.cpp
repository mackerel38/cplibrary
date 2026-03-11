#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "graph/dijkstra.hpp"
#include "graph/restore_shortestpath.hpp"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  graph g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    g.add_edge(a, b, c);
  }
  auto res = dijkstra(g, s);
  if (res.dist[t] >= (1LL << 61)) {
    cout << -1 << "\n";
    return 0;
  }
  auto es = restore_path_edges(s, t, res.prev);
  cout << res.dist[t] << " " << (int)es.size() << "\n";
  for (auto& e : es) {
    cout << e.first << " " << e.second << "\n";
  }
  return 0;
}

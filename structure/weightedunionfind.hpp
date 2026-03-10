#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T, class Op>
struct weighted_unionfind {
  int n;
  vector<int> p;
  vector<int> sz;
  vector<T> w;

  weighted_unionfind() : n(0) {}
  weighted_unionfind(int n_) { init(n_); }

  void init(int n_) {
    n = n_;
    p.resize(n);
    sz.assign(n, 1);
    w.assign(n, Op::id());
    iota(p.begin(), p.end(), 0);
  }

  T add(T a, T b) { return Op::op(a, b); }
  T sub(T a, T b) { return Op::op(a, Op::inv(b)); }

  int leader(int x) {
    if (p[x] == x) return x;
    int r = leader(p[x]);
    w[x] = add(w[x], w[p[x]]);
    return p[x] = r;
  }

  T weight(int x) {
    leader(x);
    return w[x];
  }

  bool same(int a, int b) { return leader(a) == leader(b); }

  T diff(int a, int b) { return sub(weight(a), weight(b)); }

  bool get(int a, int b, T &out) {
    if (!same(a, b)) return false;
    out = diff(a, b);
    return true;
  }

  bool merge(int a, int b, T x) {
    int ra = leader(a);
    int rb = leader(b);
    T wa = w[a];
    T wb = w[b];
    if (ra == rb) return sub(wa, wb) == x;
    if (sz[ra] < sz[rb]) {
      p[ra] = rb;
      sz[rb] += sz[ra];
      w[ra] = sub(add(wb, x), wa);
    } else {
      p[rb] = ra;
      sz[ra] += sz[rb];
      w[rb] = sub(sub(wa, wb), x);
    }
    return true;
  }

  int size(int x) { return sz[leader(x)]; }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
  int n;
  vector<T> d;

  BIT() : n(0) {}
  BIT(int n_) { init(n_); }

  void init(int n_) {
    n = n_;
    d.assign(n + 1, T());
  }

  void add(int i, T x) {
    for (int p = i + 1; p <= n; p += p & -p) d[p] += x;
  }

  T sum(int r) const {
    T res = T();
    for (int p = r; p > 0; p -= p & -p) res += d[p];
    return res;
  }

  T sum(int l, int r) const { return sum(r) - sum(l); }
};

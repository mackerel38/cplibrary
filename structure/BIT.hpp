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
    for (i++; i <= n; i += i & -i) d[i] += x;
  }
  T sum(int r) const {
    T s = T();
    for (; r > 0; r -= r & -r) s += d[r];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int lower_bound(T x) const {
    if (x <= T()) return 0;
    int i = 0;
    int k = 1;
    while ((k << 1) <= n) k <<= 1;
    for (; k > 0; k >>= 1) {
      int ni = i + k;
      if (ni <= n && d[ni] < x) {
        x -= d[ni];
        i = ni;
      }
    }
    return i;
  }
};

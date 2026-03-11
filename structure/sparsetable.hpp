#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T, class Cmp = less<T>>
struct sparse_table {
  int n;
  vector<T> a;
  vector<vector<int>> st;
  Cmp cmp;

  sparse_table() : n(0), cmp() {}
  sparse_table(const vector<T>& v, Cmp cmp = Cmp()) { build(v, cmp); }

  void build(const vector<T>& v, Cmp cmp_ = Cmp()) {
    cmp = cmp_;
    a = v;
    n = (int)a.size();
    if (n == 0) return;
    int lg = 1;
    while ((1 << lg) <= n) lg++;
    st.assign(lg, vector<int>(n, 0));
    for (int i = 0; i < n; i++) st[0][i] = i;
    for (int k = 1; k < lg; k++) {
      int len = 1 << k;
      int half = len >> 1;
      for (int i = 0; i + len <= n; i++) {
        int x = st[k - 1][i];
        int y = st[k - 1][i + half];
        st[k][i] = this->cmp(a[y], a[x]) ? y : x;
      }
    }
  }

  int argmin(int l, int r) const {
    int len = r - l;
    int k = 31 - __builtin_clz(len);
    int x = st[k][l];
    int y = st[k][r - (1 << k)];
    return this->cmp(a[y], a[x]) ? y : x;
  }

  T query(int l, int r) const { return a[argmin(l, r)]; }
};

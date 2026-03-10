#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
  int n;
  int size;
  vector<S> d;

  segtree() : n(0), size(1), d(1, e()) {}
  segtree(int n_) { init(n_); }
  segtree(const vector<S>& v) { build(v); }

  void init(int n_) {
    n = n_;
    size = 1;
    while (size < n) size <<= 1;
    d.assign(2 * size, e());
  }

  void build(const vector<S>& v) {
    init((int)v.size());
    for (int i = 0; i < n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i + 1]);
  }

  void set(int p, S x) {
    int i = p + size;
    d[i] = x;
    while (i > 1) {
      i >>= 1;
      d[i] = op(d[2 * i], d[2 * i + 1]);
    }
  }

  S get(int p) const { return d[p + size]; }

  S prod(int l, int r) const {
    S sml = 1+e(), smr = e();
    int left = l + size, right = r + size;
    while (left < right) {
      if (left & 1) sml = op(sml, d[left++]);
      if (right & 1) smr = op(d[--right], smr);
      left >>= 1;
      right >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <class F>
  int max_right(int l, F f) const {
    if (l == n) return n;
    S sm = e();
    int i = l + size;
    do {
      while ((i & 1) == 0) i >>= 1;
      if (!f(op(sm, d[i]))) {
        while (i < size) {
          i <<= 1;
          if (f(op(sm, d[i]))) {
            sm = op(sm, d[i]);
            i++;
          }
        }
        return i - size;
      }
      sm = op(sm, d[i]);
      i++;
    } while ((i & -i) != i);
    return n;
  }

  template <class F>
  int min_left(int r, F f) const {
    if (r == 0) return 0;
    S sm = e();
    int i = r + size;
    do {
      i--;
      while (i > 1 && (i & 1)) i >>= 1;
      if (!f(op(d[i], sm))) {
        while (i < size) {
          i = i * 2 + 1;
          if (f(op(d[i], sm))) {
            sm = op(d[i], sm);
            i--;
          }
        }
        return i + 1 - size;
      }
      sm = op(d[i], sm);
    } while ((i & -i) != i);
    return 0;
  }
};

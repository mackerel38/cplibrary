#pragma once
#include <bits/stdc++.h>
using namespace std;

struct segtreebeats {
  int n;
  vector<long long> sum;
  vector<long long> max1;
  vector<long long> max2;
  vector<int> maxc;
  vector<long long> min1;
  vector<long long> min2;
  vector<int> minc;
  vector<long long> add;
  vector<int> len;

  const long long INF = (long long)4e18;

  segtreebeats() : n(0) {}
  segtreebeats(int n_) { init(n_); }
  segtreebeats(const vector<long long>& v) { build(v); }

  void init(int n_) {
    n = n_;
    int sz = 4 * n + 5;
    sum.assign(sz, 0);
    max1.assign(sz, -INF);
    max2.assign(sz, -INF);
    maxc.assign(sz, 0);
    min1.assign(sz, INF);
    min2.assign(sz, INF);
    minc.assign(sz, 0);
    add.assign(sz, 0);
    len.assign(sz, 0);
  }

  void build(const vector<long long>& v) {
    init((int)v.size());
    build(1, 0, n, v);
  }

  void range_chmin(int l, int r, long long x) { range_chmin(1, 0, n, l, r, x); }
  void range_chmax(int l, int r, long long x) { range_chmax(1, 0, n, l, r, x); }
  void range_add(int l, int r, long long x) { range_add(1, 0, n, l, r, x); }
  long long range_sum(int l, int r) { return range_sum(1, 0, n, l, r); }

  void build(int k, int l, int r, const vector<long long>& v) {
    len[k] = r - l;
    if (r - l == 1) {
      long long x = v[l];
      sum[k] = x;
      max1[k] = x;
      max2[k] = -INF;
      maxc[k] = 1;
      min1[k] = x;
      min2[k] = INF;
      minc[k] = 1;
      return;
    }
    int m = (l + r) >> 1;
    build(k << 1, l, m, v);
    build(k << 1 | 1, m, r, v);
    pull(k);
  }

  void apply_add(int k, long long x) {
    sum[k] += x * (long long)len[k];
    max1[k] += x;
    if (max2[k] != -INF) max2[k] += x;
    min1[k] += x;
    if (min2[k] != INF) min2[k] += x;
    add[k] += x;
  }

  void apply_chmin(int k, long long x) {
    if (max1[k] <= x) return;
    sum[k] += (x - max1[k]) * (long long)maxc[k];
    if (min1[k] == max1[k]) min1[k] = x;
    else if (min2[k] == max1[k]) min2[k] = x;
    max1[k] = x;
  }

  void apply_chmax(int k, long long x) {
    if (min1[k] >= x) return;
    sum[k] += (x - min1[k]) * (long long)minc[k];
    if (max1[k] == min1[k]) max1[k] = x;
    else if (max2[k] == min1[k]) max2[k] = x;
    min1[k] = x;
  }

  void push(int k) {
    if (len[k] == 1) return;
    if (add[k] != 0) {
      apply_add(k << 1, add[k]);
      apply_add(k << 1 | 1, add[k]);
      add[k] = 0;
    }
    if (max1[k] < max1[k << 1]) apply_chmin(k << 1, max1[k]);
    if (max1[k] < max1[k << 1 | 1]) apply_chmin(k << 1 | 1, max1[k]);
    if (min1[k] > min1[k << 1]) apply_chmax(k << 1, min1[k]);
    if (min1[k] > min1[k << 1 | 1]) apply_chmax(k << 1 | 1, min1[k]);
  }

  void pull(int k) {
    int l = k << 1;
    int r = k << 1 | 1;
    sum[k] = sum[l] + sum[r];

    if (max1[l] > max1[r]) {
      max1[k] = max1[l];
      maxc[k] = maxc[l];
      max2[k] = max(max2[l], max1[r]);
    } else if (max1[l] < max1[r]) {
      max1[k] = max1[r];
      maxc[k] = maxc[r];
      max2[k] = max(max1[l], max2[r]);
    } else {
      max1[k] = max1[l];
      maxc[k] = maxc[l] + maxc[r];
      max2[k] = max(max2[l], max2[r]);
    }

    if (min1[l] < min1[r]) {
      min1[k] = min1[l];
      minc[k] = minc[l];
      min2[k] = min(min2[l], min1[r]);
    } else if (min1[l] > min1[r]) {
      min1[k] = min1[r];
      minc[k] = minc[r];
      min2[k] = min(min1[l], min2[r]);
    } else {
      min1[k] = min1[l];
      minc[k] = minc[l] + minc[r];
      min2[k] = min(min2[l], min2[r]);
    }
  }

  void range_chmin(int k, int l, int r, int ql, int qr, long long x) {
    if (qr <= l || r <= ql || max1[k] <= x) return;
    if (ql <= l && r <= qr && max2[k] < x) {
      apply_chmin(k, x);
      return;
    }
    push(k);
    int m = (l + r) >> 1;
    range_chmin(k << 1, l, m, ql, qr, x);
    range_chmin(k << 1 | 1, m, r, ql, qr, x);
    pull(k);
  }

  void range_chmax(int k, int l, int r, int ql, int qr, long long x) {
    if (qr <= l || r <= ql || min1[k] >= x) return;
    if (ql <= l && r <= qr && min2[k] > x) {
      apply_chmax(k, x);
      return;
    }
    push(k);
    int m = (l + r) >> 1;
    range_chmax(k << 1, l, m, ql, qr, x);
    range_chmax(k << 1 | 1, m, r, ql, qr, x);
    pull(k);
  }

  void range_add(int k, int l, int r, int ql, int qr, long long x) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
      apply_add(k, x);
      return;
    }
    push(k);
    int m = (l + r) >> 1;
    range_add(k << 1, l, m, ql, qr, x);
    range_add(k << 1 | 1, m, r, ql, qr, x);
    pull(k);
  }

  long long range_sum(int k, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return sum[k];
    push(k);
    int m = (l + r) >> 1;
    return range_sum(k << 1, l, m, ql, qr) +
           range_sum(k << 1 | 1, m, r, ql, qr);
  }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

struct wavelet_matrix {
  int n;
  int lg;
  vector<int> mid;
  vector<vector<int>> pref;

  wavelet_matrix() : n(0), lg(0) {}
  wavelet_matrix(const vector<int>& v) { build(v); }

  void build(const vector<int>& v) {
    n = (int)v.size();
    int mx = 0;
    for (int x : v) mx = max(mx, x);
    lg = 0;
    while ((1LL << lg) <= mx) lg++;
    if (lg == 0) lg = 1;
    mid.assign(lg, 0);
    pref.assign(lg, vector<int>(n + 1, 0));
    vector<int> cur = v;
    vector<int> nxt(n);
    for (int lv = lg - 1; lv >= 0; lv--) {
      int zero = 0;
      for (int i = 0; i < n; i++) {
        int f = (cur[i] >> lv) & 1;
        pref[lv][i + 1] = pref[lv][i] + (f == 0);
      }
      zero = pref[lv][n];
      mid[lv] = zero;
      int p0 = 0, p1 = zero;
      for (int i = 0; i < n; i++) {
        int f = (cur[i] >> lv) & 1;
        if (f == 0)
          nxt[p0++] = cur[i];
        else
          nxt[p1++] = cur[i];
      }
      cur.swap(nxt);
    }
  }

  int kth(int l, int r, int k) const {
    int ans = 0;
    for (int lv = lg - 1; lv >= 0; lv--) {
      int zl = pref[lv][l];
      int zr = pref[lv][r];
      int zc = zr - zl;
      if (k < zc) {
        l = zl;
        r = zr;
      } else {
        k -= zc;
        int ol = l - zl;
        int orr = r - zr;
        l = mid[lv] + ol;
        r = mid[lv] + orr;
        ans |= (1 << lv);
      }
    }
    return ans;
  }
};

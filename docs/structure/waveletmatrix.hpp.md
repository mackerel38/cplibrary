---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_kth_smallest.test.cpp
    title: verify/yosupo_range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/waveletmatrix.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct wavelet_matrix {\n  int n;\n  int lg;\n  vector<int>\
    \ mid;\n  vector<vector<int>> pref;\n\n  wavelet_matrix() : n(0), lg(0) {}\n \
    \ wavelet_matrix(const vector<int>& v) { build(v); }\n\n  void build(const vector<int>&\
    \ v) {\n    n = (int)v.size();\n    int mx = 0;\n    for (int x : v) mx = max(mx,\
    \ x);\n    lg = 0;\n    while ((1LL << lg) <= mx) lg++;\n    if (lg == 0) lg =\
    \ 1;\n    mid.assign(lg, 0);\n    pref.assign(lg, vector<int>(n + 1, 0));\n  \
    \  vector<int> cur = v;\n    vector<int> nxt(n);\n    for (int lv = lg - 1; lv\
    \ >= 0; lv--) {\n      int zero = 0;\n      for (int i = 0; i < n; i++) {\n  \
    \      int f = (cur[i] >> lv) & 1;\n        pref[lv][i + 1] = pref[lv][i] + (f\
    \ == 0);\n      }\n      zero = pref[lv][n];\n      mid[lv] = zero;\n      int\
    \ p0 = 0, p1 = zero;\n      for (int i = 0; i < n; i++) {\n        int f = (cur[i]\
    \ >> lv) & 1;\n        if (f == 0)\n          nxt[p0++] = cur[i];\n        else\n\
    \          nxt[p1++] = cur[i];\n      }\n      cur.swap(nxt);\n    }\n  }\n\n\
    \  int kth(int l, int r, int k) const {\n    int ans = 0;\n    for (int lv = lg\
    \ - 1; lv >= 0; lv--) {\n      int zl = pref[lv][l];\n      int zr = pref[lv][r];\n\
    \      int zc = zr - zl;\n      if (k < zc) {\n        l = zl;\n        r = zr;\n\
    \      } else {\n        k -= zc;\n        int ol = l - zl;\n        int orr =\
    \ r - zr;\n        l = mid[lv] + ol;\n        r = mid[lv] + orr;\n        ans\
    \ |= (1 << lv);\n      }\n    }\n    return ans;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct wavelet_matrix\
    \ {\n  int n;\n  int lg;\n  vector<int> mid;\n  vector<vector<int>> pref;\n\n\
    \  wavelet_matrix() : n(0), lg(0) {}\n  wavelet_matrix(const vector<int>& v) {\
    \ build(v); }\n\n  void build(const vector<int>& v) {\n    n = (int)v.size();\n\
    \    int mx = 0;\n    for (int x : v) mx = max(mx, x);\n    lg = 0;\n    while\
    \ ((1LL << lg) <= mx) lg++;\n    if (lg == 0) lg = 1;\n    mid.assign(lg, 0);\n\
    \    pref.assign(lg, vector<int>(n + 1, 0));\n    vector<int> cur = v;\n    vector<int>\
    \ nxt(n);\n    for (int lv = lg - 1; lv >= 0; lv--) {\n      int zero = 0;\n \
    \     for (int i = 0; i < n; i++) {\n        int f = (cur[i] >> lv) & 1;\n   \
    \     pref[lv][i + 1] = pref[lv][i] + (f == 0);\n      }\n      zero = pref[lv][n];\n\
    \      mid[lv] = zero;\n      int p0 = 0, p1 = zero;\n      for (int i = 0; i\
    \ < n; i++) {\n        int f = (cur[i] >> lv) & 1;\n        if (f == 0)\n    \
    \      nxt[p0++] = cur[i];\n        else\n          nxt[p1++] = cur[i];\n    \
    \  }\n      cur.swap(nxt);\n    }\n  }\n\n  int kth(int l, int r, int k) const\
    \ {\n    int ans = 0;\n    for (int lv = lg - 1; lv >= 0; lv--) {\n      int zl\
    \ = pref[lv][l];\n      int zr = pref[lv][r];\n      int zc = zr - zl;\n     \
    \ if (k < zc) {\n        l = zl;\n        r = zr;\n      } else {\n        k -=\
    \ zc;\n        int ol = l - zl;\n        int orr = r - zr;\n        l = mid[lv]\
    \ + ol;\n        r = mid[lv] + orr;\n        ans |= (1 << lv);\n      }\n    }\n\
    \    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/waveletmatrix.hpp
  requiredBy: []
  timestamp: '2026-03-12 02:13:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_range_kth_smallest.test.cpp
documentation_of: //structure/waveletmatrix.hpp
layout: document
title: Wavelet Matrix
---
Definition
整数列に対して区間の k 番目に小さい値を求める。

Complexity
構築: O(N log V)
クエリ: O(log V)

ポイント
- 値のビットで階層分割する
- 区間の k 番目を高速に取得できる
- 値域 V に対して対数時間

使い方
- `wavelet_matrix wm(v);` で構築
- `wm.kth(l, r, k);` で [l, r) の k 番目に小さい値を取得

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segtreebeats.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 Beats"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#line 2 \"structure/segtreebeats.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct segtreebeats {\n  int n;\n  vector<long long> sum;\n  vector<long\
    \ long> max1;\n  vector<long long> max2;\n  vector<int> maxc;\n  vector<long long>\
    \ min1;\n  vector<long long> min2;\n  vector<int> minc;\n  vector<long long> add;\n\
    \  vector<int> len;\n\n  const long long INF = (long long)4e18;\n\n  segtreebeats()\
    \ : n(0) {}\n  segtreebeats(int n_) { init(n_); }\n  segtreebeats(const vector<long\
    \ long>& v) { build(v); }\n\n  void init(int n_) {\n    n = n_;\n    int sz =\
    \ 4 * n + 5;\n    sum.assign(sz, 0);\n    max1.assign(sz, -INF);\n    max2.assign(sz,\
    \ -INF);\n    maxc.assign(sz, 0);\n    min1.assign(sz, INF);\n    min2.assign(sz,\
    \ INF);\n    minc.assign(sz, 0);\n    add.assign(sz, 0);\n    len.assign(sz, 0);\n\
    \  }\n\n  void build(const vector<long long>& v) {\n    init((int)v.size());\n\
    \    build(1, 0, n, v);\n  }\n\n  void range_chmin(int l, int r, long long x)\
    \ { range_chmin(1, 0, n, l, r, x); }\n  void range_chmax(int l, int r, long long\
    \ x) { range_chmax(1, 0, n, l, r, x); }\n  void range_add(int l, int r, long long\
    \ x) { range_add(1, 0, n, l, r, x); }\n  long long range_sum(int l, int r) { return\
    \ range_sum(1, 0, n, l, r); }\n\n  void build(int k, int l, int r, const vector<long\
    \ long>& v) {\n    len[k] = r - l;\n    if (r - l == 1) {\n      long long x =\
    \ v[l];\n      sum[k] = x;\n      max1[k] = x;\n      max2[k] = -INF;\n      maxc[k]\
    \ = 1;\n      min1[k] = x;\n      min2[k] = INF;\n      minc[k] = 1;\n      return;\n\
    \    }\n    int m = (l + r) >> 1;\n    build(k << 1, l, m, v);\n    build(k <<\
    \ 1 | 1, m, r, v);\n    pull(k);\n  }\n\n  void apply_add(int k, long long x)\
    \ {\n    sum[k] += x * (long long)len[k];\n    max1[k] += x;\n    if (max2[k]\
    \ != -INF) max2[k] += x;\n    min1[k] += x;\n    if (min2[k] != INF) min2[k] +=\
    \ x;\n    add[k] += x;\n  }\n\n  void apply_chmin(int k, long long x) {\n    if\
    \ (max1[k] <= x) return;\n    sum[k] += (x - max1[k]) * (long long)maxc[k];\n\
    \    if (min1[k] == max1[k]) min1[k] = x;\n    else if (min2[k] == max1[k]) min2[k]\
    \ = x;\n    max1[k] = x;\n  }\n\n  void apply_chmax(int k, long long x) {\n  \
    \  if (min1[k] >= x) return;\n    sum[k] += (x - min1[k]) * (long long)minc[k];\n\
    \    if (max1[k] == min1[k]) max1[k] = x;\n    else if (max2[k] == min1[k]) max2[k]\
    \ = x;\n    min1[k] = x;\n  }\n\n  void push(int k) {\n    if (len[k] == 1) return;\n\
    \    if (add[k] != 0) {\n      apply_add(k << 1, add[k]);\n      apply_add(k <<\
    \ 1 | 1, add[k]);\n      add[k] = 0;\n    }\n    if (max1[k] < max1[k << 1]) apply_chmin(k\
    \ << 1, max1[k]);\n    if (max1[k] < max1[k << 1 | 1]) apply_chmin(k << 1 | 1,\
    \ max1[k]);\n    if (min1[k] > min1[k << 1]) apply_chmax(k << 1, min1[k]);\n \
    \   if (min1[k] > min1[k << 1 | 1]) apply_chmax(k << 1 | 1, min1[k]);\n  }\n\n\
    \  void pull(int k) {\n    int l = k << 1;\n    int r = k << 1 | 1;\n    sum[k]\
    \ = sum[l] + sum[r];\n\n    if (max1[l] > max1[r]) {\n      max1[k] = max1[l];\n\
    \      maxc[k] = maxc[l];\n      max2[k] = max(max2[l], max1[r]);\n    } else\
    \ if (max1[l] < max1[r]) {\n      max1[k] = max1[r];\n      maxc[k] = maxc[r];\n\
    \      max2[k] = max(max1[l], max2[r]);\n    } else {\n      max1[k] = max1[l];\n\
    \      maxc[k] = maxc[l] + maxc[r];\n      max2[k] = max(max2[l], max2[r]);\n\
    \    }\n\n    if (min1[l] < min1[r]) {\n      min1[k] = min1[l];\n      minc[k]\
    \ = minc[l];\n      min2[k] = min(min2[l], min1[r]);\n    } else if (min1[l] >\
    \ min1[r]) {\n      min1[k] = min1[r];\n      minc[k] = minc[r];\n      min2[k]\
    \ = min(min1[l], min2[r]);\n    } else {\n      min1[k] = min1[l];\n      minc[k]\
    \ = minc[l] + minc[r];\n      min2[k] = min(min2[l], min2[r]);\n    }\n  }\n\n\
    \  void range_chmin(int k, int l, int r, int ql, int qr, long long x) {\n    if\
    \ (qr <= l || r <= ql || max1[k] <= x) return;\n    if (ql <= l && r <= qr &&\
    \ max2[k] < x) {\n      apply_chmin(k, x);\n      return;\n    }\n    push(k);\n\
    \    int m = (l + r) >> 1;\n    range_chmin(k << 1, l, m, ql, qr, x);\n    range_chmin(k\
    \ << 1 | 1, m, r, ql, qr, x);\n    pull(k);\n  }\n\n  void range_chmax(int k,\
    \ int l, int r, int ql, int qr, long long x) {\n    if (qr <= l || r <= ql ||\
    \ min1[k] >= x) return;\n    if (ql <= l && r <= qr && min2[k] > x) {\n      apply_chmax(k,\
    \ x);\n      return;\n    }\n    push(k);\n    int m = (l + r) >> 1;\n    range_chmax(k\
    \ << 1, l, m, ql, qr, x);\n    range_chmax(k << 1 | 1, m, r, ql, qr, x);\n   \
    \ pull(k);\n  }\n\n  void range_add(int k, int l, int r, int ql, int qr, long\
    \ long x) {\n    if (qr <= l || r <= ql) return;\n    if (ql <= l && r <= qr)\
    \ {\n      apply_add(k, x);\n      return;\n    }\n    push(k);\n    int m = (l\
    \ + r) >> 1;\n    range_add(k << 1, l, m, ql, qr, x);\n    range_add(k << 1 |\
    \ 1, m, r, ql, qr, x);\n    pull(k);\n  }\n\n  long long range_sum(int k, int\
    \ l, int r, int ql, int qr) {\n    if (qr <= l || r <= ql) return 0;\n    if (ql\
    \ <= l && r <= qr) return sum[k];\n    push(k);\n    int m = (l + r) >> 1;\n \
    \   return range_sum(k << 1, l, m, ql, qr) +\n           range_sum(k << 1 | 1,\
    \ m, r, ql, qr);\n  }\n};\n#line 4 \"verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for (int i = 0; i\
    \ < N; i++) cin >> a[i];\n  segtreebeats seg(a);\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int l, r;\n      long\
    \ long b;\n      cin >> l >> r >> b;\n      seg.range_chmin(l, r, b);\n    } else\
    \ if (t == 1) {\n      int l, r;\n      long long b;\n      cin >> l >> r >> b;\n\
    \      seg.range_chmax(l, r, b);\n    } else if (t == 2) {\n      int l, r;\n\
    \      long long b;\n      cin >> l >> r >> b;\n      seg.range_add(l, r, b);\n\
    \    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.range_sum(l,\
    \ r) << \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"structure/segtreebeats.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n  for (int i = 0; i\
    \ < N; i++) cin >> a[i];\n  segtreebeats seg(a);\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int l, r;\n      long\
    \ long b;\n      cin >> l >> r >> b;\n      seg.range_chmin(l, r, b);\n    } else\
    \ if (t == 1) {\n      int l, r;\n      long long b;\n      cin >> l >> r >> b;\n\
    \      seg.range_chmax(l, r, b);\n    } else if (t == 2) {\n      int l, r;\n\
    \      long long b;\n      cin >> l >> r >> b;\n      seg.range_add(l, r, b);\n\
    \    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.range_sum(l,\
    \ r) << \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/segtreebeats.hpp
  isVerificationFile: true
  path: verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-12 00:53:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp
- /verify/verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp.html
title: verify/yosupo_range_chmin_chmax_add_range_sum.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/yosupo_static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"structure/segtree.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct segtree {\n  int n;\n  int sz;\n  int lg;\n  vector<S>\
    \ d;\n  segtree() : n(0), sz(1), lg(0), d(1, e()) {}\n  segtree(int n_) { init(n_);\
    \ }\n  segtree(const vector<S>& v) { build(v); }\n  void init(int n_) {\n    n\
    \ = n_;\n    sz = 1;\n    lg = 0;\n    while (sz < n) {\n      sz <<= 1;\n   \
    \   lg++;\n    }\n    d.assign(2 * sz, e());\n  }\n  void build(const vector<S>&\
    \ v) {\n    init((int)v.size());\n    for (int i = 0; i < n; i++) d[sz + i] =\
    \ v[i];\n    for (int i = sz - 1; i >= 1; i--) d[i] = op(d[i << 1], d[i << 1 |\
    \ 1]);\n  }\n  void set(int p, S x) {\n    p += sz;\n    d[p] = x;\n    for (int\
    \ i = 1; i <= lg; i++) {\n      int k = p >> i;\n      d[k] = op(d[k << 1], d[k\
    \ << 1 | 1]);\n    }\n  }\n  S get(int p) const { return d[p + sz]; }\n  S prod(int\
    \ l, int r) const {\n    S sml = e();\n    S smr = e();\n    l += sz;\n    r +=\
    \ sz;\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n      if\
    \ (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n    return\
    \ op(sml, smr);\n  }\n  S all_prod() const { return d[1]; }\n  template <class\
    \ F>\n  int max_right(int l, F f) const {\n    if (l == n) return n;\n    S sm\
    \ = e();\n    l += sz;\n    do {\n      while ((l & 1) == 0) l >>= 1;\n      if\
    \ (!f(op(sm, d[l]))) {\n        while (l < sz) {\n          l <<= 1;\n       \
    \   if (f(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n            l++;\n\
    \          }\n        }\n        return l - sz;\n      }\n      sm = op(sm, d[l]);\n\
    \      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n  template <class\
    \ F>\n  int min_left(int r, F f) const {\n    if (r == 0) return 0;\n    S sm\
    \ = e();\n    r += sz;\n    do {\n      r--;\n      while (r > 1 && (r & 1)) r\
    \ >>= 1;\n      if (!f(op(d[r], sm))) {\n        while (r < sz) {\n          r\
    \ = r << 1 | 1;\n          if (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n\
    \            r--;\n          }\n        }\n        return r + 1 - sz;\n      }\n\
    \      sm = op(d[r], sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\
    };\n#line 3 \"verify/yosupo_static_range_sum.test.cpp\"\n\nusing ll = long long;\n\
    \nll op(ll a, ll b) { return a + b; }\nll e() { return 0; }\n\nint main() {\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int n, q;\n  if (!(cin\
    \ >> n >> q)) return 0;\n  vector<ll> a(n);\n  for (int i = 0; i < n; i++) cin\
    \ >> a[i];\n  segtree<ll, op, e> seg(a);\n  while (q--) {\n    int l, r;\n   \
    \ cin >> l >> r;\n    cout << seg.prod(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"structure/segtree.hpp\"\n\nusing ll = long long;\n\nll op(ll a, ll b) { return\
    \ a + b; }\nll e() { return 0; }\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int n, q;\n  if (!(cin >> n >> q)) return 0;\n  vector<ll>\
    \ a(n);\n  for (int i = 0; i < n; i++) cin >> a[i];\n  segtree<ll, op, e> seg(a);\n\
    \  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << seg.prod(l, r)\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/segtree.hpp
  isVerificationFile: true
  path: verify/yosupo_static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 05:17:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_static_range_sum.test.cpp
- /verify/verify/yosupo_static_range_sum.test.cpp.html
title: verify/yosupo_static_range_sum.test.cpp
---

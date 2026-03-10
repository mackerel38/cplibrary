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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 2 \"structure/segtree.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct segtree {\n  int n;\n  int size;\n  vector<S> d;\n\n \
    \ segtree() : n(0), size(1), d(1, e()) {}\n  segtree(int n_) { init(n_); }\n \
    \ segtree(const vector<S>& v) { build(v); }\n\n  void init(int n_) {\n    n =\
    \ n_;\n    size = 1;\n    while (size < n) size <<= 1;\n    d.assign(2 * size,\
    \ e());\n  }\n\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[size + i] = v[i];\n    for (int i = size -\
    \ 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i + 1]);\n  }\n\n  void set(int p,\
    \ S x) {\n    int i = p + size;\n    d[i] = x;\n    while (i > 1) {\n      i >>=\
    \ 1;\n      d[i] = op(d[2 * i], d[2 * i + 1]);\n    }\n  }\n\n  S get(int p) const\
    \ { return d[p + size]; }\n\n  S prod(int l, int r) const {\n    S sml = e(),\
    \ smr = e();\n    int left = l + size, right = r + size;\n    while (left < right)\
    \ {\n      if (left & 1) sml = op(sml, d[left++]);\n      if (right & 1) smr =\
    \ op(d[--right], smr);\n      left >>= 1;\n      right >>= 1;\n    }\n    return\
    \ op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n};\n#line 3 \"\
    verify/yosupo_point_add_range_sum.test.cpp\"\n\nusing ll = long long;\n\nll op(ll\
    \ a, ll b) { return a + b; }\nll e() { return 0; }\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n, q;\n  if (!(cin >> n >> q)) return 0;\n  vector<ll>\
    \ a(n);\n  for (int i = 0; i < n; i++) cin >> a[i];\n  segtree<ll, op, e> seg(a);\n\
    \  for (int i = 0; i < q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n\
    \      int p;\n      ll x;\n      cin >> p >> x;\n      seg.set(p, seg.get(p)\
    \ + x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.prod(l,\
    \ r) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../structure/segtree.hpp\"\n\nusing ll = long long;\n\nll op(ll a,\
    \ ll b) { return a + b; }\nll e() { return 0; }\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n, q;\n  if (!(cin >> n >> q)) return 0;\n  vector<ll>\
    \ a(n);\n  for (int i = 0; i < n; i++) cin >> a[i];\n  segtree<ll, op, e> seg(a);\n\
    \  for (int i = 0; i < q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n\
    \      int p;\n      ll x;\n      cin >> p >> x;\n      seg.set(p, seg.get(p)\
    \ + x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.prod(l,\
    \ r) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/segtree.hpp
  isVerificationFile: true
  path: verify/yosupo_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 03:11:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_point_add_range_sum.test.cpp
- /verify/verify/yosupo_point_add_range_sum.test.cpp.html
title: verify/yosupo_point_add_range_sum.test.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_set_range_composite.test.cpp
    title: verify/yosupo_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_static_range_sum.test.cpp
    title: verify/yosupo_static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct segtree\
    \ {\n  int n;\n  int sz;\n  int lg;\n  vector<S> d;\n  segtree() : n(0), sz(1),\
    \ lg(0), d(1, e()) {}\n  segtree(int n_) { init(n_); }\n  segtree(const vector<S>&\
    \ v) { build(v); }\n  void init(int n_) {\n    n = n_;\n    sz = 1;\n    lg =\
    \ 0;\n    while (sz < n) {\n      sz <<= 1;\n      lg++;\n    }\n    d.assign(2\
    \ * sz, e());\n  }\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[sz + i] = v[i];\n    for (int i = sz - 1; i\
    \ >= 1; i--) d[i] = op(d[i << 1], d[i << 1 | 1]);\n  }\n  void set(int p, S x)\
    \ {\n    p += sz;\n    d[p] = x;\n    for (int i = 1; i <= lg; i++) {\n      int\
    \ k = p >> i;\n      d[k] = op(d[k << 1], d[k << 1 | 1]);\n    }\n  }\n  S get(int\
    \ p) const { return d[p + sz]; }\n  S prod(int l, int r) const {\n    S sml =\
    \ e();\n    S smr = e();\n    l += sz;\n    r += sz;\n    while (l < r) {\n  \
    \    if (l & 1) sml = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r], smr);\n\
    \      l >>= 1;\n      r >>= 1;\n    }\n    return op(sml, smr);\n  }\n  S all_prod()\
    \ const { return d[1]; }\n  template <class F>\n  int max_right(int l, F f) const\
    \ {\n    if (l == n) return n;\n    S sm = e();\n    l += sz;\n    do {\n    \
    \  while ((l & 1) == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while\
    \ (l < sz) {\n          l <<= 1;\n          if (f(op(sm, d[l]))) {\n         \
    \   sm = op(sm, d[l]);\n            l++;\n          }\n        }\n        return\
    \ l - sz;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return n;\n  }\n  template <class F>\n  int min_left(int r, F f)\
    \ const {\n    if (r == 0) return 0;\n    S sm = e();\n    r += sz;\n    do {\n\
    \      r--;\n      while (r > 1 && (r & 1)) r >>= 1;\n      if (!f(op(d[r], sm)))\
    \ {\n        while (r < sz) {\n          r = r << 1 | 1;\n          if (f(op(d[r],\
    \ sm))) {\n            sm = op(d[r], sm);\n            r--;\n          }\n   \
    \     }\n        return r + 1 - sz;\n      }\n      sm = op(d[r], sm);\n    }\
    \ while ((r & -r) != r);\n    return 0;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n  int n;\n  int sz;\n\
    \  int lg;\n  vector<S> d;\n  segtree() : n(0), sz(1), lg(0), d(1, e()) {}\n \
    \ segtree(int n_) { init(n_); }\n  segtree(const vector<S>& v) { build(v); }\n\
    \  void init(int n_) {\n    n = n_;\n    sz = 1;\n    lg = 0;\n    while (sz <\
    \ n) {\n      sz <<= 1;\n      lg++;\n    }\n    d.assign(2 * sz, e());\n  }\n\
    \  void build(const vector<S>& v) {\n    init((int)v.size());\n    for (int i\
    \ = 0; i < n; i++) d[sz + i] = v[i];\n    for (int i = sz - 1; i >= 1; i--) d[i]\
    \ = op(d[i << 1], d[i << 1 | 1]);\n  }\n  void set(int p, S x) {\n    p += sz;\n\
    \    d[p] = x;\n    for (int i = 1; i <= lg; i++) {\n      int k = p >> i;\n \
    \     d[k] = op(d[k << 1], d[k << 1 | 1]);\n    }\n  }\n  S get(int p) const {\
    \ return d[p + sz]; }\n  S prod(int l, int r) const {\n    S sml = e();\n    S\
    \ smr = e();\n    l += sz;\n    r += sz;\n    while (l < r) {\n      if (l & 1)\
    \ sml = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r], smr);\n      l >>=\
    \ 1;\n      r >>= 1;\n    }\n    return op(sml, smr);\n  }\n  S all_prod() const\
    \ { return d[1]; }\n  template <class F>\n  int max_right(int l, F f) const {\n\
    \    if (l == n) return n;\n    S sm = e();\n    l += sz;\n    do {\n      while\
    \ ((l & 1) == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < sz)\
    \ {\n          l <<= 1;\n          if (f(op(sm, d[l]))) {\n            sm = op(sm,\
    \ d[l]);\n            l++;\n          }\n        }\n        return l - sz;\n \
    \     }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n\
    \    return n;\n  }\n  template <class F>\n  int min_left(int r, F f) const {\n\
    \    if (r == 0) return 0;\n    S sm = e();\n    r += sz;\n    do {\n      r--;\n\
    \      while (r > 1 && (r & 1)) r >>= 1;\n      if (!f(op(d[r], sm))) {\n    \
    \    while (r < sz) {\n          r = r << 1 | 1;\n          if (f(op(d[r], sm)))\
    \ {\n            sm = op(d[r], sm);\n            r--;\n          }\n        }\n\
    \        return r + 1 - sz;\n      }\n      sm = op(d[r], sm);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 04:15:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_set_range_composite.test.cpp
  - verify/yosupo_static_range_sum.test.cpp
documentation_of: //structure/segtree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

Definition
区間に対する結合演算を扱うセグメント木。

Complexity
更新: O(log N)
区間クエリ: O(log N)

概要
モノイドに対して区間クエリと更新を行う。

使い方
`segtree<S, op, e> seg(n);` でサイズ n を作る。
`segtree<S, op, e> seg(v);` で配列 v から構築する。
`seg.init(n);` で再初期化する。
`seg.build(v);` で配列 v から再構築する。
`seg.set(p, x);` で位置 p を x に更新する。
`seg.get(p);` で位置 p の値を取得する。
`seg.prod(l, r);` で [l, r) の積を取得する。
`seg.all_prod();` で全区間の積を取得する。
`seg.max_right(l, f);` は `f(op(a[l],...,a[r-1]))` が true を保つ最大の r を返す。
`seg.min_left(r, f);` は `f(op(a[l],...,a[r-1]))` が true を保つ最小の l を返す。
`f(e())` が true であり、単調性が必要。

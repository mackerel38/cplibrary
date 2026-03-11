---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: structure/range_affine_range_sum.hpp
    title: Range Affine Range Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_affine_point_get.test.cpp
    title: verify/yosupo_range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_affine_range_sum.test.cpp
    title: verify/yosupo_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/lazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nstruct lazysegtree\
    \ {\n  int n;\n  int sz;\n  int lg;\n  vector<S> d;\n  vector<F> lz;\n\n  lazysegtree()\
    \ : n(0), sz(1), lg(0) {\n    d.assign(1, e());\n    lz.assign(1, id());\n  }\n\
    \  lazysegtree(int n_) { init(n_); }\n  lazysegtree(const vector<S>& v) { build(v);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    sz = 1;\n    lg = 0;\n    while\
    \ (sz < n) {\n      sz <<= 1;\n      lg++;\n    }\n    d.assign(2 * sz, e());\n\
    \    lz.assign(sz, id());\n  }\n\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[sz + i] = v[i];\n    for (int i = sz - 1; i\
    \ >= 1; i--) update(i);\n  }\n\n  void set(int p, S x) {\n    p += sz;\n    for\
    \ (int i = lg; i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int i = 1;\
    \ i <= lg; i++) update(p >> i);\n  }\n\n  S get(int p) {\n    p += sz;\n    for\
    \ (int i = lg; i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n\n  S prod(int\
    \ l, int r) {\n    if (l == r) return e();\n    l += sz;\n    r += sz;\n    for\
    \ (int i = lg; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    S sml = e();\n\
    \    S smr = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void\
    \ apply(int p, F f) {\n    p += sz;\n    for (int i = lg; i >= 1; i--) push(p\
    \ >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n  }\n\n  void apply(int l, int r, F f) {\n    if (l == r) return;\n\
    \    l += sz;\n    r += sz;\n    for (int i = lg; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l;\n    int r2 = r;\n    while (l < r) {\n     \
    \ if (l & 1) all_apply(l++, f);\n      if (r & 1) all_apply(--r, f);\n      l\
    \ >>= 1;\n      r >>= 1;\n    }\n    l = l2;\n    r = r2;\n    for (int i = 1;\
    \ i <= lg; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  void update(int k)\
    \ { d[k] = op(d[k << 1], d[k << 1 | 1]); }\n\n  void all_apply(int k, F f) {\n\
    \    d[k] = mapping(f, d[k]);\n    if (k < sz) lz[k] = composition(f, lz[k]);\n\
    \  }\n\n  void push(int k) {\n    all_apply(k << 1, lz[k]);\n    all_apply(k <<\
    \ 1 | 1, lz[k]);\n    lz[k] = id();\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\nstruct lazysegtree {\n  int n;\n  int sz;\n\
    \  int lg;\n  vector<S> d;\n  vector<F> lz;\n\n  lazysegtree() : n(0), sz(1),\
    \ lg(0) {\n    d.assign(1, e());\n    lz.assign(1, id());\n  }\n  lazysegtree(int\
    \ n_) { init(n_); }\n  lazysegtree(const vector<S>& v) { build(v); }\n\n  void\
    \ init(int n_) {\n    n = n_;\n    sz = 1;\n    lg = 0;\n    while (sz < n) {\n\
    \      sz <<= 1;\n      lg++;\n    }\n    d.assign(2 * sz, e());\n    lz.assign(sz,\
    \ id());\n  }\n\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[sz + i] = v[i];\n    for (int i = sz - 1; i\
    \ >= 1; i--) update(i);\n  }\n\n  void set(int p, S x) {\n    p += sz;\n    for\
    \ (int i = lg; i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int i = 1;\
    \ i <= lg; i++) update(p >> i);\n  }\n\n  S get(int p) {\n    p += sz;\n    for\
    \ (int i = lg; i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n\n  S prod(int\
    \ l, int r) {\n    if (l == r) return e();\n    l += sz;\n    r += sz;\n    for\
    \ (int i = lg; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    S sml = e();\n\
    \    S smr = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void\
    \ apply(int p, F f) {\n    p += sz;\n    for (int i = lg; i >= 1; i--) push(p\
    \ >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n  }\n\n  void apply(int l, int r, F f) {\n    if (l == r) return;\n\
    \    l += sz;\n    r += sz;\n    for (int i = lg; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l;\n    int r2 = r;\n    while (l < r) {\n     \
    \ if (l & 1) all_apply(l++, f);\n      if (r & 1) all_apply(--r, f);\n      l\
    \ >>= 1;\n      r >>= 1;\n    }\n    l = l2;\n    r = r2;\n    for (int i = 1;\
    \ i <= lg; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  void update(int k)\
    \ { d[k] = op(d[k << 1], d[k << 1 | 1]); }\n\n  void all_apply(int k, F f) {\n\
    \    d[k] = mapping(f, d[k]);\n    if (k < sz) lz[k] = composition(f, lz[k]);\n\
    \  }\n\n  void push(int k) {\n    all_apply(k << 1, lz[k]);\n    all_apply(k <<\
    \ 1 | 1, lz[k]);\n    lz[k] = id();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazysegtree.hpp
  requiredBy:
  - structure/range_affine_range_sum.hpp
  timestamp: '2026-03-11 18:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_range_affine_point_get.test.cpp
  - verify/yosupo_range_affine_range_sum.test.cpp
documentation_of: //structure/lazysegtree.hpp
layout: document
title: Lazy Segment Tree
---

Definition
遅延伝搬付きセグメント木。区間更新と区間取得を扱う。

Complexity
各操作は O(log N)。

ポイント
- 区間更新と区間取得を同時に扱える
- 作用素の合成と単位元を用意する
- `mapping` と `composition` の設計が肝

使い方

- `lazysegtree<S, op, e, F, mapping, composition, id> seg(n);` で作成する。
- `seg.init(n);` で再初期化する。
- `seg.build(v);` で配列 v から構築する。
- `seg.set(p, x);` で位置 p の値を x に更新する。
- `seg.get(p);` で位置 p の値を取得する。
- `seg.prod(l, r);` で [l, r) の区間積を取得する。
- `seg.all_prod();` で全区間の積を取得する。
- `seg.apply(p, f);` で位置 p に作用素 f を適用する。
- `seg.apply(l, r, f);` で [l, r) に作用素 f を適用する。
- `mapping(f, x)` は要素 x に作用素 f を適用した結果を返す。
- `composition(f, g)` は作用素 g の後に f を適用した合成を返す。
- `id()` は作用素の単位元。
- `update`, `all_apply`, `push` は内部用の補助関数。

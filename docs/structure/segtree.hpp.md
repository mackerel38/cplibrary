---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum.test.cpp
    title: verify/yosupo_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct segtree\
    \ {\n  int n;\n  int size;\n  vector<S> d;\n\n  segtree() : n(0), size(1), d(1,\
    \ e()) {}\n  segtree(int n_) { init(n_); }\n  segtree(const vector<S>& v) { build(v);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    size = 1;\n    while (size < n)\
    \ size <<= 1;\n    d.assign(2 * size, e());\n  }\n\n  void build(const vector<S>&\
    \ v) {\n    init((int)v.size());\n    for (int i = 0; i < n; i++) d[size + i]\
    \ = v[i];\n    for (int i = size - 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i\
    \ + 1]);\n  }\n\n  void set(int p, S x) {\n    int i = p + size;\n    d[i] = x;\n\
    \    while (i > 1) {\n      i >>= 1;\n      d[i] = op(d[2 * i], d[2 * i + 1]);\n\
    \    }\n  }\n\n  S get(int p) const { return d[p + size]; }\n\n  S prod(int l,\
    \ int r) const {\n    S sml = e(), smr = e();\n    int left = l + size, right\
    \ = r + size;\n    while (left < right) {\n      if (left & 1) sml = op(sml, d[left++]);\n\
    \      if (right & 1) smr = op(d[--right], smr);\n      left >>= 1;\n      right\
    \ >>= 1;\n    }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return\
    \ d[1]; }\n\n  template <class F>\n  int max_right(int l, F f) const {\n    if\
    \ (l == n) return n;\n    S sm = e();\n    int i = l + size;\n    do {\n     \
    \ while ((i & 1) == 0) i >>= 1;\n      if (!f(op(sm, d[i]))) {\n        while\
    \ (i < size) {\n          i <<= 1;\n          if (f(op(sm, d[i]))) {\n       \
    \     sm = op(sm, d[i]);\n            i++;\n          }\n        }\n        return\
    \ i - size;\n      }\n      sm = op(sm, d[i]);\n      i++;\n    } while ((i &\
    \ -i) != i);\n    return n;\n  }\n\n  template <class F>\n  int min_left(int r,\
    \ F f) const {\n    if (r == 0) return 0;\n    S sm = e();\n    int i = r + size;\n\
    \    do {\n      i--;\n      while (i > 1 && (i & 1)) i >>= 1;\n      if (!f(op(d[i],\
    \ sm))) {\n        while (i < size) {\n          i = i * 2 + 1;\n          if\
    \ (f(op(d[i], sm))) {\n            sm = op(d[i], sm);\n            i--;\n    \
    \      }\n        }\n        return i + 1 - size;\n      }\n      sm = op(d[i],\
    \ sm);\n    } while ((i & -i) != i);\n    return 0;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n  int n;\n  int size;\n\
    \  vector<S> d;\n\n  segtree() : n(0), size(1), d(1, e()) {}\n  segtree(int n_)\
    \ { init(n_); }\n  segtree(const vector<S>& v) { build(v); }\n\n  void init(int\
    \ n_) {\n    n = n_;\n    size = 1;\n    while (size < n) size <<= 1;\n    d.assign(2\
    \ * size, e());\n  }\n\n  void build(const vector<S>& v) {\n    init((int)v.size());\n\
    \    for (int i = 0; i < n; i++) d[size + i] = v[i];\n    for (int i = size -\
    \ 1; i >= 1; i--) d[i] = op(d[2 * i], d[2 * i + 1]);\n  }\n\n  void set(int p,\
    \ S x) {\n    int i = p + size;\n    d[i] = x;\n    while (i > 1) {\n      i >>=\
    \ 1;\n      d[i] = op(d[2 * i], d[2 * i + 1]);\n    }\n  }\n\n  S get(int p) const\
    \ { return d[p + size]; }\n\n  S prod(int l, int r) const {\n    S sml = e(),\
    \ smr = e();\n    int left = l + size, right = r + size;\n    while (left < right)\
    \ {\n      if (left & 1) sml = op(sml, d[left++]);\n      if (right & 1) smr =\
    \ op(d[--right], smr);\n      left >>= 1;\n      right >>= 1;\n    }\n    return\
    \ op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n  template <class\
    \ F>\n  int max_right(int l, F f) const {\n    if (l == n) return n;\n    S sm\
    \ = e();\n    int i = l + size;\n    do {\n      while ((i & 1) == 0) i >>= 1;\n\
    \      if (!f(op(sm, d[i]))) {\n        while (i < size) {\n          i <<= 1;\n\
    \          if (f(op(sm, d[i]))) {\n            sm = op(sm, d[i]);\n          \
    \  i++;\n          }\n        }\n        return i - size;\n      }\n      sm =\
    \ op(sm, d[i]);\n      i++;\n    } while ((i & -i) != i);\n    return n;\n  }\n\
    \n  template <class F>\n  int min_left(int r, F f) const {\n    if (r == 0) return\
    \ 0;\n    S sm = e();\n    int i = r + size;\n    do {\n      i--;\n      while\
    \ (i > 1 && (i & 1)) i >>= 1;\n      if (!f(op(d[i], sm))) {\n        while (i\
    \ < size) {\n          i = i * 2 + 1;\n          if (f(op(d[i], sm))) {\n    \
    \        sm = op(d[i], sm);\n            i--;\n          }\n        }\n      \
    \  return i + 1 - size;\n      }\n      sm = op(d[i], sm);\n    } while ((i &\
    \ -i) != i);\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy: []
  timestamp: '2026-03-11 03:38:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_add_range_sum.test.cpp
documentation_of: //structure/segtree.hpp
layout: document
redirect_from:
- /library/structure/segtree.hpp
- /library/structure/segtree.hpp.html
title: structure/segtree.hpp
---

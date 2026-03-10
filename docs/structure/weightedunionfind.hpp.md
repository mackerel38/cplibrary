---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential.test.cpp
    title: verify/yosupo_unionfind_with_potential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/weightedunionfind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, class Op>\nstruct weighted_unionfind\
    \ {\n  int n;\n  vector<int> p;\n  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind()\
    \ : n(0) {}\n  weighted_unionfind(int n_) { init(n_); }\n\n  void init(int n_)\
    \ {\n    n = n_;\n    p.resize(n);\n    sz.assign(n, 1);\n    w.assign(n, Op::id());\n\
    \    iota(p.begin(), p.end(), 0);\n  }\n\n  T add(T a, T b) { return Op::op(a,\
    \ b); }\n  T sub(T a, T b) { return Op::op(a, Op::inv(b)); }\n\n  int leader(int\
    \ x) {\n    if (p[x] == x) return x;\n    int r = leader(p[x]);\n    w[x] = add(w[x],\
    \ w[p[x]]);\n    return p[x] = r;\n  }\n\n  T weight(int x) {\n    leader(x);\n\
    \    return w[x];\n  }\n\n  bool same(int a, int b) { return leader(a) == leader(b);\
    \ }\n\n  T diff(int a, int b) { return sub(weight(a), weight(b)); }\n\n  bool\
    \ get(int a, int b, T &out) {\n    if (!same(a, b)) return false;\n    out = diff(a,\
    \ b);\n    return true;\n  }\n\n  bool merge(int a, int b, T x) {\n    int ra\
    \ = leader(a);\n    int rb = leader(b);\n    T wa = w[a];\n    T wb = w[b];\n\
    \    if (ra == rb) return sub(wa, wb) == x;\n    if (sz[ra] < sz[rb]) {\n    \
    \  p[ra] = rb;\n      sz[rb] += sz[ra];\n      w[ra] = sub(add(wb, x), wa);\n\
    \    } else {\n      p[rb] = ra;\n      sz[ra] += sz[rb];\n      w[rb] = sub(sub(wa,\
    \ wb), x);\n    }\n    return true;\n  }\n\n  int size(int x) { return sz[leader(x)];\
    \ }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, class Op>\nstruct weighted_unionfind {\n  int n;\n  vector<int> p;\n\
    \  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind() : n(0) {}\n  weighted_unionfind(int\
    \ n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n    p.resize(n);\n\
    \    sz.assign(n, 1);\n    w.assign(n, Op::id());\n    iota(p.begin(), p.end(),\
    \ 0);\n  }\n\n  T add(T a, T b) { return Op::op(a, b); }\n  T sub(T a, T b) {\
    \ return Op::op(a, Op::inv(b)); }\n\n  int leader(int x) {\n    if (p[x] == x)\
    \ return x;\n    int r = leader(p[x]);\n    w[x] = add(w[x], w[p[x]]);\n    return\
    \ p[x] = r;\n  }\n\n  T weight(int x) {\n    leader(x);\n    return w[x];\n  }\n\
    \n  bool same(int a, int b) { return leader(a) == leader(b); }\n\n  T diff(int\
    \ a, int b) { return sub(weight(a), weight(b)); }\n\n  bool get(int a, int b,\
    \ T &out) {\n    if (!same(a, b)) return false;\n    out = diff(a, b);\n    return\
    \ true;\n  }\n\n  bool merge(int a, int b, T x) {\n    int ra = leader(a);\n \
    \   int rb = leader(b);\n    T wa = w[a];\n    T wb = w[b];\n    if (ra == rb)\
    \ return sub(wa, wb) == x;\n    if (sz[ra] < sz[rb]) {\n      p[ra] = rb;\n  \
    \    sz[rb] += sz[ra];\n      w[ra] = sub(add(wb, x), wa);\n    } else {\n   \
    \   p[rb] = ra;\n      sz[ra] += sz[rb];\n      w[rb] = sub(sub(wa, wb), x);\n\
    \    }\n    return true;\n  }\n\n  int size(int x) { return sz[leader(x)]; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/weightedunionfind.hpp
  requiredBy: []
  timestamp: '2026-03-11 06:11:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_unionfind_with_potential.test.cpp
documentation_of: //structure/weightedunionfind.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union-Find"
---

Definition
重み付き Union-Find は各要素にポテンシャルを持たせ、同一連結成分内での差分を扱える素集合データ構造。要素 u, v と値 x に対して a_u = a_v + x を統合し、既存の情報と矛盾しないか判定できる。連結であれば a_u - a_v を取得できる。

Complexity
各操作はならし O(\u03b1(n))。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind.test.cpp
    title: verify/yosupo_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/unionfind.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct unionfind {\n  int n;\n  vector<int> p;\n  vector<int>\
    \ sz;\n\n  unionfind() : n(0) {}\n  unionfind(int n_) { init(n_); }\n\n  void\
    \ init(int n_) {\n    n = n_;\n    p.resize(n);\n    sz.assign(n, 1);\n    iota(p.begin(),\
    \ p.end(), 0);\n  }\n\n  int leader(int x) {\n    if (p[x] == x) return x;\n \
    \   return p[x] = leader(p[x]);\n  }\n\n  bool same(int a, int b) { return leader(a)\
    \ == leader(b); }\n\n  bool merge(int a, int b) {\n    a = leader(a);\n    b =\
    \ leader(b);\n    if (a == b) return false;\n    if (sz[a] < sz[b]) swap(a, b);\n\
    \    p[b] = a;\n    sz[a] += sz[b];\n    return true;\n  }\n\n  int size(int x)\
    \ { return sz[leader(x)]; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct unionfind\
    \ {\n  int n;\n  vector<int> p;\n  vector<int> sz;\n\n  unionfind() : n(0) {}\n\
    \  unionfind(int n_) { init(n_); }\n\n  void init(int n_) {\n    n = n_;\n   \
    \ p.resize(n);\n    sz.assign(n, 1);\n    iota(p.begin(), p.end(), 0);\n  }\n\n\
    \  int leader(int x) {\n    if (p[x] == x) return x;\n    return p[x] = leader(p[x]);\n\
    \  }\n\n  bool same(int a, int b) { return leader(a) == leader(b); }\n\n  bool\
    \ merge(int a, int b) {\n    a = leader(a);\n    b = leader(b);\n    if (a ==\
    \ b) return false;\n    if (sz[a] < sz[b]) swap(a, b);\n    p[b] = a;\n    sz[a]\
    \ += sz[b];\n    return true;\n  }\n\n  int size(int x) { return sz[leader(x)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/unionfind.hpp
  requiredBy: []
  timestamp: '2026-03-11 06:01:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_unionfind.test.cpp
documentation_of: //structure/unionfind.hpp
layout: document
title: Union-Find
---

Definition
Union-Find は素集合データ構造であり、連結判定と併合を提供する。

Complexity
各操作はならし O(α(n))。

使い方

- `unionfind uf(n);` で要素数 n の集合を作る。
- `uf.init(n);` で再初期化する。
- `uf.leader(x);` で x の代表元を返す。
- `uf.same(a, b);` で同一集合か判定する。
- `uf.merge(a, b);` で併合し、成功なら true を返す。
- `uf.size(x);` で x が属する集合のサイズを返す。

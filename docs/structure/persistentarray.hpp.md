---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/persistentarray.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T>\nstruct persistent_array {\n  struct\
    \ node {\n    T val;\n    int l;\n    int r;\n  };\n\n  long long n;\n  T def;\n\
    \  vector<node> nd;\n  vector<int> root;\n\n  persistent_array() : n(0), def(T())\
    \ {}\n  persistent_array(long long n_, T def_ = T()) { init(n_, def_); }\n  persistent_array(const\
    \ vector<T>& v, T def_ = T()) { build(v, def_); }\n\n  void init(long long n_,\
    \ T def_ = T()) {\n    n = n_;\n    def = def_;\n    nd.clear();\n    root.clear();\n\
    \    root.push_back(-1);\n  }\n\n  void build(const vector<T>& v, T def_ = T())\
    \ {\n    init((long long)v.size(), def_);\n    for (long long i = 0; i < (long\
    \ long)v.size(); i++) set(0, i, v[i]);\n  }\n\n  int set(int ver, long long p,\
    \ T x) {\n    int nr = set(root[ver], 0, n, p, x);\n    root.push_back(nr);\n\
    \    return (int)root.size() - 1;\n  }\n\n  T get(int ver, long long p) { return\
    \ get(root[ver], 0, n, p); }\n\n  int new_node(T val, int l, int r) {\n    nd.push_back({val,\
    \ l, r});\n    return (int)nd.size() - 1;\n  }\n\n  int set(int v, long long l,\
    \ long long r, long long p, T x) {\n    if (r - l == 1) return new_node(x, -1,\
    \ -1);\n    long long m = (l + r) >> 1;\n    int nl = -1, nr = -1;\n    if (v\
    \ != -1) {\n      nl = nd[v].l;\n      nr = nd[v].r;\n    }\n    if (p < m) {\n\
    \      nl = set(nl, l, m, p, x);\n    } else {\n      nr = set(nr, m, r, p, x);\n\
    \    }\n    return new_node(def, nl, nr);\n  }\n\n  T get(int v, long long l,\
    \ long long r, long long p) {\n    if (v == -1) return def;\n    if (r - l ==\
    \ 1) return nd[v].val;\n    long long m = (l + r) >> 1;\n    if (p < m) return\
    \ get(nd[v].l, l, m, p);\n    return get(nd[v].r, m, r, p);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct persistent_array {\n  struct node {\n    T val;\n    int l;\n\
    \    int r;\n  };\n\n  long long n;\n  T def;\n  vector<node> nd;\n  vector<int>\
    \ root;\n\n  persistent_array() : n(0), def(T()) {}\n  persistent_array(long long\
    \ n_, T def_ = T()) { init(n_, def_); }\n  persistent_array(const vector<T>& v,\
    \ T def_ = T()) { build(v, def_); }\n\n  void init(long long n_, T def_ = T())\
    \ {\n    n = n_;\n    def = def_;\n    nd.clear();\n    root.clear();\n    root.push_back(-1);\n\
    \  }\n\n  void build(const vector<T>& v, T def_ = T()) {\n    init((long long)v.size(),\
    \ def_);\n    for (long long i = 0; i < (long long)v.size(); i++) set(0, i, v[i]);\n\
    \  }\n\n  int set(int ver, long long p, T x) {\n    int nr = set(root[ver], 0,\
    \ n, p, x);\n    root.push_back(nr);\n    return (int)root.size() - 1;\n  }\n\n\
    \  T get(int ver, long long p) { return get(root[ver], 0, n, p); }\n\n  int new_node(T\
    \ val, int l, int r) {\n    nd.push_back({val, l, r});\n    return (int)nd.size()\
    \ - 1;\n  }\n\n  int set(int v, long long l, long long r, long long p, T x) {\n\
    \    if (r - l == 1) return new_node(x, -1, -1);\n    long long m = (l + r) >>\
    \ 1;\n    int nl = -1, nr = -1;\n    if (v != -1) {\n      nl = nd[v].l;\n   \
    \   nr = nd[v].r;\n    }\n    if (p < m) {\n      nl = set(nl, l, m, p, x);\n\
    \    } else {\n      nr = set(nr, m, r, p, x);\n    }\n    return new_node(def,\
    \ nl, nr);\n  }\n\n  T get(int v, long long l, long long r, long long p) {\n \
    \   if (v == -1) return def;\n    if (r - l == 1) return nd[v].val;\n    long\
    \ long m = (l + r) >> 1;\n    if (p < m) return get(nd[v].l, l, m, p);\n    return\
    \ get(nd[v].r, m, r, p);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/persistentarray.hpp
  requiredBy: []
  timestamp: '2026-03-11 21:36:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: //structure/persistentarray.hpp
layout: document
title: "\u6C38\u7D9A\u914D\u5217"
---
Definition
過去の版を保持しながら一点更新と一点取得を行う配列。

Complexity
更新: O(log N)
取得: O(log N)

概要
更新ごとに新しい版を作り、各版に対して値の取得ができる。

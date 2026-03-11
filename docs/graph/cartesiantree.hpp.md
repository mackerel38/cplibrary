---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: structure/sparsetable.hpp
    title: Sparse Table RMQ
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_staticrmq.test.cpp
    title: verify/yosupo_staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/cartesiantree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T, class Cmp = less<T>>\nstruct cartesian_tree\
    \ {\n  int n;\n  vector<int> parent;\n  vector<int> left;\n  vector<int> right;\n\
    \  int root;\n  Cmp cmp;\n\n  cartesian_tree() : n(0), root(-1), cmp() {}\n  cartesian_tree(const\
    \ vector<T>& a, Cmp cmp_ = Cmp()) { build(a, cmp_); }\n\n  void build(const vector<T>&\
    \ a, Cmp cmp_ = Cmp()) {\n    cmp = cmp_;\n    n = (int)a.size();\n    parent.assign(n,\
    \ -1);\n    left.assign(n, -1);\n    right.assign(n, -1);\n    vector<int> st;\n\
    \    st.reserve(n);\n    for (int i = 0; i < n; i++) {\n      int last = -1;\n\
    \      while (!st.empty() && cmp(a[i], a[st.back()])) {\n        last = st.back();\n\
    \        st.pop_back();\n      }\n      if (!st.empty()) {\n        parent[i]\
    \ = st.back();\n        right[st.back()] = i;\n      }\n      if (last != -1)\
    \ {\n        parent[last] = i;\n        left[i] = last;\n      }\n      st.push_back(i);\n\
    \    }\n    root = -1;\n    for (int i = 0; i < n; i++) {\n      if (parent[i]\
    \ == -1) {\n        root = i;\n        break;\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, class Cmp = less<T>>\nstruct cartesian_tree {\n  int n;\n  vector<int>\
    \ parent;\n  vector<int> left;\n  vector<int> right;\n  int root;\n  Cmp cmp;\n\
    \n  cartesian_tree() : n(0), root(-1), cmp() {}\n  cartesian_tree(const vector<T>&\
    \ a, Cmp cmp_ = Cmp()) { build(a, cmp_); }\n\n  void build(const vector<T>& a,\
    \ Cmp cmp_ = Cmp()) {\n    cmp = cmp_;\n    n = (int)a.size();\n    parent.assign(n,\
    \ -1);\n    left.assign(n, -1);\n    right.assign(n, -1);\n    vector<int> st;\n\
    \    st.reserve(n);\n    for (int i = 0; i < n; i++) {\n      int last = -1;\n\
    \      while (!st.empty() && cmp(a[i], a[st.back()])) {\n        last = st.back();\n\
    \        st.pop_back();\n      }\n      if (!st.empty()) {\n        parent[i]\
    \ = st.back();\n        right[st.back()] = i;\n      }\n      if (last != -1)\
    \ {\n        parent[last] = i;\n        left[i] = last;\n      }\n      st.push_back(i);\n\
    \    }\n    root = -1;\n    for (int i = 0; i < n; i++) {\n      if (parent[i]\
    \ == -1) {\n        root = i;\n        break;\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cartesiantree.hpp
  requiredBy:
  - structure/sparsetable.hpp
  timestamp: '2026-03-11 17:13:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_staticrmq.test.cpp
documentation_of: //graph/cartesiantree.hpp
layout: document
title: Cartesian Tree
---

Definition
配列に対する Cartesian Tree を構築する。in-order が元の順序になり、根が最小値になる。

Complexity
O(n)。

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
  requiredBy: []
  timestamp: '2026-03-11 17:13:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: //graph/cartesiantree.hpp
layout: document
title: Cartesian Tree
---

Definition
配列に対する Cartesian Tree を構築する。in-order が元の順序になり、根が最小値になる。

Complexity
O(n)。

使い方

- `cartesian_tree<T, Cmp> ct(a);` で配列 a から構築する。
- `ct.build(a, cmp);` で再構築できる。
- `ct.root` が根のインデックス。
- `ct.parent[i]` が親、`ct.left[i]` と `ct.right[i]` が左右の子（存在しない場合は -1）。
- `Cmp` を `greater<T>` にすると最大値が根になる。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_double_ended_priority_queue.test.cpp
    title: verify/yosupo_double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/bipq.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct bipq {\n  multiset<T> s;\n\n  int size()\
    \ const { return (int)s.size(); }\n  bool empty() const { return s.empty(); }\n\
    \n  void push(const T& x) { s.insert(x); }\n\n  T min() const { return *s.begin();\
    \ }\n  T max() const {\n    auto it = s.end();\n    --it;\n    return *it;\n \
    \ }\n\n  T pop_min() {\n    auto it = s.begin();\n    T v = *it;\n    s.erase(it);\n\
    \    return v;\n  }\n\n  T pop_max() {\n    auto it = s.end();\n    --it;\n  \
    \  T v = *it;\n    s.erase(it);\n    return v;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct bipq {\n  multiset<T> s;\n\n  int size() const { return (int)s.size();\
    \ }\n  bool empty() const { return s.empty(); }\n\n  void push(const T& x) { s.insert(x);\
    \ }\n\n  T min() const { return *s.begin(); }\n  T max() const {\n    auto it\
    \ = s.end();\n    --it;\n    return *it;\n  }\n\n  T pop_min() {\n    auto it\
    \ = s.begin();\n    T v = *it;\n    s.erase(it);\n    return v;\n  }\n\n  T pop_max()\
    \ {\n    auto it = s.end();\n    --it;\n    T v = *it;\n    s.erase(it);\n   \
    \ return v;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bipq.hpp
  requiredBy: []
  timestamp: '2026-03-11 05:51:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_double_ended_priority_queue.test.cpp
documentation_of: //structure/bipq.hpp
layout: document
title: "\u4E21\u7AEF\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC"
---

Definition
bipq は多重集合として最小値・最大値の取得と削除を提供する。

Complexity
各操作は O(log n)。

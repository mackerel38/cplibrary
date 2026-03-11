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
    \ std;\n\ntemplate <class T>\nstruct bipq {\n  priority_queue<T, vector<T>, greater<T>>\
    \ mn;\n  priority_queue<T> mx;\n  map<T, int> cnt;\n  int sz = 0;\n\n  int size()\
    \ const { return sz; }\n  bool empty() const { return sz == 0; }\n\n  void push(const\
    \ T& x) {\n    mn.push(x);\n    mx.push(x);\n    cnt[x]++;\n    sz++;\n  }\n\n\
    \  void clean_min() {\n    while (!mn.empty()) {\n      T v = mn.top();\n    \
    \  auto it = cnt.find(v);\n      if (it != cnt.end() && it->second > 0) break;\n\
    \      mn.pop();\n    }\n  }\n\n  void clean_max() {\n    while (!mx.empty())\
    \ {\n      T v = mx.top();\n      auto it = cnt.find(v);\n      if (it != cnt.end()\
    \ && it->second > 0) break;\n      mx.pop();\n    }\n  }\n\n  T min() {\n    clean_min();\n\
    \    return mn.top();\n  }\n\n  T max() {\n    clean_max();\n    return mx.top();\n\
    \  }\n\n  T pop_min() {\n    clean_min();\n    T v = mn.top();\n    mn.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n\n  T pop_max() {\n    clean_max();\n    T v = mx.top();\n    mx.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct bipq {\n  priority_queue<T, vector<T>, greater<T>> mn;\n \
    \ priority_queue<T> mx;\n  map<T, int> cnt;\n  int sz = 0;\n\n  int size() const\
    \ { return sz; }\n  bool empty() const { return sz == 0; }\n\n  void push(const\
    \ T& x) {\n    mn.push(x);\n    mx.push(x);\n    cnt[x]++;\n    sz++;\n  }\n\n\
    \  void clean_min() {\n    while (!mn.empty()) {\n      T v = mn.top();\n    \
    \  auto it = cnt.find(v);\n      if (it != cnt.end() && it->second > 0) break;\n\
    \      mn.pop();\n    }\n  }\n\n  void clean_max() {\n    while (!mx.empty())\
    \ {\n      T v = mx.top();\n      auto it = cnt.find(v);\n      if (it != cnt.end()\
    \ && it->second > 0) break;\n      mx.pop();\n    }\n  }\n\n  T min() {\n    clean_min();\n\
    \    return mn.top();\n  }\n\n  T max() {\n    clean_max();\n    return mx.top();\n\
    \  }\n\n  T pop_min() {\n    clean_min();\n    T v = mn.top();\n    mn.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n\n  T pop_max() {\n    clean_max();\n    T v = mx.top();\n    mx.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bipq.hpp
  requiredBy: []
  timestamp: '2026-03-11 15:55:52+09:00'
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

使い方
`bipq<T> pq;` で空の多重集合を作る。
`pq.push(x);` で要素 x を追加する。
`pq.min();` で最小値を取得する。
`pq.max();` で最大値を取得する。
`pq.pop_min();` で最小値を削除して返す。
`pq.pop_max();` で最大値を削除して返す。
`pq.size();` は要素数、`pq.empty();` は空かどうかを返す。
`pq.clean_min();` と `pq.clean_max();` は内部の整合性を保つための掃除で、通常は直接呼ばなくてよい。

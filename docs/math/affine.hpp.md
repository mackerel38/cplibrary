---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_set_range_composite.test.cpp
    title: verify/yosupo_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_set_range_composite_large_array.test.cpp
    title: verify/yosupo_point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_affine_point_get.test.cpp
    title: verify/yosupo_range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/affine.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0)\
    \ {}\n  affine(T a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a *\
    \ x + b; }\n};\n\ntemplate <class T>\ninline affine<T> affine_add(const affine<T>&\
    \ f, const affine<T>& g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n}\n\ntemplate\
    \ <class T>\ninline affine<T> affine_compose(const affine<T>& f, const affine<T>&\
    \ g) {\n  return affine<T>(f.a * g.a, f.a * g.b + f.b);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0) {}\n  affine(T\
    \ a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a * x + b; }\n};\n\
    \ntemplate <class T>\ninline affine<T> affine_add(const affine<T>& f, const affine<T>&\
    \ g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n}\n\ntemplate <class T>\ninline\
    \ affine<T> affine_compose(const affine<T>& f, const affine<T>& g) {\n  return\
    \ affine<T>(f.a * g.a, f.a * g.b + f.b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/affine.hpp
  requiredBy: []
  timestamp: '2026-03-11 17:47:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_set_range_composite_large_array.test.cpp
  - verify/yosupo_point_set_range_composite.test.cpp
  - verify/yosupo_range_affine_point_get.test.cpp
documentation_of: //math/affine.hpp
layout: document
title: Affine
---

Definition
一次関数 f(x)=ax+b を表す。

Complexity
各操作は O(1)。

使い方
`affine<T> f(a, b);` で f(x)=ax+b を作る。
`f.eval(x);` で f(x) を計算する。
`affine_add(f, g);` で f+g を返す。
`affine_compose(f, g);` で f∘g を返す。

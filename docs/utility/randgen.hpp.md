---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: structure/treap.hpp
    title: Treap
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ordered_set.test.cpp
    title: verify/yosupo_ordered_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_predecessor_problem.test.cpp
    title: verify/yosupo_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/randgen.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct randgen {\n  mt19937_64 rng;\n\n  randgen() {\n    uint64_t seed\
    \ = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();\n    rng.seed(seed);\n\
    \  }\n\n  uint64_t u64() { return rng(); }\n\n  long long ll(long long l, long\
    \ long r) {\n    return uniform_int_distribution<long long>(l, r - 1)(rng);\n\
    \  }\n\n  int i(int l, int r) { return uniform_int_distribution<int>(l, r - 1)(rng);\
    \ }\n\n  double real(double l = 0.0, double r = 1.0) {\n    return uniform_real_distribution<double>(l,\
    \ r)(rng);\n  }\n\n  template <class T>\n  void shuffle_vec(vector<T>& v) {\n\
    \    shuffle(v.begin(), v.end(), rng);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct randgen\
    \ {\n  mt19937_64 rng;\n\n  randgen() {\n    uint64_t seed = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();\n\
    \    rng.seed(seed);\n  }\n\n  uint64_t u64() { return rng(); }\n\n  long long\
    \ ll(long long l, long long r) {\n    return uniform_int_distribution<long long>(l,\
    \ r - 1)(rng);\n  }\n\n  int i(int l, int r) { return uniform_int_distribution<int>(l,\
    \ r - 1)(rng); }\n\n  double real(double l = 0.0, double r = 1.0) {\n    return\
    \ uniform_real_distribution<double>(l, r)(rng);\n  }\n\n  template <class T>\n\
    \  void shuffle_vec(vector<T>& v) {\n    shuffle(v.begin(), v.end(), rng);\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/randgen.hpp
  requiredBy:
  - structure/treap.hpp
  timestamp: '2026-03-11 22:03:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_predecessor_problem.test.cpp
  - verify/yosupo_ordered_set.test.cpp
documentation_of: //utility/randgen.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---
Definition
`mt19937_64` を用いた乱数生成ユーティリティ。

Complexity
各生成は O(1)

ポイント
- `chrono::steady_clock` 由来の seed で初期化
- 整数・実数・シャッフルをまとめて提供
- 区間は [l, r) を前提

使い方
- `randgen rg;` で生成器を作る
- `rg.u64();` で 64bit 乱数
- `rg.i(l, r);` で int の [l, r) 乱数
- `rg.ll(l, r);` で long long の [l, r) 乱数
- `rg.real(l, r);` で実数の [l, r) 乱数
- `rg.shuffle_vec(v);` で配列をシャッフル

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_range_parallel_unionfind.test.cpp
    title: verify/yosupo_range_parallel_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential.test.cpp
    title: verify/yosupo_unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
    title: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <long long MOD>\nstruct modint {\n  long long v;\n\n  modint()\
    \ : v(0) {}\n  modint(long long x) {\n    x %= MOD;\n    if (x < 0) x += MOD;\n\
    \    v = x;\n  }\n\n  static modint raw(long long x) {\n    modint m;\n    m.v\
    \ = x;\n    return m;\n  }\n\n  modint& operator+=(const modint& o) {\n    v +=\
    \ o.v;\n    if (v >= MOD) v -= MOD;\n    return *this;\n  }\n  modint& operator-=(const\
    \ modint& o) {\n    v -= o.v;\n    if (v < 0) v += MOD;\n    return *this;\n \
    \ }\n  modint& operator*=(const modint& o) {\n    v = (long long)((__int128)v\
    \ * o.v % MOD);\n    return *this;\n  }\n\n  modint operator+(const modint& o)\
    \ const { return modint(*this) += o; }\n  modint operator-(const modint& o) const\
    \ { return modint(*this) -= o; }\n  modint operator*(const modint& o) const {\
    \ return modint(*this) *= o; }\n\n  modint operator-() const { return v == 0 ?\
    \ *this : modint::raw(MOD - v); }\n\n  bool operator==(const modint& o) const\
    \ { return v == o.v; }\n  bool operator!=(const modint& o) const { return v !=\
    \ o.v; }\n\n  static modint pow(modint a, long long e) {\n    modint r = 1;\n\
    \    while (e > 0) {\n      if (e & 1) r *= a;\n      a *= a;\n      e >>= 1;\n\
    \    }\n    return r;\n  }\n\n  static modint inv(modint a) { return pow(a, MOD\
    \ - 2); }\n\n  friend ostream& operator<<(ostream& os, const modint& x) {\n  \
    \  return os << x.v;\n  }\n  friend istream& operator>>(istream& is, modint& x)\
    \ {\n    long long t;\n    is >> t;\n    x = modint(t);\n    return is;\n  }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <long long MOD>\nstruct modint {\n  long long v;\n\n  modint() : v(0) {}\n \
    \ modint(long long x) {\n    x %= MOD;\n    if (x < 0) x += MOD;\n    v = x;\n\
    \  }\n\n  static modint raw(long long x) {\n    modint m;\n    m.v = x;\n    return\
    \ m;\n  }\n\n  modint& operator+=(const modint& o) {\n    v += o.v;\n    if (v\
    \ >= MOD) v -= MOD;\n    return *this;\n  }\n  modint& operator-=(const modint&\
    \ o) {\n    v -= o.v;\n    if (v < 0) v += MOD;\n    return *this;\n  }\n  modint&\
    \ operator*=(const modint& o) {\n    v = (long long)((__int128)v * o.v % MOD);\n\
    \    return *this;\n  }\n\n  modint operator+(const modint& o) const { return\
    \ modint(*this) += o; }\n  modint operator-(const modint& o) const { return modint(*this)\
    \ -= o; }\n  modint operator*(const modint& o) const { return modint(*this) *=\
    \ o; }\n\n  modint operator-() const { return v == 0 ? *this : modint::raw(MOD\
    \ - v); }\n\n  bool operator==(const modint& o) const { return v == o.v; }\n \
    \ bool operator!=(const modint& o) const { return v != o.v; }\n\n  static modint\
    \ pow(modint a, long long e) {\n    modint r = 1;\n    while (e > 0) {\n     \
    \ if (e & 1) r *= a;\n      a *= a;\n      e >>= 1;\n    }\n    return r;\n  }\n\
    \n  static modint inv(modint a) { return pow(a, MOD - 2); }\n\n  friend ostream&\
    \ operator<<(ostream& os, const modint& x) {\n    return os << x.v;\n  }\n  friend\
    \ istream& operator>>(istream& is, modint& x) {\n    long long t;\n    is >> t;\n\
    \    x = modint(t);\n    return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2026-03-11 16:50:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_range_parallel_unionfind.test.cpp
  - verify/yosupo_unionfind_with_potential.test.cpp
  - verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: //math/modint.hpp
layout: document
title: modint
---

Definition
法 MOD 上の整数型。加減乗、冪、逆元、入出力を提供する。

Complexity
各演算は O(1)、冪と逆元は O(log MOD)。

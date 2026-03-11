---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
    title: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <long long MOD>\nstruct mat2 {\n  long long a00, a01, a10,\
    \ a11;\n\n  mat2(long long b00 = 1, long long b01 = 0, long long b10 = 0,\n  \
    \     long long b11 = 1)\n      : a00(norm(b00)),\n        a01(norm(b01)),\n \
    \       a10(norm(b10)),\n        a11(norm(b11)) {}\n\n  static long long norm(long\
    \ long v) {\n    v %= MOD;\n    if (v < 0) v += MOD;\n    return v;\n  }\n\n \
    \ static mat2 id() { return mat2(); }\n\n  static mat2 op(const mat2 &x, const\
    \ mat2 &y) {\n    mat2 r(0, 0, 0, 0);\n    r.a00 = (x.a00 * y.a00 + x.a01 * y.a10)\
    \ % MOD;\n    r.a01 = (x.a00 * y.a01 + x.a01 * y.a11) % MOD;\n    r.a10 = (x.a10\
    \ * y.a00 + x.a11 * y.a10) % MOD;\n    r.a11 = (x.a10 * y.a01 + x.a11 * y.a11)\
    \ % MOD;\n    return r;\n  }\n\n  static long long modpow(long long a, long long\
    \ e) {\n    long long r = 1;\n    while (e > 0) {\n      if (e & 1) r = r * a\
    \ % MOD;\n      a = a * a % MOD;\n      e >>= 1;\n    }\n    return r;\n  }\n\n\
    \  static mat2 inv(const mat2 &x) {\n    long long det = (x.a00 * x.a11 - x.a01\
    \ * x.a10) % MOD;\n    if (det < 0) det += MOD;\n    long long idet = modpow(det,\
    \ MOD - 2);\n    mat2 r(0, 0, 0, 0);\n    r.a00 = x.a11 * idet % MOD;\n    r.a01\
    \ = (MOD - x.a01) % MOD * idet % MOD;\n    r.a10 = (MOD - x.a10) % MOD * idet\
    \ % MOD;\n    r.a11 = x.a00 * idet % MOD;\n    return r;\n  }\n\n  bool operator==(const\
    \ mat2 &o) const {\n    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&\n\
    \           a11 == o.a11;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <long long MOD>\nstruct mat2 {\n  long long a00, a01, a10, a11;\n\n  mat2(long\
    \ long b00 = 1, long long b01 = 0, long long b10 = 0,\n       long long b11 =\
    \ 1)\n      : a00(norm(b00)),\n        a01(norm(b01)),\n        a10(norm(b10)),\n\
    \        a11(norm(b11)) {}\n\n  static long long norm(long long v) {\n    v %=\
    \ MOD;\n    if (v < 0) v += MOD;\n    return v;\n  }\n\n  static mat2 id() { return\
    \ mat2(); }\n\n  static mat2 op(const mat2 &x, const mat2 &y) {\n    mat2 r(0,\
    \ 0, 0, 0);\n    r.a00 = (x.a00 * y.a00 + x.a01 * y.a10) % MOD;\n    r.a01 = (x.a00\
    \ * y.a01 + x.a01 * y.a11) % MOD;\n    r.a10 = (x.a10 * y.a00 + x.a11 * y.a10)\
    \ % MOD;\n    r.a11 = (x.a10 * y.a01 + x.a11 * y.a11) % MOD;\n    return r;\n\
    \  }\n\n  static long long modpow(long long a, long long e) {\n    long long r\
    \ = 1;\n    while (e > 0) {\n      if (e & 1) r = r * a % MOD;\n      a = a *\
    \ a % MOD;\n      e >>= 1;\n    }\n    return r;\n  }\n\n  static mat2 inv(const\
    \ mat2 &x) {\n    long long det = (x.a00 * x.a11 - x.a01 * x.a10) % MOD;\n   \
    \ if (det < 0) det += MOD;\n    long long idet = modpow(det, MOD - 2);\n    mat2\
    \ r(0, 0, 0, 0);\n    r.a00 = x.a11 * idet % MOD;\n    r.a01 = (MOD - x.a01) %\
    \ MOD * idet % MOD;\n    r.a10 = (MOD - x.a10) % MOD * idet % MOD;\n    r.a11\
    \ = x.a00 * idet % MOD;\n    return r;\n  }\n\n  bool operator==(const mat2 &o)\
    \ const {\n    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&\n      \
    \     a11 == o.a11;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2026-03-11 16:11:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: //math/matrix.hpp
layout: document
title: "2x2 \u884C\u5217"
---

Definition
mod 上の 2x2 行列を扱う。行列積、単位行列、逆行列を提供する。

Complexity
行列積・逆行列は O(1)。

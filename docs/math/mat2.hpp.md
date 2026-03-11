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
  bundledCode: "#line 2 \"math/mat2.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class Ops>\nstruct mat2 {\n  using T = typename Ops::T;\n\
    \  T a00, a01, a10, a11;\n\n  mat2(T b00 = Ops::one(), T b01 = Ops::zero(), T\
    \ b10 = Ops::zero(),\n       T b11 = Ops::one())\n      : a00(b00), a01(b01),\
    \ a10(b10), a11(b11) {}\n\n  static mat2 id() { return mat2(); }\n\n  static mat2\
    \ op(const mat2 &x, const mat2 &y) {\n    mat2 r(Ops::zero(), Ops::zero(), Ops::zero(),\
    \ Ops::zero());\n    r.a00 = Ops::add(Ops::mul(x.a00, y.a00), Ops::mul(x.a01,\
    \ y.a10));\n    r.a01 = Ops::add(Ops::mul(x.a00, y.a01), Ops::mul(x.a01, y.a11));\n\
    \    r.a10 = Ops::add(Ops::mul(x.a10, y.a00), Ops::mul(x.a11, y.a10));\n    r.a11\
    \ = Ops::add(Ops::mul(x.a10, y.a01), Ops::mul(x.a11, y.a11));\n    return r;\n\
    \  }\n\n  static mat2 inv(const mat2 &x) {\n    T det = Ops::sub(Ops::mul(x.a00,\
    \ x.a11), Ops::mul(x.a01, x.a10));\n    T idet = Ops::inv(det);\n    mat2 r(Ops::zero(),\
    \ Ops::zero(), Ops::zero(), Ops::zero());\n    r.a00 = Ops::mul(x.a11, idet);\n\
    \    r.a01 = Ops::mul(Ops::neg(x.a01), idet);\n    r.a10 = Ops::mul(Ops::neg(x.a10),\
    \ idet);\n    r.a11 = Ops::mul(x.a00, idet);\n    return r;\n  }\n\n  bool operator==(const\
    \ mat2 &o) const {\n    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&\n\
    \           a11 == o.a11;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class Ops>\nstruct mat2 {\n  using T = typename Ops::T;\n  T a00, a01, a10,\
    \ a11;\n\n  mat2(T b00 = Ops::one(), T b01 = Ops::zero(), T b10 = Ops::zero(),\n\
    \       T b11 = Ops::one())\n      : a00(b00), a01(b01), a10(b10), a11(b11) {}\n\
    \n  static mat2 id() { return mat2(); }\n\n  static mat2 op(const mat2 &x, const\
    \ mat2 &y) {\n    mat2 r(Ops::zero(), Ops::zero(), Ops::zero(), Ops::zero());\n\
    \    r.a00 = Ops::add(Ops::mul(x.a00, y.a00), Ops::mul(x.a01, y.a10));\n    r.a01\
    \ = Ops::add(Ops::mul(x.a00, y.a01), Ops::mul(x.a01, y.a11));\n    r.a10 = Ops::add(Ops::mul(x.a10,\
    \ y.a00), Ops::mul(x.a11, y.a10));\n    r.a11 = Ops::add(Ops::mul(x.a10, y.a01),\
    \ Ops::mul(x.a11, y.a11));\n    return r;\n  }\n\n  static mat2 inv(const mat2\
    \ &x) {\n    T det = Ops::sub(Ops::mul(x.a00, x.a11), Ops::mul(x.a01, x.a10));\n\
    \    T idet = Ops::inv(det);\n    mat2 r(Ops::zero(), Ops::zero(), Ops::zero(),\
    \ Ops::zero());\n    r.a00 = Ops::mul(x.a11, idet);\n    r.a01 = Ops::mul(Ops::neg(x.a01),\
    \ idet);\n    r.a10 = Ops::mul(Ops::neg(x.a10), idet);\n    r.a11 = Ops::mul(x.a00,\
    \ idet);\n    return r;\n  }\n\n  bool operator==(const mat2 &o) const {\n   \
    \ return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&\n           a11 == o.a11;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mat2.hpp
  requiredBy: []
  timestamp: '2026-03-11 16:26:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: //math/mat2.hpp
layout: document
title: "2x2 \u884C\u5217"
---

Definition
2x2 行列を扱う。要素の演算は外部で与える。行列積、単位行列、逆行列を提供する。

Complexity
行列積・逆行列は O(1)。

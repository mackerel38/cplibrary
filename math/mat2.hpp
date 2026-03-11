#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class Ops>
struct mat2 {
  using T = typename Ops::T;
  T a00, a01, a10, a11;

  mat2(T b00 = Ops::one(), T b01 = Ops::zero(), T b10 = Ops::zero(),
       T b11 = Ops::one())
      : a00(b00), a01(b01), a10(b10), a11(b11) {}

  static mat2 id() { return mat2(); }

  static mat2 op(const mat2 &x, const mat2 &y) {
    mat2 r(Ops::zero(), Ops::zero(), Ops::zero(), Ops::zero());
    r.a00 = Ops::add(Ops::mul(x.a00, y.a00), Ops::mul(x.a01, y.a10));
    r.a01 = Ops::add(Ops::mul(x.a00, y.a01), Ops::mul(x.a01, y.a11));
    r.a10 = Ops::add(Ops::mul(x.a10, y.a00), Ops::mul(x.a11, y.a10));
    r.a11 = Ops::add(Ops::mul(x.a10, y.a01), Ops::mul(x.a11, y.a11));
    return r;
  }

  static mat2 inv(const mat2 &x) {
    T det = Ops::sub(Ops::mul(x.a00, x.a11), Ops::mul(x.a01, x.a10));
    T idet = Ops::inv(det);
    mat2 r(Ops::zero(), Ops::zero(), Ops::zero(), Ops::zero());
    r.a00 = Ops::mul(x.a11, idet);
    r.a01 = Ops::mul(Ops::neg(x.a01), idet);
    r.a10 = Ops::mul(Ops::neg(x.a10), idet);
    r.a11 = Ops::mul(x.a00, idet);
    return r;
  }

  bool operator==(const mat2 &o) const {
    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&
           a11 == o.a11;
  }

  bool operator!=(const mat2 &o) const { return !(*this == o); }

  mat2 operator+(const mat2 &o) const {
    return mat2(Ops::add(a00, o.a00), Ops::add(a01, o.a01),
                Ops::add(a10, o.a10), Ops::add(a11, o.a11));
  }

  mat2 operator-(const mat2 &o) const {
    return mat2(Ops::sub(a00, o.a00), Ops::sub(a01, o.a01),
                Ops::sub(a10, o.a10), Ops::sub(a11, o.a11));
  }

  mat2 operator*(const mat2 &o) const { return op(*this, o); }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

template <long long MOD>
struct mat2 {
  long long a00, a01, a10, a11;

  mat2(long long b00 = 1, long long b01 = 0, long long b10 = 0,
       long long b11 = 1)
      : a00(norm(b00)),
        a01(norm(b01)),
        a10(norm(b10)),
        a11(norm(b11)) {}

  static long long norm(long long v) {
    v %= MOD;
    if (v < 0) v += MOD;
    return v;
  }

  static mat2 id() { return mat2(); }

  static mat2 op(const mat2 &x, const mat2 &y) {
    mat2 r(0, 0, 0, 0);
    r.a00 = (x.a00 * y.a00 + x.a01 * y.a10) % MOD;
    r.a01 = (x.a00 * y.a01 + x.a01 * y.a11) % MOD;
    r.a10 = (x.a10 * y.a00 + x.a11 * y.a10) % MOD;
    r.a11 = (x.a10 * y.a01 + x.a11 * y.a11) % MOD;
    return r;
  }

  static long long modpow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
      if (e & 1) r = r * a % MOD;
      a = a * a % MOD;
      e >>= 1;
    }
    return r;
  }

  static mat2 inv(const mat2 &x) {
    long long det = (x.a00 * x.a11 - x.a01 * x.a10) % MOD;
    if (det < 0) det += MOD;
    long long idet = modpow(det, MOD - 2);
    mat2 r(0, 0, 0, 0);
    r.a00 = x.a11 * idet % MOD;
    r.a01 = (MOD - x.a01) % MOD * idet % MOD;
    r.a10 = (MOD - x.a10) % MOD * idet % MOD;
    r.a11 = x.a00 * idet % MOD;
    return r;
  }

  bool operator==(const mat2 &o) const {
    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&
           a11 == o.a11;
  }
};

#pragma once
#include <bits/stdc++.h>
using namespace std;

template <long long MOD>
struct modint {
  long long v;

  modint() : v(0) {}
  modint(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    v = x;
  }

  static modint raw(long long x) {
    modint m;
    m.v = x;
    return m;
  }

  modint& operator+=(const modint& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modint& operator-=(const modint& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modint& operator*=(const modint& o) {
    v = (long long)((__int128)v * o.v % MOD);
    return *this;
  }

  modint operator+(const modint& o) const { return modint(*this) += o; }
  modint operator-(const modint& o) const { return modint(*this) -= o; }
  modint operator*(const modint& o) const { return modint(*this) *= o; }

  modint operator-() const { return v == 0 ? *this : modint::raw(MOD - v); }

  bool operator==(const modint& o) const { return v == o.v; }
  bool operator!=(const modint& o) const { return v != o.v; }

  static modint pow(modint a, long long e) {
    modint r = 1;
    while (e > 0) {
      if (e & 1) r *= a;
      a *= a;
      e >>= 1;
    }
    return r;
  }

  static modint inv(modint a) { return pow(a, MOD - 2); }

  friend ostream& operator<<(ostream& os, const modint& x) {
    return os << x.v;
  }
  friend istream& operator>>(istream& is, modint& x) {
    long long t;
    is >> t;
    x = modint(t);
    return is;
  }
};

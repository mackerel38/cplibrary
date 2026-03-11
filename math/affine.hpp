#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct affine {
  T a, b;
  affine() : a(1), b(0) {}
  affine(T a_, T b_) : a(a_), b(b_) {}
  T eval(T x) const { return a * x + b; }
};

template <class T>
inline affine<T> affine_add(const affine<T>& f, const affine<T>& g) {
  return affine<T>(f.a + g.a, f.b + g.b);
}

template <class T>
inline affine<T> affine_compose(const affine<T>& f, const affine<T>& g) {
  return affine<T>(f.a * g.a, f.a * g.b + f.b);
}

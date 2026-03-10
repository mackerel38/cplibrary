#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct bipq {
  multiset<T> s;

  int size() const { return (int)s.size(); }
  bool empty() const { return s.empty(); }

  void push(const T& x) { s.insert(x); }

  T min() const { return *s.begin(); }
  T max() const {
    auto it = s.end();
    --it;
    return *it;
  }

  T pop_min() {
    auto it = s.begin();
    T v = *it;
    s.erase(it);
    return v;
  }

  T pop_max() {
    auto it = s.end();
    --it;
    T v = *it;
    s.erase(it);
    return v;
  }
};

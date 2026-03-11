#pragma once
#include <bits/stdc++.h>
using namespace std;

struct randgen {
  mt19937_64 rng;

  randgen() {
    uint64_t seed = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();
    rng.seed(seed);
  }

  uint64_t u64() { return rng(); }

  long long ll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r - 1)(rng);
  }

  int i(int l, int r) { return uniform_int_distribution<int>(l, r - 1)(rng); }

  double real(double l = 0.0, double r = 1.0) {
    return uniform_real_distribution<double>(l, r)(rng);
  }

  template <class T>
  void shuffle_vec(vector<T>& v) {
    shuffle(v.begin(), v.end(), rng);
  }
};

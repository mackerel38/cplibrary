#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct bipq {
  priority_queue<T, vector<T>, greater<T>> mn;
  priority_queue<T> mx;
  map<T, int> cnt;
  int sz = 0;

  int size() const { return sz; }
  bool empty() const { return sz == 0; }

  void push(const T& x) {
    mn.push(x);
    mx.push(x);
    cnt[x]++;
    sz++;
  }

  void clean_min() {
    while (!mn.empty()) {
      T v = mn.top();
      auto it = cnt.find(v);
      if (it != cnt.end() && it->second > 0) break;
      mn.pop();
    }
  }

  void clean_max() {
    while (!mx.empty()) {
      T v = mx.top();
      auto it = cnt.find(v);
      if (it != cnt.end() && it->second > 0) break;
      mx.pop();
    }
  }

  T min() {
    clean_min();
    return mn.top();
  }

  T max() {
    clean_max();
    return mx.top();
  }

  T pop_min() {
    clean_min();
    T v = mn.top();
    mn.pop();
    cnt[v]--;
    if (cnt[v] == 0) cnt.erase(v);
    sz--;
    return v;
  }

  T pop_max() {
    clean_max();
    T v = mx.top();
    mx.pop();
    cnt[v]--;
    if (cnt[v] == 0) cnt.erase(v);
    sz--;
    return v;
  }
};

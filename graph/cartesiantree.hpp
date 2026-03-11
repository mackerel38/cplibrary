#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T, class Cmp = less<T>>
struct cartesian_tree {
  int n;
  vector<int> parent;
  vector<int> left;
  vector<int> right;
  int root;
  Cmp cmp;

  cartesian_tree() : n(0), root(-1), cmp() {}
  cartesian_tree(const vector<T>& a, Cmp cmp_ = Cmp()) { build(a, cmp_); }

  void build(const vector<T>& a, Cmp cmp_ = Cmp()) {
    cmp = cmp_;
    n = (int)a.size();
    parent.assign(n, -1);
    left.assign(n, -1);
    right.assign(n, -1);
    vector<int> st;
    st.reserve(n);
    for (int i = 0; i < n; i++) {
      int last = -1;
      while (!st.empty() && cmp(a[i], a[st.back()])) {
        last = st.back();
        st.pop_back();
      }
      if (!st.empty()) {
        parent[i] = st.back();
        right[st.back()] = i;
      }
      if (last != -1) {
        parent[last] = i;
        left[i] = last;
      }
      st.push_back(i);
    }
    root = -1;
    for (int i = 0; i < n; i++) {
      if (parent[i] == -1) {
        root = i;
        break;
      }
    }
  }
};

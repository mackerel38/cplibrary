#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct hm_default_hash {
  size_t operator()(const T &x) const {
    if constexpr (is_integral_v<T> && sizeof(T) <= 8) {
      uint64_t z = uint64_t(x) + 0x9e3779b97f4a7c15ULL;
      z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
      z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
      return size_t(z ^ (z >> 31));
    } else {
      return hash<T>{}(x);
    }
  }
};

template <class K, class V, class H = hm_default_hash<K>>
struct hashmap {
  vector<K> keys;
  vector<V> vals;
  vector<unsigned char> st;
  size_t n = 0;
  size_t cap = 0;
  H hasher;

  hashmap(size_t c = 8) { init(c); }

  void init(size_t c) {
    cap = 1;
    while (cap < c) cap <<= 1;
    keys.assign(cap, K());
    vals.assign(cap, V());
    st.assign(cap, 0);
    n = 0;
  }

  size_t size() const { return n; }
  bool empty() const { return n == 0; }

  void reserve(size_t m) {
    if (m * 10 > cap * 7) rehash(m * 2 + 1);
  }

  void rehash(size_t c) {
    vector<K> ok = move(keys);
    vector<V> ov = move(vals);
    vector<unsigned char> os = move(st);
    init(c);
    for (size_t i = 0; i < os.size(); i++) {
      if (os[i] == 1) set(ok[i], ov[i]);
    }
  }

  size_t find_idx(const K &k) const {
    size_t m = cap - 1;
    size_t h = hasher(k) & m;
    for (size_t i = 0;; i++) {
      size_t idx = (h + i) & m;
      if (st[idx] == 0) return cap;
      if (st[idx] == 1 && keys[idx] == k) return idx;
    }
  }

  bool contains(const K &k) const { return find_idx(k) != cap; }

  V get(const K &k, const V &def = V()) const {
    size_t idx = find_idx(k);
    if (idx == cap) return def;
    return vals[idx];
  }

  V *get_ptr(const K &k) {
    size_t idx = find_idx(k);
    if (idx == cap) return nullptr;
    return &vals[idx];
  }

  void set(const K &k, const V &v) {
    if ((n + 1) * 10 > cap * 7) rehash(cap * 2 + 1);
    size_t m = cap - 1;
    size_t h = hasher(k) & m;
    size_t first_del = cap;
    for (size_t i = 0;; i++) {
      size_t idx = (h + i) & m;
      if (st[idx] == 1) {
        if (keys[idx] == k) {
          vals[idx] = v;
          return;
        }
      } else if (st[idx] == 2) {
        if (first_del == cap) first_del = idx;
      } else {
        if (first_del != cap) idx = first_del;
        st[idx] = 1;
        keys[idx] = k;
        vals[idx] = v;
        n++;
        return;
      }
    }
  }

  V &operator[](const K &k) {
    if ((n + 1) * 10 > cap * 7) rehash(cap * 2 + 1);
    size_t m = cap - 1;
    size_t h = hasher(k) & m;
    size_t first_del = cap;
    for (size_t i = 0;; i++) {
      size_t idx = (h + i) & m;
      if (st[idx] == 1) {
        if (keys[idx] == k) return vals[idx];
      } else if (st[idx] == 2) {
        if (first_del == cap) first_del = idx;
      } else {
        if (first_del != cap) idx = first_del;
        st[idx] = 1;
        keys[idx] = k;
        vals[idx] = V();
        n++;
        return vals[idx];
      }
    }
  }

  bool erase(const K &k) {
    size_t idx = find_idx(k);
    if (idx == cap) return false;
    st[idx] = 2;
    n--;
    return true;
  }
};

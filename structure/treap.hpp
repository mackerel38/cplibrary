#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T, class Cmp = less<T>>
struct treap {
  struct node {
    T key;
    uint32_t pr;
    int sz;
    node* l;
    node* r;
    node(const T& k, uint32_t p) : key(k), pr(p), sz(1), l(nullptr), r(nullptr) {}
  };

  Cmp cmp;
  uint64_t seed;
  node* root;

  treap() : cmp(), seed(88172645463325252ULL), root(nullptr) {}

  static int size(node* t) { return t ? t->sz : 0; }
  static void pull(node* t) {
    if (t) t->sz = 1 + size(t->l) + size(t->r);
  }

  int size() const { return size(root); }

  uint32_t rnd() {
    seed ^= seed << 7;
    seed ^= seed >> 9;
    return (uint32_t)seed;
  }

  bool eq(const T& a, const T& b) const { return !cmp(a, b) && !cmp(b, a); }

  void split(node* t, const T& key, node*& a, node*& b) {
    if (!t) {
      a = nullptr;
      b = nullptr;
      return;
    }
    if (cmp(t->key, key)) {
      split(t->r, key, t->r, b);
      a = t;
      pull(a);
    } else {
      split(t->l, key, a, t->l);
      b = t;
      pull(b);
    }
  }

  node* merge(node* a, node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pr > b->pr) {
      a->r = merge(a->r, b);
      pull(a);
      return a;
    } else {
      b->l = merge(a, b->l);
      pull(b);
      return b;
    }
  }

  bool contains(const T& key) const {
    node* t = root;
    while (t) {
      if (eq(key, t->key)) return true;
      if (cmp(key, t->key))
        t = t->l;
      else
        t = t->r;
    }
    return false;
  }

  void insert(const T& key) {
    if (contains(key)) return;
    node* it = new node(key, rnd());
    insert(root, it);
  }

  void insert(node*& t, node* it) {
    if (!t) {
      t = it;
      return;
    }
    if (it->pr > t->pr) {
      split(t, it->key, it->l, it->r);
      t = it;
      pull(t);
      return;
    }
    if (cmp(it->key, t->key))
      insert(t->l, it);
    else
      insert(t->r, it);
    pull(t);
  }

  void erase(const T& key) { erase(root, key); }

  void erase(node*& t, const T& key) {
    if (!t) return;
    if (eq(key, t->key)) {
      node* u = merge(t->l, t->r);
      delete t;
      t = u;
      return;
    }
    if (cmp(key, t->key))
      erase(t->l, key);
    else
      erase(t->r, key);
    pull(t);
  }

  bool kth(int k, T& out) const {
    if (k < 0 || k >= size()) return false;
    node* t = root;
    while (t) {
      int ls = size(t->l);
      if (k < ls)
        t = t->l;
      else if (k == ls) {
        out = t->key;
        return true;
      } else {
        k -= ls + 1;
        t = t->r;
      }
    }
    return false;
  }

  int count_lt(const T& key) const {
    node* t = root;
    int res = 0;
    while (t) {
      if (cmp(key, t->key)) {
        t = t->l;
      } else if (cmp(t->key, key)) {
        res += size(t->l) + 1;
        t = t->r;
      } else {
        res += size(t->l);
        return res;
      }
    }
    return res;
  }

  int count_le(const T& key) const {
    node* t = root;
    int res = 0;
    while (t) {
      if (cmp(key, t->key)) {
        t = t->l;
      } else {
        res += size(t->l) + 1;
        t = t->r;
      }
    }
    return res;
  }

  bool lower_bound(const T& key, T& out) const {
    node* t = root;
    bool ok = false;
    T best;
    while (t) {
      if (!cmp(t->key, key)) {
        ok = true;
        best = t->key;
        t = t->l;
      } else {
        t = t->r;
      }
    }
    if (ok) out = best;
    return ok;
  }

  bool upper_bound(const T& key, T& out) const {
    node* t = root;
    bool ok = false;
    T best;
    while (t) {
      if (cmp(key, t->key)) {
        ok = true;
        best = t->key;
        t = t->l;
      } else {
        t = t->r;
      }
    }
    if (ok) out = best;
    return ok;
  }

  bool prev(const T& key, T& out) const {
    node* t = root;
    bool ok = false;
    T best;
    while (t) {
      if (cmp(t->key, key)) {
        ok = true;
        best = t->key;
        t = t->r;
      } else {
        t = t->l;
      }
    }
    if (ok) out = best;
    return ok;
  }

  bool prev_eq(const T& key, T& out) const {
    node* t = root;
    bool ok = false;
    T best;
    while (t) {
      if (!cmp(key, t->key)) {
        ok = true;
        best = t->key;
        t = t->r;
      } else {
        t = t->l;
      }
    }
    if (ok) out = best;
    return ok;
  }
};

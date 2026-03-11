---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ordered_set.test.cpp
    title: verify/yosupo_ordered_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_predecessor_problem.test.cpp
    title: verify/yosupo_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/treap.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T, class Cmp = less<T>>\nstruct treap {\n  struct node\
    \ {\n    T key;\n    uint32_t pr;\n    int sz;\n    node* l;\n    node* r;\n \
    \   node(const T& k, uint32_t p) : key(k), pr(p), sz(1), l(nullptr), r(nullptr)\
    \ {}\n  };\n\n  Cmp cmp;\n  uint64_t seed;\n  node* root;\n\n  treap() : cmp(),\
    \ seed(88172645463325252ULL), root(nullptr) {}\n\n  static int size(node* t) {\
    \ return t ? t->sz : 0; }\n  static void pull(node* t) {\n    if (t) t->sz = 1\
    \ + size(t->l) + size(t->r);\n  }\n\n  int size() const { return size(root); }\n\
    \n  uint32_t rnd() {\n    seed ^= seed << 7;\n    seed ^= seed >> 9;\n    return\
    \ (uint32_t)seed;\n  }\n\n  bool eq(const T& a, const T& b) const { return !cmp(a,\
    \ b) && !cmp(b, a); }\n\n  void split(node* t, const T& key, node*& a, node*&\
    \ b) {\n    if (!t) {\n      a = nullptr;\n      b = nullptr;\n      return;\n\
    \    }\n    if (cmp(t->key, key)) {\n      split(t->r, key, t->r, b);\n      a\
    \ = t;\n      pull(a);\n    } else {\n      split(t->l, key, a, t->l);\n     \
    \ b = t;\n      pull(b);\n    }\n  }\n\n  node* merge(node* a, node* b) {\n  \
    \  if (!a || !b) return a ? a : b;\n    if (a->pr > b->pr) {\n      a->r = merge(a->r,\
    \ b);\n      pull(a);\n      return a;\n    } else {\n      b->l = merge(a, b->l);\n\
    \      pull(b);\n      return b;\n    }\n  }\n\n  bool contains(const T& key)\
    \ const {\n    node* t = root;\n    while (t) {\n      if (eq(key, t->key)) return\
    \ true;\n      if (cmp(key, t->key))\n        t = t->l;\n      else\n        t\
    \ = t->r;\n    }\n    return false;\n  }\n\n  void insert(const T& key) {\n  \
    \  if (contains(key)) return;\n    node* it = new node(key, rnd());\n    insert(root,\
    \ it);\n  }\n\n  void insert(node*& t, node* it) {\n    if (!t) {\n      t = it;\n\
    \      return;\n    }\n    if (it->pr > t->pr) {\n      split(t, it->key, it->l,\
    \ it->r);\n      t = it;\n      pull(t);\n      return;\n    }\n    if (cmp(it->key,\
    \ t->key))\n      insert(t->l, it);\n    else\n      insert(t->r, it);\n    pull(t);\n\
    \  }\n\n  void erase(const T& key) { erase(root, key); }\n\n  void erase(node*&\
    \ t, const T& key) {\n    if (!t) return;\n    if (eq(key, t->key)) {\n      node*\
    \ u = merge(t->l, t->r);\n      delete t;\n      t = u;\n      return;\n    }\n\
    \    if (cmp(key, t->key))\n      erase(t->l, key);\n    else\n      erase(t->r,\
    \ key);\n    pull(t);\n  }\n\n  bool kth(int k, T& out) const {\n    if (k < 0\
    \ || k >= size()) return false;\n    node* t = root;\n    while (t) {\n      int\
    \ ls = size(t->l);\n      if (k < ls)\n        t = t->l;\n      else if (k ==\
    \ ls) {\n        out = t->key;\n        return true;\n      } else {\n       \
    \ k -= ls + 1;\n        t = t->r;\n      }\n    }\n    return false;\n  }\n\n\
    \  int count_lt(const T& key) const {\n    node* t = root;\n    int res = 0;\n\
    \    while (t) {\n      if (cmp(key, t->key)) {\n        t = t->l;\n      } else\
    \ if (cmp(t->key, key)) {\n        res += size(t->l) + 1;\n        t = t->r;\n\
    \      } else {\n        res += size(t->l);\n        return res;\n      }\n  \
    \  }\n    return res;\n  }\n\n  int count_le(const T& key) const {\n    node*\
    \ t = root;\n    int res = 0;\n    while (t) {\n      if (cmp(key, t->key)) {\n\
    \        t = t->l;\n      } else {\n        res += size(t->l) + 1;\n        t\
    \ = t->r;\n      }\n    }\n    return res;\n  }\n\n  bool lower_bound(const T&\
    \ key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (!cmp(t->key, key)) {\n        ok = true;\n       \
    \ best = t->key;\n        t = t->l;\n      } else {\n        t = t->r;\n     \
    \ }\n    }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool upper_bound(const\
    \ T& key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (cmp(key, t->key)) {\n        ok = true;\n        best\
    \ = t->key;\n        t = t->l;\n      } else {\n        t = t->r;\n      }\n \
    \   }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool prev(const T& key,\
    \ T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n  \
    \  while (t) {\n      if (cmp(t->key, key)) {\n        ok = true;\n        best\
    \ = t->key;\n        t = t->r;\n      } else {\n        t = t->l;\n      }\n \
    \   }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool prev_eq(const T&\
    \ key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (!cmp(key, t->key)) {\n        ok = true;\n       \
    \ best = t->key;\n        t = t->r;\n      } else {\n        t = t->l;\n     \
    \ }\n    }\n    if (ok) out = best;\n    return ok;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, class Cmp = less<T>>\nstruct treap {\n  struct node {\n    T key;\n\
    \    uint32_t pr;\n    int sz;\n    node* l;\n    node* r;\n    node(const T&\
    \ k, uint32_t p) : key(k), pr(p), sz(1), l(nullptr), r(nullptr) {}\n  };\n\n \
    \ Cmp cmp;\n  uint64_t seed;\n  node* root;\n\n  treap() : cmp(), seed(88172645463325252ULL),\
    \ root(nullptr) {}\n\n  static int size(node* t) { return t ? t->sz : 0; }\n \
    \ static void pull(node* t) {\n    if (t) t->sz = 1 + size(t->l) + size(t->r);\n\
    \  }\n\n  int size() const { return size(root); }\n\n  uint32_t rnd() {\n    seed\
    \ ^= seed << 7;\n    seed ^= seed >> 9;\n    return (uint32_t)seed;\n  }\n\n \
    \ bool eq(const T& a, const T& b) const { return !cmp(a, b) && !cmp(b, a); }\n\
    \n  void split(node* t, const T& key, node*& a, node*& b) {\n    if (!t) {\n \
    \     a = nullptr;\n      b = nullptr;\n      return;\n    }\n    if (cmp(t->key,\
    \ key)) {\n      split(t->r, key, t->r, b);\n      a = t;\n      pull(a);\n  \
    \  } else {\n      split(t->l, key, a, t->l);\n      b = t;\n      pull(b);\n\
    \    }\n  }\n\n  node* merge(node* a, node* b) {\n    if (!a || !b) return a ?\
    \ a : b;\n    if (a->pr > b->pr) {\n      a->r = merge(a->r, b);\n      pull(a);\n\
    \      return a;\n    } else {\n      b->l = merge(a, b->l);\n      pull(b);\n\
    \      return b;\n    }\n  }\n\n  bool contains(const T& key) const {\n    node*\
    \ t = root;\n    while (t) {\n      if (eq(key, t->key)) return true;\n      if\
    \ (cmp(key, t->key))\n        t = t->l;\n      else\n        t = t->r;\n    }\n\
    \    return false;\n  }\n\n  void insert(const T& key) {\n    if (contains(key))\
    \ return;\n    node* it = new node(key, rnd());\n    insert(root, it);\n  }\n\n\
    \  void insert(node*& t, node* it) {\n    if (!t) {\n      t = it;\n      return;\n\
    \    }\n    if (it->pr > t->pr) {\n      split(t, it->key, it->l, it->r);\n  \
    \    t = it;\n      pull(t);\n      return;\n    }\n    if (cmp(it->key, t->key))\n\
    \      insert(t->l, it);\n    else\n      insert(t->r, it);\n    pull(t);\n  }\n\
    \n  void erase(const T& key) { erase(root, key); }\n\n  void erase(node*& t, const\
    \ T& key) {\n    if (!t) return;\n    if (eq(key, t->key)) {\n      node* u =\
    \ merge(t->l, t->r);\n      delete t;\n      t = u;\n      return;\n    }\n  \
    \  if (cmp(key, t->key))\n      erase(t->l, key);\n    else\n      erase(t->r,\
    \ key);\n    pull(t);\n  }\n\n  bool kth(int k, T& out) const {\n    if (k < 0\
    \ || k >= size()) return false;\n    node* t = root;\n    while (t) {\n      int\
    \ ls = size(t->l);\n      if (k < ls)\n        t = t->l;\n      else if (k ==\
    \ ls) {\n        out = t->key;\n        return true;\n      } else {\n       \
    \ k -= ls + 1;\n        t = t->r;\n      }\n    }\n    return false;\n  }\n\n\
    \  int count_lt(const T& key) const {\n    node* t = root;\n    int res = 0;\n\
    \    while (t) {\n      if (cmp(key, t->key)) {\n        t = t->l;\n      } else\
    \ if (cmp(t->key, key)) {\n        res += size(t->l) + 1;\n        t = t->r;\n\
    \      } else {\n        res += size(t->l);\n        return res;\n      }\n  \
    \  }\n    return res;\n  }\n\n  int count_le(const T& key) const {\n    node*\
    \ t = root;\n    int res = 0;\n    while (t) {\n      if (cmp(key, t->key)) {\n\
    \        t = t->l;\n      } else {\n        res += size(t->l) + 1;\n        t\
    \ = t->r;\n      }\n    }\n    return res;\n  }\n\n  bool lower_bound(const T&\
    \ key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (!cmp(t->key, key)) {\n        ok = true;\n       \
    \ best = t->key;\n        t = t->l;\n      } else {\n        t = t->r;\n     \
    \ }\n    }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool upper_bound(const\
    \ T& key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (cmp(key, t->key)) {\n        ok = true;\n        best\
    \ = t->key;\n        t = t->l;\n      } else {\n        t = t->r;\n      }\n \
    \   }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool prev(const T& key,\
    \ T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n  \
    \  while (t) {\n      if (cmp(t->key, key)) {\n        ok = true;\n        best\
    \ = t->key;\n        t = t->r;\n      } else {\n        t = t->l;\n      }\n \
    \   }\n    if (ok) out = best;\n    return ok;\n  }\n\n  bool prev_eq(const T&\
    \ key, T& out) const {\n    node* t = root;\n    bool ok = false;\n    T best;\n\
    \    while (t) {\n      if (!cmp(key, t->key)) {\n        ok = true;\n       \
    \ best = t->key;\n        t = t->r;\n      } else {\n        t = t->l;\n     \
    \ }\n    }\n    if (ok) out = best;\n    return ok;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/treap.hpp
  requiredBy: []
  timestamp: '2026-03-11 05:43:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_predecessor_problem.test.cpp
  - verify/yosupo_ordered_set.test.cpp
documentation_of: //structure/treap.hpp
layout: document
title: Treap
---

Definition
Treap は乱数優先度付きの二分探索木であり、順序付き集合として insert/erase/contains と順序統計（kth、count_lt、count_le、lower_bound、upper_bound、prev、prev_eq）を提供する。

Complexity
各操作は期待 O(log n)。

使い方

- `treap<T, Cmp> tr;` で空の集合を作る。
- `tr.size();` で要素数を取得する。
- `tr.contains(key);` で存在判定する。
- `tr.insert(key);` で要素を追加する。重複は無視される。
- `tr.erase(key);` で要素を削除する。
- `tr.kth(k, out);` で 0-indexed の k 番目を取得し、成功なら true。
- `tr.count_lt(key);` で key 未満の個数を返す。
- `tr.count_le(key);` で key 以下の個数を返す。
- `tr.lower_bound(key, out);` で key 以上の最小要素を取得する。
- `tr.upper_bound(key, out);` で key より大きい最小要素を取得する。
- `tr.prev(key, out);` で key 未満の最大要素を取得する。
- `tr.prev_eq(key, out);` で key 以下の最大要素を取得する。
- `Cmp` は順序の比較関数で、デフォルトは昇順。
- `size(node*)`, `pull(node*)`, `rnd()`, `eq(a, b)`, `split`, `merge`, `insert(node*, node*)`, `erase(node*, key)` は内部用の補助関数。

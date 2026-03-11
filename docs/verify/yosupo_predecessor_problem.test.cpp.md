---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/treap.hpp
    title: Treap
  - icon: ':heavy_check_mark:'
    path: utility/randgen.hpp
    title: "\u4E71\u6570\u751F\u6210"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/yosupo_predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#line 2 \"structure/treap.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"utility/randgen.hpp\"\
    \nusing namespace std;\n\nstruct randgen {\n  mt19937_64 rng;\n\n  randgen() {\n\
    \    uint64_t seed = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();\n\
    \    rng.seed(seed);\n  }\n\n  uint64_t u64() { return rng(); }\n\n  long long\
    \ ll(long long l, long long r) {\n    return uniform_int_distribution<long long>(l,\
    \ r - 1)(rng);\n  }\n\n  int i(int l, int r) { return uniform_int_distribution<int>(l,\
    \ r - 1)(rng); }\n\n  double real(double l = 0.0, double r = 1.0) {\n    return\
    \ uniform_real_distribution<double>(l, r)(rng);\n  }\n\n  template <class T>\n\
    \  void shuffle_vec(vector<T>& v) {\n    shuffle(v.begin(), v.end(), rng);\n \
    \ }\n};\n#line 6 \"structure/treap.hpp\"\n\ntemplate <class T, class Cmp = less<T>>\n\
    struct treap {\n  struct node {\n    T key;\n    uint32_t pr;\n    int sz;\n \
    \   node* l;\n    node* r;\n    node(const T& k, uint32_t p) : key(k), pr(p),\
    \ sz(1), l(nullptr), r(nullptr) {}\n  };\n\n  Cmp cmp;\n  randgen rg;\n  node*\
    \ root;\n\n  treap() : cmp(), rg(), root(nullptr) {}\n\n  static int size(node*\
    \ t) { return t ? t->sz : 0; }\n  static void pull(node* t) {\n    if (t) t->sz\
    \ = 1 + size(t->l) + size(t->r);\n  }\n\n  int size() const { return size(root);\
    \ }\n\n  uint32_t rnd() { return (uint32_t)rg.u64(); }\n\n  bool eq(const T& a,\
    \ const T& b) const { return !cmp(a, b) && !cmp(b, a); }\n\n  void split(node*\
    \ t, const T& key, node*& a, node*& b) {\n    if (!t) {\n      a = nullptr;\n\
    \      b = nullptr;\n      return;\n    }\n    if (cmp(t->key, key)) {\n     \
    \ split(t->r, key, t->r, b);\n      a = t;\n      pull(a);\n    } else {\n   \
    \   split(t->l, key, a, t->l);\n      b = t;\n      pull(b);\n    }\n  }\n\n \
    \ node* merge(node* a, node* b) {\n    if (!a || !b) return a ? a : b;\n    if\
    \ (a->pr > b->pr) {\n      a->r = merge(a->r, b);\n      pull(a);\n      return\
    \ a;\n    } else {\n      b->l = merge(a, b->l);\n      pull(b);\n      return\
    \ b;\n    }\n  }\n\n  bool contains(const T& key) const {\n    node* t = root;\n\
    \    while (t) {\n      if (eq(key, t->key)) return true;\n      if (cmp(key,\
    \ t->key))\n        t = t->l;\n      else\n        t = t->r;\n    }\n    return\
    \ false;\n  }\n\n  void insert(const T& key) {\n    if (contains(key)) return;\n\
    \    node* it = new node(key, rnd());\n    insert(root, it);\n  }\n\n  void insert(node*&\
    \ t, node* it) {\n    if (!t) {\n      t = it;\n      return;\n    }\n    if (it->pr\
    \ > t->pr) {\n      split(t, it->key, it->l, it->r);\n      t = it;\n      pull(t);\n\
    \      return;\n    }\n    if (cmp(it->key, t->key))\n      insert(t->l, it);\n\
    \    else\n      insert(t->r, it);\n    pull(t);\n  }\n\n  void erase(const T&\
    \ key) { erase(root, key); }\n\n  void erase(node*& t, const T& key) {\n    if\
    \ (!t) return;\n    if (eq(key, t->key)) {\n      node* u = merge(t->l, t->r);\n\
    \      delete t;\n      t = u;\n      return;\n    }\n    if (cmp(key, t->key))\n\
    \      erase(t->l, key);\n    else\n      erase(t->r, key);\n    pull(t);\n  }\n\
    \n  bool kth(int k, T& out) const {\n    if (k < 0 || k >= size()) return false;\n\
    \    node* t = root;\n    while (t) {\n      int ls = size(t->l);\n      if (k\
    \ < ls)\n        t = t->l;\n      else if (k == ls) {\n        out = t->key;\n\
    \        return true;\n      } else {\n        k -= ls + 1;\n        t = t->r;\n\
    \      }\n    }\n    return false;\n  }\n\n  int count_lt(const T& key) const\
    \ {\n    node* t = root;\n    int res = 0;\n    while (t) {\n      if (cmp(key,\
    \ t->key)) {\n        t = t->l;\n      } else if (cmp(t->key, key)) {\n      \
    \  res += size(t->l) + 1;\n        t = t->r;\n      } else {\n        res += size(t->l);\n\
    \        return res;\n      }\n    }\n    return res;\n  }\n\n  int count_le(const\
    \ T& key) const {\n    node* t = root;\n    int res = 0;\n    while (t) {\n  \
    \    if (cmp(key, t->key)) {\n        t = t->l;\n      } else {\n        res +=\
    \ size(t->l) + 1;\n        t = t->r;\n      }\n    }\n    return res;\n  }\n\n\
    \  bool lower_bound(const T& key, T& out) const {\n    node* t = root;\n    bool\
    \ ok = false;\n    T best;\n    while (t) {\n      if (!cmp(t->key, key)) {\n\
    \        ok = true;\n        best = t->key;\n        t = t->l;\n      } else {\n\
    \        t = t->r;\n      }\n    }\n    if (ok) out = best;\n    return ok;\n\
    \  }\n\n  bool upper_bound(const T& key, T& out) const {\n    node* t = root;\n\
    \    bool ok = false;\n    T best;\n    while (t) {\n      if (cmp(key, t->key))\
    \ {\n        ok = true;\n        best = t->key;\n        t = t->l;\n      } else\
    \ {\n        t = t->r;\n      }\n    }\n    if (ok) out = best;\n    return ok;\n\
    \  }\n\n  bool prev(const T& key, T& out) const {\n    node* t = root;\n    bool\
    \ ok = false;\n    T best;\n    while (t) {\n      if (cmp(t->key, key)) {\n \
    \       ok = true;\n        best = t->key;\n        t = t->r;\n      } else {\n\
    \        t = t->l;\n      }\n    }\n    if (ok) out = best;\n    return ok;\n\
    \  }\n\n  bool prev_eq(const T& key, T& out) const {\n    node* t = root;\n  \
    \  bool ok = false;\n    T best;\n    while (t) {\n      if (!cmp(key, t->key))\
    \ {\n        ok = true;\n        best = t->key;\n        t = t->r;\n      } else\
    \ {\n        t = t->l;\n      }\n    }\n    if (ok) out = best;\n    return ok;\n\
    \  }\n};\n#line 3 \"verify/yosupo_predecessor_problem.test.cpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  string T;\n  cin >> T;\n\n  treap<int> tr;\n  for (int i = 0;\
    \ i < N; i++) {\n    if (T[i] == '1') tr.insert(i);\n  }\n\n  for (int i = 0;\
    \ i < Q; i++) {\n    int c, k;\n    cin >> c >> k;\n    if (c == 0) {\n      tr.insert(k);\n\
    \    } else if (c == 1) {\n      tr.erase(k);\n    } else if (c == 2) {\n    \
    \  cout << (tr.contains(k) ? 1 : 0) << '\\n';\n    } else if (c == 3) {\n    \
    \  int v;\n      if (tr.lower_bound(k, v))\n        cout << v << '\\n';\n    \
    \  else\n        cout << -1 << '\\n';\n    } else if (c == 4) {\n      int v;\n\
    \      if (tr.prev_eq(k, v))\n        cout << v << '\\n';\n      else\n      \
    \  cout << -1 << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"structure/treap.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int N, Q;\n  cin >> N >> Q;\n  string T;\n  cin >> T;\n\
    \n  treap<int> tr;\n  for (int i = 0; i < N; i++) {\n    if (T[i] == '1') tr.insert(i);\n\
    \  }\n\n  for (int i = 0; i < Q; i++) {\n    int c, k;\n    cin >> c >> k;\n \
    \   if (c == 0) {\n      tr.insert(k);\n    } else if (c == 1) {\n      tr.erase(k);\n\
    \    } else if (c == 2) {\n      cout << (tr.contains(k) ? 1 : 0) << '\\n';\n\
    \    } else if (c == 3) {\n      int v;\n      if (tr.lower_bound(k, v))\n   \
    \     cout << v << '\\n';\n      else\n        cout << -1 << '\\n';\n    } else\
    \ if (c == 4) {\n      int v;\n      if (tr.prev_eq(k, v))\n        cout << v\
    \ << '\\n';\n      else\n        cout << -1 << '\\n';\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - structure/treap.hpp
  - utility/randgen.hpp
  isVerificationFile: true
  path: verify/yosupo_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 22:08:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_predecessor_problem.test.cpp
- /verify/verify/yosupo_predecessor_problem.test.cpp.html
title: verify/yosupo_predecessor_problem.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/affine.hpp
    title: Affine
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: structure/dynamicsegtree.hpp
    title: Dynamic Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"verify/yosupo_point_set_range_composite_large_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n#line 2 \"math/affine.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <class T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0) {}\n\
    \  affine(T a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a * x +\
    \ b; }\n};\n\ntemplate <class T>\ninline affine<T> affine_add(const affine<T>&\
    \ f, const affine<T>& g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n}\n\ntemplate\
    \ <class T>\ninline affine<T> affine_compose(const affine<T>& f, const affine<T>&\
    \ g) {\n  return affine<T>(f.a * g.a, f.a * g.b + f.b);\n}\n#line 3 \"math/modint.hpp\"\
    \nusing namespace std;\n\ntemplate <long long MOD>\nstruct modint {\n  long long\
    \ v;\n\n  modint() : v(0) {}\n  modint(long long x) {\n    x %= MOD;\n    if (x\
    \ < 0) x += MOD;\n    v = x;\n  }\n\n  static modint raw(long long x) {\n    modint\
    \ m;\n    m.v = x;\n    return m;\n  }\n\n  modint& operator+=(const modint& o)\
    \ {\n    v += o.v;\n    if (v >= MOD) v -= MOD;\n    return *this;\n  }\n  modint&\
    \ operator-=(const modint& o) {\n    v -= o.v;\n    if (v < 0) v += MOD;\n   \
    \ return *this;\n  }\n  modint& operator*=(const modint& o) {\n    v = (long long)((__int128)v\
    \ * o.v % MOD);\n    return *this;\n  }\n\n  modint operator+(const modint& o)\
    \ const { return modint(*this) += o; }\n  modint operator-(const modint& o) const\
    \ { return modint(*this) -= o; }\n  modint operator*(const modint& o) const {\
    \ return modint(*this) *= o; }\n\n  modint operator-() const { return v == 0 ?\
    \ *this : modint::raw(MOD - v); }\n\n  bool operator==(const modint& o) const\
    \ { return v == o.v; }\n  bool operator!=(const modint& o) const { return v !=\
    \ o.v; }\n\n  static modint pow(modint a, long long e) {\n    modint r = 1;\n\
    \    while (e > 0) {\n      if (e & 1) r *= a;\n      a *= a;\n      e >>= 1;\n\
    \    }\n    return r;\n  }\n\n  static modint inv(modint a) { return pow(a, MOD\
    \ - 2); }\n\n  friend ostream& operator<<(ostream& os, const modint& x) {\n  \
    \  return os << x.v;\n  }\n  friend istream& operator>>(istream& is, modint& x)\
    \ {\n    long long t;\n    is >> t;\n    x = modint(t);\n    return is;\n  }\n\
    };\n#line 3 \"structure/dynamicsegtree.hpp\"\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct dynamic_segtree {\n  struct node\
    \ {\n    S val;\n    int l;\n    int r;\n  };\n\n  long long n;\n  vector<node>\
    \ nd;\n  int root;\n\n  dynamic_segtree() : n(0), root(-1) {}\n  dynamic_segtree(long\
    \ long n_) { init(n_); }\n\n  void init(long long n_) {\n    n = n_;\n    nd.clear();\n\
    \    root = -1;\n  }\n\n  int new_node() {\n    nd.push_back({e(), -1, -1});\n\
    \    return (int)nd.size() - 1;\n  }\n\n  void set(long long p, S x) { root =\
    \ set(root, 0, n, p, x); }\n\n  S get(long long p) { return prod(p, p + 1); }\n\
    \n  S prod(long long l, long long r) { return prod(root, 0, n, l, r); }\n\n  S\
    \ all_prod() { return root == -1 ? e() : nd[root].val; }\n\n  int set(int v, long\
    \ long l, long long r, long long p, S x) {\n    if (v == -1) v = new_node();\n\
    \    if (r - l == 1) {\n      nd[v].val = x;\n      return v;\n    }\n    long\
    \ long m = (l + r) >> 1;\n    if (p < m) {\n      nd[v].l = set(nd[v].l, l, m,\
    \ p, x);\n    } else {\n      nd[v].r = set(nd[v].r, m, r, p, x);\n    }\n   \
    \ S lv = nd[v].l == -1 ? e() : nd[nd[v].l].val;\n    S rv = nd[v].r == -1 ? e()\
    \ : nd[nd[v].r].val;\n    nd[v].val = op(lv, rv);\n    return v;\n  }\n\n  S prod(int\
    \ v, long long l, long long r, long long ql, long long qr) {\n    if (v == -1\
    \ || qr <= l || r <= ql) return e();\n    if (ql <= l && r <= qr) return nd[v].val;\n\
    \    long long m = (l + r) >> 1;\n    S lv = prod(nd[v].l, l, m, ql, qr);\n  \
    \  S rv = prod(nd[v].r, m, r, ql, qr);\n    return op(lv, rv);\n  }\n};\n#line\
    \ 5 \"verify/yosupo_point_set_range_composite_large_array.test.cpp\"\n\nstatic\
    \ const long long MOD = 998244353;\nusing mint = modint<MOD>;\nusing F = affine<mint>;\n\
    \nF op(F x, F y) {\n  return affine_compose(y, x);\n}\nF e() { return F(mint(1),\
    \ mint(0)); }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  long long N;\n  int Q;\n  cin >> N >> Q;\n  dynamic_segtree<F, op, e> st(N);\n\
    \  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n\
    \      long long p;\n      mint c, d;\n      cin >> p >> c >> d;\n      st.set(p,\
    \ F(c, d));\n    } else {\n      long long l, r;\n      mint x;\n      cin >>\
    \ l >> r >> x;\n      F f = st.prod(l, r);\n      cout << f.eval(x) << \"\\n\"\
    ;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n#include \"math/affine.hpp\"\n#include \"math/modint.hpp\"\n#include \"structure/dynamicsegtree.hpp\"\
    \n\nstatic const long long MOD = 998244353;\nusing mint = modint<MOD>;\nusing\
    \ F = affine<mint>;\n\nF op(F x, F y) {\n  return affine_compose(y, x);\n}\nF\
    \ e() { return F(mint(1), mint(0)); }\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  long long N;\n  int Q;\n  cin >> N >> Q;\n  dynamic_segtree<F,\
    \ op, e> st(N);\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      long long p;\n      mint c, d;\n      cin >> p >> c\
    \ >> d;\n      st.set(p, F(c, d));\n    } else {\n      long long l, r;\n    \
    \  mint x;\n      cin >> l >> r >> x;\n      F f = st.prod(l, r);\n      cout\
    \ << f.eval(x) << \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/affine.hpp
  - math/modint.hpp
  - structure/dynamicsegtree.hpp
  isVerificationFile: true
  path: verify/yosupo_point_set_range_composite_large_array.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 18:00:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_point_set_range_composite_large_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_point_set_range_composite_large_array.test.cpp
- /verify/verify/yosupo_point_set_range_composite_large_array.test.cpp.html
title: verify/yosupo_point_set_range_composite_large_array.test.cpp
---

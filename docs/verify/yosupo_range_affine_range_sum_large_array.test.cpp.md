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
    path: structure/dynamiclazysegtree.hpp
    title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum_large_array
  bundledCode: "#line 1 \"verify/yosupo_range_affine_range_sum_large_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"math/affine.hpp\"\
    \nusing namespace std;\n\ntemplate <class T>\nstruct affine {\n  T a, b;\n  affine()\
    \ : a(1), b(0) {}\n  affine(T a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const\
    \ { return a * x + b; }\n};\n\ntemplate <class T>\ninline affine<T> affine_add(const\
    \ affine<T>& f, const affine<T>& g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n\
    }\n\ntemplate <class T>\ninline affine<T> affine_compose(const affine<T>& f, const\
    \ affine<T>& g) {\n  return affine<T>(f.a * g.a, f.a * g.b + f.b);\n}\n#line 3\
    \ \"math/modint.hpp\"\nusing namespace std;\n\ntemplate <long long MOD>\nstruct\
    \ modint {\n  long long v;\n\n  modint() : v(0) {}\n  modint(long long x) {\n\
    \    x %= MOD;\n    if (x < 0) x += MOD;\n    v = x;\n  }\n\n  static modint raw(long\
    \ long x) {\n    modint m;\n    m.v = x;\n    return m;\n  }\n\n  modint& operator+=(const\
    \ modint& o) {\n    v += o.v;\n    if (v >= MOD) v -= MOD;\n    return *this;\n\
    \  }\n  modint& operator-=(const modint& o) {\n    v -= o.v;\n    if (v < 0) v\
    \ += MOD;\n    return *this;\n  }\n  modint& operator*=(const modint& o) {\n \
    \   v = (long long)((__int128)v * o.v % MOD);\n    return *this;\n  }\n\n  modint\
    \ operator+(const modint& o) const { return modint(*this) += o; }\n  modint operator-(const\
    \ modint& o) const { return modint(*this) -= o; }\n  modint operator*(const modint&\
    \ o) const { return modint(*this) *= o; }\n\n  modint operator-() const { return\
    \ v == 0 ? *this : modint::raw(MOD - v); }\n\n  bool operator==(const modint&\
    \ o) const { return v == o.v; }\n  bool operator!=(const modint& o) const { return\
    \ v != o.v; }\n\n  static modint pow(modint a, long long e) {\n    modint r =\
    \ 1;\n    while (e > 0) {\n      if (e & 1) r *= a;\n      a *= a;\n      e >>=\
    \ 1;\n    }\n    return r;\n  }\n\n  static modint inv(modint a) { return pow(a,\
    \ MOD - 2); }\n\n  friend ostream& operator<<(ostream& os, const modint& x) {\n\
    \    return os << x.v;\n  }\n  friend istream& operator>>(istream& is, modint&\
    \ x) {\n    long long t;\n    is >> t;\n    x = modint(t);\n    return is;\n \
    \ }\n};\n#line 3 \"structure/dynamiclazysegtree.hpp\"\nusing namespace std;\n\n\
    template <class S, S (*op)(S, S), S (*e)(), S (*make)(long long), class F,\n \
    \         S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>\nstruct dynamic_lazysegtree\
    \ {\n  struct node {\n    S val;\n    F lz;\n    int l;\n    int r;\n    bool\
    \ has;\n  };\n\n  long long n;\n  vector<node> nd;\n  int root;\n\n  dynamic_lazysegtree()\
    \ : n(0), root(-1) {}\n  dynamic_lazysegtree(long long n_) { init(n_); }\n\n \
    \ void init(long long n_) {\n    n = n_;\n    nd.clear();\n    root = -1;\n  }\n\
    \n  int new_node(long long len) {\n    nd.push_back({make(len), id(), -1, -1,\
    \ false});\n    return (int)nd.size() - 1;\n  }\n\n  void set(long long p, S x)\
    \ { root = set(root, 0, n, p, x); }\n\n  S get(long long p) { return prod(p, p\
    \ + 1); }\n\n  S prod(long long l, long long r) { return prod(root, 0, n, l, r);\
    \ }\n\n  S all_prod() { return root == -1 ? make(n) : nd[root].val; }\n\n  void\
    \ apply(long long l, long long r, F f) {\n    root = apply(root, 0, n, l, r, f);\n\
    \  }\n\n  int set(int v, long long l, long long r, long long p, S x) {\n    if\
    \ (v == -1) v = new_node(r - l);\n    if (r - l == 1) {\n      nd[v].val = x;\n\
    \      nd[v].lz = id();\n      nd[v].has = false;\n      return v;\n    }\n  \
    \  push(v, l, r);\n    long long m = (l + r) >> 1;\n    if (p < m) {\n      nd[v].l\
    \ = set(nd[v].l, l, m, p, x);\n    } else {\n      nd[v].r = set(nd[v].r, m, r,\
    \ p, x);\n    }\n    pull(v, l, r);\n    return v;\n  }\n\n  int apply(int v,\
    \ long long l, long long r, long long ql, long long qr, F f) {\n    if (qr <=\
    \ l || r <= ql) return v;\n    if (v == -1) v = new_node(r - l);\n    if (ql <=\
    \ l && r <= qr) {\n      all_apply(v, f);\n      return v;\n    }\n    push(v,\
    \ l, r);\n    long long m = (l + r) >> 1;\n    nd[v].l = apply(nd[v].l, l, m,\
    \ ql, qr, f);\n    nd[v].r = apply(nd[v].r, m, r, ql, qr, f);\n    pull(v, l,\
    \ r);\n    return v;\n  }\n\n  S prod(int v, long long l, long long r, long long\
    \ ql, long long qr) {\n    if (qr <= l || r <= ql) return e();\n    if (v == -1)\
    \ {\n      long long len = min(r, qr) - max(l, ql);\n      if (len <= 0) return\
    \ e();\n      return make(len);\n    }\n    if (ql <= l && r <= qr) return nd[v].val;\n\
    \    push(v, l, r);\n    long long m = (l + r) >> 1;\n    S lv = prod(nd[v].l,\
    \ l, m, ql, qr);\n    S rv = prod(nd[v].r, m, r, ql, qr);\n    return op(lv, rv);\n\
    \  }\n\n  void all_apply(int v, F f) {\n    nd[v].val = mapping(f, nd[v].val);\n\
    \    if (nd[v].has) {\n      nd[v].lz = composition(f, nd[v].lz);\n    } else\
    \ {\n      nd[v].lz = f;\n      nd[v].has = true;\n    }\n  }\n\n  void push(int\
    \ v, long long l, long long r) {\n    if (!nd[v].has || r - l == 1) return;\n\
    \    long long m = (l + r) >> 1;\n    if (nd[v].l == -1) nd[v].l = new_node(m\
    \ - l);\n    if (nd[v].r == -1) nd[v].r = new_node(r - m);\n    all_apply(nd[v].l,\
    \ nd[v].lz);\n    all_apply(nd[v].r, nd[v].lz);\n    nd[v].lz = id();\n    nd[v].has\
    \ = false;\n  }\n\n  void pull(int v, long long l, long long r) {\n    long long\
    \ m = (l + r) >> 1;\n    S lv = nd[v].l == -1 ? make(m - l) : nd[nd[v].l].val;\n\
    \    S rv = nd[v].r == -1 ? make(r - m) : nd[nd[v].r].val;\n    nd[v].val = op(lv,\
    \ rv);\n  }\n};\n#line 8 \"verify/yosupo_range_affine_range_sum_large_array.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct S {\n  mint sum;\n  long long len;\n\
    };\n\nusing F = affine<mint>;\n\nS op(S a, S b) { return {a.sum + b.sum, a.len\
    \ + b.len}; }\nS e() { return {mint(0), 0}; }\nS make(long long len) { return\
    \ {mint(0), len}; }\nS mapping(F f, S x) { return {f.a * x.sum + f.b * mint(x.len),\
    \ x.len}; }\nF composition(F f, F g) { return affine_compose(f, g); }\nF id()\
    \ { return F(); }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  long long N;\n  int Q;\n  if (!(cin >> N >> Q)) return 0;\n  dynamic_lazysegtree<S,\
    \ op, e, make, F, mapping, composition, id> seg(N);\n  for (int i = 0; i < Q;\
    \ i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      long long l, r;\n\
    \      long long b, c;\n      cin >> l >> r >> b >> c;\n      seg.apply(l, r,\
    \ F(mint(b), mint(c)));\n    } else {\n      long long l, r;\n      cin >> l >>\
    \ r;\n      cout << seg.prod(l, r).sum.v << \"\\n\";\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum_large_array\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/affine.hpp\"\
    \n#include \"math/modint.hpp\"\n#include \"structure/dynamiclazysegtree.hpp\"\n\
    \nusing mint = modint<998244353>;\n\nstruct S {\n  mint sum;\n  long long len;\n\
    };\n\nusing F = affine<mint>;\n\nS op(S a, S b) { return {a.sum + b.sum, a.len\
    \ + b.len}; }\nS e() { return {mint(0), 0}; }\nS make(long long len) { return\
    \ {mint(0), len}; }\nS mapping(F f, S x) { return {f.a * x.sum + f.b * mint(x.len),\
    \ x.len}; }\nF composition(F f, F g) { return affine_compose(f, g); }\nF id()\
    \ { return F(); }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  long long N;\n  int Q;\n  if (!(cin >> N >> Q)) return 0;\n  dynamic_lazysegtree<S,\
    \ op, e, make, F, mapping, composition, id> seg(N);\n  for (int i = 0; i < Q;\
    \ i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      long long l, r;\n\
    \      long long b, c;\n      cin >> l >> r >> b >> c;\n      seg.apply(l, r,\
    \ F(mint(b), mint(c)));\n    } else {\n      long long l, r;\n      cin >> l >>\
    \ r;\n      cout << seg.prod(l, r).sum.v << \"\\n\";\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - math/affine.hpp
  - math/modint.hpp
  - structure/dynamiclazysegtree.hpp
  isVerificationFile: true
  path: verify/yosupo_range_affine_range_sum_large_array.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 20:50:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_range_affine_range_sum_large_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_range_affine_range_sum_large_array.test.cpp
- /verify/verify/yosupo_range_affine_range_sum_large_array.test.cpp.html
title: verify/yosupo_range_affine_range_sum_large_array.test.cpp
---

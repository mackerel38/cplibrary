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
    path: structure/segtree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/yosupo_point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n#line\
    \ 2 \"math/affine.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0) {}\n  affine(T\
    \ a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a * x + b; }\n};\n\
    \ntemplate <class T>\ninline affine<T> affine_add(const affine<T>& f, const affine<T>&\
    \ g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n}\n\ntemplate <class T>\ninline\
    \ affine<T> affine_compose(const affine<T>& f, const affine<T>& g) {\n  return\
    \ affine<T>(f.a * g.a, f.a * g.b + f.b);\n}\n#line 3 \"math/modint.hpp\"\nusing\
    \ namespace std;\n\ntemplate <long long MOD>\nstruct modint {\n  long long v;\n\
    \n  modint() : v(0) {}\n  modint(long long x) {\n    x %= MOD;\n    if (x < 0)\
    \ x += MOD;\n    v = x;\n  }\n\n  static modint raw(long long x) {\n    modint\
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
    };\n#line 3 \"structure/segtree.hpp\"\nusing namespace std;\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n  int n;\n  int sz;\n  int lg;\n\
    \  vector<S> d;\n  segtree() : n(0), sz(1), lg(0), d(1, e()) {}\n  segtree(int\
    \ n_) { init(n_); }\n  segtree(const vector<S>& v) { build(v); }\n  void init(int\
    \ n_) {\n    n = n_;\n    sz = 1;\n    lg = 0;\n    while (sz < n) {\n      sz\
    \ <<= 1;\n      lg++;\n    }\n    d.assign(2 * sz, e());\n  }\n  void build(const\
    \ vector<S>& v) {\n    init((int)v.size());\n    for (int i = 0; i < n; i++) d[sz\
    \ + i] = v[i];\n    for (int i = sz - 1; i >= 1; i--) d[i] = op(d[i << 1], d[i\
    \ << 1 | 1]);\n  }\n  void set(int p, S x) {\n    p += sz;\n    d[p] = x;\n  \
    \  for (int i = 1; i <= lg; i++) {\n      int k = p >> i;\n      d[k] = op(d[k\
    \ << 1], d[k << 1 | 1]);\n    }\n  }\n  S get(int p) const { return d[p + sz];\
    \ }\n  S prod(int l, int r) const {\n    S sml = e();\n    S smr = e();\n    l\
    \ += sz;\n    r += sz;\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n  S all_prod() const { return d[1]; }\n  template\
    \ <class F>\n  int max_right(int l, F f) const {\n    if (l == n) return n;\n\
    \    S sm = e();\n    l += sz;\n    do {\n      while ((l & 1) == 0) l >>= 1;\n\
    \      if (!f(op(sm, d[l]))) {\n        while (l < sz) {\n          l <<= 1;\n\
    \          if (f(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n          \
    \  l++;\n          }\n        }\n        return l - sz;\n      }\n      sm = op(sm,\
    \ d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    if (r == 0) return 0;\n \
    \   S sm = e();\n    r += sz;\n    do {\n      r--;\n      while (r > 1 && (r\
    \ & 1)) r >>= 1;\n      if (!f(op(d[r], sm))) {\n        while (r < sz) {\n  \
    \        r = r << 1 | 1;\n          if (f(op(d[r], sm))) {\n            sm = op(d[r],\
    \ sm);\n            r--;\n          }\n        }\n        return r + 1 - sz;\n\
    \      }\n      sm = op(d[r], sm);\n    } while ((r & -r) != r);\n    return 0;\n\
    \  }\n};\n#line 5 \"verify/yosupo_point_set_range_composite.test.cpp\"\n\nstatic\
    \ const long long MOD = 998244353;\nusing mint = modint<MOD>;\nusing F = affine<mint>;\n\
    \nF op(F x, F y) {\n  return affine_compose(y, x);\n}\nF e() { return F(mint(1),\
    \ mint(0)); }\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<F> v(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    mint a, b;\n    cin >> a >> b;\n    v[i] = F(a, b);\n  }\n  segtree<F,\
    \ op, e> st(v);\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      int p;\n      mint c, d;\n      cin >> p >> c >> d;\n\
    \      st.set(p, F(c, d));\n    } else {\n      int l, r;\n      mint x;\n   \
    \   cin >> l >> r >> x;\n      F f = st.prod(l, r);\n      cout << f.eval(x) <<\
    \ \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"math/affine.hpp\"\n#include \"math/modint.hpp\"\n#include \"structure/segtree.hpp\"\
    \n\nstatic const long long MOD = 998244353;\nusing mint = modint<MOD>;\nusing\
    \ F = affine<mint>;\n\nF op(F x, F y) {\n  return affine_compose(y, x);\n}\nF\
    \ e() { return F(mint(1), mint(0)); }\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<F> v(N);\n  for\
    \ (int i = 0; i < N; i++) {\n    mint a, b;\n    cin >> a >> b;\n    v[i] = F(a,\
    \ b);\n  }\n  segtree<F, op, e> st(v);\n  for (int i = 0; i < Q; i++) {\n    int\
    \ t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      mint c, d;\n     \
    \ cin >> p >> c >> d;\n      st.set(p, F(c, d));\n    } else {\n      int l, r;\n\
    \      mint x;\n      cin >> l >> r >> x;\n      F f = st.prod(l, r);\n      cout\
    \ << f.eval(x) << \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/affine.hpp
  - math/modint.hpp
  - structure/segtree.hpp
  isVerificationFile: true
  path: verify/yosupo_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 17:47:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_point_set_range_composite.test.cpp
- /verify/verify/yosupo_point_set_range_composite.test.cpp.html
title: verify/yosupo_point_set_range_composite.test.cpp
---

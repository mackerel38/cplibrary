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
    path: structure/lazysegtree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: structure/range_affine_range_sum.hpp
    title: Range Affine Range Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#line 2\
    \ \"structure/range_affine_range_sum.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"math/affine.hpp\"\nusing namespace std;\n\ntemplate <class\
    \ T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0) {}\n  affine(T a_, T\
    \ b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a * x + b; }\n};\n\ntemplate\
    \ <class T>\ninline affine<T> affine_add(const affine<T>& f, const affine<T>&\
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
    };\n#line 3 \"structure/lazysegtree.hpp\"\nusing namespace std;\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F), F (*id)()>\nstruct lazysegtree {\n  int n;\n  int sz;\n  int lg;\n  vector<S>\
    \ d;\n  vector<F> lz;\n\n  lazysegtree() : n(0), sz(1), lg(0) {\n    d.assign(1,\
    \ e());\n    lz.assign(1, id());\n  }\n  lazysegtree(int n_) { init(n_); }\n \
    \ lazysegtree(const vector<S>& v) { build(v); }\n\n  void init(int n_) {\n   \
    \ n = n_;\n    sz = 1;\n    lg = 0;\n    while (sz < n) {\n      sz <<= 1;\n \
    \     lg++;\n    }\n    d.assign(2 * sz, e());\n    lz.assign(sz, id());\n  }\n\
    \n  void build(const vector<S>& v) {\n    init((int)v.size());\n    for (int i\
    \ = 0; i < n; i++) d[sz + i] = v[i];\n    for (int i = sz - 1; i >= 1; i--) update(i);\n\
    \  }\n\n  void set(int p, S x) {\n    p += sz;\n    for (int i = lg; i >= 1; i--)\
    \ push(p >> i);\n    d[p] = x;\n    for (int i = 1; i <= lg; i++) update(p >>\
    \ i);\n  }\n\n  S get(int p) {\n    p += sz;\n    for (int i = lg; i >= 1; i--)\
    \ push(p >> i);\n    return d[p];\n  }\n\n  S prod(int l, int r) {\n    if (l\
    \ == r) return e();\n    l += sz;\n    r += sz;\n    for (int i = lg; i >= 1;\
    \ i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n    }\n    S sml = e();\n    S smr = e();\n  \
    \  while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n      if (r & 1)\
    \ smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n    return op(sml,\
    \ smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void apply(int p, F f) {\n\
    \    p += sz;\n    for (int i = lg; i >= 1; i--) push(p >> i);\n    d[p] = mapping(f,\
    \ d[p]);\n    for (int i = 1; i <= lg; i++) update(p >> i);\n  }\n\n  void apply(int\
    \ l, int r, F f) {\n    if (l == r) return;\n    l += sz;\n    r += sz;\n    for\
    \ (int i = lg; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int l2 = l;\n\
    \    int r2 = r;\n    while (l < r) {\n      if (l & 1) all_apply(l++, f);\n \
    \     if (r & 1) all_apply(--r, f);\n      l >>= 1;\n      r >>= 1;\n    }\n \
    \   l = l2;\n    r = r2;\n    for (int i = 1; i <= lg; i++) {\n      if (((l >>\
    \ i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n    }\n  }\n\n  void update(int k) { d[k] = op(d[k << 1], d[k <<\
    \ 1 | 1]); }\n\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n\
    \    if (k < sz) lz[k] = composition(f, lz[k]);\n  }\n\n  void push(int k) {\n\
    \    all_apply(k << 1, lz[k]);\n    all_apply(k << 1 | 1, lz[k]);\n    lz[k] =\
    \ id();\n  }\n};\n#line 8 \"structure/range_affine_range_sum.hpp\"\n\ntemplate\
    \ <long long MOD = 998244353>\nstruct range_affine_range_sum {\n  using mint =\
    \ modint<MOD>;\n  struct S {\n    mint sum;\n    int len;\n  };\n  using F = affine<mint>;\n\
    \n  static S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }\n  static\
    \ S e() { return {mint(0), 0}; }\n  static S mapping(F f, S x) {\n    return {f.a\
    \ * x.sum + f.b * mint(x.len), x.len};\n  }\n  static F composition(F f, F g)\
    \ { return affine_compose(f, g); }\n  static F id() { return F(); }\n\n  lazysegtree<S,\
    \ op, e, F, mapping, composition, id> seg;\n\n  range_affine_range_sum() {}\n\
    \  range_affine_range_sum(int n) { init(n); }\n  range_affine_range_sum(const\
    \ vector<mint>& a) { build(a); }\n\n  void init(int n) {\n    vector<S> v(n);\n\
    \    for (int i = 0; i < n; i++) v[i] = {mint(0), 1};\n    seg.build(v);\n  }\n\
    \n  void build(const vector<mint>& a) {\n    int n = (int)a.size();\n    vector<S>\
    \ v(n);\n    for (int i = 0; i < n; i++) v[i] = {a[i], 1};\n    seg.build(v);\n\
    \  }\n\n  void set(int p, mint x) { seg.set(p, {x, 1}); }\n  mint get(int p) {\
    \ return seg.get(p).sum; }\n  mint prod(int l, int r) { return seg.prod(l, r).sum;\
    \ }\n  void apply(int l, int r, F f) { seg.apply(l, r, f); }\n  void apply(int\
    \ l, int r, mint b, mint c) { seg.apply(l, r, F(b, c)); }\n};\n#line 3 \"verify/yosupo_range_affine_range_sum.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n, q;\n  if (!(cin >> n >> q)) return 0;\n  using seg_t = range_affine_range_sum<998244353>;\n\
    \  using mint = seg_t::mint;\n  vector<mint> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    long long x;\n    cin >> x;\n    a[i] = mint(x);\n  }\n  seg_t seg(a);\n\
    \  for (int i = 0; i < q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n\
    \      int l, r;\n      long long b, c;\n      cin >> l >> r >> b >> c;\n    \
    \  seg.apply(l, r, mint(b), mint(c));\n    } else {\n      int l, r;\n      cin\
    \ >> l >> r;\n      cout << seg.prod(l, r) << '\\n';\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"structure/range_affine_range_sum.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n, q;\n  if (!(cin >> n >> q)) return 0;\n  using\
    \ seg_t = range_affine_range_sum<998244353>;\n  using mint = seg_t::mint;\n  vector<mint>\
    \ a(n);\n  for (int i = 0; i < n; i++) {\n    long long x;\n    cin >> x;\n  \
    \  a[i] = mint(x);\n  }\n  seg_t seg(a);\n  for (int i = 0; i < q; i++) {\n  \
    \  int t;\n    cin >> t;\n    if (t == 0) {\n      int l, r;\n      long long\
    \ b, c;\n      cin >> l >> r >> b >> c;\n      seg.apply(l, r, mint(b), mint(c));\n\
    \    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.prod(l,\
    \ r) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/range_affine_range_sum.hpp
  - math/affine.hpp
  - math/modint.hpp
  - structure/lazysegtree.hpp
  isVerificationFile: true
  path: verify/yosupo_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 20:17:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_range_affine_range_sum.test.cpp.html
title: verify/yosupo_range_affine_range_sum.test.cpp
---

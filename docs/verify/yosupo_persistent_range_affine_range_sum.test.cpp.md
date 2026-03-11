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
    path: structure/persistentlazysegtree.hpp
    title: "\u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/persistent_range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_persistent_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_range_affine_range_sum\"\
    \n#line 2 \"structure/persistentlazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F), F (*id)()>\nstruct persistent_lazysegtree\
    \ {\n  struct node {\n    S val;\n    F lz;\n    int l;\n    int r;\n    bool\
    \ has;\n  };\n\n  int n;\n  vector<node> nd;\n  vector<int> root;\n\n  persistent_lazysegtree()\
    \ : n(0) {}\n  persistent_lazysegtree(int n_) { init(n_); }\n  persistent_lazysegtree(const\
    \ vector<S>& v) { build(v); }\n\n  void init(int n_) {\n    n = n_;\n    nd.clear();\n\
    \    root.clear();\n    root.push_back(build_empty(0, n));\n  }\n\n  void build(const\
    \ vector<S>& v) {\n    n = (int)v.size();\n    nd.clear();\n    root.clear();\n\
    \    root.push_back(build_vec(0, n, v));\n  }\n\n  int apply(int ver, int l, int\
    \ r, F f) {\n    int nr = apply(root[ver], 0, n, l, r, f);\n    root.push_back(nr);\n\
    \    return (int)root.size() - 1;\n  }\n\n  int set(int ver, int p, S x) {\n \
    \   int nr = set(root[ver], 0, n, p, x);\n    root.push_back(nr);\n    return\
    \ (int)root.size() - 1;\n  }\n\n  int replace_range(int ver_a, int ver_b, int\
    \ l, int r) {\n    int nr = replace_range(root[ver_a], root[ver_b], 0, n, l, r);\n\
    \    root.push_back(nr);\n    return (int)root.size() - 1;\n  }\n\n  S get(int\
    \ ver, int p) { return prod(ver, p, p + 1); }\n\n  S prod(int ver, int l, int\
    \ r) { return prod(root[ver], 0, n, l, r, id()); }\n\n  int new_node(S val, F\
    \ lz, int l, int r, bool has) {\n    nd.push_back({val, lz, l, r, has});\n   \
    \ return (int)nd.size() - 1;\n  }\n\n  int build_empty(int l, int r) {\n    if\
    \ (r - l == 1) return new_node(e(), id(), -1, -1, false);\n    int m = (l + r)\
    \ >> 1;\n    int lc = build_empty(l, m);\n    int rc = build_empty(m, r);\n  \
    \  return new_node(op(nd[lc].val, nd[rc].val), id(), lc, rc, false);\n  }\n\n\
    \  int build_vec(int l, int r, const vector<S>& v) {\n    if (r - l == 1) return\
    \ new_node(v[l], id(), -1, -1, false);\n    int m = (l + r) >> 1;\n    int lc\
    \ = build_vec(l, m, v);\n    int rc = build_vec(m, r, v);\n    return new_node(op(nd[lc].val,\
    \ nd[rc].val), id(), lc, rc, false);\n  }\n\n  int clone(int v) {\n    nd.push_back(nd[v]);\n\
    \    return (int)nd.size() - 1;\n  }\n\n  void all_apply(int v, F f) {\n    nd[v].val\
    \ = mapping(f, nd[v].val);\n    if (nd[v].has) {\n      nd[v].lz = composition(f,\
    \ nd[v].lz);\n    } else {\n      nd[v].lz = f;\n      nd[v].has = true;\n   \
    \ }\n  }\n\n  void push(int v, int l, int r) {\n    if (r - l == 1) return;\n\
    \    if (!nd[v].has) return;\n    F f = nd[v].lz;\n    int lc = nd[v].l;\n   \
    \ int rc = nd[v].r;\n    lc = clone(lc);\n    rc = clone(rc);\n    all_apply(lc,\
    \ f);\n    all_apply(rc, f);\n    nd[v].l = lc;\n    nd[v].r = rc;\n    nd[v].lz\
    \ = id();\n    nd[v].has = false;\n  }\n\n  int apply(int v, int l, int r, int\
    \ ql, int qr, F f) {\n    if (qr <= l || r <= ql) return v;\n    v = clone(v);\n\
    \    if (ql <= l && r <= qr) {\n      all_apply(v, f);\n      return v;\n    }\n\
    \    push(v, l, r);\n    int m = (l + r) >> 1;\n    int lc = apply(nd[v].l, l,\
    \ m, ql, qr, f);\n    int rc = apply(nd[v].r, m, r, ql, qr, f);\n    nd[v].l =\
    \ lc;\n    nd[v].r = rc;\n    nd[v].val = op(nd[lc].val, nd[rc].val);\n    return\
    \ v;\n  }\n\n  int set(int v, int l, int r, int p, S x) {\n    v = clone(v);\n\
    \    if (r - l == 1) {\n      nd[v].val = x;\n      nd[v].lz = id();\n      nd[v].has\
    \ = false;\n      return v;\n    }\n    push(v, l, r);\n    int m = (l + r) >>\
    \ 1;\n    if (p < m) {\n      nd[v].l = set(nd[v].l, l, m, p, x);\n    } else\
    \ {\n      nd[v].r = set(nd[v].r, m, r, p, x);\n    }\n    nd[v].val = op(nd[nd[v].l].val,\
    \ nd[nd[v].r].val);\n    return v;\n  }\n\n  S prod(int v, int l, int r, int ql,\
    \ int qr, F acc) {\n    if (qr <= l || r <= ql) return e();\n    if (ql <= l &&\
    \ r <= qr) return mapping(acc, nd[v].val);\n    int m = (l + r) >> 1;\n    F nxt\
    \ = acc;\n    if (nd[v].has) nxt = composition(acc, nd[v].lz);\n    S lv = prod(nd[v].l,\
    \ l, m, ql, qr, nxt);\n    S rv = prod(nd[v].r, m, r, ql, qr, nxt);\n    return\
    \ op(lv, rv);\n  }\n\n  int replace_range(int a, int b, int l, int r, int ql,\
    \ int qr) {\n    if (qr <= l || r <= ql) return a;\n    if (ql <= l && r <= qr)\
    \ return b;\n    a = clone(a);\n    b = clone(b);\n    push(a, l, r);\n    push(b,\
    \ l, r);\n    int m = (l + r) >> 1;\n    int lc = replace_range(nd[a].l, nd[b].l,\
    \ l, m, ql, qr);\n    int rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);\n\
    \    nd[a].l = lc;\n    nd[a].r = rc;\n    nd[a].val = op(nd[lc].val, nd[rc].val);\n\
    \    return a;\n  }\n};\n#line 3 \"math/affine.hpp\"\nusing namespace std;\n\n\
    template <class T>\nstruct affine {\n  T a, b;\n  affine() : a(1), b(0) {}\n \
    \ affine(T a_, T b_) : a(a_), b(b_) {}\n  T eval(T x) const { return a * x + b;\
    \ }\n};\n\ntemplate <class T>\ninline affine<T> affine_add(const affine<T>& f,\
    \ const affine<T>& g) {\n  return affine<T>(f.a + g.a, f.b + g.b);\n}\n\ntemplate\
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
    };\n#line 6 \"verify/yosupo_persistent_range_affine_range_sum.test.cpp\"\nusing\
    \ namespace std;\n\nusing mint = modint<998244353>;\nusing F = affine<mint>;\n\
    \nstruct S {\n  mint sum;\n  int len;\n};\n\nS op(S a, S b) { return {a.sum +\
    \ b.sum, a.len + b.len}; }\nS e() { return {mint(0), 0}; }\nS mapping(F f, S x)\
    \ { return {f.a * x.sum + f.b * mint(x.len), x.len}; }\nF composition(F f, F g)\
    \ { return affine_compose(f, g); }\nF id() { return F(); }\n\nusing seg_t = persistent_lazysegtree<S,\
    \ op, e, F, mapping, composition, id>;\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<S> v(N);\n  for\
    \ (int i = 0; i < N; i++) {\n    mint x;\n    cin >> x;\n    v[i] = {x, 1};\n\
    \  }\n  seg_t seg(v);\n  vector<int> ver(Q, -1);\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int k, l, r;\n      long\
    \ long b, c;\n      cin >> k >> l >> r >> b >> c;\n      int base = (k == -1)\
    \ ? 0 : ver[k];\n      ver[i] = seg.apply(base, l, r, F(mint(b), mint(c)));\n\
    \    } else if (t == 1) {\n      int k, s, l, r;\n      cin >> k >> s >> l >>\
    \ r;\n      int base = (k == -1) ? 0 : ver[k];\n      int src = (s == -1) ? 0\
    \ : ver[s];\n      ver[i] = seg.replace_range(base, src, l, r);\n    } else {\n\
    \      int k, l, r;\n      cin >> k >> l >> r;\n      int base = (k == -1) ? 0\
    \ : ver[k];\n      mint ans = seg.prod(base, l, r).sum;\n      cout << ans.v <<\
    \ \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_range_affine_range_sum\"\
    \n#include \"structure/persistentlazysegtree.hpp\"\n#include \"math/affine.hpp\"\
    \n#include \"math/modint.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing mint = modint<998244353>;\nusing F = affine<mint>;\n\nstruct S {\n  mint\
    \ sum;\n  int len;\n};\n\nS op(S a, S b) { return {a.sum + b.sum, a.len + b.len};\
    \ }\nS e() { return {mint(0), 0}; }\nS mapping(F f, S x) { return {f.a * x.sum\
    \ + f.b * mint(x.len), x.len}; }\nF composition(F f, F g) { return affine_compose(f,\
    \ g); }\nF id() { return F(); }\n\nusing seg_t = persistent_lazysegtree<S, op,\
    \ e, F, mapping, composition, id>;\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<S> v(N);\n  for\
    \ (int i = 0; i < N; i++) {\n    mint x;\n    cin >> x;\n    v[i] = {x, 1};\n\
    \  }\n  seg_t seg(v);\n  vector<int> ver(Q, -1);\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int k, l, r;\n      long\
    \ long b, c;\n      cin >> k >> l >> r >> b >> c;\n      int base = (k == -1)\
    \ ? 0 : ver[k];\n      ver[i] = seg.apply(base, l, r, F(mint(b), mint(c)));\n\
    \    } else if (t == 1) {\n      int k, s, l, r;\n      cin >> k >> s >> l >>\
    \ r;\n      int base = (k == -1) ? 0 : ver[k];\n      int src = (s == -1) ? 0\
    \ : ver[s];\n      ver[i] = seg.replace_range(base, src, l, r);\n    } else {\n\
    \      int k, l, r;\n      cin >> k >> l >> r;\n      int base = (k == -1) ? 0\
    \ : ver[k];\n      mint ans = seg.prod(base, l, r).sum;\n      cout << ans.v <<\
    \ \"\\n\";\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/persistentlazysegtree.hpp
  - math/affine.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: verify/yosupo_persistent_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-12 00:17:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_persistent_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_persistent_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_persistent_range_affine_range_sum.test.cpp.html
title: verify/yosupo_persistent_range_affine_range_sum.test.cpp
---

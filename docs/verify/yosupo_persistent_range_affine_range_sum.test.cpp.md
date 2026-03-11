---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/affine.hpp
    title: Affine
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
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
    };\n#line 5 \"verify/yosupo_persistent_range_affine_range_sum.test.cpp\"\nusing\
    \ namespace std;\n\nusing mint = modint<998244353>;\nusing F = affine<mint>;\n\
    \nstruct node {\n  mint sum;\n  int l;\n  int r;\n  F lz;\n  bool has;\n};\n\n\
    struct pst {\n  int n;\n  vector<node> nd;\n  vector<int> root;\n\n  pst() : n(0)\
    \ {}\n  pst(const vector<mint>& a) { build(a); }\n\n  int new_node(mint sum, int\
    \ l, int r, F lz, bool has) {\n    nd.push_back({sum, l, r, lz, has});\n    return\
    \ (int)nd.size() - 1;\n  }\n\n  int build_vec(int l, int r, const vector<mint>&\
    \ a) {\n    if (r - l == 1) return new_node(a[l], -1, -1, F(), false);\n    int\
    \ m = (l + r) >> 1;\n    int lc = build_vec(l, m, a);\n    int rc = build_vec(m,\
    \ r, a);\n    return new_node(nd[lc].sum + nd[rc].sum, lc, rc, F(), false);\n\
    \  }\n\n  void build(const vector<mint>& a) {\n    n = (int)a.size();\n    nd.clear();\n\
    \    root.clear();\n    root.push_back(build_vec(0, n, a));\n  }\n\n  int clone(int\
    \ v) {\n    nd.push_back(nd[v]);\n    return (int)nd.size() - 1;\n  }\n\n  void\
    \ all_apply(int v, F f, int len) {\n    nd[v].sum = f.a * nd[v].sum + f.b * mint(len);\n\
    \    if (nd[v].has) {\n      nd[v].lz = affine_compose(f, nd[v].lz);\n    } else\
    \ {\n      nd[v].lz = f;\n      nd[v].has = true;\n    }\n  }\n\n  void push(int\
    \ v, int l, int r) {\n    if (!nd[v].has || r - l == 1) return;\n    int m = (l\
    \ + r) >> 1;\n    int lc = clone(nd[v].l);\n    int rc = clone(nd[v].r);\n   \
    \ all_apply(lc, nd[v].lz, m - l);\n    all_apply(rc, nd[v].lz, r - m);\n    nd[v].l\
    \ = lc;\n    nd[v].r = rc;\n    nd[v].lz = F();\n    nd[v].has = false;\n  }\n\
    \n  int apply(int v, int l, int r, int ql, int qr, F f) {\n    if (qr <= l ||\
    \ r <= ql) return v;\n    v = clone(v);\n    if (ql <= l && r <= qr) {\n     \
    \ all_apply(v, f, r - l);\n      return v;\n    }\n    push(v, l, r);\n    int\
    \ m = (l + r) >> 1;\n    int lc = apply(nd[v].l, l, m, ql, qr, f);\n    int rc\
    \ = apply(nd[v].r, m, r, ql, qr, f);\n    nd[v].l = lc;\n    nd[v].r = rc;\n \
    \   nd[v].sum = nd[lc].sum + nd[rc].sum;\n    return v;\n  }\n\n  mint prod(int\
    \ v, int l, int r, int ql, int qr, F acc) {\n    if (qr <= l || r <= ql) return\
    \ mint(0);\n    if (ql <= l && r <= qr) return acc.a * nd[v].sum + acc.b * mint(r\
    \ - l);\n    int m = (l + r) >> 1;\n    F nxt = acc;\n    if (nd[v].has) nxt =\
    \ affine_compose(acc, nd[v].lz);\n    mint lv = prod(nd[v].l, l, m, ql, qr, nxt);\n\
    \    mint rv = prod(nd[v].r, m, r, ql, qr, nxt);\n    return lv + rv;\n  }\n\n\
    \  int replace_range(int a, int b, int l, int r, int ql, int qr) {\n    if (qr\
    \ <= l || r <= ql) return a;\n    if (ql <= l && r <= qr) return b;\n    a = clone(a);\n\
    \    b = clone(b);\n    push(a, l, r);\n    push(b, l, r);\n    int m = (l + r)\
    \ >> 1;\n    int lc = replace_range(nd[a].l, nd[b].l, l, m, ql, qr);\n    int\
    \ rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);\n    nd[a].l = lc;\n   \
    \ nd[a].r = rc;\n    nd[a].sum = nd[lc].sum + nd[rc].sum;\n    return a;\n  }\n\
    };\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<mint> a(N);\n  for (int i = 0; i < N; i++)\
    \ cin >> a[i];\n  pst seg(a);\n  vector<int> ver(Q, -1);\n  for (int i = 0; i\
    \ < Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int k, l, r;\n\
    \      long long b, c;\n      cin >> k >> l >> r >> b >> c;\n      int base =\
    \ (k == -1) ? seg.root[0] : ver[k];\n      int nr = seg.apply(base, 0, seg.n,\
    \ l, r, F(mint(b), mint(c)));\n      ver[i] = nr;\n    } else if (t == 1) {\n\
    \      int k, s, l, r;\n      cin >> k >> s >> l >> r;\n      int base = (k ==\
    \ -1) ? seg.root[0] : ver[k];\n      int src = (s == -1) ? seg.root[0] : ver[s];\n\
    \      int nr = seg.replace_range(base, src, 0, seg.n, l, r);\n      ver[i] =\
    \ nr;\n    } else {\n      int k, l, r;\n      cin >> k >> l >> r;\n      int\
    \ base = (k == -1) ? seg.root[0] : ver[k];\n      mint ans = seg.prod(base, 0,\
    \ seg.n, l, r, F());\n      cout << ans.v << \"\\n\";\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_range_affine_range_sum\"\
    \n#include \"math/affine.hpp\"\n#include \"math/modint.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing mint = modint<998244353>;\nusing F = affine<mint>;\n\
    \nstruct node {\n  mint sum;\n  int l;\n  int r;\n  F lz;\n  bool has;\n};\n\n\
    struct pst {\n  int n;\n  vector<node> nd;\n  vector<int> root;\n\n  pst() : n(0)\
    \ {}\n  pst(const vector<mint>& a) { build(a); }\n\n  int new_node(mint sum, int\
    \ l, int r, F lz, bool has) {\n    nd.push_back({sum, l, r, lz, has});\n    return\
    \ (int)nd.size() - 1;\n  }\n\n  int build_vec(int l, int r, const vector<mint>&\
    \ a) {\n    if (r - l == 1) return new_node(a[l], -1, -1, F(), false);\n    int\
    \ m = (l + r) >> 1;\n    int lc = build_vec(l, m, a);\n    int rc = build_vec(m,\
    \ r, a);\n    return new_node(nd[lc].sum + nd[rc].sum, lc, rc, F(), false);\n\
    \  }\n\n  void build(const vector<mint>& a) {\n    n = (int)a.size();\n    nd.clear();\n\
    \    root.clear();\n    root.push_back(build_vec(0, n, a));\n  }\n\n  int clone(int\
    \ v) {\n    nd.push_back(nd[v]);\n    return (int)nd.size() - 1;\n  }\n\n  void\
    \ all_apply(int v, F f, int len) {\n    nd[v].sum = f.a * nd[v].sum + f.b * mint(len);\n\
    \    if (nd[v].has) {\n      nd[v].lz = affine_compose(f, nd[v].lz);\n    } else\
    \ {\n      nd[v].lz = f;\n      nd[v].has = true;\n    }\n  }\n\n  void push(int\
    \ v, int l, int r) {\n    if (!nd[v].has || r - l == 1) return;\n    int m = (l\
    \ + r) >> 1;\n    int lc = clone(nd[v].l);\n    int rc = clone(nd[v].r);\n   \
    \ all_apply(lc, nd[v].lz, m - l);\n    all_apply(rc, nd[v].lz, r - m);\n    nd[v].l\
    \ = lc;\n    nd[v].r = rc;\n    nd[v].lz = F();\n    nd[v].has = false;\n  }\n\
    \n  int apply(int v, int l, int r, int ql, int qr, F f) {\n    if (qr <= l ||\
    \ r <= ql) return v;\n    v = clone(v);\n    if (ql <= l && r <= qr) {\n     \
    \ all_apply(v, f, r - l);\n      return v;\n    }\n    push(v, l, r);\n    int\
    \ m = (l + r) >> 1;\n    int lc = apply(nd[v].l, l, m, ql, qr, f);\n    int rc\
    \ = apply(nd[v].r, m, r, ql, qr, f);\n    nd[v].l = lc;\n    nd[v].r = rc;\n \
    \   nd[v].sum = nd[lc].sum + nd[rc].sum;\n    return v;\n  }\n\n  mint prod(int\
    \ v, int l, int r, int ql, int qr, F acc) {\n    if (qr <= l || r <= ql) return\
    \ mint(0);\n    if (ql <= l && r <= qr) return acc.a * nd[v].sum + acc.b * mint(r\
    \ - l);\n    int m = (l + r) >> 1;\n    F nxt = acc;\n    if (nd[v].has) nxt =\
    \ affine_compose(acc, nd[v].lz);\n    mint lv = prod(nd[v].l, l, m, ql, qr, nxt);\n\
    \    mint rv = prod(nd[v].r, m, r, ql, qr, nxt);\n    return lv + rv;\n  }\n\n\
    \  int replace_range(int a, int b, int l, int r, int ql, int qr) {\n    if (qr\
    \ <= l || r <= ql) return a;\n    if (ql <= l && r <= qr) return b;\n    a = clone(a);\n\
    \    b = clone(b);\n    push(a, l, r);\n    push(b, l, r);\n    int m = (l + r)\
    \ >> 1;\n    int lc = replace_range(nd[a].l, nd[b].l, l, m, ql, qr);\n    int\
    \ rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);\n    nd[a].l = lc;\n   \
    \ nd[a].r = rc;\n    nd[a].sum = nd[lc].sum + nd[rc].sum;\n    return a;\n  }\n\
    };\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<mint> a(N);\n  for (int i = 0; i < N; i++)\
    \ cin >> a[i];\n  pst seg(a);\n  vector<int> ver(Q, -1);\n  for (int i = 0; i\
    \ < Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int k, l, r;\n\
    \      long long b, c;\n      cin >> k >> l >> r >> b >> c;\n      int base =\
    \ (k == -1) ? seg.root[0] : ver[k];\n      int nr = seg.apply(base, 0, seg.n,\
    \ l, r, F(mint(b), mint(c)));\n      ver[i] = nr;\n    } else if (t == 1) {\n\
    \      int k, s, l, r;\n      cin >> k >> s >> l >> r;\n      int base = (k ==\
    \ -1) ? seg.root[0] : ver[k];\n      int src = (s == -1) ? seg.root[0] : ver[s];\n\
    \      int nr = seg.replace_range(base, src, 0, seg.n, l, r);\n      ver[i] =\
    \ nr;\n    } else {\n      int k, l, r;\n      cin >> k >> l >> r;\n      int\
    \ base = (k == -1) ? seg.root[0] : ver[k];\n      mint ans = seg.prod(base, 0,\
    \ seg.n, l, r, F());\n      cout << ans.v << \"\\n\";\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - math/affine.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: verify/yosupo_persistent_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-12 00:02:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_persistent_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_persistent_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_persistent_range_affine_range_sum.test.cpp.html
title: verify/yosupo_persistent_range_affine_range_sum.test.cpp
---

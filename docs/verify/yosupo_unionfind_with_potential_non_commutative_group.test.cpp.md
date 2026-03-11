---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "2x2 \u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: structure/weightedunionfind.hpp
    title: "\u91CD\u307F\u4ED8\u304D Union-Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
  bundledCode: "#line 1 \"verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#line 2 \"math/matrix.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <long long MOD>\nstruct mat2 {\n  long long a00, a01, a10, a11;\n\n\
    \  mat2(long long b00 = 1, long long b01 = 0, long long b10 = 0,\n       long\
    \ long b11 = 1)\n      : a00(norm(b00)),\n        a01(norm(b01)),\n        a10(norm(b10)),\n\
    \        a11(norm(b11)) {}\n\n  static long long norm(long long v) {\n    v %=\
    \ MOD;\n    if (v < 0) v += MOD;\n    return v;\n  }\n\n  static mat2 id() { return\
    \ mat2(); }\n\n  static mat2 op(const mat2 &x, const mat2 &y) {\n    mat2 r(0,\
    \ 0, 0, 0);\n    r.a00 = (x.a00 * y.a00 + x.a01 * y.a10) % MOD;\n    r.a01 = (x.a00\
    \ * y.a01 + x.a01 * y.a11) % MOD;\n    r.a10 = (x.a10 * y.a00 + x.a11 * y.a10)\
    \ % MOD;\n    r.a11 = (x.a10 * y.a01 + x.a11 * y.a11) % MOD;\n    return r;\n\
    \  }\n\n  static long long modpow(long long a, long long e) {\n    long long r\
    \ = 1;\n    while (e > 0) {\n      if (e & 1) r = r * a % MOD;\n      a = a *\
    \ a % MOD;\n      e >>= 1;\n    }\n    return r;\n  }\n\n  static mat2 inv(const\
    \ mat2 &x) {\n    long long det = (x.a00 * x.a11 - x.a01 * x.a10) % MOD;\n   \
    \ if (det < 0) det += MOD;\n    long long idet = modpow(det, MOD - 2);\n    mat2\
    \ r(0, 0, 0, 0);\n    r.a00 = x.a11 * idet % MOD;\n    r.a01 = (MOD - x.a01) %\
    \ MOD * idet % MOD;\n    r.a10 = (MOD - x.a10) % MOD * idet % MOD;\n    r.a11\
    \ = x.a00 * idet % MOD;\n    return r;\n  }\n\n  bool operator==(const mat2 &o)\
    \ const {\n    return a00 == o.a00 && a01 == o.a01 && a10 == o.a10 &&\n      \
    \     a11 == o.a11;\n  }\n};\n#line 3 \"structure/weightedunionfind.hpp\"\nusing\
    \ namespace std;\n\ntemplate <class T, class Op>\nstruct weighted_unionfind {\n\
    \  int n;\n  vector<int> p;\n  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind()\
    \ : n(0) {}\n  weighted_unionfind(int n_) { init(n_); }\n\n  void init(int n_)\
    \ {\n    n = n_;\n    p.resize(n);\n    sz.assign(n, 1);\n    w.assign(n, Op::id());\n\
    \    iota(p.begin(), p.end(), 0);\n  }\n\n  T mul(const T &a, const T &b) { return\
    \ Op::op(a, b); }\n  T inv(const T &a) { return Op::inv(a); }\n\n  int leader(int\
    \ x) {\n    if (p[x] == x) return x;\n    int r = leader(p[x]);\n    w[x] = mul(w[p[x]],\
    \ w[x]);\n    return p[x] = r;\n  }\n\n  T weight(int x) {\n    leader(x);\n \
    \   return w[x];\n  }\n\n  bool same(int a, int b) { return leader(a) == leader(b);\
    \ }\n\n  T diff(int a, int b) { return mul(inv(weight(b)), weight(a)); }\n\n \
    \ bool get(int a, int b, T &out) {\n    if (!same(a, b)) return false;\n    out\
    \ = diff(a, b);\n    return true;\n  }\n\n  bool merge(int a, int b, T x) {\n\
    \    int ra = leader(a);\n    int rb = leader(b);\n    T wa = w[a];\n    T wb\
    \ = w[b];\n    if (ra == rb) return mul(inv(wb), wa) == x;\n    if (sz[ra] < sz[rb])\
    \ {\n      p[ra] = rb;\n      sz[rb] += sz[ra];\n      w[ra] = mul(mul(wb, x),\
    \ inv(wa));\n    } else {\n      p[rb] = ra;\n      sz[ra] += sz[rb];\n      w[rb]\
    \ = mul(mul(wa, inv(x)), inv(wb));\n    }\n    return true;\n  }\n\n  int size(int\
    \ x) { return sz[leader(x)]; }\n};\n#line 4 \"verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n\nstatic const long long MOD = 998244353;\n\nusing mat = mat2<MOD>;\n\nstruct\
    \ mat_group {\n  static mat id() { return mat::id(); }\n  static mat op(const\
    \ mat &a, const mat &b) { return mat::op(a, b); }\n  static mat inv(const mat\
    \ &a) { return mat::inv(a); }\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  weighted_unionfind<mat,\
    \ mat_group> uf(N);\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      int u, v;\n      long long x00, x01, x10, x11;\n   \
    \   cin >> u >> v >> x00 >> x01 >> x10 >> x11;\n      mat x(x00, x01, x10, x11);\n\
    \      cout << (uf.merge(u, v, x) ? 1 : 0) << \"\\n\";\n    } else {\n      int\
    \ u, v;\n      cin >> u >> v;\n      mat ans;\n      if (uf.get(u, v, ans)) {\n\
    \        cout << ans.a00 << \" \" << ans.a01 << \" \" << ans.a10 << \" \"\n  \
    \           << ans.a11 << \"\\n\";\n      } else {\n        cout << -1 << \"\\\
    n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#include \"math/matrix.hpp\"\n#include \"structure/weightedunionfind.hpp\"\n\
    \nstatic const long long MOD = 998244353;\n\nusing mat = mat2<MOD>;\n\nstruct\
    \ mat_group {\n  static mat id() { return mat::id(); }\n  static mat op(const\
    \ mat &a, const mat &b) { return mat::op(a, b); }\n  static mat inv(const mat\
    \ &a) { return mat::inv(a); }\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  weighted_unionfind<mat,\
    \ mat_group> uf(N);\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n\
    \    if (t == 0) {\n      int u, v;\n      long long x00, x01, x10, x11;\n   \
    \   cin >> u >> v >> x00 >> x01 >> x10 >> x11;\n      mat x(x00, x01, x10, x11);\n\
    \      cout << (uf.merge(u, v, x) ? 1 : 0) << \"\\n\";\n    } else {\n      int\
    \ u, v;\n      cin >> u >> v;\n      mat ans;\n      if (uf.get(u, v, ans)) {\n\
    \        cout << ans.a00 << \" \" << ans.a01 << \" \" << ans.a10 << \" \"\n  \
    \           << ans.a11 << \"\\n\";\n      } else {\n        cout << -1 << \"\\\
    n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/matrix.hpp
  - structure/weightedunionfind.hpp
  isVerificationFile: true
  path: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 16:14:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
- /verify/verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp.html
title: verify/yosupo_unionfind_with_potential_non_commutative_group.test.cpp
---

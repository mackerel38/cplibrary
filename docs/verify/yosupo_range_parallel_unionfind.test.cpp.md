---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/rangeparallel_unionfind.hpp
    title: Range Parallel Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_parallel_unionfind
    links:
    - https://judge.yosupo.jp/problem/range_parallel_unionfind
  bundledCode: "#line 1 \"verify/yosupo_range_parallel_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\n#line\
    \ 2 \"structure/rangeparallel_unionfind.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class Ops>\nstruct range_parallel_unionfind {\n\
    \  using T = typename Ops::T;\n  int n, lg;\n  vector<int> p0, sz0;\n  vector<T>\
    \ sum;\n  T cur;\n  vector<vector<int>> p, sz;\n\n  range_parallel_unionfind()\
    \ : n(0), lg(0), cur(Ops::zero()) {}\n  range_parallel_unionfind(int n_) { init(n_);\
    \ }\n\n  void init(int n_) {\n    n = n_;\n    lg = 1;\n    while ((1 << lg) <=\
    \ n) lg++;\n    p0.resize(n);\n    sz0.assign(n, 1);\n    iota(p0.begin(), p0.end(),\
    \ 0);\n    sum.assign(n, Ops::zero());\n    cur = Ops::zero();\n    p.assign(lg,\
    \ {});\n    sz.assign(lg, {});\n    for (int l = 1; l < lg; l++) {\n      int\
    \ cnt = n - (1 << l) + 1;\n      p[l].resize(cnt);\n      sz[l].assign(cnt, 1);\n\
    \      iota(p[l].begin(), p[l].end(), 0);\n    }\n  }\n\n  void set_values(const\
    \ vector<T>& v) {\n    sum = v;\n    cur = Ops::zero();\n  }\n\n  int leader(int\
    \ x) {\n    if (p0[x] == x) return x;\n    return p0[x] = leader(p0[x]);\n  }\n\
    \n  bool merge0(int a, int b) {\n    a = leader(a);\n    b = leader(b);\n    if\
    \ (a == b) return false;\n    if (sz0[a] < sz0[b]) swap(a, b);\n    p0[b] = a;\n\
    \    sz0[a] += sz0[b];\n    cur = Ops::add(cur, Ops::mul(sum[a], sum[b]));\n \
    \   sum[a] = Ops::add(sum[a], sum[b]);\n    return true;\n  }\n\n  int leader_level(int\
    \ l, int x) {\n    if (p[l][x] == x) return x;\n    return p[l][x] = leader_level(l,\
    \ p[l][x]);\n  }\n\n  bool merge_level(int l, int a, int b) {\n    a = leader_level(l,\
    \ a);\n    b = leader_level(l, b);\n    if (a == b) return false;\n    if (sz[l][a]\
    \ < sz[l][b]) swap(a, b);\n    p[l][b] = a;\n    sz[l][a] += sz[l][b];\n    return\
    \ true;\n  }\n\n  void unite_block(int l, int a, int b) {\n    if (a == b) return;\n\
    \    if (l == 0) {\n      merge0(a, b);\n      return;\n    }\n    if (!merge_level(l,\
    \ a, b)) return;\n    int half = 1 << (l - 1);\n    unite_block(l - 1, a, b);\n\
    \    unite_block(l - 1, a + half, b + half);\n  }\n\n  void merge_range(int a,\
    \ int b, int k) {\n    for (int l = 0; k > 0; l++) {\n      if (k & 1) {\n   \
    \     unite_block(l, a, b);\n        a += 1 << l;\n        b += 1 << l;\n    \
    \  }\n      k >>= 1;\n    }\n  }\n};\n#line 3 \"verify/yosupo_range_parallel_unionfind.test.cpp\"\
    \n\nstatic const long long MOD = 998244353;\n\nstruct mod_ops {\n  using T = long\
    \ long;\n  static T zero() { return 0; }\n  static T add(T a, T b) {\n    T v\
    \ = a + b;\n    if (v >= MOD) v -= MOD;\n    return v;\n  }\n  static T mul(T\
    \ a, T b) { return a * b % MOD; }\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> x(N);\n\
    \  for (int i = 0; i < N; i++) {\n    cin >> x[i];\n    x[i] %= MOD;\n  }\n  range_parallel_unionfind<mod_ops>\
    \ uf(N);\n  uf.set_values(x);\n  for (int i = 0; i < Q; i++) {\n    int k, a,\
    \ b;\n    cin >> k >> a >> b;\n    uf.merge_range(a, b, k);\n    cout << uf.cur\
    \ % MOD << \"\\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\
    \n#include \"structure/rangeparallel_unionfind.hpp\"\n\nstatic const long long\
    \ MOD = 998244353;\n\nstruct mod_ops {\n  using T = long long;\n  static T zero()\
    \ { return 0; }\n  static T add(T a, T b) {\n    T v = a + b;\n    if (v >= MOD)\
    \ v -= MOD;\n    return v;\n  }\n  static T mul(T a, T b) { return a * b % MOD;\
    \ }\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  vector<long long> x(N);\n  for (int i = 0; i\
    \ < N; i++) {\n    cin >> x[i];\n    x[i] %= MOD;\n  }\n  range_parallel_unionfind<mod_ops>\
    \ uf(N);\n  uf.set_values(x);\n  for (int i = 0; i < Q; i++) {\n    int k, a,\
    \ b;\n    cin >> k >> a >> b;\n    uf.merge_range(a, b, k);\n    cout << uf.cur\
    \ % MOD << \"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/rangeparallel_unionfind.hpp
  isVerificationFile: true
  path: verify/yosupo_range_parallel_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 16:43:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_range_parallel_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_range_parallel_unionfind.test.cpp
- /verify/verify/yosupo_range_parallel_unionfind.test.cpp.html
title: verify/yosupo_range_parallel_unionfind.test.cpp
---

---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/yosupo_unionfind_with_potential.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\n#line\
    \ 2 \"structure/weightedunionfind.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T, class Op>\nstruct weighted_unionfind {\n  int n;\n\
    \  vector<int> p;\n  vector<int> sz;\n  vector<T> w;\n\n  weighted_unionfind()\
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
    \ x) { return sz[leader(x)]; }\n};\n#line 3 \"verify/yosupo_unionfind_with_potential.test.cpp\"\
    \n\nstatic const long long MOD = 998244353;\n\nstruct mod_add {\n  static long\
    \ long id() { return 0; }\n  static long long op(long long a, long long b) {\n\
    \    long long v = a + b;\n    if (v >= MOD) v -= MOD;\n    return v;\n  }\n \
    \ static long long inv(long long a) { return a == 0 ? 0 : MOD - a; }\n};\n\nint\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int N, Q;\n\
    \  if (!(cin >> N >> Q)) return 0;\n  weighted_unionfind<long long, mod_add> uf(N);\n\
    \  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n\
    \      int u, v;\n      long long x;\n      cin >> u >> v >> x;\n      x %= MOD;\n\
    \      cout << (uf.merge(u, v, x) ? 1 : 0) << \"\\n\";\n    } else {\n      int\
    \ u, v;\n      cin >> u >> v;\n      long long ans;\n      if (uf.get(u, v, ans))\
    \ {\n        cout << ans << \"\\n\";\n      } else {\n        cout << -1 << \"\
    \\n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n#include \"structure/weightedunionfind.hpp\"\n\nstatic const long long MOD =\
    \ 998244353;\n\nstruct mod_add {\n  static long long id() { return 0; }\n  static\
    \ long long op(long long a, long long b) {\n    long long v = a + b;\n    if (v\
    \ >= MOD) v -= MOD;\n    return v;\n  }\n  static long long inv(long long a) {\
    \ return a == 0 ? 0 : MOD - a; }\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  if (!(cin >> N >> Q)) return 0;\n  weighted_unionfind<long\
    \ long, mod_add> uf(N);\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin\
    \ >> t;\n    if (t == 0) {\n      int u, v;\n      long long x;\n      cin >>\
    \ u >> v >> x;\n      x %= MOD;\n      cout << (uf.merge(u, v, x) ? 1 : 0) <<\
    \ \"\\n\";\n    } else {\n      int u, v;\n      cin >> u >> v;\n      long long\
    \ ans;\n      if (uf.get(u, v, ans)) {\n        cout << ans << \"\\n\";\n    \
    \  } else {\n        cout << -1 << \"\\n\";\n      }\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - structure/weightedunionfind.hpp
  isVerificationFile: true
  path: verify/yosupo_unionfind_with_potential.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 16:11:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_unionfind_with_potential.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_unionfind_with_potential.test.cpp
- /verify/verify/yosupo_unionfind_with_potential.test.cpp.html
title: verify/yosupo_unionfind_with_potential.test.cpp
---

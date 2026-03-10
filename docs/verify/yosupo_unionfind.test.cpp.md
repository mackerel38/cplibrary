---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/unionfind.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo_unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 2 \"structure/unionfind.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct unionfind {\n  int n;\n  vector<int> p;\n  vector<int> sz;\n\n\
    \  unionfind() : n(0) {}\n  unionfind(int n_) { init(n_); }\n\n  void init(int\
    \ n_) {\n    n = n_;\n    p.resize(n);\n    sz.assign(n, 1);\n    iota(p.begin(),\
    \ p.end(), 0);\n  }\n\n  int leader(int x) {\n    if (p[x] == x) return x;\n \
    \   return p[x] = leader(p[x]);\n  }\n\n  bool same(int a, int b) { return leader(a)\
    \ == leader(b); }\n\n  bool merge(int a, int b) {\n    a = leader(a);\n    b =\
    \ leader(b);\n    if (a == b) return false;\n    if (sz[a] < sz[b]) swap(a, b);\n\
    \    p[b] = a;\n    sz[a] += sz[b];\n    return true;\n  }\n\n  int size(int x)\
    \ { return sz[leader(x)]; }\n};\n#line 3 \"verify/yosupo_unionfind.test.cpp\"\n\
    \nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int N,\
    \ Q;\n  cin >> N >> Q;\n  unionfind uf(N);\n  for (int i = 0; i < Q; i++) {\n\
    \    int t, u, v;\n    cin >> t >> u >> v;\n    if (t == 0) {\n      uf.merge(u,\
    \ v);\n    } else {\n      cout << (uf.same(u, v) ? 1 : 0) << '\\n';\n    }\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    structure/unionfind.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \n  int N, Q;\n  cin >> N >> Q;\n  unionfind uf(N);\n  for (int i = 0; i < Q;\
    \ i++) {\n    int t, u, v;\n    cin >> t >> u >> v;\n    if (t == 0) {\n     \
    \ uf.merge(u, v);\n    } else {\n      cout << (uf.same(u, v) ? 1 : 0) << '\\\
    n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/unionfind.hpp
  isVerificationFile: true
  path: verify/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 06:01:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_unionfind.test.cpp
- /verify/verify/yosupo_unionfind.test.cpp.html
title: verify/yosupo_unionfind.test.cpp
---

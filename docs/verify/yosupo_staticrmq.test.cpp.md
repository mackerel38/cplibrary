---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/cartesiantree.hpp
    title: Cartesian Tree
  - icon: ':x:'
    path: graph/eulertour.hpp
    title: Euler Tour
  - icon: ':x:'
    path: structure/sparsetable.hpp
    title: Sparse Table RMQ
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo_staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 2 \"structure/sparsetable.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"graph/cartesiantree.hpp\"\nusing namespace std;\n\ntemplate\
    \ <class T, class Cmp = less<T>>\nstruct cartesian_tree {\n  int n;\n  vector<int>\
    \ parent;\n  vector<int> left;\n  vector<int> right;\n  int root;\n  Cmp cmp;\n\
    \n  cartesian_tree() : n(0), root(-1), cmp() {}\n  cartesian_tree(const vector<T>&\
    \ a, Cmp cmp_ = Cmp()) { build(a, cmp_); }\n\n  void build(const vector<T>& a,\
    \ Cmp cmp_ = Cmp()) {\n    cmp = cmp_;\n    n = (int)a.size();\n    parent.assign(n,\
    \ -1);\n    left.assign(n, -1);\n    right.assign(n, -1);\n    vector<int> st;\n\
    \    st.reserve(n);\n    for (int i = 0; i < n; i++) {\n      int last = -1;\n\
    \      while (!st.empty() && cmp(a[i], a[st.back()])) {\n        last = st.back();\n\
    \        st.pop_back();\n      }\n      if (!st.empty()) {\n        parent[i]\
    \ = st.back();\n        right[st.back()] = i;\n      }\n      if (last != -1)\
    \ {\n        parent[last] = i;\n        left[i] = last;\n      }\n      st.push_back(i);\n\
    \    }\n    root = -1;\n    for (int i = 0; i < n; i++) {\n      if (parent[i]\
    \ == -1) {\n        root = i;\n        break;\n      }\n    }\n  }\n};\n#line\
    \ 3 \"graph/eulertour.hpp\"\nusing namespace std;\n\nstruct euler_tour {\n  int\
    \ n;\n  int root;\n  int timer;\n  vector<int> in, out, order, parent, depth;\n\
    \  vector<int> euler, depth_euler, first;\n\n  euler_tour() : n(0), root(0), timer(0)\
    \ {}\n\n  void build(const vector<vector<int>>& g, int r = 0) {\n    n = (int)g.size();\n\
    \    root = r;\n    timer = 0;\n    in.assign(n, -1);\n    out.assign(n, -1);\n\
    \    parent.assign(n, -1);\n    depth.assign(n, 0);\n    order.resize(n);\n  \
    \  euler.clear();\n    depth_euler.clear();\n    first.assign(n, -1);\n    euler.reserve(2\
    \ * n - 1);\n    depth_euler.reserve(2 * n - 1);\n    dfs(g, root);\n  }\n\n \
    \ void dfs(const vector<vector<int>>& g, int s) {\n    struct frame {\n      int\
    \ v;\n      int p;\n      int idx;\n    };\n    vector<frame> st;\n    st.push_back({s,\
    \ -1, 0});\n    parent[s] = -1;\n    depth[s] = 0;\n    in[s] = timer;\n    order[timer]\
    \ = s;\n    timer++;\n    euler.push_back(s);\n    depth_euler.push_back(0);\n\
    \    first[s] = 0;\n    while (!st.empty()) {\n      auto& fr = st.back();\n \
    \     int v = fr.v;\n      if (fr.idx == (int)g[v].size()) {\n        out[v] =\
    \ timer;\n        st.pop_back();\n        if (!st.empty()) {\n          int p\
    \ = st.back().v;\n          euler.push_back(p);\n          depth_euler.push_back(depth[p]);\n\
    \        }\n        continue;\n      }\n      int to = g[v][fr.idx];\n      fr.idx++;\n\
    \      if (to == fr.p) continue;\n      parent[to] = v;\n      depth[to] = depth[v]\
    \ + 1;\n      in[to] = timer;\n      order[timer] = to;\n      timer++;\n    \
    \  st.push_back({to, v, 0});\n      euler.push_back(to);\n      depth_euler.push_back(depth[to]);\n\
    \      if (first[to] == -1) first[to] = (int)euler.size() - 1;\n    }\n  }\n};\n\
    #line 7 \"structure/sparsetable.hpp\"\n\ntemplate <class T, class Cmp = less<T>>\n\
    struct sparse_table {\n  int n;\n  vector<T> a;\n  cartesian_tree<T, Cmp> ct;\n\
    \  vector<int> first;\n  vector<int> euler;\n  vector<int> depth;\n  int B;\n\
    \  vector<int> block_min;\n  vector<vector<int>> block_tbl;\n  vector<vector<int>>\
    \ st;\n\n  sparse_table() : n(0), B(16) {}\n  sparse_table(const vector<T>& v,\
    \ Cmp cmp = Cmp()) : n(0), B(16) {\n    build(v, cmp);\n  }\n\n  void build(const\
    \ vector<T>& v, Cmp cmp = Cmp()) {\n    a = v;\n    n = (int)a.size();\n    if\
    \ (B <= 0) B = 16;\n    ct.build(a, cmp);\n    vector<vector<int>> g(n);\n   \
    \ for (int i = 0; i < n; i++) {\n      int p = ct.parent[i];\n      if (p != -1)\
    \ {\n        g[p].push_back(i);\n        g[i].push_back(p);\n      }\n    }\n\
    \    euler_tour et;\n    et.build(g, ct.root);\n    first = et.first;\n    euler\
    \ = et.euler;\n    depth = et.depth_euler;\n    build_blocks();\n  }\n\n  void\
    \ build_blocks() {\n    int m = (int)euler.size();\n    int nb = (m + B - 1) /\
    \ B;\n    block_min.assign(nb, -1);\n    block_tbl.assign(nb, vector<int>(B *\
    \ B, 0));\n    for (int b = 0; b < nb; b++) {\n      int l = b * B;\n      int\
    \ r = min(m, l + B);\n      int len = r - l;\n      for (int i = 0; i < len; i++)\
    \ {\n        int best = l + i;\n        for (int j = i; j < len; j++) {\n    \
    \      int idx = l + j;\n          if (depth[idx] < depth[best]) best = idx;\n\
    \          block_tbl[b][i * B + j] = best;\n        }\n      }\n      for (int\
    \ i = 0; i < B; i++) {\n        for (int j = 0; j < B; j++) {\n          if (i\
    \ > j || i >= len || j >= len) block_tbl[b][i * B + j] = l;\n        }\n     \
    \ }\n      int minpos = l;\n      for (int i = l; i < r; i++) {\n        if (depth[i]\
    \ < depth[minpos]) minpos = i;\n      }\n      block_min[b] = minpos;\n    }\n\
    \    int lg = 1;\n    while ((1 << lg) <= nb) lg++;\n    st.assign(lg, vector<int>(nb,\
    \ -1));\n    for (int i = 0; i < nb; i++) st[0][i] = block_min[i];\n    for (int\
    \ k = 1; k < lg; k++) {\n      int len = 1 << k;\n      int half = len >> 1;\n\
    \      for (int i = 0; i + len <= nb; i++) {\n        int aidx = st[k - 1][i];\n\
    \        int bidx = st[k - 1][i + half];\n        st[k][i] = depth[aidx] < depth[bidx]\
    \ ? aidx : bidx;\n      }\n    }\n  }\n\n  int rmq_idx(int l, int r) const {\n\
    \    if (l > r) swap(l, r);\n    int bl = l / B;\n    int br = r / B;\n    if\
    \ (bl == br) {\n      int ll = l % B;\n      int rr = r % B;\n      return block_tbl[bl][ll\
    \ * B + rr];\n    }\n    int left_idx = block_tbl[bl][(l % B) * B + (B - 1)];\n\
    \    int right_idx = block_tbl[br][0 * B + (r % B)];\n    int best = depth[left_idx]\
    \ < depth[right_idx] ? left_idx : right_idx;\n    if (bl + 1 <= br - 1) {\n  \
    \    int L = bl + 1;\n      int R = br - 1;\n      int len = R - L + 1;\n    \
    \  int k = 31 - __builtin_clz(len);\n      int aidx = st[k][L];\n      int bidx\
    \ = st[k][R - (1 << k) + 1];\n      int mid = depth[aidx] < depth[bidx] ? aidx\
    \ : bidx;\n      best = depth[best] < depth[mid] ? best : mid;\n    }\n    return\
    \ best;\n  }\n\n  int argmin(int l, int r) const {\n    int u = l;\n    int v\
    \ = r - 1;\n    int fu = first[u];\n    int fv = first[v];\n    int idx = rmq_idx(fu,\
    \ fv);\n    return euler[idx];\n  }\n\n  T query(int l, int r) const { return\
    \ a[argmin(l, r)]; }\n};\n#line 3 \"verify/yosupo_staticrmq.test.cpp\"\n\nint\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int N, Q;\n\
    \  cin >> N >> Q;\n  vector<long long> a(N);\n  for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n  sparse_table<long long> st(a);\n  for (int i = 0; i < Q; i++) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << st.query(l, r) << \"\\n\";\n \
    \ }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    structure/sparsetable.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> a(N);\n\
    \  for (int i = 0; i < N; i++) cin >> a[i];\n  sparse_table<long long> st(a);\n\
    \  for (int i = 0; i < Q; i++) {\n    int l, r;\n    cin >> l >> r;\n    cout\
    \ << st.query(l, r) << \"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/sparsetable.hpp
  - graph/cartesiantree.hpp
  - graph/eulertour.hpp
  isVerificationFile: true
  path: verify/yosupo_staticrmq.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 17:19:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: //verify/yosupo_staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_staticrmq.test.cpp
- /verify/verify/yosupo_staticrmq.test.cpp.html
title: verify/yosupo_staticrmq.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/yosupo_associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n#line 2 \"structure/hashmap.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ hm_default_hash {\n  size_t operator()(const T &x) const {\n    if constexpr\
    \ (is_integral_v<T> && sizeof(T) <= 8) {\n      uint64_t z = uint64_t(x) + 0x9e3779b97f4a7c15ULL;\n\
    \      z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;\n      z = (z ^ (z >> 27))\
    \ * 0x94d049bb133111ebULL;\n      return size_t(z ^ (z >> 31));\n    } else {\n\
    \      return hash<T>{}(x);\n    }\n  }\n};\n\ntemplate <class K, class V, class\
    \ H = hm_default_hash<K>>\nstruct hashmap {\n  vector<K> keys;\n  vector<V> vals;\n\
    \  vector<unsigned char> st;\n  size_t n = 0;\n  size_t cap = 0;\n  H hasher;\n\
    \n  hashmap(size_t c = 8) { init(c); }\n\n  void init(size_t c) {\n    cap = 1;\n\
    \    while (cap < c) cap <<= 1;\n    keys.assign(cap, K());\n    vals.assign(cap,\
    \ V());\n    st.assign(cap, 0);\n    n = 0;\n  }\n\n  size_t size() const { return\
    \ n; }\n  bool empty() const { return n == 0; }\n\n  void reserve(size_t m) {\n\
    \    if (m * 10 > cap * 7) rehash(m * 2 + 1);\n  }\n\n  void rehash(size_t c)\
    \ {\n    vector<K> ok = move(keys);\n    vector<V> ov = move(vals);\n    vector<unsigned\
    \ char> os = move(st);\n    init(c);\n    for (size_t i = 0; i < os.size(); i++)\
    \ {\n      if (os[i] == 1) set(ok[i], ov[i]);\n    }\n  }\n\n  size_t find_idx(const\
    \ K &k) const {\n    size_t m = cap - 1;\n    size_t h = hasher(k) & m;\n    for\
    \ (size_t i = 0;; i++) {\n      size_t idx = (h + i) & m;\n      if (st[idx] ==\
    \ 0) return cap;\n      if (st[idx] == 1 && keys[idx] == k) return idx;\n    }\n\
    \  }\n\n  bool contains(const K &k) const { return find_idx(k) != cap; }\n\n \
    \ V get(const K &k, const V &def = V()) const {\n    size_t idx = find_idx(k);\n\
    \    if (idx == cap) return def;\n    return vals[idx];\n  }\n\n  V *get_ptr(const\
    \ K &k) {\n    size_t idx = find_idx(k);\n    if (idx == cap) return nullptr;\n\
    \    return &vals[idx];\n  }\n\n  void set(const K &k, const V &v) {\n    if ((n\
    \ + 1) * 10 > cap * 7) rehash(cap * 2 + 1);\n    size_t m = cap - 1;\n    size_t\
    \ h = hasher(k) & m;\n    size_t first_del = cap;\n    for (size_t i = 0;; i++)\
    \ {\n      size_t idx = (h + i) & m;\n      if (st[idx] == 1) {\n        if (keys[idx]\
    \ == k) {\n          vals[idx] = v;\n          return;\n        }\n      } else\
    \ if (st[idx] == 2) {\n        if (first_del == cap) first_del = idx;\n      }\
    \ else {\n        if (first_del != cap) idx = first_del;\n        st[idx] = 1;\n\
    \        keys[idx] = k;\n        vals[idx] = v;\n        n++;\n        return;\n\
    \      }\n    }\n  }\n\n  V &operator[](const K &k) {\n    if ((n + 1) * 10 >\
    \ cap * 7) rehash(cap * 2 + 1);\n    size_t m = cap - 1;\n    size_t h = hasher(k)\
    \ & m;\n    size_t first_del = cap;\n    for (size_t i = 0;; i++) {\n      size_t\
    \ idx = (h + i) & m;\n      if (st[idx] == 1) {\n        if (keys[idx] == k) return\
    \ vals[idx];\n      } else if (st[idx] == 2) {\n        if (first_del == cap)\
    \ first_del = idx;\n      } else {\n        if (first_del != cap) idx = first_del;\n\
    \        st[idx] = 1;\n        keys[idx] = k;\n        vals[idx] = V();\n    \
    \    n++;\n        return vals[idx];\n      }\n    }\n  }\n\n  bool erase(const\
    \ K &k) {\n    size_t idx = find_idx(k);\n    if (idx == cap) return false;\n\
    \    st[idx] = 2;\n    n--;\n    return true;\n  }\n};\n#line 3 \"verify/yosupo_associative_array.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ q;\n  if (!(cin >> q)) return 0;\n  hashmap<long long, long long> mp;\n  while\
    \ (q--) {\n    int t;\n    long long k;\n    cin >> t >> k;\n    if (t == 0) {\n\
    \      long long v;\n      cin >> v;\n      mp.set(k, v);\n    } else {\n    \
    \  cout << mp.get(k, 0LL) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../structure/hashmap.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int q;\n  if (!(cin >> q)) return 0;\n  hashmap<long\
    \ long, long long> mp;\n  while (q--) {\n    int t;\n    long long k;\n    cin\
    \ >> t >> k;\n    if (t == 0) {\n      long long v;\n      cin >> v;\n      mp.set(k,\
    \ v);\n    } else {\n      cout << mp.get(k, 0LL) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - structure/hashmap.hpp
  isVerificationFile: true
  path: verify/yosupo_associative_array.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 05:10:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_associative_array.test.cpp
- /verify/verify/yosupo_associative_array.test.cpp.html
title: verify/yosupo_associative_array.test.cpp
---

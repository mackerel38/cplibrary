---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/bipq.hpp
    title: "\u4E21\u7AEF\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/yosupo_double_ended_priority_queue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n#line\
    \ 2 \"structure/bipq.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    template <class T>\nstruct bipq {\n  priority_queue<T, vector<T>, greater<T>>\
    \ mn;\n  priority_queue<T> mx;\n  map<T, int> cnt;\n  int sz = 0;\n\n  int size()\
    \ const { return sz; }\n  bool empty() const { return sz == 0; }\n\n  void push(const\
    \ T& x) {\n    mn.push(x);\n    mx.push(x);\n    cnt[x]++;\n    sz++;\n  }\n\n\
    \  void clean_min() {\n    while (!mn.empty()) {\n      T v = mn.top();\n    \
    \  auto it = cnt.find(v);\n      if (it != cnt.end() && it->second > 0) break;\n\
    \      mn.pop();\n    }\n  }\n\n  void clean_max() {\n    while (!mx.empty())\
    \ {\n      T v = mx.top();\n      auto it = cnt.find(v);\n      if (it != cnt.end()\
    \ && it->second > 0) break;\n      mx.pop();\n    }\n  }\n\n  T min() {\n    clean_min();\n\
    \    return mn.top();\n  }\n\n  T max() {\n    clean_max();\n    return mx.top();\n\
    \  }\n\n  T pop_min() {\n    clean_min();\n    T v = mn.top();\n    mn.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n\n  T pop_max() {\n    clean_max();\n    T v = mx.top();\n    mx.pop();\n\
    \    cnt[v]--;\n    if (cnt[v] == 0) cnt.erase(v);\n    sz--;\n    return v;\n\
    \  }\n};\n#line 3 \"verify/yosupo_double_ended_priority_queue.test.cpp\"\n\nint\
    \ main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int N, Q;\n\
    \  cin >> N >> Q;\n  bipq<long long> pq;\n  for (int i = 0; i < N; i++) {\n  \
    \  long long x;\n    cin >> x;\n    pq.push(x);\n  }\n\n  for (int i = 0; i <\
    \ Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      long long x;\n\
    \      cin >> x;\n      pq.push(x);\n    } else if (t == 1) {\n      cout << pq.pop_min()\
    \ << '\\n';\n    } else if (t == 2) {\n      cout << pq.pop_max() << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include \"structure/bipq.hpp\"\n\nint main() {\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int N, Q;\n  cin >> N >> Q;\n  bipq<long long> pq;\n\
    \  for (int i = 0; i < N; i++) {\n    long long x;\n    cin >> x;\n    pq.push(x);\n\
    \  }\n\n  for (int i = 0; i < Q; i++) {\n    int t;\n    cin >> t;\n    if (t\
    \ == 0) {\n      long long x;\n      cin >> x;\n      pq.push(x);\n    } else\
    \ if (t == 1) {\n      cout << pq.pop_min() << '\\n';\n    } else if (t == 2)\
    \ {\n      cout << pq.pop_max() << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/bipq.hpp
  isVerificationFile: true
  path: verify/yosupo_double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 15:55:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_double_ended_priority_queue.test.cpp
- /verify/verify/yosupo_double_ended_priority_queue.test.cpp.html
title: verify/yosupo_double_ended_priority_queue.test.cpp
---

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
    template <class T>\nstruct bipq {\n  multiset<T> s;\n\n  int size() const { return\
    \ (int)s.size(); }\n  bool empty() const { return s.empty(); }\n\n  void push(const\
    \ T& x) { s.insert(x); }\n\n  T min() const { return *s.begin(); }\n  T max()\
    \ const {\n    auto it = s.end();\n    --it;\n    return *it;\n  }\n\n  T pop_min()\
    \ {\n    auto it = s.begin();\n    T v = *it;\n    s.erase(it);\n    return v;\n\
    \  }\n\n  T pop_max() {\n    auto it = s.end();\n    --it;\n    T v = *it;\n \
    \   s.erase(it);\n    return v;\n  }\n};\n#line 3 \"verify/yosupo_double_ended_priority_queue.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ N, Q;\n  cin >> N >> Q;\n  bipq<long long> pq;\n  for (int i = 0; i < N; i++)\
    \ {\n    long long x;\n    cin >> x;\n    pq.push(x);\n  }\n\n  for (int i = 0;\
    \ i < Q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      long long\
    \ x;\n      cin >> x;\n      pq.push(x);\n    } else if (t == 1) {\n      cout\
    \ << pq.pop_min() << '\\n';\n    } else if (t == 2) {\n      cout << pq.pop_max()\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
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
  timestamp: '2026-03-11 05:51:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/yosupo_double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_double_ended_priority_queue.test.cpp
- /verify/verify/yosupo_double_ended_priority_queue.test.cpp.html
title: verify/yosupo_double_ended_priority_queue.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick.hpp
    title: structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/structure/fenwick.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"structure/fenwick.hpp\"\nusing namespace std;\n\
    \ntemplate<class T>\nstruct Fenwick{\n  int n;\n  vector<T> bit;\n  Fenwick(int\
    \ n=0){init(n);}\n  Fenwick(const vector<T>& a){init((int)a.size()); for(int i=0;i<n;i++)\
    \ add(i,a[i]);}\n  void init(int n_){n=n_; bit.assign(n+1,T());}\n  void add(int\
    \ i,T x){for(i++;i<=n;i+=i&-i) bit[i]+=x;}\n  T sum(int i){T r=T(); for(;i>0;i-=i&-i)\
    \ r+=bit[i]; return r;}\n  T sum(int l,int r){return sum(r)-sum(l);}\n};\n#line\
    \ 6 \"verify/structure/fenwick.test.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int n,q;\n  cin>>n>>q;\n  vector<long long> a(n);\n  for(int\
    \ i=0;i<n;i++) cin>>a[i];\n  Fenwick<long long> fw(a);\n  while(q--){\n    int\
    \ t;\n    cin>>t;\n    if(t==0){\n      int p;\n      long long x;\n      cin>>p>>x;\n\
    \      fw.add(p,x);\n    }else{\n      int l,r;\n      cin>>l>>r;\n      cout<<fw.sum(l,r)<<\"\
    \\n\";\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"structure/fenwick.hpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int n,q;\n\
    \  cin>>n>>q;\n  vector<long long> a(n);\n  for(int i=0;i<n;i++) cin>>a[i];\n\
    \  Fenwick<long long> fw(a);\n  while(q--){\n    int t;\n    cin>>t;\n    if(t==0){\n\
    \      int p;\n      long long x;\n      cin>>p>>x;\n      fw.add(p,x);\n    }else{\n\
    \      int l,r;\n      cin>>l>>r;\n      cout<<fw.sum(l,r)<<\"\\n\";\n    }\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - structure/fenwick.hpp
  isVerificationFile: true
  path: verify/structure/fenwick.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 01:32:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: //verify/structure/fenwick.test.cpp
layout: document
redirect_from:
- /verify/verify/structure/fenwick.test.cpp
- /verify/verify/structure/fenwick.test.cpp.html
title: verify/structure/fenwick.test.cpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_point_add_range_sum.test.cpp
    title: verify/yosupo_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/fenwick.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class T>\nstruct Fenwick{\n  int n;\n  vector<T>\
    \ f;\n  Fenwick(int n=0){init(n);}\n  Fenwick(const vector<T>& a){init((int)a.size());\
    \ for(int i=0;i<n;i++) add(i,a[i]);}\n  void init(int n_){n=n_; f.assign(n+1,T());}\n\
    \  void add(int i,T x){for(i++;i<=n;i+=i&-i) f[i]+=x;}\n  T sum(int i){T r=T();\
    \ for(;i>0;i-=i&-i) r+=f[i]; return r;}\n  T sum(int l,int r){return sum(r)-sum(l);}\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct Fenwick{\n  int n;\n  vector<T> f;\n  Fenwick(int n=0){init(n);}\n\
    \  Fenwick(const vector<T>& a){init((int)a.size()); for(int i=0;i<n;i++) add(i,a[i]);}\n\
    \  void init(int n_){n=n_; f.assign(n+1,T());}\n  void add(int i,T x){for(i++;i<=n;i+=i&-i)\
    \ f[i]+=x;}\n  T sum(int i){T r=T(); for(;i>0;i-=i&-i) r+=f[i]; return r;}\n \
    \ T sum(int l,int r){return sum(r)-sum(l);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/fenwick.hpp
  requiredBy: []
  timestamp: '2026-03-11 01:56:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_point_add_range_sum.test.cpp
documentation_of: structure/fenwick.hpp
layout: document
redirect_from:
- /library/structure/fenwick.hpp
- /library/structure/fenwick.hpp.html
title: structure/fenwick.hpp
---

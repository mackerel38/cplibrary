---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segtree.hpp
    title: structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/yosupo_static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"structure/segtree.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct Segtree{\n  int n, size, lg;\n  vector<S> d;\n  Segtree(int\
    \ n_=0){init(n_);}\n  Segtree(const vector<S>& v){build(v);}\n  void init(int\
    \ n_){\n    n=n_;\n    size=1;\n    lg=0;\n    while(size<n){size<<=1; lg++;}\n\
    \    d.assign(2*size, e());\n  }\n  void build(const vector<S>& v){\n    init((int)v.size());\n\
    \    for(int i=0;i<n;i++) d[size+i]=v[i];\n    for(int i=size-1;i>=1;i--) d[i]=op(d[i<<1],\
    \ d[i<<1|1]);\n  }\n  void set(int p, S x){\n    p+=size;\n    d[p]=x;\n    for(p>>=1;p>=1;p>>=1)\
    \ d[p]=op(d[p<<1], d[p<<1|1]);\n  }\n  S get(int p) const{return d[p+size];}\n\
    \  S prod(int l, int r) const{\n    S sml=e(), smr=e();\n    l+=size; r+=size;\n\
    \    while(l<r){\n      if(l&1) sml=op(sml, d[l++]);\n      if(r&1) smr=op(d[--r],\
    \ smr);\n      l>>=1; r>>=1;\n    }\n    return op(sml, smr);\n  }\n  S all_prod()\
    \ const{return d[1];}\n  template<class F>\n  int max_right(int l, F f) const{\n\
    \    if(l==n) return n;\n    S sm=e();\n    l+=size;\n    do{\n      while((l&1)==0)\
    \ l>>=1;\n      if(!f(op(sm, d[l]))){\n        while(l<size){\n          l<<=1;\n\
    \          if(f(op(sm, d[l]))){\n            sm=op(sm, d[l]);\n            l++;\n\
    \          }\n        }\n        return l-size;\n      }\n      sm=op(sm, d[l]);\n\
    \      l++;\n    }while((l&-l)!=l);\n    return n;\n  }\n  template<class F>\n\
    \  int min_left(int r, F f) const{\n    if(r==0) return 0;\n    S sm=e();\n  \
    \  r+=size;\n    do{\n      r--;\n      while(r>1 && (r&1)) r>>=1;\n      if(!f(op(d[r],\
    \ sm))){\n        while(r<size){\n          r=r<<1|1;\n          if(f(op(d[r],\
    \ sm))){\n            sm=op(d[r], sm);\n            r--;\n          }\n      \
    \  }\n        return r+1-size;\n      }\n      sm=op(d[r], sm);\n    }while((r&-r)!=r);\n\
    \    return 0;\n  }\n};\n#line 3 \"verify/yosupo_static_range_sum.test.cpp\"\n\
    \nusing ll = long long;\n\nll op(ll a, ll b){return a+b;}\nll e(){return 0;}\n\
    \nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  int n, q;\n\
    \  if(!(cin>>n>>q)) return 0;\n  vector<ll> a(n);\n  for(int i=0;i<n;i++) cin>>a[i];\n\
    \  Segtree<ll, op, e> st(a);\n  for(int i=0;i<q;i++){\n    int l, r;\n    cin>>l>>r;\n\
    \    cout<<st.prod(l, r)<<\"\\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"structure/segtree.hpp\"\n\nusing ll = long long;\n\nll op(ll a, ll b){return\
    \ a+b;}\nll e(){return 0;}\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int n, q;\n  if(!(cin>>n>>q)) return 0;\n  vector<ll> a(n);\n  for(int i=0;i<n;i++)\
    \ cin>>a[i];\n  Segtree<ll, op, e> st(a);\n  for(int i=0;i<q;i++){\n    int l,\
    \ r;\n    cin>>l>>r;\n    cout<<st.prod(l, r)<<\"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/segtree.hpp
  isVerificationFile: true
  path: verify/yosupo_static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 02:12:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_static_range_sum.test.cpp
- /verify/verify/yosupo_static_range_sum.test.cpp.html
title: verify/yosupo_static_range_sum.test.cpp
---

#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Fenwick{
  int n;
  vector<T> bit;
  Fenwick(int n=0){init(n);}
  Fenwick(const vector<T>& a){init((int)a.size()); for(int i=0;i<n;i++) add(i,a[i]);}
  void init(int n_){n=n_; bit.assign(n+1,T());}
  void add(int i,T x){for(i++;i<=n;i+=i&-i) bit[i]+=x;}
  T sum(int i){T r=T(); for(;i>0;i-=i&-i) r+=bit[i]; return r;}
  T sum(int l,int r){return sum(r)-sum(l);}
};

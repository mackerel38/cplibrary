#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class S, S (*op)(S, S), S (*e)()>
struct Segtree{
  int n, size, lg;
  vector<S> d;
  Segtree(int n_=0){init(n_);}
  Segtree(const vector<S>& v){build(v);}
  void init(int n_){
    n=n_;
    size=1;
    lg=0;
    while(size<n){size<<=1; lg++;}
    d.assign(2*size, e());
  }
  void build(const vector<S>& v){
    init((int)v.size());
    for(int i=0;i<n;i++) d[size+i]=v[i];
    for(int i=size-1;i>=1;i--) d[i]=op(d[i<<1], d[i<<1|1]);
  }
  void set(int p, S x){
    p+=size;
    d[p]=x;
    for(p>>=1;p>=1;p>>=1) d[p]=op(d[p<<1], d[p<<1|1]);
  }
  S get(int p) const{return d[p+size];}
  S prod(int l, int r) const{
    S sml=e(), smr=e();
    l+=size; r+=size;
    while(l<r){
      if(l&1) sml=op(sml, d[l++]);
      if(r&1) smr=op(d[--r], smr);
      l>>=1; r>>=1;
    }
    return op(sml, smr);
  }
  S all_prod() const{return d[1];}
  template<class F>
  int max_right(int l, F f) const{
    if(l==n) return n;
    S sm=e();
    l+=size;
    do{
      while((l&1)==0) l>>=1;
      if(!f(op(sm, d[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sm, d[l]))){
            sm=op(sm, d[l]);
            l++;
          }
        }
        return l-size;
      }
      sm=op(sm, d[l]);
      l++;
    }while((l&-l)!=l);
    return n;
  }
  template<class F>
  int min_left(int r, F f) const{
    if(r==0) return 0;
    S sm=e();
    r+=size;
    do{
      r--;
      while(r>1 && (r&1)) r>>=1;
      if(!f(op(d[r], sm))){
        while(r<size){
          r=r<<1|1;
          if(f(op(d[r], sm))){
            sm=op(d[r], sm);
            r--;
          }
        }
        return r+1-size;
      }
      sm=op(d[r], sm);
    }while((r&-r)!=r);
    return 0;
  }
};

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "structure/fenwick.hpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin>>n>>q;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  Fenwick<long long> fw(a);
  while(q--){
    int t;
    cin>>t;
    if(t==0){
      int p;
      long long x;
      cin>>p>>x;
      fw.add(p,x);
    }else{
      int l,r;
      cin>>l>>r;
      cout<<fw.sum(l,r)<<"\n";
    }
  }
  return 0;
}

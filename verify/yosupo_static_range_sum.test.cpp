#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "structure/segtree.hpp"

using ll = long long;

ll op(ll a, ll b){return a+b;}
ll e(){return 0;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  if(!(cin>>n>>q)) return 0;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  Segtree<ll, op, e> st(a);
  for(int i=0;i<q;i++){
    int l, r;
    cin>>l>>r;
    cout<<st.prod(l, r)<<"\n";
  }
  return 0;
}

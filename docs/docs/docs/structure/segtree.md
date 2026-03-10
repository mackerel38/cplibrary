Definition
区間演算のセグメント木。

Complexity
初期化: O(n)
更新: O(log n)
区間取得: O(log n)

Usage
```cpp
#include "structure/segtree.hpp"
using ll = long long;
ll op(ll a, ll b){return a+b;}
ll e(){return 0;}
int main(){
  vector<ll> a = {1,2,3};
  Segtree<ll, op, e> st(a);
  cout << st.prod(0,3) << "\n";
}
```

#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"
#include "math/affine.hpp"
#include "math/modint.hpp"
#include <bits/stdc++.h>
using namespace std;

using mint = modint<998244353>;
using F = affine<mint>;

struct node {
  mint sum;
  int l;
  int r;
  F lz;
  bool has;
};

struct pst {
  int n;
  vector<node> nd;
  vector<int> root;

  pst() : n(0) {}
  pst(const vector<mint>& a) { build(a); }

  int new_node(mint sum, int l, int r, F lz, bool has) {
    nd.push_back({sum, l, r, lz, has});
    return (int)nd.size() - 1;
  }

  int build_vec(int l, int r, const vector<mint>& a) {
    if (r - l == 1) return new_node(a[l], -1, -1, F(), false);
    int m = (l + r) >> 1;
    int lc = build_vec(l, m, a);
    int rc = build_vec(m, r, a);
    return new_node(nd[lc].sum + nd[rc].sum, lc, rc, F(), false);
  }

  void build(const vector<mint>& a) {
    n = (int)a.size();
    nd.clear();
    root.clear();
    root.push_back(build_vec(0, n, a));
  }

  int clone(int v) {
    nd.push_back(nd[v]);
    return (int)nd.size() - 1;
  }

  void all_apply(int v, F f, int len) {
    nd[v].sum = f.a * nd[v].sum + f.b * mint(len);
    if (nd[v].has) {
      nd[v].lz = affine_compose(f, nd[v].lz);
    } else {
      nd[v].lz = f;
      nd[v].has = true;
    }
  }

  void push(int v, int l, int r) {
    if (!nd[v].has || r - l == 1) return;
    int m = (l + r) >> 1;
    int lc = clone(nd[v].l);
    int rc = clone(nd[v].r);
    all_apply(lc, nd[v].lz, m - l);
    all_apply(rc, nd[v].lz, r - m);
    nd[v].l = lc;
    nd[v].r = rc;
    nd[v].lz = F();
    nd[v].has = false;
  }

  int apply(int v, int l, int r, int ql, int qr, F f) {
    if (qr <= l || r <= ql) return v;
    v = clone(v);
    if (ql <= l && r <= qr) {
      all_apply(v, f, r - l);
      return v;
    }
    push(v, l, r);
    int m = (l + r) >> 1;
    int lc = apply(nd[v].l, l, m, ql, qr, f);
    int rc = apply(nd[v].r, m, r, ql, qr, f);
    nd[v].l = lc;
    nd[v].r = rc;
    nd[v].sum = nd[lc].sum + nd[rc].sum;
    return v;
  }

  mint prod(int v, int l, int r, int ql, int qr, F acc) {
    if (qr <= l || r <= ql) return mint(0);
    if (ql <= l && r <= qr) return acc.a * nd[v].sum + acc.b * mint(r - l);
    int m = (l + r) >> 1;
    F nxt = acc;
    if (nd[v].has) nxt = affine_compose(acc, nd[v].lz);
    mint lv = prod(nd[v].l, l, m, ql, qr, nxt);
    mint rv = prod(nd[v].r, m, r, ql, qr, nxt);
    return lv + rv;
  }

  int replace_range(int a, int b, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) return a;
    if (ql <= l && r <= qr) return b;
    a = clone(a);
    b = clone(b);
    push(a, l, r);
    push(b, l, r);
    int m = (l + r) >> 1;
    int lc = replace_range(nd[a].l, nd[b].l, l, m, ql, qr);
    int rc = replace_range(nd[a].r, nd[b].r, m, r, ql, qr);
    nd[a].l = lc;
    nd[a].r = rc;
    nd[a].sum = nd[lc].sum + nd[rc].sum;
    return a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<mint> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  pst seg(a);
  vector<int> ver(Q, -1);
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int k, l, r;
      long long b, c;
      cin >> k >> l >> r >> b >> c;
      int base = (k == -1) ? seg.root[0] : ver[k];
      int nr = seg.apply(base, 0, seg.n, l, r, F(mint(b), mint(c)));
      ver[i] = nr;
    } else if (t == 1) {
      int k, s, l, r;
      cin >> k >> s >> l >> r;
      int base = (k == -1) ? seg.root[0] : ver[k];
      int src = (s == -1) ? seg.root[0] : ver[s];
      int nr = seg.replace_range(base, src, 0, seg.n, l, r);
      ver[i] = nr;
    } else {
      int k, l, r;
      cin >> k >> l >> r;
      int base = (k == -1) ? seg.root[0] : ver[k];
      mint ans = seg.prod(base, 0, seg.n, l, r, F());
      cout << ans.v << "\n";
    }
  }
  return 0;
}

---
title: Sparse Table
documentation_of: //structure/sparsetable.hpp
---

Definition
Sparse Table により静的 RMQ を処理する。最小値の問い合わせを O(1) で処理する。

Complexity
構築は O(n log n)、クエリは O(1)。

使い方
`sparse_table<T, Cmp> st(v);` で配列 v から構築する。
`st.build(v, cmp);` で再構築する。
`st.argmin(l, r);` で区間 [l, r) の最小要素の index を返す。
`st.query(l, r);` で区間 [l, r) の最小値を返す。
`Cmp` を `greater<T>` にすると最大値版になる。

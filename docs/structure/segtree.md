---
title: セグメント木
documentation_of: //structure/segtree.hpp
---
Definition
区間演算を扱う完全二分木で、配列に対する一点更新と区間クエリを高速に処理する。

Complexity
構築は O(n)、一点更新は O(log n)、区間積は O(log n)。

この実装はモノイド (S, op, e) を前提とする。
prod(l, r) は半開区間 [l, r) の積を返す。
all_prod() は全体の積を返す。
max_right(l, f) は f(op(a[l], ..., a[r-1])) が成り立つ最大の r を返す。
min_left(r, f) は f(op(a[l], ..., a[r-1])) が成り立つ最小の l を返す。

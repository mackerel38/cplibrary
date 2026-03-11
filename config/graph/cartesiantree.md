---
title: Cartesian Tree
documentation_of: //graph/cartesiantree.hpp
---

Definition
配列に対する Cartesian Tree を構築する。in-order が元の順序になり、根が最小値になる。

Complexity
O(n)。

使い方
`cartesian_tree<T, Cmp> ct(a);` で配列 a から構築する。
`ct.build(a, cmp);` で再構築できる。
`ct.root` が根のインデックス。
`ct.parent[i]` が親、`ct.left[i]` と `ct.right[i]` が左右の子（存在しない場合は -1）。
`Cmp` を `greater<T>` にすると最大値が根になる。

---
title: Union-Find
documentation_of: //structure/unionfind.hpp
---

Definition
Union-Find は素集合データ構造であり、連結判定と併合を提供する。

Complexity
各操作はならし O(α(n))。

使い方
`unionfind uf(n);` で要素数 n の集合を作る。
`uf.init(n);` で再初期化する。
`uf.leader(x);` で x の代表元を返す。
`uf.same(a, b);` で同一集合か判定する。
`uf.merge(a, b);` で併合し、成功なら true を返す。
`uf.size(x);` で x が属する集合のサイズを返す。

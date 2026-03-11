---
title: 両端優先度付きキュー
documentation_of: //structure/bipq.hpp
---

Definition
bipq は多重集合として最小値・最大値の取得と削除を提供する。

Complexity
各操作は O(log n)。

使い方

- `bipq<T> pq;` で空の多重集合を作る。
- `pq.push(x);` で要素 x を追加する。
- `pq.min();` で最小値を取得する。
- `pq.max();` で最大値を取得する。
- `pq.pop_min();` で最小値を削除して返す。
- `pq.pop_max();` で最大値を削除して返す。
- `pq.size();` は要素数、`pq.empty();` は空かどうかを返す。
- `pq.clean_min();` と `pq.clean_max();` は内部の整合性を保つための掃除で、通常は直接呼ばなくてよい。

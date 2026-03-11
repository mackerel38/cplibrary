---
title: Treap
documentation_of: //structure/treap.hpp
---

Definition
Treap は乱数優先度付きの二分探索木であり、順序付き集合として insert/erase/contains と順序統計（kth、count_lt、count_le、lower_bound、upper_bound、prev、prev_eq）を提供する。

Complexity
各操作は期待 O(log n)。

ポイント
- 乱数優先度で平衡化する二分探索木
- 順序統計の取得が可能
- 重複は無視される集合として扱う

使い方

- `treap<T, Cmp> tr;` で空の集合を作る。
- `tr.size();` で要素数を取得する。
- `tr.contains(key);` で存在判定する。
- `tr.insert(key);` で要素を追加する。重複は無視される。
- `tr.erase(key);` で要素を削除する。
- `tr.kth(k, out);` で 0-indexed の k 番目を取得し、成功なら true。
- `tr.count_lt(key);` で key 未満の個数を返す。
- `tr.count_le(key);` で key 以下の個数を返す。
- `tr.lower_bound(key, out);` で key 以上の最小要素を取得する。
- `tr.upper_bound(key, out);` で key より大きい最小要素を取得する。
- `tr.prev(key, out);` で key 未満の最大要素を取得する。
- `tr.prev_eq(key, out);` で key 以下の最大要素を取得する。
- `Cmp` は順序の比較関数で、デフォルトは昇順。
- `size(node*)`, `pull(node*)`, `rnd()`, `eq(a, b)`, `split`, `merge`, `insert(node*, node*)`, `erase(node*, key)` は内部用の補助関数。

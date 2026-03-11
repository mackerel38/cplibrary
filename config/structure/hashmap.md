---
title: ハッシュマップ
documentation_of: //structure/hashmap.hpp
---

Definition
キーに対応する値を保存し、挿入、更新、検索、削除を行う連想配列。

Complexity
期待計算量 O(1)（挿入・検索・削除）。

線形探索によるオープンアドレス方式で実装している。

使い方

- `hashmap<K, V> mp;` で作成する。
- `mp.set(k, v);` でキー k に値 v を保存する（既存なら更新）。
- `mp.get(k, def);` でキー k の値を取得し、存在しないときは def を返す。
- `mp.get_ptr(k);` で値へのポインタを取得する。存在しないときは null。
- `mp[k]` で参照を取得し、存在しない場合はデフォルト値を挿入する。
- `mp.contains(k);` で存在判定。
- `mp.erase(k);` で削除し、成功なら true を返す。
- `mp.reserve(m);` で要素数 m を見越して容量を確保する。
- `mp.rehash(c);` で強制的に再ハッシュする（通常は不要）。
- `mp.find_idx(k);` は内部用の検索関数で、見つからない場合は `cap` を返す。

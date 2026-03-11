---
title: 動的遅延セグメント木
documentation_of: //structure/dynamiclazysegtree.hpp
---
Definition
区間更新と区間取得をサポートする動的セグメント木。

Complexity
各操作 O(log N)

巨大な N に対して必要なノードのみ確保する。初期値は `make(len)` で表現し、空ノードの区間長に応じた単位元を返す設計。

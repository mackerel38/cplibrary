---
title: 重み付き Union-Find
documentation_of: structure/weightedunionfind.hpp
---

Definition
重み付き Union-Find は各要素にポテンシャルを持たせ、同一連結成分内での差分を扱える素集合データ構造。要素 u, v と値 x に対して a_u = a_v + x を統合し、既存の情報と矛盾しないか判定できる。連結であれば a_u - a_v を取得できる。

Complexity
各操作はならし O(\u03b1(n))。

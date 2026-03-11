---
title: Range Parallel Union-Find
documentation_of: //structure/rangeparallel_unionfind.hpp
---

Definition
2つの同じ長さの区間に対して、対応する頂点をすべて併合する操作を高速に行う Union-Find。各連結成分の和を保持し、同一成分内のペアの積の総和を更新できる。

Complexity
各操作はならし O(log N \u03b1(N))。

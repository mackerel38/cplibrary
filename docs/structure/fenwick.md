## Definition
Point add and prefix/range sum on an array.

## Complexity
- `add`: O(log n)
- `sum`: O(log n)

## Usage
```cpp
Fenwick<long long> fw(n);
fw.add(i, x);
auto s = fw.sum(l, r);
```

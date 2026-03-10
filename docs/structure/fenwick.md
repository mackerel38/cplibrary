# Fenwick Tree

## Usage
```cpp
Fenwick<long long> fw(n);
fw.add(i, x);
auto s = fw.sum(l, r);
```

## Complexity
- `add`: O(log n)
- `sum`: O(log n)

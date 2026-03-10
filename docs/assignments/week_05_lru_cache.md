# Week 05 — LRU Cache

## Objective
Combine a hash map and a doubly linked list into an eviction-based cache.

## Why this assignment matters
This is the first assignment that really tests systems composition.
You are no longer just writing a data structure.
You are coordinating multiple invariants at once.

## Required public API
See `include/course/lru_cache.hpp`.

## Required behavior
- `get` returns value if present and promotes key to most-recent
- `put` inserts or updates
- oldest entry is evicted when capacity is exceeded

## Public test focus
- basic insert/get
- update existing key
- promotion on access
- eviction order

## Hidden-test themes
- capacity 0 and 1
- repeated access to same key
- overwrite before eviction
- stale list pointers
- hash/list disagreement after long sequences

## Suggested custom tests
- small-step scenario tests with exact recency order
- random model against a Python or reference implementation
- long stress tests with repeated updates

## Benchmark requirement
Measure hit latency, miss latency, and eviction-heavy workloads.

## Rubric emphasis
- multi-structure invariant correctness: 40%
- tests for edge cases and long runs: 30%
- design clarity: 15%
- benchmark note: 15%

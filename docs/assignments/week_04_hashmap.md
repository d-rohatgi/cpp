# Week 04 — HashMap

## Objective
Build a templated hash map with a clear collision strategy.

## Why this assignment matters
This is your first assignment where asymptotics are not enough.
You must think about:
- collision handling
- load factor
- resize policy
- probing or chaining tradeoffs
- how performance degrades under bad inputs

## Required public API
See `include/course/hashmap.hpp`.

## Required behavior
- insert
- contains
- find
- erase
- rehash
- size / empty

## Public test focus
- insert and find basic keys
- missing keys
- erase behavior
- overwrite/duplicate-key policy

## Hidden-test themes
- collision-heavy inputs
- repeated rehashing
- tombstone bugs if using open addressing
- erase followed by insert
- large random workloads

## Suggested custom tests
- model-based randomized test against `std::unordered_map`
- adversarial key types
- explicit rehash correctness checks
- repeated overwrite of same key

## Benchmark requirement
Compare random lookup and insert throughput vs `std::unordered_map`.

## Rubric emphasis
- invariant maintenance under long sequences: 35%
- test depth: 25%
- performance reasoning: 20%
- API/code clarity: 20%

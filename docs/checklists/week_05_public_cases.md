# Week 05 Public Test Cases

## Normal cases
- `"apple banana apple"` -> apple count 2
- top_k should return no more than `k`

## Corner cases
- `"Apple apple, APPLE!"` should normalize to one key
- empty input should return empty result
- punctuation-only input should return empty result
- tie cases should use a consistent ordering rule

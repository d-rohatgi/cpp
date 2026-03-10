# Week 08 Public Test Cases

## Normal cases
- UniquePtr owns raw pointer
- release returns pointer and nulls owner
- SharedPtr starts with count 1
- SharedPtr copy increments count

## Corner cases
- reset to null
- null default construction
- repeated copies
- destruction count under nested scope

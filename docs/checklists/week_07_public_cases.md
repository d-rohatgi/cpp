# Week 07 Public Test Cases

## Normal cases
- vector starts empty
- push_back preserves order
- reserve keeps size unchanged
- clear destroys live elements

## Corner cases
- pop_back on last element
- pop_back on empty under chosen policy
- at() out of range
- copy makes independent storage
- moved-from vector remains valid

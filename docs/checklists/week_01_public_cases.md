# Week 01 Public Test Cases

## Normal cases
- `calculate(2, 3, '+') -> 5`
- `calculate(4, 5, '*') -> 20`
- `calculate(10, 4, '-') -> 6`
- `calculate(8, 2, '/') -> 4`

## Corner cases
- `calculate(8, 0, '/')` should signal failure
- `calculate(8, 2, '?')` should signal failure
- `calculate(-3, 2, '+') -> -1`
- `calculate(2.5, 4.0, '*') -> 10.0`

# Quadratic equations solver

This library provides one function `solve_equation` for solving quadratic equations.

## How to use?

`QuadraticEquationSolution` - the result struct of the function. Is has 3 fields:

1. `x1` - first root of the equation. Has `double` type.
2. `x2` - second root of the equation. Has `double` type.
3. `roots_count` - number of equation roots. Has `unsigned int` type.

If equation has two roots, then `roots_count` is 2 and `x1` is not greater than `x2`.

If equation has one root, then `roots_count` is 1, `x1` is unique root and `x2` is `NAN`.

If equation has no roots, then `roots_count` is 0 and `x1` and `x2` is `NAN`.

### Example

```c
QuadraticEquationSolution s = solve_equation(1, -2, 1);

assert(s.roots_count == 1);  // true
assert(s.x1 == 1);           // true
assert(isnan(s.x2));         // true
```

## Create static library

```makefile
make lib
```

## Test library

```makefile
make check
```

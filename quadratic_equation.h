#ifndef QUADRATIC_EQUATION_H_
#define QUADRATIC_EQUATION_H_

/**
 * @brief Struct that represents quadratic equation solution.
 */
typedef struct {
  double x1;
  double x2;
  unsigned roots_count;
} QuadraticEquationSolution;

/**
 * @brief Function that solves quadratic equations ax^2 + bx + c.
 *
 * @param a - coeffitient a.
 * @param b - coefftitent b.
 * @param c - coeffitient c.
 *
 * @return QuadraticEquationSolution struct, x1 - first root, x2 - second root,
 * roots_count - count of quadratic equations roots. x1 is always less or equal
 * than x2 in case when there are two roots.
 */
QuadraticEquationSolution solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H_

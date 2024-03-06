#include "quadratic_equation.h"

#include <math.h>

QuadraticEquationSolution solve_equation(double a, double b, double c) {
  QuadraticEquationSolution solution = {NAN, NAN, 0};

  if (a == 0) {
    // non-quadratic equation

    if (!isnan(-c / b)) {
      solution.roots_count = 1;
      solution.x1 = -c / b;
    }
  } else {
    // quadratic equation

    double d = b * b - 4 * a * c;
    if (d == 0) {
      // one root

      solution.roots_count = 1;
      solution.x1 = -b / (2 * a);
    } else if (d > 0) {
      // two roots

      solution.roots_count = 2;
      double sq = sqrt(d);
      solution.x1 = (-b + sq) / (2 * a);
      solution.x2 = (-b - sq) / (2 * a);

      // making x1 less or equal than x2
      if (solution.x2 < solution.x1) {
        double tmp = solution.x1;
        solution.x1 = solution.x2;
        solution.x2 = tmp;
      }
    }
  }

  return solution;
}

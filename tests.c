#include <check.h>
#include <math.h>

#include "quadratic_equation.h"

#define check_doubles(x, y) ck_assert_double_eq_tol(x, y, 1e-6)

START_TEST(two_roots) {
  QuadraticEquationSolution solution = solve_equation(2, 5, -3);
  ck_assert_uint_eq(solution.roots_count, 2);
  check_doubles(solution.x1, -3);
  check_doubles(solution.x2, 1.0 / 2.0);

  solution = solve_equation(4, 21, 5);
  ck_assert_uint_eq(solution.roots_count, 2);
  check_doubles(solution.x1, -5);
  check_doubles(solution.x2, -1.0 / 4.0);

  solution = solve_equation(3, -10, 3);
  ck_assert_uint_eq(solution.roots_count, 2);
  check_doubles(solution.x1, 1.0 / 3.0);
  check_doubles(solution.x2, 3);

  solution = solve_equation(1, -8, 4);
  ck_assert_uint_eq(solution.roots_count, 2);
  check_doubles(solution.x1, 4 - 2 * sqrt(3));
  check_doubles(solution.x2, 4 + 2 * sqrt(3));
}
END_TEST

START_TEST(one_root) {
  QuadraticEquationSolution solution = solve_equation(1, -2, 1);
  ck_assert_uint_eq(solution.roots_count, 1U);
  check_doubles(solution.x1, 1);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(1, -4, 4);
  ck_assert_uint_eq(solution.roots_count, 1);
  check_doubles(solution.x1, 2);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(1, 0, 0);
  ck_assert_uint_eq(solution.roots_count, 1);
  check_doubles(solution.x1, 0);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(5, -10, 5);
  ck_assert_uint_eq(solution.roots_count, 1);
  check_doubles(solution.x1, 1);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(3, 6, 3);
  ck_assert_uint_eq(solution.roots_count, 1);
  check_doubles(solution.x1, -1);
  ck_assert_double_nan(solution.x2);
}
END_TEST

START_TEST(no_roots) {
  QuadraticEquationSolution solution = solve_equation(1, 1, 1);
  ck_assert_uint_eq(solution.roots_count, 0);
  ck_assert_double_nan(solution.x1);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(2, 3, 4);
  ck_assert_uint_eq(solution.roots_count, 0);
  ck_assert_double_nan(solution.x1);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(1, 0, 1);
  ck_assert_uint_eq(solution.roots_count, 0);
  ck_assert_double_nan(solution.x1);
  ck_assert_double_nan(solution.x2);
}
END_TEST

START_TEST(not_a_quadratic) {
  QuadraticEquationSolution solution = solve_equation(0, 2, 3);
  ck_assert_uint_eq(solution.roots_count, 1);
  check_doubles(solution.x1, -3.0 / 2.0);
  ck_assert_double_nan(solution.x2);

  solution = solve_equation(0, 0, 0);
  ck_assert_uint_eq(solution.roots_count, 0);
  ck_assert_double_nan(solution.x1);
  ck_assert_double_nan(solution.x2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, two_roots);
  tcase_add_test(tc1_1, one_root);
  tcase_add_test(tc1_1, no_roots);
  tcase_add_test(tc1_1, not_a_quadratic);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

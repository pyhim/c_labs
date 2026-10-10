//
// Created by dmytro on 30.09.2026.
//

#pragma once

#include <stdbool.h>
#include <math.h>

#define EPSILON 1e-9

typedef enum {
    MATH_SUCCESS = 0,
    MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN,
} math_debug_code;

const char *math_debug_code_to_string(math_debug_code code);

void math_debug_code_write(math_debug_code *to, math_debug_code value);

/**
 * Checks whether the number equals zero with consideration about
 * CPU's peculiarity of floating-point operations.
 * @return The result of the predicate.
 */
bool double_equals_zero(double number);

double discriminant(double a, double b, double c);

double circle_area(double radius);

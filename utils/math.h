//
// Created by dmytro on 30.09.2026.
//

#pragma once

#include <stdbool.h>

typedef enum math_debug_code {
    MATH_SUCCESS = 0,
    ERR_ARGUMENT_OUTSIDE_DOMAIN,
} math_debug_code_t;

const char *math_debug_code_to_string(math_debug_code_t code);

void write_math_debug_code(math_debug_code_t *to, math_debug_code_t value);

/**
 * Checks whether the number equals zero with consideration about
 * CPU's peculiarity of floating-point operations.
 * @return The result of the predicate.
 */
bool double_equals_zero(double number);

double discriminant(double a, double b, double c);

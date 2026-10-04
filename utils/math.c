//
// Created by dmytro on 30.09.2026.
//

#include "math.h"

#include <math.h>

#define EPSILON 1e-8 // 0.00000001

const char *math_debug_code_to_string(const math_debug_code_t code) {
    switch (code) {
        case MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN:
            return "The argument is outside the domain of the function's permissible values.";
        default:
            return "Success.";
    }
}

void write_math_debug_code(math_debug_code_t *const to, const math_debug_code_t value) {
    if (!to)
        return;

    *to = value;
}

bool double_equals_zero(const double number) {
    return fabs(number) < EPSILON;
}

double discriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

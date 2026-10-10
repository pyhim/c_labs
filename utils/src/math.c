//
// Created by dmytro on 30.09.2026.
//

#include "../include/utils/math.h"

#define EPSILON 1e-9 // 0.000000001

const char *math_debug_code_to_string(const math_debug_code code) {
    switch (code) {
        case MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN:
            return "The argument is outside the domain of the function's permissible values.";
        default:
            return "Success.";
    }
}

void math_debug_code_write(math_debug_code *const to, const math_debug_code value) {
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

double circle_area(const double radius) {
    return radius * radius * M_PI;
}

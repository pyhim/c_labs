//
// Created by dmytro on 30.09.2026.
//

#include "../include/utils/math.h"

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

bool double_less_than_zero(const double number) {
    return number < -EPSILON;
}

bool double_greater_than_zero(const double number) {
    return number > EPSILON;
}

ComparisonResult compare_doubles(const double left, const double right) {
    const double delta = left - right;

    if (double_greater_than_zero(delta)) {
        return CMP_GREATER_THAN;
    }
    if (double_less_than_zero(delta)) {
        return CMP_LESS_THAN;
    }

    return CMP_EQUAL;
}

ComparisonResult compare_ints(const int left, const int right) {
    if (left > right) {
        return CMP_GREATER_THAN;
    }
    if (left < right) {
        return CMP_LESS_THAN;
    }

    return CMP_EQUAL;
}

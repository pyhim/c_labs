//
// Created by dmytro on 30.09.2026.
//

#include "../include/utils/math.h"

const char *math_debug_code_to_string(const MathDebugCode code) {
    switch (code) {
        case MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN:
            return "The argument is outside the domain of the function's permissible values.";
        default:
            return "Success.";
    }
}

void math_debug_code_write(MathDebugCode *const to, const MathDebugCode value) {
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

ComparisonResult compare_ints(const long left, const long right) {
    if (left > right) {
        return CMP_GREATER_THAN;
    }
    if (left < right) {
        return CMP_LESS_THAN;
    }

    return CMP_EQUAL;
}

void accumulate_sum_int(int *value, const int increment) {
    if (!value)
        return;

    *value += increment;
}

void accumulate_product_int(int *value, const int factor) {
    if (!value)
        return;

    *value *= factor;
}

void qube_int(int *number) {
    if (!number)
        return;

    *number = *number * *number * *number;
}

double cross_product(const Point2D a, const Point2D b, const Point2D c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

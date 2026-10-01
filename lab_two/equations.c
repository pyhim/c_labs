//
// Created by dmytro on 23.09.2026.
//

#include "equations.h"

#include <math.h>

double task1(const double x, math_debug_code_t *dbg_code) {
    const double denominator = x * x - 8 * x + 12;

    if (double_equals_zero(denominator)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double nominator = x * x - 7 * x + 10;

    write_math_debug_code(dbg_code, MATH_SUCCESS);

    return nominator / denominator;
}

double task2(const double x, const double y, math_debug_code_t *dbg_code) {
    const double denominator = cos(x) - sin(y);

    if (double_equals_zero(denominator)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double cos_xy = cos(x * y);

    if (double_equals_zero(cos_xy)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_xy = sin(x * y) / cos_xy;

    const double nominator = sin(x) + cos(y);

    write_math_debug_code(dbg_code, MATH_SUCCESS);

    return (nominator / denominator) * tan_xy;
}

double task5(const double x, math_debug_code_t *dbg_code) {
    const double cos_x = cos(x);

    if (double_equals_zero(cos_x)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_x = sin(x) / cos_x;

    if (double_equals_zero(tan_x)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double absolute = fabs(x - 1);

    write_math_debug_code(dbg_code, MATH_SUCCESS);

    return absolute / tan_x;
}

double task7(const double x, const double y, math_debug_code_t *dbg_code) {
    const double sin_x = sin(x), cos_x = cos(x);

    if (double_equals_zero(sin_x) || double_equals_zero(cos_x)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_x = sin_x / cos_x;
    const double cot_x = cos_x / sin_x;

    const double base = 1 - tan_x;

    if (base <= 0) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    write_math_debug_code(dbg_code, MATH_SUCCESS);

    return pow(base, cot_x) + cos(x - y);
}

double task8(const double x, math_debug_code_t *dbg_code) {
    if (double_equals_zero(x)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double cos_x = cos(x);

    if (double_equals_zero(cos_x)) {
        write_math_debug_code(dbg_code, ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double nominator_logarithm_argument = fabs(cos_x);
    const double denominator_logarithm_argument = 1 + x * x;

    write_math_debug_code(dbg_code, MATH_SUCCESS);

    return log(nominator_logarithm_argument) / log(denominator_logarithm_argument);
}

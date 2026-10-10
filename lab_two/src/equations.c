//
// Created by dmytro on 23.09.2026.
//

#include "../include/equations.h"

#include <math.h>

double task18(const double x, const double y, math_debug_code *dbg_code) {
    const double denominator = 18.0 * y - 1.0;

    if (double_equals_zero(denominator)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double nominator = y * y + 12.0 * x * y - 3.0 * x * x;
    const double result = exp(x) - nominator / denominator;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return result;
}

double task21(const double x, math_debug_code *dbg_code) {
    if (x <= -1.0) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double base_powered_by_x = pow(1 + x, x);
    const double result = exp(x) - x - 2 + base_powered_by_x;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return result;
}

double task22(const double x, const double y, math_debug_code *dbg_code) {
    if (x <= 0.0) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double denominator = cos(x) - x / 3;

    if (double_equals_zero(denominator)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double result = x * log(x) + y / denominator;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return result;
}

double task25(const double x, const double y, math_debug_code *dbg_code) {
    const double sin_x_plus_y = sin(x + y);
    const double nominator = 1 + sin_x_plus_y * sin_x_plus_y;
    const double denominator = 2 + fabs(x - 2 * x / 1 + x * x * y * y);
    const double result = nominator / denominator + x;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return result;
}

double task44(const double x, const double y, math_debug_code *dbg_code) {
    const double denominator = 5 - 7 * y;

    if (double_equals_zero(denominator)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double result = fabs(3 - x / denominator);

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return result;
}

/*double task1(const double x, math_debug_code *dbg_code) {
    const double denominator = x * x - 8 * x + 12;

    if (double_equals_zero(denominator)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double nominator = x * x - 7 * x + 10;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return nominator / denominator;
}

double task2(const double x, const double y, math_debug_code *dbg_code) {
    const double denominator = cos(x) - sin(y);

    if (double_equals_zero(denominator)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double cos_xy = cos(x * y);

    if (double_equals_zero(cos_xy)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_xy = sin(x * y) / cos_xy;

    const double nominator = sin(x) + cos(y);

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return (nominator / denominator) * tan_xy;
}

double task5(const double x, math_debug_code *dbg_code) {
    const double cos_x = cos(x);

    if (double_equals_zero(cos_x)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_x = sin(x) / cos_x;

    if (double_equals_zero(tan_x)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double absolute = fabs(x - 1);

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return absolute / tan_x;
}

double task7(const double x, const double y, math_debug_code *dbg_code) {
    const double sin_x = sin(x), cos_x = cos(x);

    if (double_equals_zero(sin_x) || double_equals_zero(cos_x)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double tan_x = sin_x / cos_x;
    const double cot_x = cos_x / sin_x;

    const double base = 1 - tan_x;

    if (base <= 0) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return pow(base, cot_x) + cos(x - y);
}

double task8(const double x, math_debug_code *dbg_code) {
    if (double_equals_zero(x)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double cos_x = cos(x);

    if (double_equals_zero(cos_x)) {
        math_debug_code_write(dbg_code, MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN);
        return 0.0;
    }

    const double nominator_logarithm_argument = fabs(cos_x);
    const double denominator_logarithm_argument = 1 + x * x;

    math_debug_code_write(dbg_code, MATH_SUCCESS);

    return log(nominator_logarithm_argument) / log(denominator_logarithm_argument);
}*/

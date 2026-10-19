//
// Created by dmytro on 30.09.2026.
//

#pragma once

#include <stdbool.h>
#include <math.h>

#include "functional.h"

#define EPSILON 1e-9 // 0.000000001

typedef enum {
    MATH_SUCCESS = 0,
    MATH_ERR_ARGUMENT_OUTSIDE_DOMAIN,
} MathDebugCode;

const char *math_debug_code_to_string(MathDebugCode code);

void math_debug_code_write(MathDebugCode *to, MathDebugCode value);

/**
 * Checks whether the number <b>equals zero</b> with consideration about
 * CPU's peculiarity of floating-point operations.
 * @return The result of the predicate.
 */
bool double_equals_zero(double number);

/**
 * Checks whether the number is <b>less than zero</b> with consideration about
 * CPU's peculiarity of floating-point operations.
 * @return The result of the predicate.
 */
bool double_less_than_zero(double number);

/**
 * Checks whether the number is <b>greater than zero</b> with consideration about
 * CPU's peculiarity of floating-point operations.
 * @return The result of the predicate.
 */
bool double_greater_than_zero(double number);

/**
 * Compare two double values.
 * @param left Left operand.
 * @param right Right operand
 * @return Result of the comparison
 */
ComparisonResult compare_doubles(double left, double right);

/**
 * Compare two int values.
 * @param left Left operand.
 * @param right Right operand
 * @return Result of the comparison
 */
ComparisonResult compare_ints(long left, long right);

void accumulate_sum_int(int *value, int increment);

void accumulate_product_int(int *value, int factor);

void qube_int(int *number);

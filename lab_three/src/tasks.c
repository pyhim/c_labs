//
// Created by dmytro on 07.10.2026.
//

#include "../include/tasks.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include <utils/cli.h>
#include <utils/math.h>

#include "utils/numbers.h"

WRAP_PREDICATE(double_less_than_zero, double)

static bool int_not_three_digits(const int number) {
    return number < 100 || number > 999;
}

WRAP_PREDICATE(int_not_three_digits, int)

WRAP_AGGREGATOR(accumulate_int, int)

WRAP_ACTION(qube_int, int)

int task7(void) {
    double radius = 0, square_side = 0;

    PromptOptions radius_input_options = {
        .out = &radius,
        .label = "Radius",
        .fail_on = double_less_than_zero_adapter,
        .msg_on_fail = "Radius can't be less than zero",
        .max_attempts = 5,
    };

    if (prompt_double(&radius_input_options))
        return -1;

    PromptOptions square_side_input_options = {
        .out = &square_side,
        .label = "Square side",
        .fail_on = double_less_than_zero_adapter,
        .msg_on_fail = "Square side can't be less than zero",
        .max_attempts = 5,
    };

    if (prompt_double(&square_side_input_options))
        return -1;

    const double area_circle = M_PI * radius * radius;
    const double area_square = square_side * square_side;

    switch (compare_doubles(area_circle, area_square)) {
        case CMP_GREATER_THAN:
            puts("Circle's area is bigger than square's.");
            break;
        case CMP_LESS_THAN:
            puts("Circle's area is less than square's.");
            break;
        case CMP_EQUAL:
            puts("Circle's area is equal to square's.");
            break;
    }

    return 0;
}

int task18(void) {
    int number = 0;

    PromptOptions number_input_options = {
        .out = &number,
        .label = "Number",
        .fail_on = int_not_three_digits_adapter,
        .msg_on_fail = "Number must be three digits",
        .max_attempts = 5,
    };

    if (prompt_int(&number_input_options))
        return -1;

    int digits[3] = {0};
    Span digits_view = Span_create(digits, sizeof(int), 3);

    decompose_int(number, &digits_view);
    Span_apply(&digits_view, qube_int_adapter);
    int *qubed_and_summed = Span_aggregate(&digits_view, accumulate_int_adapter);
    const int doubled_number = number * number;

    if (doubled_number == *qubed_and_summed) {
        puts("Number is equal to the sum of its digits cubed.");
        return 0;
    }

    puts("Number is not equal to the sum of its digits cubed.");

    free(qubed_and_summed);

    return 0;
}

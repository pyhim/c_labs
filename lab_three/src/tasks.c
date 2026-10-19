//
// Created by dmytro on 07.10.2026.
//

#include "../include/tasks.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include <utils/cli.h>
#include <utils/math.h>

#include "utils/numbers.h"

WRAP_PREDICATE(double_less_than_zero, double)

static bool int_not_three_digits(const int number) {
    return number < 100 || number > 999;
}

WRAP_PREDICATE(int_not_three_digits, int)

WRAP_AGGREGATOR(accumulate_sum_int, int)

WRAP_ACTION(qube_int, int)

WRAP_AGGREGATOR(accumulate_product_int, int)

static bool int_not_four_digits(const int number) {
    return number < 1000 || number > 9999;
}

WRAP_PREDICATE(int_not_four_digits, int)

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
    int qubed_and_summed = 0;
    Span_aggregate(&digits_view, accumulate_sum_int_adapter, &qubed_and_summed);
    const int doubled_number = number * number;

    if (doubled_number == qubed_and_summed) {
        puts("Number is equal to the sum of its digits cubed.");
        return 0;
    }

    puts("Number is not equal to the sum of its digits cubed.");

    return 0;
}

int task21(void) {
    int number = 0, a = 0;

    PromptOptions number_input_options = {
        .out = &number,
        .label = "Number",
        .fail_on = int_not_four_digits_adapter,
        .msg_on_fail = "Number must be three digits",
        .max_attempts = 5,
    };

    if (prompt_int(&number_input_options))
        return -1;

    PromptOptions a_input_options = {
        .out = &a,
        .label = "a",
        .fail_on = NULL,
        .msg_on_fail = NULL,
        .max_attempts = 5,
    };

    if (prompt_int(&a_input_options))
        return -1;

    int digits[4] = {0};
    Span digits_view = Span_create(digits, sizeof(int), 4);
    decompose_int(number, &digits_view);

    /* start subtask a */

    const Span first_two_digits = Span_subspan(&digits_view, 0, 2, NULL);
    const Span last_two_digits = Span_subspan(&digits_view, 2, 2, NULL);
    int first_two_digits_sum = 0;
    int last_two_digits_sum = 0;

    Span_aggregate(&first_two_digits, accumulate_sum_int_adapter, &first_two_digits_sum);
    Span_aggregate(&last_two_digits, accumulate_sum_int_adapter, &last_two_digits_sum);

    if (first_two_digits_sum == last_two_digits_sum)
        puts("First two digits sum is equal to last two digits sum.");
    else
        puts("First two digits sum is not equal to last two digits sum.");

    /* end subtask a */

    /* start subtask b */

    int digits_sum = 0;
    Span_aggregate(&digits_view, accumulate_sum_int_adapter, &digits_sum);

    if (digits_sum % 3 == 0)
        puts("Digits sum is divisible by 3.");
    else
        puts("Digits sum is not divisible by 3.");

    /* end subtask b */

    /* start subtask c */

    int digits_product = 0;
    Span_aggregate(&digits_view, accumulate_product_int_adapter, &digits_product);

    if (digits_product % 4 == 0)
        puts("Digits product is divisible by 4.");
    else
        puts("Digits product is not divisible by 4.");

    /* end subtask c */

    /* start subtask c */

    if (digits_product % a == 0)
        puts("Digits product is divisible by 'a'.");
    else
        puts("Digits product is not divisible by 'a'.");

    /* end subtask b */

    return 0;
}

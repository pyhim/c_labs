//
// Created by dmytro on 07.10.2026.
//

#include "../include/tasks.h"

#include <stdio.h>
#include <math.h>

#include <utils/cli.h>
#include <utils/math.h>

WRAP_PREDICATE(double_less_than_zero, double)

int task7(void) {
    double radius = 0, square_side = 0;

    PromptOptions_Double radius_input_options = {
        .out = &radius,
        .label = "Radius",
        .fail_on = double_less_than_zero_adapter,
        .msg_on_fail = "Radius can't be less than zero",
        .max_attempts = 5,
    };

    if (prompt_double(&radius_input_options))
        return -1;

    PromptOptions_Double square_side_input_options = {
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

//
// Created by dmytro on 07.10.2026.
//

#include "../include/tasks.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include <utils/cli.h>
#include <utils/math.h>
#include <utils/numbers.h>

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
        .msg_on_fail = "Number must be four digits",
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

int task25(void) {
    Point2D A = {.x = 0, .y = 0};
    Point2D B = {.x = 0, .y = 0};

    PromptOptions points_input_options = {
        .out = &A.x,
        .label = "A(x)",
        .max_attempts = 5,
    };

    if (prompt_double(&points_input_options))
        return -1;

    points_input_options.out = &A.y;
    points_input_options.label = "A(y)";

    if (prompt_double(&points_input_options))
        return -1;

    points_input_options.out = &B.x;
    points_input_options.label = "B(x)";

    if (prompt_double(&points_input_options))
        return -1;

    points_input_options.out = &B.y;
    points_input_options.label = "B(y)";

    if (prompt_double(&points_input_options))
        return -1;

    const double distance_A = A.x * A.x + A.y * A.y;
    const double distance_B = B.x * B.x + B.y * B.y;

    switch (compare_doubles(distance_A, distance_B)) {
        case CMP_LESS_THAN:
            puts("A is closer to the (0,0).");
            break;
        case CMP_GREATER_THAN:
            puts("B is closer to the (0,0).");
            break;
        case CMP_EQUAL:
            puts("A and B are equidistant from the (0,0).");
            break;
    }

    return 0;
}

int task29(void) {
    int n = 0, m = 0;

    PromptOptions input_options = {
        .out = &n,
        .label = "n",
        .max_attempts = 5,
    };

    if (prompt_int(&input_options))
        return -1;

    input_options.out = &m;
    input_options.label = "m";

    if (prompt_int(&input_options))
        return -1;

    if (n > m)
        m = n;
    else if (n < m)
        n = m;
    else {
        n = 0;
        m = 0;
    }

    printf("n = %d, m = %d\n", n, m);

    return 0;
}

typedef struct {
    const char *name;
    int points;
} Participant;

int task44(void) {
    const size_t participants_count = 3;
    Participant participants[participants_count];

    for (size_t i = 0; i < participants_count; ++i) {
        const char *names[] = { "Ivanov", "Petrov", "Sidorov" };
        participants[i].name = names[i];

        printf("%s starts to participate!\n", names[i]);

        const int rounds = 3;
        for (size_t j = 0; j < rounds; ++j) {
            printf("Round %lu.\n", j + 1);

            int point = 0;
            PromptOptions input_options = {
                .out = &point,
                .label = "points",
            };

            if (prompt_int(&input_options))
                return -1;

            participants[i].points += point;
        }
    }

    Participant winner = participants[0];
    bool draw = true;

    for (size_t i = 0; i < participants_count; ++i) {
        draw = participants[i].points == winner.points;

        if (participants[i].points > winner.points)
            winner = participants[i];
    }

    if (draw)
        printf("It's a draw!\n");
    else
        printf("The winner is %s with %d points!\n", winner.name, winner.points);

    return 0;
}

int task68(void) {
    Rectangle rectangle1 = {0}, rectangle2 = {0};

    PromptOptions input_options = {
        .out = &rectangle1.top_left.x,
        .label = "x1",
        .fail_on = double_less_than_zero_adapter,
        .msg_on_fail = "Coordinate points must be greater than zero.",
        .max_attempts = 5,
    };

    if (prompt_double(&input_options))
        return -1;

    input_options.out = &rectangle1.top_left.y;
    input_options.label = "y1";

    if (prompt_double(&input_options))
        return -1;

    input_options.out = &rectangle1.bottom_right.x;
    input_options.label = "x2";

    if (prompt_double(&input_options))
        return -1;

    rectangle1.bottom_right.y = 0;

    input_options.out = &rectangle2.top_left.x;
    input_options.label = "x3";

    if (prompt_double(&input_options))
        return -1;

    input_options.out = &rectangle2.top_left.y;
    input_options.label = "y3";

    if (prompt_double(&input_options))
        return -1;

    input_options.out = &rectangle2.bottom_right.x;
    input_options.label = "x4";

    if (prompt_double(&input_options))
        return -1;

    rectangle2.bottom_right.y = 0;

    const bool valid_arguments =
        rectangle1.top_left.x < rectangle1.bottom_right.x &&
        rectangle2.top_left.x < rectangle2.bottom_right.x &&
        rectangle1.top_left.y > 0 &&
        rectangle2.top_left.y > 0;

    if (!valid_arguments) {
        puts("Argument(-s) is/are outside the domain of the function's permissible values.");
        return -1;
    }

    const double x_left = fmax(rectangle1.top_left.x, rectangle2.top_left.x);
    const double x_right = fmin(rectangle1.bottom_right.x, rectangle2.bottom_right.x);
    const double width = x_right - x_left;
    const double height = fmin(rectangle1.top_left.y, rectangle2.top_left.y);

    if (double_greater_than_zero(width)) {
        puts("The rectangles overlap.");
        const double area = width * height;
        printf("The area of the overlap is %.2lf.\n", area);
        return 0;
    }

    puts("The rectangles do not overlap.");

    return 0;
}

int task77(void) {
    const size_t points = 4;
    Point2D quadriliteral[points];

    for (size_t i = 0; i < points; ++i) {
        printf("Point #%lu: \n", i + 1);

        PromptOptions input_options = {
            .out = &quadriliteral[i].x,
            .label = "x",
        };

        if (prompt_double(&input_options)) {
            return -1;
        }

        input_options.out = &quadriliteral[i].y;
        input_options.label = "y";

        if (prompt_double(&input_options)) {
            return -1;
        }
    }

    const size_t cross_products_count = 4;
    const double cross_products[] = {
        cross_product(quadriliteral[3], quadriliteral[0], quadriliteral[1]),
        cross_product(quadriliteral[0], quadriliteral[1], quadriliteral[2]),
        cross_product(quadriliteral[1], quadriliteral[2], quadriliteral[3]),
        cross_product(quadriliteral[2], quadriliteral[3], quadriliteral[0])
    };

    bool all_positive = true;
    bool all_negative = true;

    for (size_t i = 0; i < cross_products_count; ++i) {
        all_positive = all_positive && double_greater_than_zero(cross_products[i]);
        all_negative = all_negative && double_less_than_zero(cross_products[i]);
    }

    if (all_positive || all_negative) {
        puts("The quadrilateral is convex.");
    } else {
        puts("The quadrilateral is not convex.");
    }
    return 0;
}

int task81(void) {
    int a = 0, b = 0;

    PromptOptions input_options = {
        .out = &a,
        .label = "a",
    };

    if (prompt_int(&input_options))
        return -1;

    input_options.out = &b;
    input_options.label = "b";

    if (prompt_int(&input_options))
        return -1;

    if (a == 0 && b == 0) {
        puts("No, neither of the numbers is a divisor of the other.");
        return -1;
    }
    if (a == 0) {
        puts("Yes, one of the numbers is a divisor of the other.");
        return 0;
    }
    if (b == 0) {
        puts("Yes, one of the numbers is a divisor of the other.");
        return 0;
    }
    if (a % b == 0 || b % a == 0) {
        puts("Yes, one of the numbers is a divisor of the other.");
        return 0;
    }

    puts("No, neither of the numbers is a divisor of the other.");
    return -1;
}

static bool is_valid_triplet(const double a, const double b, const double c) {
    return compare_doubles(a, b) != CMP_EQUAL &&
           compare_doubles(b, c) != CMP_EQUAL &&
           compare_doubles(a, c) != CMP_EQUAL;
}

static double get_triplet_median(const double a, const double b, const double c) {
    const double sum = a + b + c;
    const double min_val = fmin(a, fmin(b, c));
    const double max_val = fmax(a, fmax(b, c));

    return sum - min_val - max_val;
}

int task113(void) {
    double triplet1[3], triplet2[3];

    for (size_t i = 0; i < 3; ++i) {
        PromptOptions input_options = {
            .out = &triplet1[i],
        };

        if (prompt_double(&input_options))
            return -1;
    }

    for (size_t i = 0; i < 3; ++i) {
        PromptOptions input_options = {
            .out = &triplet2[i],
        };

        if (prompt_double(&input_options))
            return -1;
    }

    if (!is_valid_triplet(triplet1[0], triplet1[1], triplet1[2]) ||
        !is_valid_triplet(triplet2[0], triplet2[1], triplet2[2])) {
        puts("Invalid triplet, must be unique numbers.");
        return -1;
    }

    const double median1 = get_triplet_median(triplet1[0], triplet1[1], triplet1[2]);
    const double median2 = get_triplet_median(triplet2[0], triplet2[1], triplet2[2]);
    const double average = (median1 + median2) / 2.0;

    printf("Median 1: %.3f\n", median1);
    printf("Median 2: %.3f\n", median2);
    printf("Average of medians: %.3f\n", average);

    return 0;
}

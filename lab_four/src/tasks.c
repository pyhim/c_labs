//
// Created by dmytro on 05.11.2026.
//

#include "../include/tasks.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#include <utils/cli.h>
#include <utils/functional.h>
#include <utils/math.h>
#include <utils/span.h>

static bool is_not_natural(const int n) {
    return n < 1;
}

WRAP_PREDICATE(is_not_natural, int)

WRAP_AGGREGATOR(accumulate_sum_double, double)

int task18(void) {
    for (int i = 2; i <= 20; i++) {
        const double result = sin(i);
        printf("sin(%d) = %lf\n", i, result);
    }

    return 0;
}

int task25(void) {
    int n = 0;

    PromptOptions options = {
        .out = &n,
        .label = "n",
        .fail_on = is_not_natural_adapter,
        .msg_on_fail = "The number must be natural.",
        .max_attempts = 5
    };

    if (prompt_int(&options))
        return -1;

    double approx_sum = 0.0;
    double current_term = 1.0;

    for (int i = 0; i <= n; i++) {
        const double q = -0.5;
        approx_sum += current_term;
        current_term *= q;
    }

    printf("Approximate sum for n = %d: %.3f\n", n, approx_sum);

    return 0;
}

int task44(void) {
    int n, k;

    PromptOptions options = {
        .out = &n,
        .label = "n",
        .fail_on = is_not_natural_adapter,
        .msg_on_fail = "The number must be natural.",
        .max_attempts = 5
    };

    if (prompt_int(&options))
        return -1;

    options.out = &k;
    options.label = "k";

    if (prompt_int(&options))
        return -1;

    double current_val = sqrt(k * n);

    for (int i = n - 1; i >= 1; i--) {
        current_val = sqrt(k * i + current_val);
    }

    printf("Nested Radical Value = %.3f\n", current_val);

    return 0;
}

static double f80(const double x) {
    return 0.5 * (x + 1.0) * (x + 1.0) + 2.0;
}

int task80(void) {
    const int n = 1000;
    double start = 0, end = 0;

    PromptOptions options = {
        .out = &start,
        .label = "Start",
        .max_attempts = 5
    };

    if (prompt_double(&options))
        return -1;

    options.out = &end;
    options.label = "End";

    if (prompt_double(&options))
        return -1;

    const double step_size = (end - start) / n;
    double sum = 0.5 * (f80(start) + f80(end));

    for (int i = 1; i < n; i++) {
        const double x = start + i * step_size;
        sum += f80(x);
    }

    const double result = sum * step_size;

    printf("Approximate Area (n = %d): %.3f\n", n, result);

    return 0;
}

int task81(void) {
    const size_t numbers_length = 10;
    double numbers[numbers_length];

    for (int i = 0; i < 10; i++) {
        PromptOptions options = {
            .out = numbers + i,
            .label = "number",
            .max_attempts = 5
        };

        if (prompt_double(&options))
            return -1;
    }

    double sum = 0;
    const Span numbers_view = Span_create(numbers, sizeof(double), numbers_length);
    Span_aggregate(&numbers_view, accumulate_sum_double_adapter, &sum);

    printf("The sum of the numbers is %.3f\n", sum);

    return 0;
}

int task142(void) {
    int count = 0;

    for (int num = 1000; num <= 9999; num++) {
        const int d1 = num / 1000;
        const int d2 = (num / 100) % 10;
        const int d3 = (num / 10) % 10;
        const int d4 = num % 10;

        const bool unique = d1 != d2 && d1 != d3 && d1 != d4 &&
                            d2 != d3 && d2 != d4 && d3 != d4;

        if (!unique) continue;

        printf("%d ", num);
        count++;

        if (count % 10 == 0) {
            putchar('\n');
        }
    }

    return 0;
}

int task177(void) {
    const double numbers[] = {-5.2, -1.8, -0.5, 4.2, -3.1, 7.0};
    const size_t n = sizeof(numbers) / sizeof(numbers[0]);

    int count = 0;
    bool continue_counting = true;

    for (int i = 0; i < n; i++) {
        const bool is_negative = (numbers[i] < 0);

        continue_counting = continue_counting && is_negative;

        count += continue_counting;
    }

    printf("The number of consecutive negative numbers is %d\n", count);

    return 0;
}

static bool not_in_range_1_to_1_5(const double a) {
    return !(a >= 1 && a <= 1.5);
}

WRAP_PREDICATE(not_in_range_1_to_1_5, double)

int task186(void) {
    double a = 0;

    PromptOptions options = {
        .out = &a,
        .label = "a",
        .fail_on = not_in_range_1_to_1_5_adapter,
        .msg_on_fail = "'a' must be in the range of [1, 1.5]",
        .max_attempts = 3
    };

    if (prompt_double(&options))
        return -1;

    int n = 2;
    double current_val = 1.0 + 1.0 / n;

    while (current_val >= a) {
        n++;
        current_val = 1.0 + 1.0 / n;
    }

    printf("The first int, less than %lf: %lf (at n = %d)\n", a, current_val, n);

    return 0;
}

double f233(const double x) {
    const double sin_x = sin(x);
    return 2.0 * sin_x * sin_x + 1.0;
}

int task233(void) {
    double a, b, h;

    PromptOptions options = {
        .out = &a,
        .label = "a",
        .max_attempts = 3,
    };

    if (prompt_double(&options))
        return -1;

    options.out = &b;
    options.label = "b";

    if (prompt_double(&options))
        return -1;

    options.out = &h;
    options.label = "h";

    if (prompt_double(&options))
        return -1;

    if (h <= 0 || a > b) {
        printf("Values are incorrect!\n");
        return -1;
    }

    puts("\n+--------------+--------------+");
    puts("|      x       |     F(x)     |");
    puts("+--------------+--------------+");

    for (double x = a; x <= b + h / 2.0; x += h) {
        printf("| %12.4f | %12.4f |\n", x, f233(x));
    }

    printf("+--------------+--------------+\n");

    return 0;
}

static double f249(const double x) {
    return x / cos(x);
}

int task249(void) {
    double a, b, h;

    PromptOptions options = {
        .out = &a,
        .label = "a",
        .max_attempts = 3,
    };

    if (prompt_double(&options))
        return -1;

    options.out = &b;
    options.label = "b";

    if (prompt_double(&options))
        return -1;

    options.out = &h;
    options.label = "h";

    if (prompt_double(&options))
        return -1;

    if (h <= 0 || a > b) {
        printf("Values are incorrect!\n");
        return -1;
    }

    puts("\n+--------------+--------------+");
    puts("|      x       |     F(x)     |");
    puts("+--------------+--------------+");

    for (double x = a; x <= b + h / 2.0; x += h) {
        const double cos_x = cos(x);

        if (double_equals_zero(cos_x)) {
            printf("| %12.4f | %12s |\n", x, "Undefined");
        } else {
            printf("| %12.4f | %12.4f |\n", x, f249(x));
        }
    }

    printf("+--------------+--------------+\n");

    return 0;
}

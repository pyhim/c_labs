//
// Created by dmytro on 23.09.2026.
//

#include "cli.h"

#include <stdio.h>

#include "equations.h"
#include "../utils/safe_io.h"

int ask_for_value(double *const value_out, const char value_label) {
    int status = 0, i = 0;
    double value = 0.0;

    while (i < 5) {
        printf("Enter the value for %c: ", value_label);
        status = read_double(&value);

        if (status != 0) {
            printf("Try entering the value again.\n");
            value = 0.0;
            i++;

            continue;
        }

        break;
    }

    if (i == 5) {

    }

    *value_out = value;
    return status;
}

void print_equation_result(const int equation_id, const double result, const math_debug_code_t *dbg_code) {
    if (*dbg_code != MATH_SUCCESS) {
        const char *message = math_debug_code_to_string(*dbg_code);
        printf("Equation #%d failed: %s\n", equation_id, message);
        return;
    }

    printf("Equation #%d result: %.3f\n", equation_id, result);
}

int start_menu() {
    const char x_label = 'X', y_label = 'Y';
    double x = 0.0, y = 0.0;
    int status = 0;

    status = ask_for_value(&x, x_label);
    if (status != 0) {
        printf("Unable to read the value of %c\n", x_label);
        return status;
    }

    status = ask_for_value(&y, y_label);
    if (status != 0) {
        printf("Unable to read the value of %c\n", y_label);
        return status;
    }

    double result = 0.0;
    math_debug_code_t dbg_code;

    result = task1(x, &dbg_code);
    print_equation_result(1, result, &dbg_code);
    result = task2(x, y, &dbg_code);
    print_equation_result(2, result, &dbg_code);
    result = task5(x, &dbg_code);
    print_equation_result(5, result, &dbg_code);
    result = task7(x, y, &dbg_code);
    print_equation_result(7, result, &dbg_code);
    result = task8(x, &dbg_code);
    print_equation_result(8, result, &dbg_code);

    return 0;
}

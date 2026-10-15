//
// Created by dmytro on 23.09.2026.
//

#include "../include/cli.h"

#include <stdio.h>
#include <utils/cli.h>

#include "../include/equations.h"

void print_equation_result(const int equation_id, const double result, const math_debug_code *dbg_code) {
    if (*dbg_code != MATH_SUCCESS) {
        const char *message = math_debug_code_to_string(*dbg_code);
        printf("Equation #%d failed: %s\n", equation_id, message);
        return;
    }

    printf("Equation #%d result: %.3f\n", equation_id, result);
}

int start_menu(void) {
    double x = 0.0, y = 0.0;

    PromptOptions_Double x_input_options = {
        .out = &x,
        .label = "X",
        .max_attempts = 5,
    };
    PromptDebugCode status = prompt_double(&x_input_options);

    if (status)
        return status;

    PromptOptions_Double y_input_options = {
        .out = &y,
        .label = "Y",
        .max_attempts = 5,
    };
    status = prompt_double(&y_input_options);

    if (status)
        return status;

    double result = 0.0;
    math_debug_code dbg_code;

    result = task18(x, y, &dbg_code);
    print_equation_result(18, result, &dbg_code);
    result = task21(x, &dbg_code);
    print_equation_result(21, result, &dbg_code);
    result = task22(x, y, &dbg_code);
    print_equation_result(22, result, &dbg_code);
    result = task25(x, y, &dbg_code);
    print_equation_result(25, result, &dbg_code);
    result = task44(x, y, &dbg_code);
    print_equation_result(44, result, &dbg_code);

    return 0;
}

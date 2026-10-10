//
// Created by dmytro on 07.10.2026.
//

#include "../include/utils/cli.h"

#include <stdio.h>

#include "../include/utils/safe_io.h"

int ask_for_value_double(double *const value_out, const char value_label) {
    int status = 0, i = 0;
    double value = 0.0;

    while (i < 5) {
        printf("Enter the value for %c: ", value_label);
        status = read_double(&value);

        if (status != 0) {
            puts("Try entering the value again.");
            i++;

            continue;
        }

        break;
    }

    if (i == 5) {
        return status;
    }

    *value_out = value;
    return status;
}

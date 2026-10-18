//
// Created by dmytro on 16.10.2026.
//

#include "../include/utils/numbers.h"

#include <stdlib.h>

#include "../include/utils/vector.h"

int decompose_int(int value, Span *dest) {
    if (!dest)
        return -1;

    CollectionDebugCode dbg_code = 0;

    if (value == 0) {
        Span_set(dest, 0, &value, &dbg_code);

        return dbg_code;
    }

    Vector digits = Vector_new(sizeof(int));
    value = abs(value);

    while (value > 0) {
        int digit = value % 10;
        Vector_push_back(&digits, &digit, &dbg_code);
        value /= 10;
    }

    Vector_reverse(&digits, &dbg_code);
    Vector_copy_to_span(&digits, dest, &dbg_code);

    Vector_free(&digits);

    return dbg_code;
}

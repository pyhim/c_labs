//
// Created by dmytro on 12.10.2026.
//

#include "../include/utils/functional.h"

#include <stddef.h>

bool invoke_predicate(const Predicate func, const void *value) {
    if (func == NULL || value == NULL) {
        return false;
    }

    return func(value);
}

ComparisonResult invoke_comparer(const Comparer func, const void *left, const void *right) {
    if (func == NULL || left == NULL || right == NULL) {
        return CMP_EQUAL;
    }

    return func(left, right);
}

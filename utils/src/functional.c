//
// Created by dmytro on 12.10.2026.
//

#include "../include/utils/functional.h"

#include <stddef.h>

bool invoke_predicate(const Predicate predicate, const void *value) {
    if (predicate == NULL || value == NULL) {
        return false;
    }

    return predicate(value);
}

ComparisonResult invoke_comparer(Comparer comparer, const void *left, const void *right) {
    if (comparer == NULL || left == NULL || right == NULL) {
        return CMP_EQUAL;
    }

    return comparer(left, right);
}

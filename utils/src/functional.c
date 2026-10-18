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

void invoke_aggregator(const Aggregator func, void *total, const void *next) {
    if (func == NULL || total == NULL || next == NULL) {
        return;
    }

    func(total, next);
}

void invoke_action(const Action func, void *value) {
    if (func == NULL || value == NULL) {
        return;
    }

    func(value);
}

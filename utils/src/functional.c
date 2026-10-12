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
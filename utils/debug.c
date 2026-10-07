//
// Created by dmytro on 27.09.2026.
//

#include "debug.h"

const char *utils_debug_code_to_string(const utils_debug_code_t error_code) {
    switch (error_code) {
        case UTILS_ERR_SHRINKING_NOT_ALLOWED:
            return "Shrinking is not supported.";
        case UTILS_ERR_OUT_OF_MEMORY:
            return "Unable to grow the array. Out of memory.";
        case UTILS_ERR_OUT_OF_RANGE:
            return "Index out of range.";
        case UTILS_ERR_NULL_POINTER:
            return "Null pointer has been provided.";
        case UTILS_ERR_WRONG_TYPE:
            return "A wrong type has been provided.";
        default:
            return "Success.";
    }
}

void write_utils_debug_code(utils_debug_code_t *const to, const utils_debug_code_t value) {
    if (!to)
        return;

    *to = value;
}
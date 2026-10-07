//
// Created by dmytro on 27.09.2026.
//

#pragma once

typedef enum utils_debug_code {
    UTILS_SUCCESS = 0,
    UTILS_ERR_SHRINKING_NOT_ALLOWED,
    UTILS_ERR_OUT_OF_MEMORY,
    UTILS_ERR_OUT_OF_RANGE,
    UTILS_ERR_NULL_POINTER,
    UTILS_ERR_WRONG_TYPE,
} utils_debug_code_t;

const char *utils_debug_code_to_string(utils_debug_code_t error_code);

void write_utils_debug_code(utils_debug_code_t *to, utils_debug_code_t value);
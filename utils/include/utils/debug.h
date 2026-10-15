//
// Created by dmytro on 27.09.2026.
//

#pragma once

typedef enum {
    UTILS_SUCCESS = 0,
    UTILS_ERR_SHRINKING_NOT_ALLOWED,
    UTILS_ERR_OUT_OF_MEMORY,
    UTILS_ERR_OUT_OF_RANGE,
    UTILS_ERR_NULL_POINTER,
    UTILS_ERR_WRONG_TYPE,
} UtilsDebugCode;

const char *utils_debug_code_to_string(UtilsDebugCode error_code);

void utils_debug_code_write(UtilsDebugCode *to, UtilsDebugCode value);
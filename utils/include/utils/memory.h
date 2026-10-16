//
// Created by dmytro on 15.10.2026.
//

#pragma once

#include <string.h>

/**
 * Generates a function to safely copy a value to a destination if the pointer is not NULL.
 * @param type The data type of the source value.
 */
#define DEFINE_WRITE_UNLESS_NULL(type)                              \
    static void write_unless_null_##type(void *dest, type src) {    \
        if (dest != NULL) {                                         \
            memcpy(dest, &src, sizeof(type));                       \
        }                                                           \
    }

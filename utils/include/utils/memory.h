//
// Created by dmytro on 15.10.2026.
//

#pragma once

#include <stdlib.h>

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

/**
 * Swaps the contents of two memory regions of a specified size.
 *
 * The provided memory regions must be non-overlapping and valid.
 *
 * @param left Pointer to the first memory region.
 * @param right Pointer to the second memory region.
 * @param size The number of bytes to swap between the two regions.
 */
void memswap(void *restrict left, void *restrict right, size_t size);

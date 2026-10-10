//
// Created by dmytro on 24.09.2026.
//

#pragma once

#include "string.h"

typedef struct {
    uint8_t *array;
    size_t type_size;
    size_t size;
} Array;

Array array_init(void *raw_array, size_t type_size, size_t size);

Array array_new(size_t type_size, size_t size);

void *array_at(Array array, size_t index);

void array_free(Array *array);

String int_array_to_string(const Array *array);

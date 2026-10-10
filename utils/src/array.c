//
// Created by dmytro on 24.09.2026.
//

#include "../include/utils/array.h"

Array array_init(void *raw_array, const size_t type_size, const size_t size)  {
    const Array new_array = {
        .array = raw_array,
        .type_size = type_size,
        .size = size,
    };

    return new_array;
}

// String int_array_to_string(const Array *array) {
//     String new_string = string_new_reserve(array->size, NULL);
//
//     string
//     for (int i = 0; i < array->size; i++) {
//
//     }
// }

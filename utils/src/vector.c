//
// Created by dmytro on 24.09.2026.
//

#include "../include/utils/vector.h"

#include <stdlib.h>
#include <string.h>

#define DEFAULT_GROWTH_FACTOR 1.5

static utils_debug_code vector_increase_capacity(Vector *const self, const double factor) {
    const size_t new_capacity = self->capacity * factor; // NOLINT(*-narrowing-conversions)
    void *new_array = realloc(self->raw_array, new_capacity * self->type_size);

    if (!new_array)
        return UTILS_ERR_OUT_OF_MEMORY;

    self->raw_array = new_array;
    self->capacity = new_capacity;

    return UTILS_SUCCESS;
}

void vector_init(Vector *const self, const size_t type_size, const size_t capacity,
                 utils_debug_code *const dbg_code) {
    self->raw_array = malloc(type_size * capacity);

    if (!self->raw_array) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_MEMORY);
        return;
    }

    self->type_size = type_size;
    self->size = 0;
    self->capacity = capacity;

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

Vector vector_new_reserve(const size_t type_size, const size_t capacity, utils_debug_code *const dbg_code) {
    Vector new_vector;

    vector_init(&new_vector, type_size, capacity, dbg_code);

    return new_vector;
}

Vector vector_new(const size_t type_size, utils_debug_code *const dbg_code) {
    Vector new_vector;

    vector_init(&new_vector, type_size, DEFAULT_VECTOR_CAPACITY, dbg_code);

    return new_vector;
}

void vector_reserve(Vector *const self, const size_t capacity, utils_debug_code *const dbg_code) {
    if (self->size > capacity) {
        utils_debug_code_write(dbg_code, UTILS_ERR_SHRINKING_NOT_ALLOWED);
        return;
    }
    if (self->size == capacity)
        return;

    void *new_array = realloc(self->raw_array, capacity * self->type_size);

    if (new_array == NULL) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_MEMORY);
        return;
    }

    self->raw_array = new_array;
    self->capacity = capacity;

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

// Copies the element and adds to the end of the vector
void vector_push_back(Vector *const self, const void *const element, utils_debug_code *const dbg_code) {
    if (self->size == self->capacity) {
        const utils_debug_code code = vector_increase_capacity(self, DEFAULT_GROWTH_FACTOR);

        if (code != UTILS_SUCCESS) {
            utils_debug_code_write(dbg_code, code);
            return;
        }
    }

    void *dest = self->raw_array + self->type_size * self->size;
    memcpy(dest, element, self->type_size);
    self->size++;

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

// void vector_pop_back(Vector *const self, utils_debug_code *const dbg_code) {
//     if (self->size == 0) {
//         write_error_code(dbg_code, ERR_OUT_OF_RANGE);
//         return NULL;
//     }
//
//     self->size--;
//
//     write_error_code(dbg_code, UTILS_SUCCESS);
// }

void *vector_at(const Vector *const self, const size_t index, utils_debug_code *const dbg_code) {
    if (index > self->size) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_RANGE);
        return NULL;
    }

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);

    return self->raw_array + self->type_size * index;
}

void vector_memcpy_to(const Vector *self, void *dest, const size_t n, utils_debug_code *const dbg_code) {
    if (n > self->size) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_RANGE);
        return;
    }

    memcpy(dest, &self->raw_array, n);

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

void vector_free(Vector *const self) {
    free(self->raw_array);
    self->raw_array = NULL;
    self->capacity = 0;
    self->size = 0;
}

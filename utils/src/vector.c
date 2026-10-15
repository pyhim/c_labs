//
// Created by dmytro on 24.09.2026.
//

#include "../include/utils/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils/safe_mem.h"

DEFINE_WRITE_UNLESS_NULL(int)

#define DEFAULT_GROWTH_FACTOR 1.5

static CollectionDebugCode vector_increase_capacity(Vector *const self, const double factor) {
    const size_t new_capacity = self->capacity * factor; // NOLINT(*-narrowing-conversions)
    void *new_array = realloc(self->raw_array, new_capacity * self->type_size);

    if (!new_array) {
        fprintf(stderr, "Lol, buy more RAM looser");
        return COLLECTION_ERR_OUT_OF_MEMORY;
    }

    self->raw_array = new_array;
    self->capacity = new_capacity;

    return COLLECTION_SUCCESS;
}

void vector_init(Vector *const self, const size_t type_size, const size_t capacity) {
    self->raw_array = malloc(type_size * capacity);

    if (!self->raw_array) {
        fprintf(stderr, "Lol, buy more RAM looser");
        return;
    }

    self->type_size = type_size;
    self->size = 0;
    self->capacity = capacity;
}

Vector vector_new_reserve(const size_t type_size, const size_t capacity) {
    Vector new_vector;

    vector_init(&new_vector, type_size, capacity);

    return new_vector;
}

Vector vector_new(const size_t type_size) {
    Vector new_vector;

    vector_init(&new_vector, type_size, DEFAULT_VECTOR_CAPACITY);

    return new_vector;
}

void vector_reserve(Vector *const self, const size_t capacity, CollectionDebugCode *const dbg_code) {
    if (self->size > capacity) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_SHRINKING_NOT_ALLOWED);
        return;
    }
    if (self->size == capacity)
        return;

    void *new_array = realloc(self->raw_array, capacity * self->type_size);

    if (new_array == NULL) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_MEMORY);
        return;
    }

    self->raw_array = new_array;
    self->capacity = capacity;

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);
}

void vector_push_back(Vector *const self, const void *const element, CollectionDebugCode *const dbg_code) {
    if (self->size == self->capacity) {
        const CollectionDebugCode code = vector_increase_capacity(self, DEFAULT_GROWTH_FACTOR);

        if (code != COLLECTION_SUCCESS) {
            write_unless_null_int(dbg_code, code);
            return;
        }
    }

    void *dest = self->raw_array + self->type_size * self->size;
    memcpy(dest, element, self->type_size);
    self->size++;

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);
}

// void vector_pop_back(Vector *const self, CollectionDebugCode *const dbg_code) {
//     if (self->size == 0) {
//         write_error_code(dbg_code, ERR_OUT_OF_RANGE);
//         return NULL;
//     }
//
//     self->size--;
//
//     write_error_code(dbg_code, COLLECTION_SUCCESS);
// }

void *vector_at(const Vector *const self, const size_t index, CollectionDebugCode *const dbg_code) {
    if (index > self->size) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return NULL;
    }

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);

    return vector_unsafe_at(self, index);
}

void *vector_first(const Vector *self, CollectionDebugCode *dbg_code) {
    if (self->size == 0) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return NULL;
    }

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);

    return vector_unsafe_at(self, 0);
}

void *vector_last(const Vector *self, CollectionDebugCode *dbg_code) {
    if (self->size == 0) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return NULL;
    }

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);

    return vector_unsafe_at(self, self->size - 1);
}

void *vector_unsafe_at(const Vector *self, const size_t index) {
    return self->raw_array + self->type_size * index;
}

void vector_memcpy_to(const Vector *self, void *dest, const size_t n, CollectionDebugCode *const dbg_code) {
    if (n > self->size) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return;
    }

    memcpy(dest, &self->raw_array, n);

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);
}

void vector_free(Vector *const self) {
    free(self->raw_array);
    self->raw_array = NULL;
    self->capacity = 0;
    self->size = 0;
}

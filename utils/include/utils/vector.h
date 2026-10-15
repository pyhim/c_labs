//
// Created by dmytro on 24.09.2026.
//

#pragma once

#include <stddef.h>
#include <stdint.h>

#include "collections.h"

#define DEFAULT_VECTOR_CAPACITY 8

/**
 * Generic-typed dynamically-resizable array
 */
typedef struct {
    uint8_t *raw_array;
    size_t type_size;
    size_t size;
    size_t capacity;
} Vector;

static const Vector empty_vector = {
    .raw_array = NULL,
    .type_size = 0,
    .size = 0,
    .capacity = 0,
};

Vector vector_new(size_t type_size, CollectionDebugCode *dbg_code);

Vector vector_new_reserve(size_t type_size, size_t capacity, CollectionDebugCode *dbg_code);

void vector_init(Vector *self, size_t type_size, size_t capacity, CollectionDebugCode *dbg_code);

void vector_reserve(Vector *self, size_t capacity, CollectionDebugCode *dbg_code);

void vector_push_back(Vector *self, const void *element, CollectionDebugCode *dbg_code);

void vector_push_back_multiple(Vector *self, const void *elements, size_t count, CollectionDebugCode *dbg_code);

void vector_pop_back(Vector *self, CollectionDebugCode *dbg_code);

void vector_memcpy_to(const Vector *self, void *dest, size_t n, CollectionDebugCode *dbg_code);

void *vector_at(const Vector *self, size_t index, CollectionDebugCode *dbg_code);

void *vector_first(const Vector *self, CollectionDebugCode *dbg_code);

void *vector_last(const Vector *self, CollectionDebugCode *dbg_code);

void *vector_unsafe_at(const Vector *self, size_t index);

void vector_free(Vector *self);

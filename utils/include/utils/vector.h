//
// Created by dmytro on 24.09.2026.
//

#pragma once

#include <stddef.h>
#include <stdint.h>

#include "debug.h"

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

/**
 * Creates a new <c>vector_t</c>.
 * @param type_size The size of the type of the stored values in bytes.
 * @param dbg_code The pointer to write the debug code to.
 * @return A new <c>vector_t</c>.
 */
Vector vector_new(size_t type_size, utils_debug_code *dbg_code);

/**
 * Creates a new <c>vector_t</c> with a custom capacity.
 * @param type_size The size of the type of the stored values in bytes.
 * @param capacity The capacity of the vector to reserve.
 * @param dbg_code The pointer to write the debug code to.
 * @return A new <c>vector_t</c>.
 */
Vector vector_new_reserve(size_t type_size, size_t capacity, utils_debug_code *dbg_code);

/**
 * Initializes the provided <c>vector_t</c>.
 * @param self The pointer to the <c>vector_t</c>.
 * @param type_size The size of the type of the stored values in bytes.
 * @param capacity The capacity of the vector to reserve.
 * @param dbg_code The pointer to write the debug code to.
 */
void vector_init(Vector *self, size_t type_size, size_t capacity, utils_debug_code *dbg_code);

/**
 * Reserve some capacity in the vector in advance.
 * @param self The pointer to the <c>vector_t</c>.
 * @param capacity The capacity of the vector to reserve.
 * @param dbg_code The pointer to write the debug code to.
 */
void vector_reserve(Vector *self, size_t capacity, utils_debug_code *dbg_code);

/**
 * Push an element into the back of the vector.
 * @param self The pointer to the <c>vector_t</c>.
 * @param element The pointer to the element to push back.
 * @param dbg_code The pointer to write the debug code to.
 * @note The element are always copied, not moved.
 */
void vector_push_back(Vector *self, const void *element, utils_debug_code *dbg_code);

/**
 * Push multiple elements into the back of the vector.
 * @param self The pointer to the <c>vector_t</c>.
 * @param elements The pointer to the start of the area of memory to push back.
 * @param count The count of the elements to push from the area of memory.
 * @param dbg_code The pointer to write the debug code to.
 * @note The element are always copied, not moved.
 */
void vector_push_back_multiple(Vector *self, const void *elements, size_t count, utils_debug_code *dbg_code);

/**
 * Deletes the element at the end and decreases the size of the vector by one.
 * @param self The pointer to the <c>vector_t</c>.
 * @param dbg_code The pointer to write the debug code to.
 */
void vector_pop_back(Vector *self, utils_debug_code *dbg_code);

/**
 *
 * @param self
 * @param dest
 * @param n
 * @param dbg_code
 */
void vector_memcpy_to(const Vector *self, void *dest, size_t n, utils_debug_code *dbg_code);

void *vector_at(const Vector *self, size_t index, utils_debug_code *dbg_code);

void *vector_unsafe_at(const Vector *self, size_t index);

void vector_free(Vector *self);

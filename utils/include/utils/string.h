//
// Created by dmytro on 26.09.2026.
//

#pragma once

#include "vector.h"

typedef struct {
    Vector char_vector;
    size_t length;
} String;

String string_new(utils_debug_code *dbg_code);

String string_new_reserve(size_t capacity, utils_debug_code *dbg_code);

void string_init(String *self, size_t capacity, utils_debug_code *dbg_code);

String string_init_from_cstr(const char* str, size_t size, utils_debug_code *dbg_code);

/*
 Gets the standard C-string. The returned string is
 always allocated on the heap, and it is your
 responsibility to free it!
 */
const char *string_get_cstr(const String *self, utils_debug_code *dbg_code);

char *string_at(const String *self, size_t index, utils_debug_code *dbg_code);

void string_push_back_char(String *self, char c, utils_debug_code *dbg_code);

void string_push_back_cstr(String *self, const char *c_str, size_t length, utils_debug_code *dbg_code);

// TODO: Implement string_insert() and etc.

inline char *string_unsafe_at(const String *self, const size_t index) {
    return vector_unsafe_at(&self->char_vector, index);
}

void string_free(String *self);

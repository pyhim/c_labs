//
// Created by dmytro on 26.09.2026.
//

#pragma once

#include "vector.h"

typedef struct {
    Vector char_vector;
    size_t length;
} String;

String string_new(CollectionDebugCode *dbg_code);

String string_new_reserve(size_t capacity, CollectionDebugCode *dbg_code);

void string_init(String *self, size_t capacity, CollectionDebugCode *dbg_code);

String string_init_from_cstr(const char* str, size_t size, CollectionDebugCode *dbg_code);

/*
 Gets the standard C-string. The returned string is
 always allocated on the heap, and it is your
 responsibility to free it!
 */
const char *string_get_cstr(const String *self, CollectionDebugCode *dbg_code);

char *string_at(const String *self, size_t index, CollectionDebugCode *dbg_code);

void string_push_back_char(String *self, char c, CollectionDebugCode *dbg_code);

void string_push_back_cstr(String *self, const char *c_str, size_t length, CollectionDebugCode *dbg_code);

// TODO: Implement string_insert() and etc.

inline char *string_unsafe_at(const String *self, const size_t index) {
    return vector_unsafe_at(&self->char_vector, index);
}

void string_free(String *self);

//
// Created by dmytro on 26.09.2026.
//

#include "../include/utils/string.h"

#include <stdlib.h>
#include <string.h>

static const char NULL_TERMINATOR = '\0';

static void append_null_terminator(String *const self, utils_debug_code *const dbg_code) {
    // char *at = vector_unsafe_at(&self->char_vector, self->length);
    // *at = '\0';
    vector_push_back(&self->char_vector, &NULL_TERMINATOR, dbg_code);
}

void string_init(String *self, const size_t capacity, utils_debug_code *dbg_code) {
    self->char_vector = vector_new_reserve(sizeof(char), capacity, dbg_code);
    self->length = 0;

    append_null_terminator(self, dbg_code);

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

String string_new(utils_debug_code *const dbg_code) {
    String new_string;

    string_init(&new_string, DEFAULT_VECTOR_CAPACITY, dbg_code);

    return new_string;
}

String string_new_reserve(const size_t capacity, utils_debug_code *const dbg_code) {
    String new_string;

    string_init(&new_string, capacity, dbg_code);

    return new_string;
}

String string_init_from_cstr(const char *const str, const size_t size, utils_debug_code *const dbg_code) {
    String new_string = {
        .char_vector = vector_new_reserve(sizeof(char), size, dbg_code),
        .length = size - 1,
    };
    
    memcpy(&new_string.char_vector, str, size);

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);

    return new_string;
}

const char *string_get_cstr(const String *self, utils_debug_code *const dbg_code) {
    char *new_c_string = malloc(sizeof(char) * self->char_vector.size);

    if (!new_c_string) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_MEMORY);
        return NULL;
    }

    vector_memcpy_to(&self->char_vector, new_c_string, self->char_vector.size, dbg_code);

    return new_c_string;
}

char *string_at(const String *const self, const size_t index, utils_debug_code *const dbg_code) {
    if (index > self->length) {
        utils_debug_code_write(dbg_code, UTILS_ERR_OUT_OF_MEMORY);
        return NULL;
    }

    return vector_unsafe_at(&self->char_vector, index);
}

void string_push_back_char(String *self, const char c, utils_debug_code *dbg_code) {
    char *replace_at = vector_at(&self->char_vector, self->char_vector.size, dbg_code);
    *replace_at = c;

    append_null_terminator(self, dbg_code);

    utils_debug_code_write(dbg_code, UTILS_SUCCESS);
}

void string_push_back_cstr(String *self, const char *c_str, const size_t length, utils_debug_code *dbg_code) {
    // TODO: Implement pushing back a C-string
}

void string_free(String *const self) {
    vector_free(&self->char_vector);
    self->length = 0;
}

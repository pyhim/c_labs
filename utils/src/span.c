//
// Created by dmytro on 16.10.2026.
//

#include "../include/utils/span.h"

#include <string.h>

#include "../include/utils/memory.h"

DEFINE_WRITE_UNLESS_NULL(int)

static uint8_t *to_address(const Span *self, const size_t index) {
    return self->start + self->type_size * index;
}

void Span_init(Span *self, uint8_t *data, const size_t data_type, const size_t len) {
    self->start = data;
    self->type_size = data_type;
    self->len = len;
}

Span Span_create(uint8_t *data, const size_t data_type, const size_t len) {
    Span new_self;

    Span_init(&new_self, data, data_type, len);

    return new_self;
}

void *Span_get(const Span *self, const size_t index, CollectionDebugCode *dbg_code) {
    if (index >= self->len) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return NULL;
    }

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);

    return Span_unsafe_get(self, index);
}

void Span_set(const Span *self, const size_t index, const void *value, CollectionDebugCode *dbg_code) {
    if (index >= self->len) {
        write_unless_null_int(dbg_code, COLLECTION_ERR_OUT_OF_RANGE);
        return;
    }

    Span_unsafe_set(self, index, value);

    write_unless_null_int(dbg_code, COLLECTION_SUCCESS);
}

void *Span_unsafe_get(const Span *self, const size_t index) {
    return to_address(self, index);
}

void Span_unsafe_set(const Span *self, const size_t index, const void *value) {
    memcpy(to_address(self, index), value, self->type_size);
}

void *Span_aggregate(const Span *self, const Aggregator func) {
    void *result = malloc(self->type_size);
    // init result with the first element of the span
    memcpy(result, to_address(self, 0), self->type_size);

    for (size_t i = 0; i < self->len; i++)
        invoke_aggregator(func, result, to_address(self, i));

    return result;
}

void Span_apply(const Span *self, const Action func) {
    for (size_t i = 0; i < self->len; i++)
        invoke_action(func, to_address(self, i));
}

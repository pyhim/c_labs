//
// Created by dmytro on 16.10.2026.
//

#pragma once

#include <stddef.h>
#include <stdint.h>

#include "collections.h"
#include "functional.h"
#include "defs.h"

typedef struct {
    uint8_t *start;
    size_t type_size;
    size_t len;
} Span;

void Span_init(Span *self, uint8_t *data, size_t data_type, size_t len);

Span Span_create(uint8_t *data, size_t data_type, size_t len);

void Span_set(const Span *self, size_t index, const void *value, CollectionDebugCode *dbg_code);

void *Span_unsafe_get(const Span *self, size_t index);

void Span_unsafe_set(const Span *self, size_t index, const void *value);

NO_DISCARD void *Span_get(const Span *self, size_t index, CollectionDebugCode *dbg_code);

NO_DISCARD void *Span_aggregate(const Span *self, Aggregator func);

void Span_apply(const Span *self, Action func);
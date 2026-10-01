//
// Created by dmytro on 23.09.2026.
//

#pragma once

#include "collections/array.h"

int stdin_read(char *out, int size);

int read_double(double *out);

int read_int(int *out);

void print_int_array(const array_t *array, utils_debug_code_t *dbg_code);

void print_double_array(const array_t *array, utils_debug_code_t *dbg_code);

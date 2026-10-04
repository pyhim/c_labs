//
// Created by dmytro on 23.09.2026.
//

#include "safe_io.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void warn_if_error(const int code) {
    if (code != 0) {
        fprintf(stderr, "%s\n", strerror(errno));
    }
}

int stdin_read(char *const out, const int size) {
    const char *result = fgets(out, size, stdin);
    const int status = result == NULL;

    warn_if_error(status);

    return status;
}

int read_double(double *const out) {
    char buffer[32];
    char *endptr = NULL;

    if (stdin_read(buffer, sizeof(buffer)))
        return -1;

    errno = 0;
    *out = strtod(buffer, &endptr);

    if (endptr == buffer || *endptr != '\n' && *endptr != '\0')
        return -1;

    const int status = errno == ERANGE;
    warn_if_error(status);

    return status;
}

int read_int(int *const out) {
    char buffer[32];
    char *endptr = NULL;

    if (stdin_read(buffer, sizeof(buffer)))
        return -1;

    errno = 0;
    *out = (int)strtol(buffer, &endptr, 10);

    if (endptr == buffer || *endptr != '\n' && *endptr != '\0')
        return -1;

    const int status = errno == ERANGE;
    warn_if_error(status);

    return status;
}

/*void print_int_array(const array_t *array, utils_debug_code_t *dbg_code) {
    printf("[");

    for (int i = 0; i < array->size - 1; i++) {
        const int *number = array_at(array, i);
        printf("%d, ", *number);
    }

    const int *number = array_at(array, array->size - 1);
    printf("%d]\n", *number);
}

void print_double_array(const array_t *array, utils_debug_code_t *dbg_code) {
    printf("[");

    for (int i = 0; i < array->size - 1; i++) {
        const double *number = array_at(array, i);
        printf("%.3f, ", *number);
    }

    const double *number = array_at(array, array->size - 1);
    printf("%.3f]\n", *number);
}*/

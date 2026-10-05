//
// Created by dmytro on 23.09.2026.
//

#include "safe_io.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_PLACEHOLDER '?'

// This weird function is to drain the input stream (stdin) if the input was to big
// and the newline character is still in the stream, not letting the user to enter anything
// until the newline character is flushed from the stream.
static void drain_stdin(void) {
    for (int c = getchar(); c != '\n' && c != EOF; c = getchar()) {
    }
}

int stdin_read(char *const out, const int size) {
    const char *result = fgets(out, size, stdin);

    if (!result) {
        perror("Unable to read from stdin");
        return -1;
    }

    if (!strchr(out, '\n'))
        drain_stdin();

    return 0;
}

int read_double(double *const out) {
    char buffer[64];
    char *endptr = NULL;

    memset(buffer, BUFFER_PLACEHOLDER, sizeof(buffer));

    if (stdin_read(buffer, sizeof(buffer)))
        return -1;

    errno = 0;
    const double converted_value = strtod(buffer, &endptr);

    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0'))
        return -1;

    if (errno) {
        perror("Unable to read a 'double' value from stdin");
        return -1;
    }

    *out = converted_value;

    return 0;
}

int read_int(int *const out) {
    char buffer[32];
    char *endptr = NULL;

    if (stdin_read(buffer, sizeof(buffer)))
        return -1;

    errno = 0;
    const int converted_value = (int)strtol(buffer, &endptr, 10);

    if (endptr == buffer || (*endptr != '\n' && *endptr != '\0'))
        return -1;

    if (errno) {
        perror("Unable to read a 'double' value from stdin");
        return -1;
    }

    *out = converted_value;

    return 0;
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

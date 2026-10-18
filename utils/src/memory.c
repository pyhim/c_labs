//
// Created by dmytro on 15.10.2026.
//

#include "../include/utils/memory.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_BUFFER_SIZE 1024

void memswap(void *restrict left, void *restrict right, const size_t size) {
    if (size <= DEFAULT_BUFFER_SIZE) {
        uint8_t buffer[DEFAULT_BUFFER_SIZE];

        memcpy(buffer, left, size);
        memcpy(left, right, size);
        memcpy(right, buffer, size);

        return;
    }

    void *buffer = malloc(size);

    if (!buffer) {
        fprintf(stderr, "Buy more ram lol");
        return;
    }

    memcpy(buffer, left, size);
    memcpy(left, right, size);
    memcpy(right, buffer, size);

    free(buffer);
}

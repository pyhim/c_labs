//
// Created by dmytro on 07.10.2026.
//

#pragma once

#include "functional.h"

typedef enum {
    PROMPT_SUCCESS = 0,
    PROMPT_NULL_POINTER,
    PROMPT_MAX_ATTEMPTS_EXCEEDED,
} PromptDebugCode;

typedef struct {
    double *out;
    char *label;
    Predicate fail_on;
    char *msg_on_fail;
    int max_attempts;
} PromptOptions_Double;

const char *prompt_debug_code_to_string(PromptDebugCode code);

PromptDebugCode prompt_double(PromptOptions_Double *options);

//
// Created by dmytro on 07.10.2026.
//

#include "../include/utils/cli.h"

#include <stdio.h>

#include "../include/utils/safe_io.h"

typedef enum {
    TRY_PROMPT_SUCCESS = 0,
    TRY_PROMPT_UNEXPECTED_INPUT,
    TRY_PROMPT_INPUT_VIOLATES_CONSTRAINT,
} TryPromptDebugCode;

const char *prompt_debug_code_to_string(const PromptDebugCode code) {
    switch (code) {
        case PROMPT_NULL_POINTER:
            return "An unexpected null pointer.";
        case PROMPT_MAX_ATTEMPTS_EXCEEDED:
            return "Maximum number of attempts exceeded.";
        default:
            return "Success.";
    }
}

static int PromptOptions_prepare(PromptOptions *const options) {
    if (!options->label)
        options->label = "";

    if (!options->msg_on_fail)
        options->msg_on_fail = "Try entering the value again.";

    if (options->max_attempts < 1)
        options->max_attempts = 1;

    return 0;
}

static TryPromptDebugCode try_prompt_double(double *const out, const char *const label, const Predicate fail_on) {
    printf("Enter the value for '%s': ", label);

    const int status = read_double(out);

    if (status != 0) {
        return TRY_PROMPT_UNEXPECTED_INPUT;
    }
    if (invoke_predicate(fail_on, out)) {
        return TRY_PROMPT_INPUT_VIOLATES_CONSTRAINT;
    }

    return TRY_PROMPT_SUCCESS;
}

static TryPromptDebugCode try_prompt_int(int *const out, const char *const label, const Predicate fail_on) {
    printf("Enter the value for '%s': ", label);

    const int status = read_int(out);

    if (status != 0) {
        return TRY_PROMPT_UNEXPECTED_INPUT;
    }
    if (invoke_predicate(fail_on, out)) {
        return TRY_PROMPT_INPUT_VIOLATES_CONSTRAINT;
    }

    return TRY_PROMPT_SUCCESS;
}

PromptDebugCode prompt_double(PromptOptions *const options) {
    if (!options)
        return PROMPT_NULL_POINTER;

    PromptOptions_prepare(options);

    int i = 0;
    while (i < options->max_attempts) {
        const TryPromptDebugCode status = try_prompt_double(options->out, options->label, options->fail_on);

        switch (status) {
            case TRY_PROMPT_INPUT_VIOLATES_CONSTRAINT:
                puts(options->msg_on_fail);
                i++;
                continue;
            case TRY_PROMPT_UNEXPECTED_INPUT:
                puts("Try entering the value again.");
                i++;
                continue;
            case TRY_PROMPT_SUCCESS:
                return PROMPT_SUCCESS;
        }
    }

    puts("Failed to read the value.");

    return PROMPT_MAX_ATTEMPTS_EXCEEDED;
}

PromptDebugCode prompt_int(PromptOptions *options) {
    if (!options)
        return PROMPT_NULL_POINTER;

    PromptOptions_prepare(options);

    int i = 0;
    while (i < options->max_attempts) {
        const TryPromptDebugCode status = try_prompt_int(options->out, options->label, options->fail_on);

        switch (status) {
            case TRY_PROMPT_INPUT_VIOLATES_CONSTRAINT:
                puts(options->msg_on_fail);
                i++;
                continue;
            case TRY_PROMPT_UNEXPECTED_INPUT:
                puts("Try entering the value again.");
                i++;
                continue;
            case TRY_PROMPT_SUCCESS:
                return PROMPT_SUCCESS;
        }
    }

    puts("Failed to read the value.");

    return PROMPT_MAX_ATTEMPTS_EXCEEDED;
}

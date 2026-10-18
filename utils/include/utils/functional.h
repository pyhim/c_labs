//
// Created by dmytro on 12.10.2026.
//

#pragma once

#include <stdbool.h>

/*      Predicate       */

typedef bool (*Predicate)(const void *);

bool invoke_predicate(Predicate func, const void *value);

#define WRAP_PREDICATE(P_name, P_arg_type)              \
    static bool P_name##_adapter(const void *value) {   \
        return P_name(*(P_arg_type*)value);             \
    }

/*       Comparer       */

typedef enum {
    CMP_LESS_THAN = -1,
    CMP_EQUAL = 0,
    CMP_GREATER_THAN = 1,
} ComparisonResult;

/**
 * A comparer function interface that compares the left operand with the right operand.
 * @return If LEFT == RIGHT: <c>CMP_EQUAL</c>
 * @return If LEFT < RIGHT: <c>CMP_LESS_THAN</c>
 * @return If LEFT > RIGHT: <c>CMP_GREATER_THAN</c>
 */
typedef ComparisonResult (*Comparer)(const void*, const void*);

ComparisonResult invoke_comparer(Comparer func, const void *left, const void *right);

#define WRAP_COMPARER(C_name, C_arg1_type, C_arg2_type)                                 \
    static ComparisonResult C_name##_adapter(const void *left, const void *right) {     \
        return C_name(*(C_arg1_type*)left, *(C_arg2_type*)right);                       \
    }

/*      Aggregator      */

typedef void (*Aggregator)(void*, const void*);

void invoke_aggregator(Aggregator func, void *total, const void *next);

#define WRAP_AGGREGATOR(A_name, A_arg_type)                                             \
    static void A_name##_adapter(void *total, const void *next) {                       \
        return A_name(*(A_arg_type*)total, *(A_arg_type*)next);                         \
    }

/*      Action          */

typedef void (*Action)(void*);

void invoke_action(Action func, void *value);

#define WRAP_ACTION(A_name, A_arg_type)                                                 \
    static void A_name##_adapter(void *value) {                                   \
        return A_name(*(A_arg_type*)value);                                             \
    }
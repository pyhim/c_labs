//
// Created by dmytro on 27.09.2026.
//

#pragma once

typedef enum {
    COLLECTION_SUCCESS = 0,
    COLLECTION_ERR_SHRINKING_NOT_ALLOWED,
    COLLECTION_ERR_OUT_OF_MEMORY,
    COLLECTION_ERR_OUT_OF_RANGE,
    COLLECTION_ERR_NULL_POINTER,
    COLLECTION_ERR_WRONG_TYPE,
    COLLECTION_ERR_UNINITIALIZED,
} CollectionDebugCode;

const char *collections_debug_code_to_string(CollectionDebugCode error_code);

//
// Created by dmytro on 27.09.2026.
//

#include "../include/utils/collections.h"

const char *collections_debug_code_to_string(const CollectionDebugCode error_code) {
    switch (error_code) {
        case COLLECTION_ERR_SHRINKING_NOT_ALLOWED:
            return "Shrinking is not supported.";
        case COLLECTION_ERR_OUT_OF_MEMORY:
            return "Unable to grow the array. Out of memory.";
        case COLLECTION_ERR_OUT_OF_RANGE:
            return "Index out of range.";
        case COLLECTION_ERR_NULL_POINTER:
            return "Null pointer has been provided.";
        case COLLECTION_ERR_WRONG_TYPE:
            return "A wrong type has been provided.";
        default:
            return "Success.";
    }
}

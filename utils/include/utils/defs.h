//
// Created by dmytro on 18.10.2026.
//

#pragma once

#if defined(__GNUC__) || defined(__clang__)
#   define NO_DISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
#   include <sal.h>
#   define NO_DISCARD _Check_return_
#endif

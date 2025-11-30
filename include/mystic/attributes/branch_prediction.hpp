/**
 * Copyright 2025 Suryansh Singh
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ------------------------------------------------------------------------------------------------------
 *
 * @path [ROOT]/include/mystic/attributes/branch_prediction.hpp
 * @file branch_prediction.hpp
 * @brief Defines likely & unlikely macro.
 *
 * @details
 * This header provides branch prediction macros, hinting compiler
 * to make branch optimizations.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/branch_prediction.hpp"
 *
 * // ... in code
 * // When compiler do not support attribute (Pre-C++20)
 * if (MYSTIC_LIKELY(some_condition)) {
 *     // Likely path
 * } else {
 *     // Unlikely path
 * }
 *
 * // If compiler supports attribute (C++20+)
 * if (some_condition) MYSTIC_LIKELY {
 *     // Likely path
 * } else {
 *     // Unlikely path
 * }
 * 
 * @endcode
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "mystic/architecture/compiler_detection.hpp"
#include "mystic/architecture/standard_detection.hpp"

/**
 * @macro MYSTIC_LIKELY_EXPECT(x)
 * @brief Macro for likely using __builtin_expect().
 
 * @macro MYSTIC_UNLIKELY_EXPECT(x)
 * @brief Macro for unlikely using __builtin_expect().
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Define likely and unlikely as __builtin_expect().
 */
# define MYSTIC_LIKELY_EXPECT(x)   __builtin_expect(!!(x), 1)
# define MYSTIC_UNLIKELY_EXPECT(x) __builtin_expect(!!(x), 0)

#else /* if non-supported */
/**
 * @brief Define it as no-op.
 */
# define MYSTIC_LIKELY_EXPECT(x)
# define MYSTIC_UNLIKELY_EXPECT(x)

#endif

/**
 * @macro MYSTIC_LIKELY_ATTRIBUTE
 * @brief Macro for likely attribute (if avialable).
 *
 * @macro MYSTIC_UNLIKELY_ATTRIBUTE
 * @brief Macro for unlikely attribute (if avialable).
 */
#if (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP20)
/**
 * @brief Use the standard [[likely]] and [[unlikely]].
 */
# define MYSTIC_LIKELY_ATTRIBUTE [[likely]]
# define MYSTIC_UNLIKELY_ATTRIBUTE [[unlikely]]

#else /* if non-supported */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_LIKELY_ATTRIBUTE
# define MYSTIC_UNLIKELY_ATTRIBUTE

#endif

/* =================================================
    Dispatching Logic
   ------------------------------------------------- */

/**
 * @macro MYSTIC_BRANCH_PREDICTION_DISPATCHER
 * @brief Dispatches macro based whether value was provided or not.
 */
#define MYSTIC_BRANCH_PREDICTION_DISPATCHER(_1, N, ...) N

/**
 * @macro MYSTIC_LIKELY
 * @brief Public facing likely macro.
 */
#define MYSTIC_LIKELY(...) \
    MYSTIC_BRANCH_PREDICTION_DISPATCHER(__VA_ARGS__, \
            MYSTIC_LIKELY_ATTRIBUTE, \
            MYSTIC_LIKELY_EXPECT, )()(__VA_ARGS__)


/**
 * @macro MYSTIC_UNLIKELY
 * @brief Public facing unlikely macro.
 */
#define MYSTIC_UNLIKELY(...) \
    MYSTIC_BRANCH_PREDICTION_DISPATCHER(__VA_ARGS__, \
            MYSTIC_UNLIKELY_ATTRIBUTE, \
            MYSTIC_UNLIKELY_EXPECT, )()(__VA_ARGS__)


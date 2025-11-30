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
 * @path [ROOT]/include/mystic/attributes/deprecated.hpp
 * @file deprecated.hpp
 * @brief Defines deprecated macro.
 *
 * @details
 * This header provides deprecated macro to deprecate a function, classes,
 * struct, etc.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/deprecated.hpp"
 *
 * MYSTIC_DEPRECATED
 * void some_deprecated_func();
 * 
 * MYSTIC_DEPRECATED("This function is deprecated. Use new_func() instead")
 * void some_deprecated_func_with_msg();
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
 * @macro MYSTIC_DEPRECATED_NO_MSG
 * @brief Macro to deprecate a function.
 * 
 * @macro MYSTIC_DEPRECATED_WITH_MSG(msg)
 * @brief Macro to deprecate a function with a message.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses __declspec(deprecated).
 */
# define MYSTIC_DEPRECATED_NO_MSG        __declspec(deprecated)
# define MYSTIC_DEPRECATED_WITH_MSG(msg) __declspec(deprecated(msg))

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((deprecated)).
 */
# define MYSTIC_DEPRECATED_NO_MSG        __attribute__((deprecated))
# define MYSTIC_DEPRECATED_WITH_MSG(msg) __attribute__((deprecated(msg)))

#elif (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP14)
/**
 * @brief Use standard [[deprecated]].
 */
# define MYSTIC_DEPRECATED_NO_MSG        [[deprecated]]
# define MYSTIC_DEPRECATED_WITH_MSG(msg) [[deprecated(msg)]]

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_DEPRECATED_NO_MSG
# define MYSTIC_DEPRECATED_WITH_MSG(msg)

#endif

/* ==================================================
    Dispatching Logic
   -------------------------------------------------- */

/**
 * @macro MYSTIC_DEPRECATED_MACRO_DISPATCHER
 * @brief Counts arguments and selects the appropriate macro.
 *
 * @details
 * The '...' will consume the variable arguments (including none).
 * The (N, ...) part defines the selection order.
 */
#define MYSTIC_DEPRECATED_MACRO_DISPATCHER(_1, N, ...) N

/**
 * @macro MYSTIC_DEPRECATED
 * @brief Public facing deprecated macro.
 *
 * @details
 * - If DEPRECATED(msg) is used, it resolves to DEPRECATED_WITH_MSG.
 * - If DEPRECATED() is used (or no arguments), it resolves to DEPRECATED_NO_MSG.
 */
#define MYSTIC_DEPRECATED(...) \
    MYSTIC_DEPRECATED_MACRO_DISPATCHER(__VA_ARGS__, MYSTIC_DEPRECATED_WITH_MSG, MYSTIC_DEPRECATED_NO_MSG, )()(__VA_ARGS__)


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
 * @path [ROOT]/include/mystic/attributes/maybe_unused.hpp
 * @file maybe_unused.hpp
 * @brief Defines maybe_unused macro.
 *
 * @details
 * This header provides maybe_unused macro to mark a variable
 * as unused.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/maybe_unused.hpp"
 *
 * int some_func(int a, MYSTIC_MAYBE_UNUSED b) {
 *     int c = a;
 *     return a;
 * }
 * // No warning as b is marked with MYSTIC_MAYBE_UNUSED.
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
 * @macro MYSTIC_MAYBE_UNUSED_ATTRIBUTE
 * @brief Macro to mark a variable as unused.
 */
#if (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP17)
/**
 * @brief Use the standard [[maybe_unused]].
 */
# define MYSTIC_MAYBE_UNUSED_ATTRIBUTE [[maybe_unused]]

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC do not provide any.
 */
# define MYSTIC_MAYBE_UNUSED_ATTRIBUTE

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((unused)).
 */
# define MYSTIC_MAYBE_UNUSED_ATTRIBUTE __attribute__((unused))

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_MAYBE_UNUSED_ATTRIBUTE

#endif

/**
 * @macro MYSTIC_MAYBE_UNUSED_VOID_CAST(variable)
 * @brief Marks an variable unused by void casting.
 */
#define MYSTIC_MAYBE_UNUSED_VOID_CAST(variable) (void)(variable)

/* =================================================
    Dispatching Logic
   ------------------------------------------------- */

/**
 * @macro MYSTIC_MAYBE_UNUSED_DISPATCHER
 * @brief Dispatches unused macro based whether value was provided or not.
 */
#define MYSTIC_MAYBE_UNUSED_DISPATCHER(_1, N, ...) N

/**
 * @macro MYSTIC_MAYBE_UNUSED
 * @brief Public facing maybe_unused macro.
 */
#define MYSTIC_MAYBE_UNUSED(...) \
    MYSTIC_MAYBE_UNUSED_DISPATCHER(__VA_ARGS__, \
            MYSTIC_MAYBE_UNUSED_ATTRIBUTE, \
            MYSTIC_MAYBE_UNUSED_VOID_CAST, )()(__VA_ARGS__)


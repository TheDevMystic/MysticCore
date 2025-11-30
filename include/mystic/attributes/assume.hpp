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
 * @path [ROOT]/include/mystic/attributes/assume.hpp
 * @file assume.hpp
 * @brief Defines assume macro.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/assume.hpp"
 *
 * int shift(int x) {
 *     MYSTIC_ASSUME(x >= 0)
 *     return x / 32;
 * }
 *
 * // ↑ The above function can be optimized by the compiler
 * // As x is sure to be +ve.
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
 * @macro MYSTIC_ASSUME(cond)
 * @brief Macro to assume a condition.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses __assume().
 */
# define MYSTIC_ASSUME(cond) __assume(cond)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __builtin_assume()
 */
# define MYSTIC_ASSUME __builtin_assume(cond)

#elif (MYSTIC_ARCH_STANDARD > MYSTIC_ARCH_STANDARD_CPP20)
/**
 * @brief Use standard [[assume]].
 */
# define MYSTIC_ASSUME(cond) [[assume(cond)]]

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_ASSUME

#endif


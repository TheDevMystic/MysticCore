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
 * @path [ROOT]/include/mystic/attributes/noreturn.hpp
 * @file noreturn.hpp
 * @brief Defines noreturn macro.
 *
 * @details
 * This header provides noreturn macro to not return a function,
 * overriding reached end of non-void warning and improving static analysising.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/noreturn.hpp"
 *
 * MYSTIC_NORETURN void some_func_need_to_noreturn();
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
 * @macro MYSTIC_NORETURN
 * @brief Macro to no return a function.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses __declspec(noreturn).
 */
# define MYSTIC_NORETURN __declspec(noreturn)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((noreturn)).
 */
# define MYSTIC_NORETURN __attribute__((noreturn))

#elif (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP11)
/**
 * @brief Use standard [[noreturn]].
 */
# define MYSTIC_NORETURN [[noreturn]]

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_NORETURN

#endif


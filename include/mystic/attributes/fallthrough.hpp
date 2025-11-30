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
 * @path [ROOT]/include/mystic/attributes/fallthrough.hpp
 * @file fallthrough.hpp
 * @brief Defines fallthrough macro.
 *
 * @details
 * This header provides fallthrough macro to fallthrough
 * a switch statement.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/fallthrough.hpp"
 *
 * // ... in code
 * switch (SomeCase) {
 *     case 1:
 *         do_something();
 *         // intended fallthrough
 *         MYSTIC_FALLTHROUGH
 *     case 2:
 *         do_another_thing();
 *     default:
 *         do_third_thing();
 * }
 *
 * // no warning as MYSTIC_FALLTHROUGH supress it.
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
 * @macro MYSTIC_FALLTHROUGH
 * @brief Macro to mark a variable as unused.
 */
#if (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP17)
/**
 * @brief Use the standard [[fallthrough]].
 */
# define MYSTIC_FALLTHROUGH [[fallthrough]]

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC do not provide any.
 */
# define MYSTIC_FALLTHROUGH

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((fallthrough)).
 */
# define MYSTIC_FALLTHROUGH __attribute__((fallthrough))

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_FALLTHROUGH

#endif


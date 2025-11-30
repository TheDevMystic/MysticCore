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
 * @path [ROOT]/include/mystic/attributes/noinline.hpp
 * @file noinline.hpp
 * @brief Defines noinline macro.
 *
 * @details
 * This header provides noinline macro to not inline a function,
 * overriding compiler's benifit heuristic.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/noinline.hpp"
 *
 * MYSTIC_NOINLINE void some_func_need_to_noinlined();
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

/**
 * @macro MYSTIC_NOINLINE
 * @brief Macro to no inline a function.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_HIPCC) || \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_NVCC) /* using HIPCC/NVCC */
/**
 * @brief HIPCC and NVCC use __noinline__.
 */
# define MYSTIC_NOINLINE __noinline__

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses __declspec(noinline).
 */
# define MYSTIC_NOINLINE __declspec(noinline)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((noinline)).
 */
# define MYSTIC_NOINLINE __attribute__((noinline))

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_NOINLINE

#endif


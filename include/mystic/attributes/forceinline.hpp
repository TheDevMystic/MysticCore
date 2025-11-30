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
 * @path [ROOT]/include/mystic/attributes/forceinline.hpp
 * @file forceinline.hpp
 * @brief Defines forceinline macro.
 *
 * @details
 * This header provides forceinline macro to inline a function,
 * overriding compiler's benifit heuristic.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/forceinline.hpp"
 *
 * MYSTIC_FORCEINLINE void some_func_need_to_inlined();
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
 * @macro MYSTIC_FORCEINLINE
 * @brief Macro to force inline a function.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_HIPCC) || \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_NVCC) /* using HIPCC/NVCC */
/**
 * @brief HIPCC and NVCC use __forceinline__.
 */
# define MYSTIC_FORCEINLINE __forceinline__

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses __forceinline.
 */
# define MYSTIC_FORCEINLINE __forceinline

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((always_inline)).
 */
# define MYSTIC_FORCEINLINE __attribute__((always_inline))

#else /* if unknown */
/**
 * @brief Use standard inline keyword.
 */
# define MYSTIC_FORCEINLINE inline

#endif


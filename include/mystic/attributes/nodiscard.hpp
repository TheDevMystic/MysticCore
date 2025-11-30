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
 * @path [ROOT]/include/mystic/attributes/nodiscard.hpp
 * @file nodiscard.hpp
 * @brief Defines nodiscard macro.
 *
 * @details
 * This header provides nodiscard macro to not discard a return value.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/nodiscard.hpp"
 *
 * MYSTIC_NODISCARD int some_important_func();
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
 * @macro MYSTIC_NODISCARD_NO_MSG
 * @brief Macro to no discard a function without msg.
 *
 * @macro MYSTIC_NODISCARD_WITH_MSG(msg)
 * @brief Macro to no discard a function with msg.
 */
#if (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP20)
/**
 * @brief We can use the reason string.
 */
# define MYSTIC_NODISCARD_NO_MSG        [[nodiscard]]
# define MYSTIC_NODISCARD_WITH_MSG(msg) [[nodiscard(msg)]]

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC) /* using MSVC */
/**
 * @brief MSVC uses _Check_return_.
 */
# define MYSTIC_NODISCARD_NO_MSG        _Check_return_
# define MYSTIC_NODISCARD_WITH_MSG(msg) _Check_return_

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC) /* using Clang/GCC/ICC */
/**
 * @brief Clang, GCC, and ICC use __attribute__((warn_unused_result)).
 */
# define MYSTIC_NODISCARD_NO_MSG        __attribute__((warn_unused_result))
# define MYSTIC_NODISCARD_WITH_MSG(msg) __attribute__((warn_unused_result))

#elif (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP17)
/**
 * @brief Use standard [[nodiscard]].
 */
# define MYSTIC_NODISCARD_NO_MSG        [[nodiscard]]
# define MYSTIC_NODISCARD_WITH_MSG(msg) [[nodiscard]]

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_NODISCARD_NO_MSG
# define MYSTIC_NODISCARD_WITH_MSG(msg)

#endif

/* ==================================================
    Dispatching Logic
   -------------------------------------------------- */

/**
 * @macro MYSTIC_NODISCARD_MACRO_DISPATCHER
 * @brief Counts arguments and selects the appropriate macro.
 *
 * @details
 * The '...' will consume the variable arguments (including none).
 * The (N, ...) part defines the selection order.
 */
#define MYSTIC_NODISCARD_MACRO_DISPATCHER(_1, N, ...) N

/**
 * @macro MYSTIC_NODISCARD
 * @brief Public facing nodiscard macro.
 *
 * @details
 * - If NODISCARD(msg) is used, it resolves to NODISCARD_WITH_MSG.
 * - If NODISCARD() is used (or no arguments), it resolves to NODISCARD_NO_MSG.
 */
#define MYSTIC_NODISCARD(...) \
    MYSTIC_NODISCARD_MACRO_DISPATCHER(__VA_ARGS__, MYSTIC_NODISCARD_WITH_MSG, MYSTIC_NODISCARD_NO_MSG, )()(__VA_ARGS__)


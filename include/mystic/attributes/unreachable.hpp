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
 * @path [ROOT]/include/mystic/attributes/unreachable.hpp
 * @file unreachable.hpp
 * @brief Defines unreachable macro.
 *
 * @code{.cpp}
 * #include "mystic/attributes/unreachable.hpp"
 *
 * void control_loop() {
 *     // ... main loop
 *
 *     // Control can never end, so assume this is unreachable.
 *     MYSTIC_UNREACHABLE()
 *     // or, mystic::unreachable();
 * }
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "mystic/architecture/compiler_detection.hpp"
#include "mystic/attributes/forceinline.hpp"

/**
 * @macro MYSTIC_UNREACHABLE()
 * @brief Unreachable macro.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC)
/**
 * @brief Use __assume(0).
 */
# define MYSTIC_UNREACHABLE() __assume(0)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC)   || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC)
/**
 * @brief Use __builtin_unreachable().
 */
# define MYSTIC_UNREACHABLE() __builtin_unreachable()

#else /* for non-supported compilers */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_UNREACHABLE()

#endif

/**
 * @namespace mystic
 * @brief Top-level namespace.
 */
namespace mystic {

/**
 * @brief Function for unreachable macro in runtime.
 */
constexpr MYSTIC_FORCEINLINE void unreachable() noexcept {
    MYSTIC_UNREACHABLE()
}

} // namespace mystic


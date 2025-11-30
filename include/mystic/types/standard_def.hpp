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
 * @path [ROOT]/include/mystic/types/standard_def.hpp
 * @file standard_def.hpp
 * @brief Defines components of cstddef.
 *
 * @details
 * This header is a simple wrapper around cstddef.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/types/standard_def.hpp"
 *
 * int main() {
 *     // size_t
 *     mystic::types::size_t size_of_value = sizeof(some_value);
 *
 *    // ptrdiff_t
 *    mystic::types::ptrdiff_t = ptr1 - ptr2;
 *
 *    // max_align_t
 *    mystic::types:max_align_t max = 20;
 *
 *    // nullptr_t
 *    mystic::types::nullptr_t my_null_value = nullptr;
 *
 *    // Byte
 *    mystic::types::byte my_byte = 0b00000000;
 *
 *    return 0;
 * }
 * @endcode
 *
 * @author TheDevMystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <cstddef>

#include "mystic/types/internal/byte_internal.hpp"

/**
 * @namespace mystic
 * @brief Top-level namespace.
 */
namespace mystic {

/**
 * @namespace mystic::types
 * @ingroup Types
 * @brief Basic and high level data types.
 *
 * This namespace contains all data types from low level
 * to high level.
 */
namespace types {

/**
 * @brief Type aliases to standard types.
 */
using size_t      = ::std::size_t;
using ptrdiff_t   = ::std::ptrdiff_t;
using max_align_t = ::std::max_align_t;
using nullptr_t   = ::std::nullptr_t;

/**
 * @brief Alias byte to internal byte impl.
 */
using byte = ::mystic::types::internal::byte;

} // namespace types
} // namespace mystic

/**
 * @brief if user opted in for macros, then alias standard library
 * macros to Mystic macros.
 */
#if defined(MYSTIC_ALLOW_MACRO_USAGE) // Usage macro

/**
 * @macro MYSTIC_OFFSETOF(type, member)
 * @brief Calculates the offset of member of type.
 *
 * @param type The struct or class.
 * @param member The member of type.
 *
 * @returns Offset of member.
 */
#define MYSTIC_OFFSETOF(type, member) offsetof(type, member)

/**
 * @macro MYSTIC_NULL
 * @brief NULL constant.
 */
#define MYSTIC_NULL NULL

#endif // defined(MYSTIC_ALLOW_MACRO_USAGE)


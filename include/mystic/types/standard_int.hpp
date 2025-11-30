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
 * @path [ROOT]/include/mystic/types/standard_int.hpp
 * @file standard_int.hpp
 * @brief Defines fixed-width integers.
 *
 * @details
 * This header provides fixed-width, minimum-width and fast variant of fundamental integral
 * primitives. It simply uses `cstdint` for portable integer types.
 * 
 * This header file provides,
 * 1. Fixed-width integers.
 * 2. Minimum width integers.
 * 3. Fast variant integers.
 * 4. Pointer types
 * 5. Several limit macros (if user desire)
 *
 * Fixed-width integers are named,
 * `mystic::types::intN_t` & `mystic::types::uintN_t`.
 * Minimum width integers are named,
 * `mystic::types::int_leastN_t` & `mystic::types::uint_leastN_t`.
 * Fast variant integers are named,
 * `mystic::types::int_fastN_t` & `mystic::types::uint_fastN_t`.
 *
 * Pointers are,
 * `mystic::types::intptr_t` & `mystic::types::uintptr_t`.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/types/standard_int.hpp"
 *
 * int main() {
 *     // Fixed widths
 *     mystic::types::int32_t value1 = 1234;
 *     mystic::types::uint32_t value2 = 2025;
 *
 *     // Minimum widths
 *     mystic::types::int_least32_t value3 = 8910;
 *     mystic::types::uint_least32_t value4 = 2344;
 *
 *     // Fast variants
 *     mystic::types::int_fast32_t value5 = 8888;
 *     mystic::types::uint_fast32_t value6 = 6969;
 *
 *     return 0;
 * }
 * @endcode
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <cstdint>

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
 * @brief Signed fixed-width integers types.
 */
using int8_t  = ::std::int8_t;
using int16_t = ::std::int16_t;
using int32_t = ::std::int32_t;
using int64_t = ::std::int64_t;

/**
 * @brief Unsigned fixed-width integers types.
 */
using uint8_t  = ::std::uint8_t;
using uint16_t = ::std::uint16_t;
using uint32_t = ::std::uint32_t;
using uint64_t = ::std::uint64_t;

/**
 * @brief Signed minimum-width integers types.
 */
using int_least8_t  = ::std::int_least8_t;
using int_least16_t = ::std::int_least16_t;
using int_least32_t = ::std::int_least32_t;
using int_least64_t = ::std::int_least64_t;

/**
 * @brief Unsigned minimum-width integers types.
 */
using uint_least8_t  = ::std::uint_least8_t;
using uint_least16_t = ::std::uint_least16_t;
using uint_least32_t = ::std::uint_least32_t;
using uint_least64_t = ::std::uint_least64_t;

/**
 * @brief Signed fast variant integers types.
 */
using int_fast8_t  = ::std::int_fast8_t;
using int_fast16_t = ::std::int_fast16_t;
using int_fast32_t = ::std::int_fast32_t;
using int_fast64_t = ::std::int_fast64_t;

/**
 * @brief Unsigned fast variant integers types.
 */
using uint_fast8_t  = ::std::uint_fast8_t;
using uint_fast16_t = ::std::uint_fast16_t;
using uint_fast32_t = ::std::uint_fast32_t;
using uint_fast64_t = ::std::uint_fast64_t;

/**
 * @brief Maximum variants.
 */
using intmax_t  = ::std::intmax_t;
using uintmax_t = ::std::uintmax_t;

/**
 * @brief Pointer types.
 */
using intptr_t  = ::std::intptr_t;
using uintptr_t = ::std::uintptr_t;

} // namespace types
} // namespace mystic

/**
 * @brief if user opted in for macros, then alias standard library
 * macros to Mystic macros.
 */
#if defined(MYSTIC_ALLOW_MACRO_USAGE) // Usage macro

// --- Integer Limit Macros ---

/**
 * @macro MYSTIC_INT8_MIN
 * @brief Minimum holding capacity of int8_t.
 */
#define MYSTIC_INT8_MIN INT8_MIN

/**
 * @macro MYSTIC_INT8_MAX
 * @brief Maximum holding capacity of int8_t.
 */
#define MYSTIC_INT8_MAX INT8_MAX

/**
 * @macro MYSTIC_INT16_MIN
 * @brief Minimum holding capacity of int16_t.
 */
#define MYSTIC_INT16_MIN INT16_MIN

/**
 * @macro MYSTIC_INT16_MAX
 * @brief Maximum holding capacity of int16_t.
 */
#define MYSTIC_INT16_MAX INT16_MAX

/**
 * @macro MYSTIC_INT32_MIN
 * @brief Minimum holding capacity of int32_t.
 */
#define MYSTIC_INT32_MIN INT32_MIN

/**
 * @macro MYSTIC_INT32_MAX
 * @brief Maximum holding capacity of int32_t.
 */
#define MYSTIC_INT32_MAX INT32_MAX

/**
 * @macro MYSTIC_INT64_MIN
 * @brief Minimum holding capacity of int64_t.
 */
#define MYSTIC_INT64_MIN INT64_MIN

/**
 * @macro MYSTIC_INT64_MAX
 * @brief Maximum holding capacity of int64_t.
 */
#define MYSTIC_INT64_MAX INT64_MAX

// --- Unsigned Integer Limit Macros ---

/**
 * @macro MYSTIC_UINT8_MAX
 * @brief Maximum holding capacity of uint8_t.
 */
#define MYSTIC_UINT8_MAX UINT8_MAX

/**
 * @macro MYSTIC_UINT16_MAX
 * @brief Maximum holding capacity of uint16_t.
 */
#define MYSTIC_UINT16_MAX UINT16_MAX

/**
 * @macro MYSTIC_UINT32_MAX
 * @brief Maximum holding capacity of uint32_t.
 */
#define MYSTIC_UINT32_MAX UINT32_MAX

/**
 * @macro MYSTIC_UINT64_MAX
 * @brief Maximum holding capacity of uint64_t.
 */
#define MYSTIC_UINT64_MAX UINT64_MAX

// --- Least Integer Limit Macros ---

/**
 * @macro MYSTIC_INT_LEAST8_MIN
 * @brief Minimum holding capacity of int_least8_t.
 */
#define MYSTIC_INT_LEAST8_MIN INT_LEAST8_MIN

/**
 * @macro MYSTIC_INT_LEAST8_MAX
 * @brief Maximum holding capacity of int_least8_t.
 */
#define MYSTIC_INT_LEAST8_MAX INT_LEAST8_MAX

/**
 * @macro MYSTIC_INT_LEAST16_MIN
 * @brief Minimum holding capacity of int_least16_t.
 */
#define MYSTIC_INT_LEAST16_MIN INT_LEAST16_MIN

/**
 * @macro MYSTIC_INT_LEAST16_MAX
 * @brief Maximum holding capacity of int_least16_t.
 */
#define MYSTIC_INT_LEAST16_MAX INT_LEAST16_MAX

/**
 * @macro MYSTIC_INT_LEAST32_MIN
 * @brief Minimum holding capacity of int_least32_t.
 */
#define MYSTIC_INT_LEAST32_MIN INT_LEAST32_MIN

/**
 * @macro MYSTIC_INT_LEAST32_MAX
 * @brief Maximum holding capacity of int_least32_t.
 */
#define MYSTIC_INT_LEAST32_MAX INT_LEAST32_MAX

/**
 * @macro MYSTIC_INT_LEAST64_MIN
 * @brief Minimum holding capacity of int_least64_t.
 */
#define MYSTIC_INT_LEAST64_MIN INT_LEAST64_MIN

/**
 * @macro MYSTIC_INT_LEAST64_MAX
 * @brief Maximum holding capacity of int_least64_t.
 */
#define MYSTIC_INT_LEAST64_MAX INT_LEAST64_MAX

// --- Unsigned Least Integer Limit Macros ---

/**
 * @macro MYSTIC_UINT_LEAST8_MAX
 * @brief Maximum holding capacity of uint_least8_t.
 */
#define MYSTIC_UINT_LEAST8_MAX UINT_LEAST8_MAX

/**
 * @macro MYSTIC_UINT_LEAST16_MAX
 * @brief Maximum holding capacity of uint_least16_t.
 */
#define MYSTIC_UINT_LEAST16_MAX UINT_LEAST16_MAX

/**
 * @macro MYSTIC_UINT_LEAST32_MAX
 * @brief Maximum holding capacity of uint_least32_t.
 */
#define MYSTIC_UINT_LEAST32_MAX UINT_LEAST32_MAX

/**
 * @macro MYSTIC_UINT_LEAST64_MAX
 * @brief Maximum holding capacity of uint_least64_t.
 */
#define MYSTIC_UINT_LEAST64_MAX UINT_LEAST64_MAX

// --- Fast Integer Limit Macros ---

/**
 * @macro MYSTIC_INT_FAST8_MIN
 * @brief Minimum holding capacity of int_fast8_t.
 */
#define MYSTIC_INT_FAST8_MIN INT_FAST8_MIN

/**
 * @macro MYSTIC_INT_FAST8_MAX
 * @brief Maximum holding capacity of int_fast8_t.
 */
#define MYSTIC_INT_FAST8_MAX INT_FAST8_MAX

/**
 * @macro MYSTIC_INT_FAST16_MIN
 * @brief Minimum holding capacity of int_fast16_t.
 */
#define MYSTIC_INT_FAST16_MIN INT_FAST16_MIN

/**
 * @macro MYSTIC_INT_FAST16_MAX
 * @brief Maximum holding capacity of int_fast16_t.
 */
#define MYSTIC_INT_FAST16_MAX INT_FAST16_MAX

/**
 * @macro MYSTIC_INT_FAST32_MIN
 * @brief Minimum holding capacity of int_fast32_t.
 */
#define MYSTIC_INT_FAST32_MIN INT_FAST32_MIN

/**
 * @macro MYSTIC_INT_FAST32_MAX
 * @brief Maximum holding capacity of int_fast32_t.
 */
#define MYSTIC_INT_FAST32_MAX INT_FAST32_MAX

/**
 * @macro MYSTIC_INT_FAST64_MIN
 * @brief Minimum holding capacity of int_fast64_t.
 */
#define MYSTIC_INT_FAST64_MIN INT_FAST64_MIN

/**
 * @macro MYSTIC_INT_FAST64_MAX
 * @brief Maximum holding capacity of int_fast64_t.
 */
#define MYSTIC_INT_FAST64_MAX INT_FAST64_MAX

// --- Unsigned Fast Integer Limit Macros ---

/**
 * @macro MYSTIC_UINT_FAST8_MAX
 * @brief Maximum holding capacity of uint_fast8_t.
 */
#define MYSTIC_UINT_FAST8_MAX UINT_FAST8_MAX

/**
 * @macro MYSTIC_UINT_FAST16_MAX
 * @brief Maximum holding capacity of uint_fast16_t.
 */
#define MYSTIC_UINT_FAST16_MAX UINT_FAST16_MAX

/**
 * @macro MYSTIC_UINT_FAST32_MAX
 * @brief Maximum holding capacity of uint_fast32_t.
 */
#define MYSTIC_UINT_FAST32_MAX UINT_FAST32_MAX

/**
 * @macro MYSTIC_UINT_FAST64_MAX
 * @brief Maximum holding capacity of uint_fast64_t.
 */
#define MYSTIC_UINT_FAST64_MAX UINT_FAST64_MAX

// --- Maximum Variant ---

/**
 * @macro MYSTIC_INTMAX_MIN
 * @brief Minimum holding capacity of intmax_t.
 */
#define MYSTIC_INTMAX_MIN INTMAX_MIN

/**
 * @macro MYSTIC_INTMAX_MAX
 * @brief Maximum holding capacity of intMAX_t.
 */
#define MYSTIC_INTMAX_MAX INTMAX_MAX

/**
 * @macro MYSTIC_UINTMAX_MAX
 * @brief Maximum holding capacity of uintmax_t.
 */
#define MYSTIC_UINTMAX_MAX UINTMAX_MAX

// --- Pointer Types ---

/**
 * @macro MYSTIC_INTPTR_MIN
 * @brief Minimum holding capacity of intptr_t.
 */
#define MYSTIC_INTPTR_MIN INTPTR_MIN

/**
 * @macro MYSTIC_INTPTR_MAX
 * @brief Maximum holding capacity of intptr_t.
 */
#define MYSTIC_INTPTR_MAX INTPTR_MAX

/**
 * @macro MYSTIC_UINTPTR_MAX
 * @brief Maximum holding capacity of uintptr_t.
 */
#define MYSTIC_UINTPTR_MAX UINTPTR_MAX

// --- Function-Like Macros ---

/**
 * @macro MYSTIC_INT8_C(value)
 * @brief Adds correct literal for int8_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_INT8_C(value) INT8_C(value)

/**
 * @macro MYSTIC_INT16_C(value)
 * @brief Adds correct literal for int16_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_INT16_C(value) INT16_C(value)

/**
 * @macro MYSTIC_INT32_C(value)
 * @brief Adds correct literal for int32_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_INT32_C(value) INT32_C(value)

/**
 * @macro MYSTIC_INT64_C(value)
 * @brief Adds correct literal for int64_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_INT64_C(value) INT64_C(value)

/**
 * @macro MYSTIC_UINT8_C(value)
 * @brief Adds correct literal for uint8_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_UINT8_C(value) UINT8_C(value)

/**
 * @macro MYSTIC_UINT16_C(value)
 * @brief Adds correct literal for uint16_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_UINT16_C(value) UINT16_C(value)

/**
 * @macro MYSTIC_UINT32_C(value)
 * @brief Adds correct literal for uint32_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_UINT32_C(value) UINT32_C(value)

/**
 * @macro MYSTIC_UINT64_C(value)
 * @brief Adds correct literal for uint64_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_UINT64_C(value) UINT64_C(value)

/**
 * @macro MYSTIC_INTMAX_C(value)
 * @brief Adds correct literal for intmax_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_INTMAX_C(value) INTMAX_C(value)

/**
 * @macro MYSTIC_UINTMAX_C(value)
 * @brief Adds correct literal for uintmax_t.
 *
 * @param value The value on which literal will be added.
 *
 * @returns Literal appended value.
 */
#define MYSTIC_UINTMAX_C(value) UINTMAX_C(value)

// --- Related Macros ---

/**
 * @macro MYSTIC_PTRDIFF_MIN
 * @brief Minimum value ptrdiff_t can hold.
 *
 * @sa ptrdiff_t is defined in standard_def.hpp
 */
#define MYSTIC_PTRDIFF_MIN PTRDIFF_MIN

/**
 * @macro MYSTIC_PTRDIFF_MAX
 * @brief Maximum value ptrdiff_t can hold.
 *
 * @sa ptrdiff_t is defined in standard_def.hpp
 */
#define MYSTIC_PTRDIFF_MAX PTRDIFF_MAX

/**
 * @macro MYSTIC_SIZE_MAX
 * @brief Maximum value size_t can hold.
 *
 * @sa size_t is defined in standard_def.hpp
 */
#define MYSTIC_SIZE_MAX SIZE_MAX

/**
 * @macro MYSTIC_WCHAR_MIN
 * @brief Minimum value wchar_t can hold.
 *
 * @sa wchar_t is defined in standard_wchar.hpp
 */
#define MYSTIC_WCHAR_MIN WCHAR_MIN

/**
 * @macro MYSTIC_WCHAR_MAX
 * @brief Maximum value wchar_t can hold.
 *
 * @sa wchar_t is defined in standard_wchar.hpp
 */
#define MYSTIC_WCHAR_MAX WCHAR_MAX

/**
 * @macro MYSTIC_WINT_MIN
 * @brief Minimum value wint_t can hold.
 *
 * @sa wint_t is defined in standard_wchar.hpp
 */
#define MYSTIC_WINT_MIN WINT_MIN

/**
 * @macro MYSTIC_WINT_MAX
 * @brief Maximum value wint_t can hold.
 *
 * @sa wint_t is defined in standard_wchar.hpp
 */
#define MYSTIC_WINT_MAX WINT_MAX

/**
 * @macro MYSTIC_SIG_ATOMIC_MIN
 * @brief Minimum value sig_atomic_t can hold.
 *
 * @sa sig_atomic_t is defined in standard_signal.hpp
 */
#define MYSTIC_SIG_ATOMIC_MIN SIG_ATOMIC_MIN

/**
 * @macro MYSTIC_SIG_ATOMIC_MAX
 * @brief Maximum value sig_atomic_t can hold.
 *
 * @sa sig_atomic_t is defined in standard_signal.hpp
 */
#define MYSTIC_SIG_ATOMIC_MAX SIG_ATOMIC_MAX

#endif // defined(MYSTIC_ALLOW_MACRO_USAGE)


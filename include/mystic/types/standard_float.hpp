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
 * @path [ROOT]/include/mystic/types/standard_float.hpp
 * @file standard_float.hpp
 * @brief Defines various floating point related macros.
 *
 * @details
 * This header defines many macros related to floating point numbers. It wraps cfloat header file.
 *
 * This header defines,
 * 1. Fixed width float types.
 * 2. Float realted macros prefixed with `MYSTIC_FLT_*`.
 * 3. Double realted macros prefixed with `MYSTIC_DBL_*`.
 * 4. Long double realted macros prefixed with `MYSTIC_LDBL_*`.
 
 * @code {.cpp}
 * // Example
 * #define MYSTIC_ALLOW_MACRO_USAGE
 * #include "mystic/types/standard_float.hpp"
 *
 * int main() {
 *     // Epsilon
 *     mystic::types::float32_t float_epsilon = MYSTIC_FLT_EPSILON;
 *     mystic::types::float64_t double_epsilon = MYSTIC_DBL_EPSILON;
 *     mystic::types::float128_t ldouble_epsilon = MYSTIC_LDBL_EPSILON;
 *
 *     // Radix
 *     mystic::types::float32_t float_radix = MYSTIC_FLT_RADIX;
 *     mystic::types::float64_t double_radix = MYSTIC_DBL_RADIX;
 *     mystic::types::float128_t double ldouble_radix = MYSTIC_LDBL_RADIX;
 *     
 *     // ... other macros 
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

#include <cfloat>

#include "mystic/types/internal/fixed_width_floats.hpp"

/**
 * @namespace mystic::types
 * @ingroup Types
 * @brief Basic and high level data types.
 *
 * This namespace contains all data types from low level
 * to high level.
 */
namespace mystic::types {

/**
 * @brief Fixed width floating-point types.
 */
using float16_t = ::mystic::types::internal::float16_t;
using float32_t = ::mystic::types::internal::float32_t;
using float64_t = ::mystic::types::internal::float64_t;
using float128_t = ::mystic::types::internal::float128_t;

/**
 * @brief Fixed width brain floating point type.
 */
using bfloat16_t = ::mystic::types::internal::bfloat16_t;

} // namespace mystic::types

/**
 * @brief if user opted in for macros, then alias standard library
 * macros to Mystic macros.
 */
#if defined(MYSTIC_ALLOW_MACRO_USAGE) // Usage macro

// --- Representation & Base ---

// --- Radix ---

/**
 * @macro MYSTIC_FLT_RADIX
 * @brief The base of the exponent representation.
 */
#define MYSTIC_FLT_RADIX FLT_RADIX

// --- Mantissa --- 

/**
 * @macro MYSTIC_FLT_MANT_DIG
 * @brief The number of base-FLT_RADIX digits in the mantissa (significand) of float.
 */
#define MYSTIC_FLT_MANT_DIG FLT_MANT_DIG

/**
 * @macro MYSTIC_DBL_MANT_DIG
 * @brief The number of base-FLT_RADIX digits in the mantissa (significand) of double.
 */
#define MYSTIC_DBL_MANT_DIG DBL_MANT_DIG

/**
 * @macro MYSTIC_LDBL_MANT_DIG
 * @brief The number of base-FLT_RADIX digits in the mantissa (significand) of long double.
 */
#define MYSTIC_LDBL_MANT_DIG LDBL_MANT_DIG

// ------------------------------------------------------------------------------------

// --- Range & Limits ---

// --- Maximum Floating-Point Number ---

/**
 * @macro MYSTIC_FLT_MAX
 * @brief The maximum finite representable floating-point number of float.
 */
#define MYSTIC_FLT_MAX FLT_MAX

/**
 * @macro MYSTIC_DBL_MAX
 * @brief The maximum finite representable floating-point number of double.
 */
#define MYSTIC_DBL_MAX DBL_MAX

/**
 * @macro MYSTIC_LDBL_MAX
 * @brief The maximum finite representable floating-point number of long double.
 */
#define MYSTIC_LDBL_MAX LDBL_MAX

// --- Minimum Floating-Point Number ---

/**
 * @macro MYSTIC_FLT_MIN
 * @brief The minimum representable normalized positive floating-point number of float.
 */
#define MYSTIC_FLT_MIN FLT_MIN

/**
 * @macro MYSTIC_DBL_MIN
 * @brief The minimum representable normalized positive floating-point number of double.
 */
#define MYSTIC_DBL_MIN DBL_MIN

/**
 * @macro MYSTIC_LDBL_MIN
 * @brief The minimum representable normalized positive floating-point number of long double.
 */
#define MYSTIC_LDBL_MIN LDBL_MIN

// ------------------------------------------------------------------------------------

// --- Precision & Digits ---

// --- Digits of precision ---

/**
 * @macro MYSTIC_FLT_DIG
 * @brief Number of decimal digits of precision of float.
 */
#define MYSTIC_FLT_DIG FLT_DIG

/**
 * @macro MYSTIC_DBL_DIG
 * @brief Number of decimal digits of precision of double.
 */
#define MYSTIC_DBL_DIG DBL_DIG

/**
 * @macro MYSTIC_LDBL_DIG
 * @brief Number of decimal digits of precision of long double.
 */
#define MYSTIC_LDBL_DIG LDBL_DIG

// --- Decimal Precision ---

/**
 * @macro MYSTIC_FLT_DECIMAL_DIG
 * @brief Minimum number of decimal digits that can be
 * stored and retrieved without change of float.
 */
#define MYSTIC_FLT_DECIMAL_DIG FLT_DECIMAL_DIG

/**
 * @macro MYSTIC_DBL_DECIMAL_DIG
 * @brief Minimum number of decimal digits that can be
 * stored and retrieved without change of double.
 */
#define MYSTIC_DBL_DECIMAL_DIG DBL_DECIMAL_DIG

/**
 * @macro MYSTIC_LDBL_DECIMAL_DIG
 * @brief Minimum number of decimal digits that can be
 * stored and retrieved without change of long double.
 */
#define MYSTIC_LDBL_DECIMAL_DIG LDBL_DECIMAL_DIG

#endif // defined(MYSTIC_ALLOW_MACRO_USAGE)


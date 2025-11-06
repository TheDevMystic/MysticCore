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
 * 1. Float realted macros prefixed with `MYSTIC_FLT_*`.
 * 2. Double realted macros prefixed with `MYSTIC_DBL_*`.
 * 3. Long double realted macros prefixed with `MYSTIC_LDBL_*`.
 
 * @code {.cpp}
 * // Example
 * #define MYSTIC_ALLOW_MACRO_USAGE
 * #include "mystic/types/standard_float.hpp"
 *
 * int main() {
 *     // Epsilon
 *     float float_epsilon = MYSTIC_FLT_EPSILON;
 *     double double_epsilon = MYSTIC_DBL_EPSILON;
 *     long double ldouble_epsilon = MYSTIC_LDBL_EPSILON;
 *
 *     // Radix
 *     float float_radix = MYSTIC_FLT_RADIX;
 *     double double_radix = MYSTIC_DBL_RADIX;
 *     long double ldouble_radix = MYSTIC_LDBL_RADIX;
 *     
 *     // ... other macros 
 *     
 *     return 0;
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

#include <cfloat>

/**
 * @brief if user opted in for macros, then alias standard library
 * macros to Mystic macros.
 */
#if defined(MYSTIC_ALLOW_MACRO_USAGE) // Usage macro

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


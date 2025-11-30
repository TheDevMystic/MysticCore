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
 * @path [ROOT]/include/mystic/architecture/endianness_detection.hpp
 * @file endianness_detection.hpp
 * @brief Defines endianness detection macros & runtime logic.
 *
 * @details
 * This header provides endianness detection macros and runtime detection,
 * for cross endianness portable code. Endians are Little and Big.
 * 
 * This header file provides,   
 * 1. endianness detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/endianness_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_ENDIANNESS == MYSTIC_ARCH_ENDIANNESS_BIG)
 * // big endian specific code
 * 
 * #else
 * // little endian specific code
 * 
 * #endif
 * @endcode
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

/* =============================================
    Endianness Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_ENDIANNESS_BIG
 * @brief Tag for big endianness.
 */
#define MYSTIC_ARCH_ENDIANNESS_BIG 0

/**
 * @macro MYSTIC_ARCH_ENDIANNESS_LITTLE
 * @brief Tag for little endianness.
 */
#define MYSTIC_ARCH_ENDIANNESS_LITTLE 1

/**
 * @macro MYSTIC_ARCH_ENDIANNESS_UNKNOWN
 * @brief Tag for Unknown endianness.
 */
#define MYSTIC_ARCH_ENDIANNESS_UNKNOWN 2

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_ENDIANNESS
 * @brief Tag for endianness identification.
 */
#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) /* using little endian */
/**
 * @brief Set Endianness to Little
 */
# define MYSTIC_ARCH_ENDIANNESS MYSTIC_ARCH_ENDIANNESS_LITTLE

#elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) /* using big endian */
/**
 * @brief Set Endianness to Big
 */
# define MYSTIC_ARCH_ENDIANNESS MYSTIC_ARCH_ENDIANNESS_BIG

/**
 * @brief CPU architecture specific endians.
 */
#elif defined(__LITTLE_ENDIAN__) || defined(__ARMEL__)
/**
 * @brief Set Endianness to Little
 */
# define MYSTIC_ARCH_ENDIANNESS MYSTIC_ARCH_ENDIANNESS_LITTLE

#elif defined(__BIG_ENDIAN__) || defined(__ARMEB__)
/**
 * @brief Set Endianness to Big
 */

#else /* If non supported Endianness */
/**
 * @brief Set Endiannes tag to unknown.
 */
# define MYSTIC_ARCH_ENDIANNESS MYSTIC_ARCH_ENDIANNESS_UNKNOWN

#endif

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If endianness is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_ENDIANNESS.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_ENDIANNESS) && \
    (MYSTIC_ARCH_ENDIANNESS == MYSTIC_ARCH_ENDIANNESS_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - Endianness - The Endianness currently being used is not supported, consider using supported endiannesss."

#endif

/* =============================================
    Endianness Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_ENDIANNESS_NAME
 * @brief Endianness name.
 */
#if (MYSTIC_ARCH_ENDIANNESS == MYSTIC_ARCH_ENDIANNESS_BIG)
/**
 * @brief Set Endianness name to big.
 */
# define MYSTIC_ARCH_ENDIANNESS_NAME "Big"

#elif (MYSTIC_ARCH_ENDIANNESS == MYSTIC_ARCH_ENDIANNESS_LITTLE)
/**
 * @brief Set Endianness name to little.
 */
# define MYSTIC_ARCH_ENDIANNESS_NAME "Little"

#else /* if unknown */
/**
 * @brief Set Endianness name to UNKNOWN.
 */
# define MYSTIC_ARCH_ENDIANNESS_NAME "UNKNOWN"

#endif

/* =============================================
    ENDIANNESS Runtime Logic
   --------------------------------------------- */

/**
 * @namespace mystic
 * @brief Top level namespace.
 */
namespace mystic {

/**
 * @namespace mystic::architecture
 * @brief Contains architecture-specific runtime code.
 */
namespace architecture {

/**
 * @namespace mystic::architecture::endianness
 * @brief Contains endianness-specific runtime code.
 */
namespace endianness {

/**
 * @brief Returns ENDIANNESS name in runtime.
 */
constexpr inline const char* get_endianness_name() {
    return MYSTIC_ARCH_ENDIANNESS_NAME;
}

} // namespace endianness
} // namespace architecture
} // namespace mystic


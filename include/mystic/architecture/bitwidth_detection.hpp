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
 * @path [ROOT]/include/mystic/architecture/bitwidth_detection.hpp
 * @file bitwidth_detection.hpp
 * @brief Defines bitwidth detection macros & runtime logic.
 *
 * @details
 * This header provides bitwidth detection macros and runtime detection,
 * for cross bitwidth portable code. There are many bitwidth out (i think so)
 * of which 2 are major usage share holders, i.e., 64 bit and 32 bit.
 * 
 * This header file provides,   
 * 1. bitwidth detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/bitwidth_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_BITWIDTH == MYSTIC_ARCH_BITWIDTH_64)
 * // 64 bit-specific code
 * 
 * #elif (MYSTIC_ARCH_BITWIDTH == MYSTIC_ARCH_BITWIDTH_32)
 * // 32 bit-specific code
 * 
 * #else
 * // If not a supported BITWIDTH
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

#include "mystic/architecture/cpu_detection.hpp"

/* =============================================
    Bitwidth Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BITWIDTH_64
 * @brief Tag for 64 bitwidth.
 */
#define MYSTIC_ARCH_BITWIDTH_64 0

/**
 * @macro MYSTIC_ARCH_BITWIDTH_32
 * @brief Tag for 32 bitwidth.
 */
#define MYSTIC_ARCH_BITWIDTH_32 1

/**
 * @macro MYSTIC_ARCH_BITWIDTH_UNKNOWN
 * @brief Tag for Unknown bitwidth.
 */
#define MYSTIC_ARCH_BITWIDTH_UNKNOWN 2

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BITWIDTH
 * @brief Tag for bitwidth identification.
 */
#if (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86_64) || \
    (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM64) /* using 64-bit CPU */
/**
 * @brief Set bitwidth tag to 64.
 */
# define MYSTIC_ARCH_BITWIDTH MYSTIC_ARCH_BITWIDTH_64

#elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86) || \
    (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM32) /* using 32-bit CPU */
/**
 * @brief Set bitwidth tag to 32.
 */
# define MYSTIC_ARCH_BITWIDTH MYSTIC_ARCH_BITWIDTH_32

#else /* if unknown */
/**
 * @brief Set bitwidth tag to UNKNOWN.
 */
# define MYSTIC_ARCH_BITWIDTH MYSTIC_ARCH_BITWIDTH_UNKNOWN

#endif // (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86_64) || \
       // (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM64)

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If bitwidth is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_BITWIDTH.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_BITWIDTH) && \
    (MYSTIC_ARCH_BITWIDTH == MYSTIC_ARCH_BITWIDTH_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - Bitwidth - The Bitwidth currently being used is not supported, consider using supported bitwidths."

#endif

/* =============================================
    Bitwidth Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BITWIDTH_NAME
 * @brief Bitwidth name.
 */
#if (MYSTIC_ARCH_BITWIDTH == MYSTIC_ARCH_BITWIDTH_64)
/**
 * @brief Set Bitwidth name to 64.
 */
# define MYSTIC_ARCH_BITWIDTH_NAME "64"

#elif (MYSTIC_ARCH_BITWIDTH == MYSTIC_ARCH_BITWIDTH_32)
/**
 * @brief Set Bitwidth name to 32.
 */
# define MYSTIC_ARCH_BITWIDTH_NAME "32"

#else /* if unknown */
/**
 * @brief Set Bitwidth name to UNKNOWN.
 */
# define MYSTIC_ARCH_BITWIDTH_NAME "UNKNOWN"

#endif

/* =============================================
    BITWIDTH Runtime Logic
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
 * @namespace mystic::architecture::bitwidth
 * @brief Contains bitwidth-specific runtime code.
 */
namespace bitwidth {

/**
 * @brief Returns BITWIDTH name in runtime.
 */
constexpr inline const char* get_bitwidth_name() {
    return MYSTIC_ARCH_BITWIDTH_NAME;
}

} // namespace bitwidth
} // namespace architecture
} // namespace mystic


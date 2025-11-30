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
 * @path [ROOT]/include/mystic/architecture/cpu_detection.hpp
 * @file cpu_detection.hpp
 * @brief Defines cpu detection macros & runtime logic.
 *
 * @details
 * This header provides cpu detection macros and runtime detection,
 * for cross cpu portable code. There are many cpu out
 * of which 4 are major usage share holders, i.e., x86-64, x86, arm64, arm32.
 * 
 * This header file provides,   
 * 1. cpu detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/cpu_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86_64)
 * // x86-specific code
 * 
 * #elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86)
 * // x86-specific code
 * 
 * #elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM64)
 * // Arm64-specific code
 * 
 * #elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM32)
 * // Arm32-specific code
 * 
 * #else
 * // If not a supported CPU
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
    CPU Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_CPU_X86_64
 * @brief Tag for x86-64 CPU.
 */
#define MYSTIC_ARCH_CPU_X86_64 0

/**
 * @macro MYSTIC_ARCH_CPU_X86
 * @brief Tag for x86 CPU.
 */
#define MYSTIC_ARCH_CPU_X86 1

/**
 * @macro MYSTIC_ARCH_CPU_ARM64
 * @brief Tag for Arm64 CPU.
 */
#define MYSTIC_ARCH_CPU_ARM64 2

/**
 * @macro MYSTIC_ARCH_CPU_ARM32
 * @brief Tag for Arm32 CPU.
 */
#define MYSTIC_ARCH_CPU_ARM32 3

/**
 * @macro MYSTIC_ARCH_CPU_UNKNOWN
 * @brief Tag for Unknown CPU.
 */
#define MYSTIC_ARCH_CPU_UNKNOWN 4

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_CPU
 * @brief Tag for CPU identification.
 */
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64) /* using x86-64 */
/**
 * @brief Set CPU tag to x86-64.
 */
# define MYSTIC_ARCH_CPU MYSTIC_ARCH_CPU_X86_64

#elif defined(__i386__) || defined(_M_IX86) /* using x86 */
/**
 * @brief Set CPU tag to x86.
 */
# define MYSTIC_ARCH_CPU MYSTIC_ARCH_CPU_X86

#elif defined(__aarch64__) || defined(_M_ARM64) /* using Arm64 */
/**
 * @brief Set CPU tag to Arm64.
 */
# define MYSTIC_ARCH_CPU MYSTIC_ARCH_CPU_ARM64

#elif defined(__arm__) || defined(_M_ARM) /* using Arm32 */
/**
 * @brief Set CPU tag to Arm32.
 */
# define MYSTIC_ARCH_CPU MYSTIC_ARCH_CPU_ARM32

#else /* if cpu is unknown */
/**
 * @brief Set CPU tag to UNKNOWN.
 */
#define MYSTIC_ARCH_CPU MYSTIC_ARCH_CPU_UNKNOWN

#endif // defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If CPU is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_CPU.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_CPU) && \
    (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - CPU - The CPU currently being used is not supported, consider using supported cpus."

#endif

/* =============================================
    CPU Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_CPU_NAME
 * @brief CPU name.
 */
#if (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86_64)
/**
 * @brief Set CPU name to x86-64.
 */
# define MYSTIC_ARCH_CPU_NAME "x86-64"

#elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86)
/**
 * @brief Set CPU name to x86.
 */
# define MYSTIC_ARCH_CPU_NAME "x86"

#elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM64)
/**
 * @brief Set CPU name to Arm64.
 */
# define MYSTIC_ARCH_CPU_NAME "Arm64"

#elif (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_ARM32)
/**
 * @brief Set CPU name to Arm32.
 */
# define MYSTIC_ARCH_CPU_NAME "Arm32"

#else /* if unknown */
/**
 * @brief Set CPU name to Unknown.
 */
# define MYSTIC_ARCH_CPU_NAME "UNKNOWN"

#endif // (MYSTIC_ARCH_CPU == MYSTIC_ARCH_CPU_X86_64)

/* =============================================
    CPU Runtime Logic
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
 * @namespace mystic::architecture::cpu
 * @brief Contains cpu-specific runtime code.
 */
namespace cpu {

/**
 * @brief Returns CPU name in runtime.
 */
constexpr inline const char* get_cpu_name() {
    return MYSTIC_ARCH_CPU_NAME;
}

} // namespace cpu
} // namespace architecture
} // namespace mystic


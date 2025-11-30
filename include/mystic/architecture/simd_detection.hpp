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
 * @path [ROOT]/include/mystic/architecture/simd_detection.hpp
 * @file simd_detection.hpp
 * @brief Defines simd detection macros & runtime logic.
 *
 * @details
 * This header provides simd detection macros and runtime detection,
 * for cross simd portable code. There are many simd out
 * of which 2 are major usage share holders, i.e., AVX and NEON (and variants).
 * 
 * This header file provides,   
 * 1. simd detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/simd_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_AVX2)
 * // AVX2-specific code
 * 
 * #elif (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_NEON)
 * // NEON-specific code
 * 
 * #else
 * // Scalar code
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

#include "mystic/features/use_simd.hpp"

/* =============================================
    SIMD Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_SIMD_AVX2
 * @brief Tag for AVX2 simd.
 */
#define MYSTIC_ARCH_SIMD_AVX2 0

/**
 * @macro MYSTIC_ARCH_SIMD_AVX512
 * @brief Tag for AVX512 simd.
 */
#define MYSTIC_ARCH_SIMD_AVX512 1

/**
 * @macro MYSTIC_ARCH_SIMD_NEON
 * @brief Tag for NEON simd.
 */
#define MYSTIC_ARCH_SIMD_NEON 2

/**
 * @macro MYSTIC_ARCH_SIMD_SVE
 * @brief Tag for SVE simd.
 */
#define MYSTIC_ARCH_SIMD_SVE 3

/**
 * @macro MYSTIC_ARCH_SIMD_SVE2
 * @brief Tag for SVE2 simd.
 */
#define MYSTIC_ARCH_SIMD_SVE2 4

/**
 * @macro MYSTIC_ARCH_SIMD_UNKNOWN
 * @brief Tag for Unknown simd.
 */
#define MYSTIC_ARCH_SIMD_UNKNOWN 5

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_SIMD
 * @brief Tag for simd identification.
 */
#if defined(__AVX512__) /* using AVX512 */
/**
 * @brief Set simd tag to AVX512.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_AVX512

#elif defined(__AVX2__) /* using AVX2 */
/**
 * @brief Set simd tag to AVX2.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_AVX2

#elif defined(__ARM_FEATURE_SVE2) && defined(__ARM_FEATURE_SME) /* using SVE2 */
/**
 * @brief Set simd tag to SVE2.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_SVE2

#elif defined(__ARM_FEATURE_SVE) /* using SVE */
/**
 * @brief Set simd tag to SVE.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_SVE

#elif defined(__ARM_NEON) /* using NEON */
/**
 * @brief Set simd tag to NEON.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_NEON

#else /* if simd is unknown */
/**
 * @brief Set simd tag to UNKNOWN.
 */
# define MYSTIC_ARCH_SIMD MYSTIC_ARCH_SIMD_UNKNOWN

#endif // defined(__AVX512__)


/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If simd is unknown and MYSTIC_FEATURE_USE_SIMD is defined,
 * then stop compilation.
 */
#if (defined(MYSTIC_FEATURE_USE_SIMD) && \
    (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - SIMD - The SIMD currently being used is not supported, consider using supported SIMD or use scalar."

#endif

/* =============================================
    SIMD Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_SIMD_NAME
 * @brief simd name.
 */
#if (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_AVX512)
/**
 * @brief Set simd name to AVX512.
 */
# define MYSTIC_ARCH_SIMD_NAME "AVX512"

#elif (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_AVX2)
/**
 * @brief Set simd name to AVX2.
 */
# define MYSTIC_ARCH_SIMD_NAME "AVX2"

#elif (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_SVE2)
/**
 * @brief Set simd name to SVE2.
 */
# define MYSTIC_ARCH_SIMD_NAME "SVE2"

#elif (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_SVE)
/**
 * @brief Set simd name to SVE.
 */
# define MYSTIC_ARCH_SIMD_NAME "SVE"

#elif (MYSTIC_ARCH_SIMD == MYSTIC_ARCH_SIMD_NEON)
/**
 * @brief Set simd name to NEON.
 */
# define MYSTIC_ARCH_SIMD_NAME "NEON"

#else /* if unknown */
/**
 * @brief Set simd name to UNKNOWN.
 */
# define MYSTIC_ARCH_SIMD_NAME "UNKNOWN"

#endif

/* =============================================
    SIMD Runtime Logic
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
 * @namespace mystic::architecture::simd
 * @brief Contains simd-specific runtime code.
 */
namespace simd {

/**
 * @brief Returns simd name in runtime.
 */
constexpr inline const char* get_simd_name() {
    return MYSTIC_ARCH_SIMD_NAME;
}

} // namespace simd
} // namespace architecture
} // namespace mystic


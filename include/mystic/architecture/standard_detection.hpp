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
 * @path [ROOT]/include/mystic/architecture/standard_detection.hpp
 * @file standard_detection.hpp
 * @brief Defines standard detection macros & runtime logic.
 *
 * @details
 * This header provides standard detection macros and runtime detection,
 * for cross standard portable code.
 * 
 * This header file provides,   
 * 1. standard detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/standard_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP20)
 * // cpp 20-specific code
 * 
 * #else
 * // pre-cpp 20-specific code
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
    Standard Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_STANDARD_CPP98
 * @brief Tag for C++98/C++03 Standard (Value: 199711L)
 */
#define MYSTIC_ARCH_STANDARD_CPP98 199711L

/**
 * @macro MYSTIC_ARCH_STANDARD_CPP11
 * @brief Tag for C++11 Standard (Value: 201103L)
 */
#define MYSTIC_ARCH_STANDARD_CPP11 201103L

/**
 * @macro MYSTIC_ARCH_STANDARD_CPP14
 * @brief Tag for C++14 Standard (Value: 201402L)
 */
#define MYSTIC_ARCH_STANDARD_CPP14 201402L

/**
 * @macro MYSTIC_ARCH_STANDARD_CPP17
 * @brief Tag for C++17 Standard (Value: 201703L)
 */
#define MYSTIC_ARCH_STANDARD_CPP17 201703L

/**
 * @macro MYSTIC_ARCH_STANDARD_CPP20
 * @brief Tag for C++20 Standard (Value: 202002L)
 */
#define MYSTIC_ARCH_STANDARD_CPP20 202002L

/**
 * @macro MYSTIC_ARCH_STANDARD_UNKNOWN
 * @brief Tag for unknown Standard (Value: 999999L)
 */
#define MYSTIC_ARCH_STANDARD_CPP20 999999L

/* =============================================
    Detection Logic
   --------------------------------------------- */

// MSVC-specific handling:
// MSVC often sets __cplusplus to 199711L by default, even in C++17/20 mode.
// It provides a dedicated macro, _MSVC_LANG, which is standard-conforming.
#if defined(_MSVC_LANG)
# define MYSTIC_CPP_LANG_VERSION _MSVC_LANG
#else
# define MYSTIC_CPP_LANG_VERSION __cplusplus
#endif

/**
 * @macro MYSTIC_ARCH_STANDARD
 * @brief Tag for standard identification.
 */
#if MYSTIC_CPP_LANG_VERSION > MYSTIC_ARCH_STANDARD_CPP20
/**
 * @brief Set Standard to C++20 or later (C++23/C++26)
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP20

#elif MYSTIC_CPP_LANG_VERSION >= MYSTIC_ARCH_STANDARD_CPP20
/**
 * @brief Set Standard to C++20
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP20

#elif MYSTIC_CPP_LANG_VERSION >= MYSTIC_ARCH_STANDARD_CPP17
/**
 * @brief Set Standard to C++17
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP17

#elif MYSTIC_CPP_LANG_VERSION >= MYSTIC_ARCH_STANDARD_CPP14
/**
 * @brief Set Standard to C++14
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP14

#elif MYSTIC_CPP_LANG_VERSION >= MYSTIC_ARCH_STANDARD_CPP11
/**
 * @brief Set Standard to C++11
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP11

#elif MYSTIC_CPP_LANG_VERSION >= MYSTIC_ARCH_STANDARD_CPP98
/**
 * @brief Set Standard to C++98/C++03
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_CPP98

#else /* if unknown standard (e.g., C++ being compiled as C) */
/**
 * @brief Set Standard to UNKNOWN.
 */
# define MYSTIC_ARCH_STANDARD MYSTIC_ARCH_STANDARD_UNKNOWN

#endif

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If Standard is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_STANDARD.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_STANDARD) && \
    (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - Standard - The standard currently being used is not supported, consider using supported standards."

#endif

/* =============================================
    Standard Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_STANDARD_NAME
 * @brief Standard name.
 */
#if (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP20)
/**
 * @brief Set Standard name to C++20.
 */
# define MYSTIC_ARCH_STANDARD_NAME "C++20"

#elif (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP17)
/**
 * @brief Set Standard name to C++17.
 */
# define MYSTIC_ARCH_STANDARD_NAME "C++17"

#elif (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP14)
/**
 * @brief Set Standard name to C++14.
 */
# define MYSTIC_ARCH_STANDARD_NAME "C++14"

#elif (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP11)
/**
 * @brief Set Standard name to C++11.
 */
# define MYSTIC_ARCH_STANDARD_NAME "C++11"

#elif (MYSTIC_ARCH_STANDARD == MYSTIC_ARCH_STANDARD_CPP98)
/**
 * @brief Set Standard name to C++98.
 */
# define MYSTIC_ARCH_STANDARD_NAME "C++98"

#else
/**
 * @brief Set Standard name to UNKNOWN.
 */
# define MYSTIC_ARCH_STANDARD_NAME "UNKNOWN"

#endif

/* =============================================
    STANDARD Runtime Logic
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
 * @namespace mystic::architecture::standard
 * @brief Contains standard-specific runtime code.
 */
namespace standard {

/**
 * @brief Returns STANDARD name in runtime.
 */
constexpr inline const char* get_standard_name() {
    return MYSTIC_ARCH_STANDARD_NAME;
}

} // namespace standard
} // namespace architecture
} // namespace mystic

/// Cleanup of temp macro.
#undef MYSTIC_CPP_LANG_VERSION


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
 * @path [ROOT]/include/mystic/architecture/os_detection.hpp
 * @file os_detection.hpp
 * @brief Defines os detection macros & runtime logic.
 *
 * @details
 * This header provides os detection macros and runtime detection,
 * for cross os portable code. There are many os out
 * of which 3 are major usage share holders, i.e., Windows, MacOS, and Linux.
 * 
 * This header file provides,   
 * 1. os detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/os_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_WINDOWS)
 * // Windows-specific code
 * 
 * #elif (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_MACOS)
 * // MacOS-specific code
 * 
 * #elif (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_LINUX)
 * // Linux-specific code
 * 
 * #else
 * // If not a supported OS
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
    OS Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_OS_WINDOWS
 * @brief Tag for Microsoft Windows OS.
 */
#define MYSTIC_ARCH_OS_WINDOWS 0

/**
 * @macro MYSTIC_ARCH_OS_MACOS
 * @brief Tag for Apple Mac OS.
 */
#define MYSTIC_ARCH_OS_MACOS 1

/**
 * @macro MYSTIC_ARCH_OS_LINUX
 * @brief Tag for our good ol' Linux OS.
 */
#define MYSTIC_ARCH_OS_LINUX 2

/**
 * @macro MYSTIC_ARCH_OS_UNKNOWN
 * @brief Tag for Unknown OS.
 */
#define MYSTIC_ARCH_OS_UNKNOWN 3

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_OS
 * @brief Tag for OS identification.
 */
#if defined(_WIN32) || defined(_WIN64) /* using Windows */
/**
 * @brief Set OS tag to Windows
 */
# define MYSTIC_ARCH_OS MYSTIC_ARCH_OS_WINDOWS

#elif defined(__APPLE__) || defined(__MACH__) /* using Apple */

// Include Apple's development header to make sure it is a MacOS
#include <TargetConditionals.h>

# if defined(TARGET_OS_MAC) && TARGET_OS_MAC /* using MacOS */
/**
 * @brief Set OS tag to MacOS
 */
#  define MYSTIC_ARCH_OS MYSTIC_ARCH_OS_MACOS
# endif // defined(TARGET_OS_MAC) && TARGET_OS_MAC

#elif defined(__linux__) /* using Linux */
/**
 * @brief Set OS tag to Linux
 */
# define MYSTIC_ARCH_OS MYSTIC_ARCH_OS_LINUX

#else /* if OS is unknown */
/**
 * @brief Set OS tag to Unknown.
 */
# define MYSTIC_ARCH_OS MYSTIC_ARCH_OS_UNKNOWN

#endif // defined(_WIN32) || defined(_WIN64)

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If OS is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_OS.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_OS) && \
    (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - OS - The OS currently being used is not supported, consider using supported compilers."

#endif

/* =============================================
    OS Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_OS_NAME
 * @brief OS name.
 */
#if (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_WINDOWS)
/**
 * @brief Set OS name to Windows.
 */
# define MYSTIC_ARCH_OS_NAME "Windows"

#elif (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_MACOS)
/**
 * @brief Set OS name to MacOS.
 */
# define MYSTIC_ARCH_OS_NAME "MacOS"

#elif (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_LINUX)
/**
 * @brief Set OS name to Linux.
 */
# define MYSTIC_ARCH_OS_NAME "Linux"

#else /* if unknown */
/**
 * @brief Set OS name to Unknown.
 */
# define MYSTIC_ARCH_OS_NAME "UNKNOWN"

#endif // (MYSTIC_ARCH_OS == MYSTIC_ARCH_OS_WINDOWS)

/* =============================================
    OS Runtime Logic
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
 * @namespace mystic::architecture::os
 * @brief Contains os-specific runtime code.
 */
namespace os {

/**
 * @brief Returns OS name in runtime.
 */
constexpr inline const char* get_os_name() {
    return MYSTIC_ARCH_OS_NAME;
}

} // namespace os
} // namespace architecture
} // namespace mystic


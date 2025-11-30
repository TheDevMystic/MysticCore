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
 * @path [ROOT]/include/mystic/architecture/build_type_detection.hpp
 * @file build_type_detection.hpp
 * @brief Defines build type detection macros & runtime logic.
 *
 * @details
 * This header provides build type detection macros and runtime detection.
 * 
 * This header file provides,   
 * 1. build type detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/build_type_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_BUILD_TYPE == MYSTIC_ARCH_BUILD_TYPE_DEBUG)
 * // debug-specific code
 * 
 * #else
 * // release-specific code
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
    Build Type Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BUILD_TYPE_DEBUG
 * @brief Tag for debug build type.
 */
#define MYSTIC_ARCH_BUILD_TYPE_DEBUG 0

/**
 * @macro MYSTIC_ARCH_BUILD_TYPE_RELEASE_WITH_DEBINFO
 * @brief Tag for release with debug information build type.
 */
#define MYSTIC_ARCH_BUILD_TYPE_RELEASE_WITH_DEBINFO 1

/**
 * @macro MYSTIC_ARCH_BUILD_TYPE_RELEASE
 * @brief Tag for release build type.
 */
#define MYSTIC_ARCH_BUILD_TYPE_RELEASE 2

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BUILD_TYPE
 * @brief Tag for build type identification.
 */
#if defined(DEBUG) || defined(_DEBUG) /* Debug build */
/**
 * @brief Set build type tag to Debug.
 */
# define MYSTIC_ARCH_BUILD_TYPE MYSTIC_ARCH_BUILD_TYPE_DEBUG

#elif defined(NDEBUG) && defined(_RELWITHDEBINFO) /* ReleaseWithDebInfo build */
/**
 * @brief Set build type tag to ReleaseWithDebInfo.
 */
# define MYSTIC_ARCH_BUILD_TYPE MYSTIC_ARCH_BUILD_TYPE_RELEASE_WITH_DEBINFO

#else /* Default to Release */
/**
 * @brief Set build type to Release.
 */
# define MYSTIC_ARCH_BUILD_TYPE MYSTIC_ARCH_BUILD_TYPE_RELEASE

#endif

/* =============================================
    Build Type Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_BUILD_TYPE_NAME
 * @brief Build Type name.
 */
#if (MYSTIC_ARCH_BUILD_TYPE == MYSTIC_ARCH_BUILD_TYPE_DEBUG)
/**
 * @brief Set Build Type name to Debug.
 */
# define MYSTIC_ARCH_BUILD_TYPE_NAME "Debug"

#elif (MYSTIC_ARCH_BUILD_TYPE == MYSTIC_ARCH_BUILD_TYPE_RELEASE_WITH_DEBINFO)
/**
 * @brief Set Build Type name to ReleaseWithDebInfo.
 */
# define MYSTIC_ARCH_BUILD_TYPE_NAME "ReleaseWithDebInfo"

#else
/**
 * @brief Set Build Type name to Release.
 */
# define MYSTIC_ARCH_BUILD_TYPE_NAME "Release"

#endif

/* =============================================
    BUILD_TYPE Runtime Logic
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
 * @namespace mystic::architecture::build type
 * @brief Contains build type-specific runtime code.
 */
namespace build type {

/**
 * @brief Returns BUILD_TYPE name in runtime.
 */
constexpr inline const char* get_build_type_name() {
    return MYSTIC_ARCH_BUILD_TYPE_NAME;
}

} // namespace build type
} // namespace architecture
} // namespace mystic


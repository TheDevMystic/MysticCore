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
 * @path [ROOT]/include/mystic/macros/framework_api.hpp
 * @file framework_api.hpp
 * @brief Defines framework api macro.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "mystic/architecture/compiler_detection.hpp"

/**
 * @macro MYSTIC_API_EXPORT_TAG
 * @brief Export tag for framework.
 *
 * @macro MYSTIC_API_IMPORT_TAG
 * @brief Import tag for framework.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC)
/**
 * @brief Use __declspec(dllexport) and __declspec(dllimport).
 */
# define MYSTIC_API_EXPORT_TAG __declspec(dllexport)
# define MYSTIC_API_IMPORT_TAG __declspec(dllimport)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC)   || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC)   || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_HIPCC) || \
      (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_NVCC)
/**
 * @brief Use __attribute__((visibility("default"))).
 */
# define MYSTIC_API_EXPORT_TAG __attribute__((visibility("default")))
# define MYSTIC_API_IMPORT_TAG __attribute__((visibility("default")))

#else /* for static builds, or non-supported compilers */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_API_EXPORT_TAG
# define MYSTIC_API_IMPORT_TAG

#endif

/**
 * @macro MYSTIC_FRAMEWORK_API
 * @brief Main framework api macro.
 */
#if defined(MYSTIC_FRAMEWORK_API_EXPORT_CMAKE)
/**
 * @define Use export tag.
 */
# define MYSTIC_FRAMEWORK_API MYSTIC_API_EXPORT_TAG

#else /* for import */
/**
 * @define Use import tag.
 */
# define MYSTIC_FRAMEWORK_API MYSTIC_API_IMPORT_TAG

#endif

/// Cleanup Tags
#undef MYSTIC_API_EXPORT_TAG
#undef MYSTIC_API_IMPORT_TAG


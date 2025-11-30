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
 * @path [ROOT]/include/mystic/attributes/pure.hpp
 * @file pure.hpp
 * @brief Defines pure macro.
 *
 * @details
 * This header provides pure macro for CSE.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/pure.hpp"
 *
 * MYSTIC_PURE
 * void my_pure_func();
 * 
 * @endcode
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
 * @macro MYSTIC_PURE
 * @brief Macro for pure functions.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC) || \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC)
/**
 * @brief Use __attribute__((pure)).
 */
# define MYSTIC_PURE __attribute__((pure))

#else /* if non-supported */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_PURE

#endif


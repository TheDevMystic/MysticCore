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
 * @path [ROOT]/include/mystic/attributes/no_unique_address.hpp
 * @file no_unique_address.hpp
 * @brief Defines no_unique_address macro.
 *
 * @details
 * This header provides no_unique_address macro for EBCO.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/attributes/no_unique_address.hpp"
 *
 * class MyCoolClass {
 *     MYSTIC_NO_UNIQUE_ADDRESS int x;
 * };
 *
 * // sizeof(MyCoolClass) == 1 evalutes to true.
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

#include "mystic/architecture/standard_detection.hpp"

/**
 * @macro MYSTIC_NO_UNIQUE_ADDRESS
 * @brief Macro for no unique address.
 */
#if (MYSTIC_ARCH_STANDARD >= MYSTIC_ARCH_STANDARD_CPP20)
/**
 * @brief Use standard macro.
 */
# define MYSTIC_NO_UNIQUE_ADDRESS [[no_unique_address]]

#else /* if unknown */
/**
 * @brief Use blank no-op.
 */
# define MYSTIC_NO_UNIQUE_ADDRESS

#endif


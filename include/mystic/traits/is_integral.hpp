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
 * @path [ROOT]/include/mystic/types/is_integral.hpp
 * @file is_integral.hpp
 * @brief Defines is integral type trait.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <type_traits>

/**
 * @namespace mystic
 * @brief Top-level enclosing namespace.
 */
namespace mystic {

/**
 * @namespace mystic::traits
 * @ingroup Traits
 * @brief This namespace defines type traits.
 */
namespace traits {

/**
 * @brief Standard type trait is_integral.
 */
template <typename Type>
using is_integral = std::is_integral<Type>;

/**
 * @brief _v Alias for type (pre-C++14).
 */
template <typename Type>
static constexpr bool is_integral_v = typename std::is_integral<Type>::value;

} // namespace traits
} // namespace mystic


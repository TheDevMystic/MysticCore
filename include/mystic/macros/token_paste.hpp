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
 * @path [ROOT]/include/mystic/macros/token_paste.hpp
 * @file token_paste.hpp
 * @brief Defines token_paste macro.
 *
 * @details
 * This header provides token_paste macro for token pasting.
 * 
 * @code {.cpp}
 * // Example
 * #include "mystic/macros/token_paste.hpp"
 *
 * #define USER_MACRO 134
 * #define USER_MACRO_STR MYSTIC_TOKEN_PASTE(USER_MACRO)
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

/**
 * @macro MYSTIC_TOKEN_PASTE_HELPER(variable_macro)
 * @brief Implementation helper of token_paste macro.
 *
 * @param variable_macro1 The macro to be token pasted.
 * @param variable_macro2 The macro to be token pasted.
 *
 * @returns Token pasted version of variable_macro.
 */
#define MYSTIC_TOKEN_PASTE_HELPER(variable_macro) \
    variable_macro1##variable_macro2

/**
 * @macro MYSTIC_TOKEN_PASTE(variable_macro)
 * @brief Public-facing token_paste macro.
 *
 * @param variable_macro1 The macro to be token pasted.
 * @param variable_macro2 The macro to be token pasted.
 *
 * @returns Token pasted version of variable_macro.
 */
#define MYSTIC_TOKEN_PASTE(variable_macro) MYSTIC_TOKEN_PASTE_HELPER(variable_macro1, variable_macro2)


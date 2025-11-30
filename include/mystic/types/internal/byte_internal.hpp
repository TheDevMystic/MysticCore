/**
 * Copyright 2025 Suryansh Singh
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ------------------------------------------------------------------------------------------------------
 *
 * @path [ROOT]/include/mystic/types/internal/byte_internal.hpp
 * @file byte_internal.hpp
 * @brief Defines byte struct for pre-C++17.
 *
 * @details
 * This header defines byte for pre-C++17. It is intended for internal usage only.
 * It will be public if compiler is pre-C++17 via, types/standard_defs.hpp.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "mystic/assert/assert.hpp"
#include "mystic/architecture/forceinline.hpp"
#include "mystic/traits/is_integral.hpp"

/**
 * @namespace mystic::types::internal
 * @ingroup Types
 * @brief Internal types definitions
 *
 * This namespace contains all internal type definitions.
 * **This namespace should not be directly used.** It is for internal
 * usage only. Use mystic::types instead.
 */
namespace mystic::types::internal {

// --- Class Def ---

/**
 * @enum byte
 * @brief Internal byte struct for pre-C++17.
 */
enum class byte : unsigned char {};

// --- Conversion Operators ---

/**
 * @brief Function for conversion of byte to integer (non-const).
 *
 * @tparam IntegerType The integral type.
 * @param b The byte enum to be converted.
 * 
 * @pre IntegerType must be an integral type.
 *
 * @returns Integer version of byte.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE IntegerType ConvertToInteger(byte b) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")

    // Perform the cast
    return static_cast<IntegerType>(b);
}

/**
 * @brief Function for conversion of byte to integer (const).
 *
 * @tparam IntegerType The integral type.
 * @param b The byte enum to be converted.
 * 
 * @pre IntegerType must be an integral type.
 *
 * @returns Integer version of byte.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE IntegerType ConvertToInteger(const byte b) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")

    return static_cast<IntegerType>(b);
}

/**
 * @brief Function for conversion of integer to byte (non-const).
 *
 * @tparam IntegerType The integral type.
 * @param value The integral to be converted.
 * 
 * @pre IntegerType must be an integral type.
 * @pre value must be in range of byte (8 bit), i.e., 0 - 255.
 *
 * @returns Byte.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte ConvertToByte(IntegerType value) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")

    // Ensure the value is in byte range.
    MYSTIC_DCHECK(value >= 0 && value <= 255, "[MYSTIC FRAMEWORK] - Byte - The given variable value exceeds the range of byte.")

    return static_cast<byte>(value);
}

/**
 * @brief Function for conversion of integer to byte (const).
 *
 * @tparam IntegerType The integral type.
 * @param value The integral to be converted.
 * 
 * @pre IntegerType must be an integral type.
 * @pre value must be in range of byte (8 bit), i.e., 0 - 255.
 *
 * @returns Byte.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte ConvertToByte(const IntegerType value) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")

    // Ensure the value is in byte range.
    MYSTIC_DCHECK(value >= 0 && value <= 255, "[MYSTIC FRAMEWORK] - Byte - The given variable value exceeds the range of byte.")

    return static_cast<byte>(value);
}

// --- Bitwise Binary Operators ---

/**
 * @brief Bitwise AND operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Byte after bitwise AND operation.
 */
constexpr MYSTIC_FORCEINLINE byte operator&(const byte& lhs, const byte& rhs) noexcept {
    return static_cast<byte>(ConvertToInteger(lhs) & ConvertToInteger(rhs));
}

/**
 * @brief Bitwise OR operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Byte after bitwise OR operation.
 */
constexpr MYSTIC_FORCEINLINE byte operator|(const byte& lhs, const byte& rhs) noexcept {
    return static_cast<byte>(ConvertToInteger(lhs) | ConvertToInteger(rhs));
}

/**
 * @brief Bitwise XOR operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Byte after bitwise XOR operation.
 */
constexpr MYSTIC_FORCEINLINE byte operator^(const byte& lhs, const byte& rhs) noexcept {
    return static_cast<byte>(ConvertToInteger(lhs) ^ ConvertToInteger(rhs));
}


// --- Bitwise Unary Operators ---

/**
 * @brief Bitwise NOT operator.
 *
 * @param byte The byte value.
 *
 * @returns Byte after bitwise NOT operation.
 */
constexpr MYSTIC_FORCEINLINE byte operator~(const byte& byte) noexcept {
    return static_cast<byte>(~ConvertToInteger(byte));
}


// --- Bitwise Shift Operators ---

/**
 * @brief Bitwise left shift operator.
 *
 * @tparam IntegerType The integral type.
 * @param byte The byte value.
 * @param shift The required shift.
 *
 * @pre IntegerType must be integral type.
 *
 * @returns Byte after bitwise left shift operation.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte operator<<(const byte& byte, IntegerType shift) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")
    
    // Perform shift
    return static_cast<byte>(ConvertToInteger(byte) << shift);
}

/**
 * @brief Bitwise right shift operator.
 *
 * @tparam IntegerType The integral type.
 * @param byte The byte value.
 * @param shift The required shift.
 *
 * @pre IntegerType must be integral type.
 *
 * @returns Byte after bitwise right shift operation.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte operator>>(const byte& byte, IntegerType shift) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")
    
    // Perform shift
    return static_cast<byte>(ConvertToInteger(byte) >> shift);
}


// --- Compound Assignment Bitwise Operators ---

/**
 * @brief Bitwise AND assignment operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Reference to LHS after bitwise AND assignment operation.
 */
constexpr MYSTIC_FORCEINLINE byte& operator&=(byte& lhs, const byte& rhs) noexcept {
    lhs = lhs & rhs;
    return lhs;
}

/**
 * @brief Bitwise OR assignment operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Reference to LHS after bitwise OR assignment operation.
 */
constexpr MYSTIC_FORCEINLINE byte& operator|=(byte& lhs, const byte& rhs) noexcept {
    lhs = lhs | rhs;
    return lhs;
}

/**
 * @brief Bitwise XOR assignment operator.
 *
 * @param LHS The left handside byte.
 * @param RHS The right handside byte.
 *
 * @returns Reference to LHS after bitwise XOR assignment operation.
 */
constexpr MYSTIC_FORCEINLINE byte& operator^=(byte& lhs, const byte& rhs) noexcept {
    lhs = lhs ^ rhs;
    return lhs;
}

/**
 * @brief Bitwise left shift assignment operator.
 *
 * @tparam IntegerType The integral type.
 * @param byte The byte value.
 * @param shift The required shift.
 *
 * @pre IntegerType must be integral type.
 *
 * @returns Reference to byte after bitwise left shift assignment operation.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte& operator<<=(byte& byte, IntegerType shift) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")
    
    // Perform shift
    byte = byte << shift;
    return byte;
}

/**
 * @brief Bitwise right shift assignment operator.
 *
 * @tparam IntegerType The integral type.
 * @param byte The byte value.
 * @param shift The required shift.
 *
 * @pre IntegerType must be integral type.
 *
 * @returns Reference to byte after bitwise right shift assignment operation.
 */
template <typename IntegerType = unsigned int>
constexpr MYSTIC_FORCEINLINE byte& operator>>=(byte& byte, IntegerType shift) noexcept {
    // Ensure that IntegerType is an integral type.
    MYSTIC_DCHECK(::mystic::traits::is_integral_v<IntegerType>, "[MYSTIC FRAMEWORK] - Byte - The given variable type must be an integral type.")
    
    // Perform shift
    byte = byte >> shift;
    return byte;
}

} // namespace mystic::types::internal


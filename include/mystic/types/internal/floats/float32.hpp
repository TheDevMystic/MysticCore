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
 * @path [ROOT]/include/mystic/types/internal/floats/float32_internal.hpp
 * @file float32_internal.hpp
 * @brief Defines Float32 for pre-C++23.
 *
 * @details
 * This header defines Float32 for pre-C++23. It is intended for internal usage only.
 * It will be public if compiler is pre-C++23 via, types/standard_float.hpp.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <cfloat>
#include <cmath>

#include "mystic/traits/enable_if.hpp"
#include "mystic/traits/is_arithmetic.hpp"
#include "mystic/traits/is_convertible.hpp"

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

/**
 * @class Float32
 * @brief Fixed-width Float32 class.
 */
class Float32 {
public:
    /**
     * @brief Function to initiate a Float32 object from any type.
     *
     * @tparam ArithmeticType Any arithmetic type or convertible type.
     * @param val The value of the ArithmeticType.
     *
     * @pre ArithmeticType must be an arithemtic type or convertible type.
     */
    template <typename ArithmeticType,
              typename = ::mystic::traits::enable_if_t<
                  ::mystic::traits::is_arithmetic_v<ArithmeticType> ||
                  ::mystic::traits::is_convertible_v<ArithmeticType, float>>>
    constexpr Float32(ArithmeticType val) noexcept {
        // Perform cast and store it.
        this->m_raw_value = static_cast<float>(val);
    }

    /**
     * @brief Function to convert Float32 to any other type.
     *
     * @tparam ArithmeticType Any arithmetic type or convertible type.
     *
     * @pre ArithmeticType must be an arithemtic type or convertible type.
     */
    template <typename ArithmeticType,
              typename = ::mystic::traits::enable_if_t<
                  ::mystic::traits::is_arithmetic_v<ArithmeticType> ||
                  ::mystic::traits::is_convertible_v<ArithmeticType, float>>>
    constexpr operator ArithmeticType() const noexcept {
        // Perform cast.
        return static_cast<ArithmeticType>(this->m_raw_value);
    }
    
    /**
     * @brief Function to retrive the internal raw value.
     *
     * @returns float The internal value.
     */
    constexpr MYSTIC_FORCEINLINE float Value() const noexcept {
        return this->m_raw_value;
    }

private:
    float m_raw_value;
}; // class Float32

// --- Binary Operators ---

/**
 * @brief Binary addition operator (+)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator+(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<Float32>(lhs.Value() + rhs);
}

/**
 * @brief Binary addition operator (+)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator+(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<ArithmeticType>(lhs.Value() + rhs);
}

/**
 * @brief Binary addition operator (+)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator+(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<Float32>(lhs + rhs.Value());
}

/**
 * @brief Binary addition operator (+)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator+(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<ArithmeticType>(lhs + rhs.Value());
}

/**
 * @brief Binary subtraction operator (-)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator-(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<Float32>(lhs.Value() - rhs);
}

/**
 * @brief Binary subtraction operator (-)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator-(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<ArithmeticType>(lhs.Value() - rhs);
}

/**
 * @brief Binary subtraction operator (-)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator-(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<Float32>(lhs - rhs.Value());
}

/**
 * @brief Binary subtraction operator (-)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator-(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<ArithmeticType>(lhs - rhs.Value());
}

/**
 * @brief Binary multiplication operator (*)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator*(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<Float32>(lhs.Value() * rhs);
}

/**
 * @brief Binary multiplication operator (*)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator*(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    return static_cast<ArithmeticType>(lhs.Value() * rhs);
}

/**
 * @brief Binary multiplication operator (*)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator*(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<Float32>(lhs * rhs.Value());
}

/**
 * @brief Binary multiplication operator (*)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator*(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    return static_cast<ArithmeticType>(lhs * rhs.Value());
}

/**
 * @brief Binary division operator (/)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator/(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    // Check if denominator is 0 or not.
    MYSTIC_CHECK(std::abs(rhs) < FLT_EPSILON, "[Mystic Framework] - Float32 - Division by Zero is undefined.")
    return static_cast<Float32>(lhs.Value() / rhs);
}

/**
 * @brief Binary division operator (/)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The left handside Float32 type.
 * @param rhs The right handside arithemtic type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator/(const Float32& lhs, const ArithmeticType& rhs) noexcept {
    // Check if denominator is 0 or not.
    MYSTIC_CHECK(std::abs(rhs) < FLT_EPSILON, "[Mystic Framework] - Float32 - Division by Zero is undefined.")
    return static_cast<ArithmeticType>(lhs.Value() / rhs);
}

/**
 * @brief Binary division operator (/)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns Float32.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) <= sizeof(float))>>
constexpr MYSTIC_FORCEINLINE Float32 operator/(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    // Check if denominator is 0 or not.
    MYSTIC_CHECK(std::abs(rhs.Value()) < FLT_EPSILON, "[Mystic Framework] - Float32 - Division by Zero is undefined.")
    return static_cast<Float32>(lhs / rhs.Value());
}

/**
 * @brief Binary division operator (/)
 *
 * @tparam ArithmeticType Any arithmetic type.
 * @param lhs The right handside arithemtic type.
 * @param rhs The left handside Float32 type.
 *
 * @pre ArithmeticType must be an arithemtic type or convertible type.
 *
 * @returns ArithmeticType.
 */
template <typename ArithmeticType,
          typename = ::mystic::traits::enable_if_t<
              (::mystic::traits::is_arithmetic_v<ArithmeticType> ||
               ::mystic::traits::is_convertible_v<ArithmeticType, float>) &&
               (sizeof(ArithmeticType) > sizeof(float))>>
constexpr MYSTIC_FORCEINLINE ArithmeticType operator/(const ArithmeticType& lhs, const Float32& rhs)  noexcept {
    // Check if denominator is 0 or not.
    MYSTIC_CHECK(std::abs(rhs.Value()) < FLT_EPSILON, "[Mystic Framework] - Float32 - Division by Zero is undefined.")
    return static_cast<ArithmeticType>(lhs / rhs.Value());
}

} // namespace mystic::types::internal


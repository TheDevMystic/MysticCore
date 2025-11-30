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
 * @path [ROOT]/include/mystic/status/internal/status_internal.hpp
 * @file status.hpp
 * @brief Defines `Status` and `StatusCode` classes with utility functions for error handling.
 *
 * @details
 * This header provides public-facing status error handling and reporting interface.
 * It defines core status codes via, `mystic::status::StatusCode` enum class,
 * and status handling via, `mystic::status::Status` class.
 * It also provides utility functions, for string conversions like
 * `mystic::status::StatusCodeToString()`.
 * 
 * This header file provides,
 * 1. `mystic::status::StatusCode` For status codes and error codes enumeration.
 * 2. `mystic::status::Status` For status handling and reporting.
 * 3. A set of utility functions.
 *
 * Within Mystic framework `mystic::status::Status` is the primary mechanism to communicate
 * errors in C++. It is inspired by Google's `absl::Status`.
 *
 * @code {.cpp}
 * // Example
 *
 * #include "mystic/status/status.hpp"
 *
 * mystic::status::Status DoSomething() {
 *     // Standalone check
 *     if (some invalid argument) {
 *         return mystic::status::InvalidArgument("Provided argument is invalid");
 *     }
 *
 *     // Checking a result object
 *     mystic::status::Status result = DoAnotherThing1();
 *     if (!result.ok()) {
 *         return result;
 *     }
 *     
 *     // Using a macro (see mystic/status/status_macros.h)
 *     MYSTIC_RETURN_IF_ERROR(DoAnotherThing2())
 *
 *     // Return OK on success
 *     return mystic::status::OK();
 * }
 * @endcode
 *
 * `mystic::status::Status` is used for functions which have conceptual return type of `void`.
 * If some function returns something use `mystic::status::StatusOr<T>` instead (see mystic/status/status_or.h)
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <sstream>

#include "mystic/architecture/attributes.hpp"
#include "mystic/architecture/framework_api.hpp"

/**
 * @namespace Mystic::Status
 * @brief Core status and error handling components.
 *
 * @details
 * This namespace contains status and error handling mechanisms.
 * It provides status codes, status handling and status reporting
 * functions and classes.
 */
namespace Mystic::Status {

/**
 * @class Status
 * @brief Class to status of a operation.
 */
MYSTIC_INTERNAL_ARCH_FRAMEWORK_API
class Status {
public:
    /**
     * @brief Default constructor (Success)
     * @details This constructor constructs a default Status object.
     * By default, Status is success.
     */
    Status() : m_Code(StatusCode::OK) {}

    /**
     * @brief Error constructor
     * @details This constructor constructs a error Status object.
     * It can hold any StatusCode, from success to errors. It holds
     * a string explaining the error, which is critical for debugging.
     *
     * @param code The specific StatusCode object.
     * @param message The string explaining the error.
     */
    Status(StatusCode code, std:string message)
        : m_Code(code), m_Message(std::move(message)) {}

    /**
     * @brief Accessor ok()
     * @details This function checks if the status was success or not.
     * This acheives it by check current status code with StatusCode::OK.
     *
     * @note While framework use PascalCase for functions, it is delibrate
     * inconsistency for natural accessor syntax like, some_value.ok().
     *
     * @returns bool Whether the StatusCode is OK or not.
     */
    bool ok() const { return m_Code == StatusCode::OK; }

    /**
     * @brief Getter for status code.
     * @details This function returns the StatusCode stored in Status
     * object.
     *
     * @returns StatusCode The specific status code stored in Status object.
     */
    StatusCode code() const { return m_Code; }

    /**
     * @brief Getter for status message.
     * @details This function returns the status message stored in
     * Status object.
     *
     * @returns const std::string& Const reference to the message stored in Status object.
     */
    const std::string& message() const { return m_Message; }

    /**
     * @brief Factory method to get success status.
     * @details This function creates a success Status object.
     */
    static Status OK() { return Status(); }

    /**
     * @brief Logging function of Status object.
     * @details This converts Status object to string.
     */
    std::string ToString() const {
        std::stringstream ss;
        ss << "[" << StatusCodeToString(m_Code) << "] " << m_Message;
        return ss.str();
    }
    
private:
    /**
     * @brief StatusCode to store the current status code of the object.
     */
    StatusCode m_Code;

    /**
     * @brief Message to provide information on the status.
     */
    std::string m_Message;
}; // class Status

/**
 * @brief convenience function to generate ok status.
 */
MYSTIC_INTERNAL_ARCH_FRAMEWORK_API
MYSTIC_INTERNAL_FORCEINLINE
Status OkStatus() { return Status::OK(); }

} // namespace Mystic::Status


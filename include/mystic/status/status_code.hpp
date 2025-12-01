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
 * @path [ROOT]/include/mystic/status/status_code.hpp
 * @file status_code.hpp
 * @brief Defines enum class for status codes.
 *
 * @details
 * This header provides error and status codes for error-handling.
 * It is based on gRPC, for standard industry recommended error codes.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "mystic/attributes/forceinline.hpp"
#include "mystic/attributes/nodiscard.hpp"
#include "mystic/attributes/unreachable.hpp"
#include "mystic/containers/string.hpp"
#include "mystic/macros/framework_api.hpp"
#include "mystic/types/standard_int.hpp"
#include "mystic/utility/string_utils.hpp"

/**
 * @namespace mystic
 * @brief Top-level namespace.
 */
namespace mystic {

/**
 * @namespace status
 * @brief Status-specific classes and functions.
 */
namespace status {

/**
 * @brief Enum class for status, and error codes.
 */
enum class MYSTIC_FRAMEWORK_API StatusCode :
    ::mystic::types::uint16_t {

    /**
     * @brief OK, or Success.
     * Enum to denote that the operation completed without any
     * error, or problem.
     */
    OK = 0x0000,

    /**
     * @brief Cancellation.
     * Enum to denote that the operation was cancelled before it
     * was completed (typically by the user).
     */
    CANCELLED = 0x0001,

    /**
     * @brief Invalid argument.
     * Enum to denote that the user has specified invalid arguments for
     * the operation.
     */
    INVALID_ARGUMENT = 0x0002,

    /**
     * @brief Not found.
     * Enum to denote that the requested resource (i.e., files, records, etc)
     * was not found.
     */
    NOT_FOUND = 0x0003,

    /**
     * @brief Already exists.
     * Enum to denote that the requested creation of a resource already
     * exists.
     */
    ALREADY_EXISTS = 0x0004,

    /**
     * @brief Permission denied.
     * Enum to denote that the user do not have the required permission to
     * do the operation.
     */
    PERMISSION_DENIED = 0x0005,

    /**
     * @brief Unauthenticated.
     * Enum to denote that the request do not have the required credentials to
     * be authenticated.
     */
    UNAUTHENTICATED = 0x0006,

    /**
     * @brief Out of range.
     * Enum to denote that the request, or current operation is accessing out
     * of bounds.
     */
    OUT_OF_RANGE = 0x0007,

    /**
     * @brief Deadline exceeded.
     * Enum to denote that the operation has exceeded its designated timeline.
     */
    DEADLINE_EXCEEDED = 0x0008,

    /**
     * @brief Resource exhausted.
     * Enum to denote that the operation has exhausted all the resoures that were
     * allocated to it.
     */
    RESOURCE_EXHAUSTED = 0x0009,

    /**
     * @brief Failed precondition.
     * Enum to denote that the operation failed the precondition, even before it was
     * started.
     */
    FAILED_PRECONDITION = 0x000A,

    /**
     * @brief Aborted.
     * Enum to denote that the operation was aborted due to some conditions.
     */
    ABORT = 0x000B,

    /**
     * @brief Unimplemented.
     * Enum to denote that the operation has not been implemented yet.
     */
    UNIMPLEMENTED = 0x000C,

    /**
     * @brief Internal.
     * Enum to denote that the operation can not complete due to an internal
     * error.
     */
    INTERNAL = 0x000D,

    /**
     * @brief Unavailable.
     * Enum to denote that the operation is currently unavailable.
     */
    UNAVAILABLE = 0x000E,

    /**
     * @brief Data loss.
     * Enum to denote that the operation has undergone an unrecoverable
     * data loss, or corruption.
     */
    DATA_LOSS = 0x000F,

    /**
     * @brief Unknown status code.
     * Enum to denote that the status code is unknown.
     */
    UNKNOWN = 0xFFFF

}; // enum class StatusCode

/**
 * @brief Function to convert StatusCode to string.
 * This function uses direct lookup up to convert the given
 * StatusCode to string.
 *
 * @param code The given StatusCode.
 *
 * @returns The corresponding string.
 */
MYSTIC_NODISCARD MYSTIC_FORCEINLINE
::mystic::string to_string(const StatusCode& code) noexcept {
    switch(code) {
        case StatusCode::OK:
            return "OK";
        case StatusCode::CANCELLED:
            return "CANCELLED";
        case StatusCode::INVALID_ARGUMENT:
            return "INVALID ARGUMENT";
        case StatusCode::NOT_FOUND:
            return "NOT FOUND";
        case StatusCode::ALREADY_EXISTS:
            return "ALREADY EXISTS";
        case StatusCode::PERMISSION_DENIED:
            return "PERMISSION DENIED";
        case StatusCode::UNAUTHENTICATED:
            return "UNAUTHENTICATED";
        case StatusCode::OUT_OF_RANGE:
            return "OUT OF RANGE";
        case StatusCode::DEADLINE_EXCEEDED:
            return "DEADLINE EXCEEDED";
        case StatusCode::RESOURCE_EXHAUSTED:
            return "RESOURCE EXHAUSTED";
        case StatusCode::FAILED_PRECONDITION:
            return "FAILED PRECONDITION";
        case StatusCode::ABORT:
            return "ABORT";
        case StatusCode::UNIMPLEMENTED:
            return "UNIMPLEMENTED";
        case StatusCode::INTERNAL:
            return "INTERNAL";
        case StatusCode::UNAVAILABLE:
            return "UNAVAILABLE";
        case StatusCode::DATA_LOSS:
            return "DATA LOSS";
        case StatusCode::UNKNOWN:
            return "UNKNOWN";
        default:
            ::mystic::unreachable();
    }
}

/**
 * @brief Function to convert string to StatusCode.
 *
 * This function uses direct lookup up to convert the given
 * string to StatusCode.
 *
 * @param str The given string.
 *
 * @returns The corresponding StatusCode.
 *
 * @note
 * When unknown string is given, it defaults to `StatusCode::OK`.
 */
MYSTIC_NODISCARD MYSTIC_FORCEINLINE
StatusCode from_string(const ::mystic::string& str) noexcept {

    // Convert to uppercase for case-agnostic comparision.
    ::mystic::string str_upper = ::mystic::string_utils::to_uppercase(str);

    if (str_upper == "OK") {
        return StatusCode::OK;
    } else if (str_upper == "CANCELLED") {
        return StatusCode::CANCELLED;
    } else if (str_upper == "INVALID ARGUMENT") {
        return StatusCode::INVALID_ARGUMENT;
    } else if (str_upper == "NOT FOUND") {
        return StatusCode::NOT_FOUND;
    } else if (str_upper == "ALREADY EXISTS") {
        return StatusCode::ALREADY_EXISTS;
    } else if (str_upper == "PERMISSION DENIED") {
        return StatusCode::PERMISSION_DENIED;
    } else if (str_upper == "UNAUTHENTICATED") {
        return StatusCode::UNAUTHENTICATED;
    } else if (str_upper == "OUT OF RANGE") {
        return StatusCode::OUT_OF_RANGE;
    } else if (str_upper == "DEADLINE EXCEEDED") {
        return StatusCode::DEADLINE_EXCEEDED;
    } else if (str_upper == "RESOURCE EXHAUSTED") {
        return StatusCode::RESOURCE_EXHAUSTED;
    } else if (str_upper == "FAILED PRECONDITION") {
        return StatusCode::FAILED_PRECONDITION;
    } else if (str_upper == "ABORT") {
        return StatusCode::ABORT;
    } else if (str_upper == "UNIMPLEMENTED") {
        return StatusCode::UNIMPLEMENTED;
    } else if (str_upper == "INTERNAL") {
        return StatusCode::INTERNAL;
    } else if (str_upper == "UNAVAILABLE") {
        return StatusCode::UNAVAILABLE;
    } else if (str_upper == "DATA LOSS") {
        return StatusCode::DATA_LOSS;
    } else {
        return StatusCode::UNKNOWN;
    }
}

} // namespace status
} // namespace mystic


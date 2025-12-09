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
 * @file status_internal.hpp
 * @brief Status class internal details.
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <atomic>
#include <memory>
#include <string_view>
#include <utility>

#include "mystic/attributes/attributes.hpp"
#include "mystic/types/standard_int.hpp"

namespace mystic::status {

/// Forward declaration of StatusCode and Status
enum class StatusCode : mystic::types::uint16_t;

} // namespace mystic:status


/**
 * @namespace mystic::status::internal
 * @brief Internal implementation details of Status.
 *
 * @details
 * This namespace contains internal implementation details of Status handling.
 * **It should not be used directly.**
 */
namespace mystic::status::internal {

/**
 * @brief Internal status representation.
 */
class StatusRep {
public:
    /**
     * @brief Constructor.
     * This function increments the ref counter by one.
     */
    StatusRep(mystic::status::StatusCode code, std::string_view message)
        : ref_(mystic::types::int32_t{1}),
          code_(code),
          message_(message) {}

    /**
     * @brief Returns status code.
     */
    mystic::status::StatusCode code() const { return code_; }

    /**
     * @brief Returns status message.
     */
    std::string_view message() const { return message_; }

    /**
     * @brief Function to increment ref counter.
     */
    void incrementRef() const;
    void decrementRef() const;

    /**
     * @brief To string conversion.
     */
    std::string_view toString() const;

    /**
     * @brief Equality operators.
     */
    bool operator==(const StatusRep& other) const;
    bool operator!=(const StatusRep& other) const;

    StatusRep* MYSTIC_NONULL cloneAndDecrementRef() const;

private:
    /// Reference counter
    mutable std::atomic<mystic::types::int32_t> ref_;

    /// Status code and message
    mystic::status::StatusCode code_;
    std::string_view message_;

}; // class StatusRep

} // namespace mystic::status::internal


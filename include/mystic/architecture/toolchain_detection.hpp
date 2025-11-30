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
 * @path [ROOT]/include/mystic/architecture/toolchain_detection.hpp
 * @file toolchain_detection.hpp
 * @brief Defines toolchain detection macros & runtime logic.
 *
 * @details
 * This header provides toolchain detection macros and runtime detection,
 * for cross toolchain portable code. There are two toolchain, GPU and HOST
 * toolchain.
 * 
 * This header file provides,   
 * 1. toolchain detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/toolchain_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_TOOLCHAIN == MYSTIC_ARCH_TOOLCHAIN_GPU)
 * // GPU-specific code
 * 
 * #else
 * // HOST-specific code
 * 
 * #endif
 * @endcode
 *
 * @author thedevmystic (Surya)
 * @copyright 2025 Suryansh Singh Apache-2.0 License
 *
 * SPDX-FileCopyrightText: 2025 Suryansh Singh
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

/* =============================================
    Toolchain Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_TOOLCHAIN_GPU
 * @brief Tag for GPU toolchain.
 */
#define MYSTIC_ARCH_TOOLCHAIN_GPU 0

/**
 * @macro MYSTIC_ARCH_TOOLCHAIN_HOST
 * @brief Tag for HOST toolchain.
 */
#define MYSTIC_ARCH_TOOLCHAIN_HOST 1

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_TOOLCHAIN
 * @brief Tag for toolchain identification.
 */
#if defined(__CUDA_ARCH__) || \
    defined(__HIP_DEVICE_COMPILE__) || \
    defined(__SYCL_DEVICE_ONLY__) /* using GPU toolchain */
/**
 * @brief Set toolchain tag to GPU.
 */
# define MYSTIC_ARCH_TOOLCHAIN MYSTIC_ARCH_TOOLCHAIN_GPU

#else /* Default to HOST */
/**
 * @brief Set toolchain to HOST.
 */
# define MYSTIC_ARCH_TOOLCHAIN MYSTIC_ARCH_TOOLCHAIN_HOST

#endif

/* =============================================
    Toolchain Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_TOOLCHAIN_NAME
 * @brief Toolchain name.
 */
#if (MYSTIC_ARCH_TOOLCHAIN == MYSTIC_ARCH_TOOLCHAIN_GPU)
/**
 * @brief Set Toolchain name to GPU.
 */
# define MYSTIC_ARCH_TOOLCHAIN_NAME "GPU"

#else
/**
 * @brief Set Toolchain name to HOST.
 */
# define MYSTIC_ARCH_TOOLCHAIN_NAME "HOST"

#endif

/* =============================================
    TOOLCHAIN Runtime Logic
   --------------------------------------------- */

/**
 * @namespace mystic
 * @brief Top level namespace.
 */
namespace mystic {

/**
 * @namespace mystic::architecture
 * @brief Contains architecture-specific runtime code.
 */
namespace architecture {

/**
 * @namespace mystic::architecture::toolchain
 * @brief Contains toolchain-specific runtime code.
 */
namespace toolchain {

/**
 * @brief Returns TOOLCHAIN name in runtime.
 */
constexpr inline const char* get_toolchain_name() {
    return MYSTIC_ARCH_TOOLCHAIN_NAME;
}

} // namespace toolchain
} // namespace architecture
} // namespace mystic


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
 * @path [ROOT]/include/mystic/architecture/gpu_detection.hpp
 * @file gpu_detection.hpp
 * @brief Defines gpu detection macros & runtime logic.
 *
 * @details
 * This header provides gpu detection macros and runtime detection,
 * for cross gpu portable code. There are many gpu out
 * of which 4 are major usage share holders, i.e., x86-64, x86, arm64, arm32.
 * 
 * This header file provides,   
 * 1. gpu detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/gpu_detection.hpp"
 * 
 * #if (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_X86_64)
 * // x86-specific code
 * 
 * #elif (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_X86)
 * // x86-specific code
 * 
 * #elif (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_ARM64)
 * // Arm64-specific code
 * 
 * #elif (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_ARM32)
 * // Arm32-specific code
 * 
 * #else
 * // If not a supported GPU
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

#include "mystic/features/use_gpu.hpp"

/* =============================================
    GPU Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_GPU_NVIDIA
 * @brief Tag for Nvidia GPU.
 */
#define MYSTIC_ARCH_GPU_NVIDIA 0

/**
 * @macro MYSTIC_ARCH_GPU_AMD
 * @brief Tag for AMD GPU.
 */
#define MYSTIC_ARCH_GPU_AMD 1

/**
 * @macro MYSTIC_ARCH_GPU_INTEL
 * @brief Tag for Intel GPU.
 */
#define MYSTIC_ARCH_GPU_INTEL 2

/**
 * @macro MYSTIC_ARCH_GPU_UNKNOWN
 * @brief Tag for unknown GPU.
 */
#define MYSTIC_ARCH_GPU_UNKNOWN 3

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_GPU
 * @brief Tag for GPU identification.
 */
#if defined(__HIP_PLATFORM_NVIDIA__) || defined(__NVCC__) || defined(__CUDACC__) /* Using Nvidia GPU */
/**
 * @breif Set GPU to Nvidia
 */
# define MYSTIC_ARCH_GPU MYSTIC_ARCH_GPU_NVIDIA

#elif defined(__HIP_PLATFORM_AMD__) || defined(__HCC__) /* Using AMD GPU */
/**
 * @breif Set GPU to AMD
 */
# define MYSTIC_ARCH_GPU MYSTIC_ARCH_GPU_AMD

#elif defined(__INTEL_LLVM_COMPILER) || defined(__INTEL_COMPILER) || defined(__SYCL_DEVICE_ONLY__)
/**
 * @breif Set GPU to INTEL
 */
# define MYSTIC_ARCH_GPU MYSTIC_ARCH_GPU_INTEL

#else /* if gpu is unknown */
/**
 * @brief Set GPU tag to UNKNOWN.
 */
#define MYSTIC_ARCH_GPU MYSTIC_ARCH_GPU_UNKNOWN

#endif // defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If GPU is unknown and MYSTIC_FEATURE_USE_GPU is defined,
 * then stop compilation.
 */
#if (defined(MYSTIC_FEATURE_USE_GPU) && \
    (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - GPU - The GPU currently being used is not supported, consider using supported gpus."

#endif

/* =============================================
    GPU Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_GPU_NAME
 * @brief GPU name.
 */
#if (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_NVIDIA)
/**
 * @brief Set GPU name to NVIDIA.
 */
# define MYSTIC_ARCH_GPU_NAME "NVIDIA"

#elif (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_AMD)
/**
 * @brief Set GPU name to AMD.
 */
# define MYSTIC_ARCH_GPU_NAME "AMD"

#elif (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_INTEL)
/**
 * @brief Set GPU name to Intel.
 */
# define MYSTIC_ARCH_GPU_NAME "Intel"

#else /* if unknown */
/**
 * @brief Set GPU name to Unknown.
 */
# define MYSTIC_ARCH_GPU_NAME "UNKNOWN"

#endif // (MYSTIC_ARCH_GPU == MYSTIC_ARCH_GPU_NVIDIA)

/* =============================================
    GPU Runtime Logic
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
 * @namespace mystic::architecture::gpu
 * @brief Contains gpu-specific runtime code.
 */
namespace gpu {

/**
 * @brief Returns GPU name in runtime.
 */
constexpr inline const char* get_gpu_name() {
    return MYSTIC_ARCH_GPU_NAME;
}

} // namespace gpu
} // namespace architecture
} // namespace mystic


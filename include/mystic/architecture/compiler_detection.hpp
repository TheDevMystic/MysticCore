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
 * @path [ROOT]/include/mystic/architecture/compiler_detection.hpp
 * @file compiler_detection.hpp
 * @brief Defines compiler detection macros & runtime logic.
 *
 * @details
 * This header provides compiler detection macros and runtime detection,
 * for cross compiler portable code. There are many compiler out
 * of which 3 are major usage share holders, i.e., ΜSVC, GCC, and Clang.
 * Two major GPU compilers are either based on LLVM/Clang (HIPCC) or
 * GCC (NVCC).
 * 
 * This header file provides,   
 * 1. Compiler detection macros.
 *
 * @code {.cpp}
 * // Example
 * #include "mystic/architecture/compiler_detection.hpp"
 * 
 * // For MSVC
 * #if (MYSTIC_ARCH_ARCH_COMPILER == MYSTIC_ARCH_ARCH_COMPILER_MSVC)
 * #define SOME_FORCEINLINE_MACRO __forceinline
 *
 * // For Clang/GCC
 * #elif (MYSTIC_ARCH_ARCH_COMPILER == MYSTIC_ARCH_ARCH_COMPILER_GCC)
 *       || (MYSTIC_ARCH_ARCH_COMPILER == MYSTIC_ARCH_ARCH_COMPILER_CLANG)
 * #define SOME_FORCEINLINE_MACRO __attribute__((always_inline))
 * 
 * // For other compilers
 * #else
 * #define SOME_FORCEINLINE_MACRO inline
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

#include "mystic/macros/stringify.hpp"

/* =============================================
    Compiler Tags
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_COMPILER_HIPCC
 * @brief Tag for HIP C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_HIPCC 0

/**
 * @macro MYSTIC_ARCH_COMPILER_NVCC
 * @brief Tag for Nvidia C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_NVCC 1

/**
 * @macro MYSTIC_ARCH_COMPILER_ICC
 * @brief Tag for Intel C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_ICC 2

/**
 * @macro MYSTIC_ARCH_COMPILER_MSVC
 * @brief Tag for Microsoft/Visual C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_MSVC 3

/**
 * @macro MYSTIC_ARCH_COMPILER_CLANG
 * @brief Tag for LLVM/Clang C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_CLANG 4

/**
 * @macro MYSTIC_ARCH_COMPILER_GCC
 * @brief Tag for GNU C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_GCC 5

/**
 * @macro MYSTIC_ARCH_COMPILER_UNKNOWN
 * @brief Tag for Unknown C++ Compiler.
 */
#define MYSTIC_ARCH_COMPILER_UNKNOWN 6

/* =============================================
    Detection Logic
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_COMPILER
 * @brief Tag for C++ compiler identification.
 */
#if defined(__HIP__) || defined(__HIPCC__) /* using HIP C++ compiler */
/**
 * @brief Set compiler tag to HIPCC.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_HIPCC

#elif defined(__NVCC__) || defined(__CUDACC__) /* using Nvidia C++ compiler */
/**
 * @brief Set compiler tag to NVCC.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_NVCC

#elif defined(__INTEL_LLVM_COMPILER) || defined(__INTEL_COMPILER)
/**
 * @brief Set compiler tag to ICC.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_ICC

#elif defined(_MSC_VER)  /* using Microsoft/Visual C++ compiler */
/**
 * @brief Set compiler tag MSVC.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_MSVC

#elif defined(__clang__) /* using LLVM/Clang C++ compiler */
/**
 * @brief Set compiler tag to Clang.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_CLANG

#elif defined(__GNUC__) /* using GNU C++ compiler */
/**
 * @brief Set compiler tag to GCC.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_GCC

#else /* if compiler is unknown */
/**
 * @brief Set compiler to unknown.
 */
# define MYSTIC_ARCH_COMPILER MYSTIC_ARCH_COMPILER_UNKNOWN

#endif // defined(__HIP__) || defined(__HIPCC__)

/* =============================================
    Guardrail
   --------------------------------------------- */

/**
 * @brief If compiler is unknown, then stop compilation.
 * Only way to restrict it is to define MYSTIC_ALLOW_UNKNOWN_COMPILER.
 */
#if (!defined(MYSTIC_ALLOW_UNKNOWN_COMPILER) && \
    (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_UNKNOWN))
/**
 * @brief Stop compilation.
 */
# error "[Mystic Framework] - Compiler - The compiler currently being used is not supported, consider using supported compilers."

#endif

/* =============================================
    Compiler Details Detection
   --------------------------------------------- */

/**
 * @macro MYSTIC_ARCH_COMPILER_NAME
 * @brief Defines compiler name as string using tags.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION
 * @brief Defines compiler version as integer.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_MAJOR
 * @brief Defines compiler major version as integer.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_MINOR
 * @brief Defines compiler minor version as integer.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_PATCH
 * @brief Defines compiler patch version as integer.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_STR
 * @brief Defines compiler version as string.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR
 * @brief Defines compiler major version as string.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR
 * @brief Defines compiler minor version as string.
 *
 * @macro MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR
 * @brief Defines compiler patch version as string.
 */
#if (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_HIPCC)
/**
 * @brief Set compiler name to HIPCC.
 */
# define MYSTIC_ARCH_COMPILER_NAME "HIPCC"

/**
 * @brief Set compiler version to Major * 10000 + Minor * 100 + 0 (As HIPCC do not have patch).
 */
# define MYSTIC_ARCH_COMPILER_VERSION \
    HIP_VERSION_MAJOR * 10000 + HIP_VERSION_MINOR * 100

/**
 * @brief Define different level of versions.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR HIP_VERSION_MAJOR
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR HIP_VERSION_MINOR
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0

/**
 * @brief String version Major.Minor
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_NVCC)
/**
 * @brief Set compiler name to NVCC.
 */
# define MYSTIC_ARCH_COMPILER_NAME "NVCC"

/**
 * @brief Set compiler version to Major * 10000 + Minor * 100 + 0 (As NVCC do not have patch).
 */
// NVCC/CUDA runtime version is typically CUDART_VERSION (Major * 1000 + Minor * 10).
# define MYSTIC_ARCH_COMPILER_VERSION CUDART_VERSION

/**
 * @brief Define different level of versions.
 */
// Deriving components from CUDART_VERSION
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR (CUDART_VERSION / 1000)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR ((CUDART_VERSION % 1000) / 10)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0

/**
 * @brief String version Major.Minor
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_ICC)
/**
 * @brief Set compiler name to ICC.
 */
# if defined(__INTEL_LLVM_COMPILER)
   // Using ICX (Clang-based Intel compiler)
#  define MYSTIC_ARCH_COMPILER_NAME "ICX (Clang-based)"
#  define MYSTIC_ARCH_COMPILER_VERSION \
        __INTEL_LLVM_COMPILER / 100 * 10000 + (__INTEL_LLVM_COMPILER % 100) * 100 + 0 // Version is usually MajorMinor
#  define MYSTIC_ARCH_COMPILER_VERSION_MAJOR (__INTEL_LLVM_COMPILER / 100)
#  define MYSTIC_ARCH_COMPILER_VERSION_MINOR (__INTEL_LLVM_COMPILER % 100)
#  define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0
# else
   // Using ICC Classic
#  define MYSTIC_ARCH_COMPILER_NAME "ICC Classic"
#  define MYSTIC_ARCH_COMPILER_VERSION __INTEL_COMPILER
#  define MYSTIC_ARCH_COMPILER_VERSION_MAJOR (__INTEL_COMPILER / 100)
#  define MYSTIC_ARCH_COMPILER_VERSION_MINOR (__INTEL_COMPILER % 100)
#  define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0
# endif // defined(__INTEL_LLVM_COMPILER)

/**
 * @brief String version Major.Minor
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_MSVC)
/**
 * @brief Set compiler name to MSVC.
 */
# define MYSTIC_ARCH_COMPILER_NAME "MSVC"

/**
 * @brief Set compiler version to Major * 10000 + Minor * 100 + Patch (from _MSC_FULL_VER).
 */
// _MSC_VER is Major * 100 + Minor.
# define MYSTIC_ARCH_COMPILER_VERSION _MSC_VER

/**
 * @brief Define different level of versions.
 */
// Deriving components from _MSC_VER (Major * 100 + Minor)
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0

/**
 * @brief String version Major.Minor
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_CLANG)
/**
 * @brief Set compiler name to Clang.
 */
# define MYSTIC_ARCH_COMPILER_NAME "CLANG"

/**
 * @brief Set compiler version to Major * 10000 + Minor * 100 + Patch.
 */
# define MYSTIC_ARCH_COMPILER_VERSION \
    __clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__

/**
 * @brief Define different level of versions.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR __clang_major__
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR __clang_minor__
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH __clang_patchlevel__

/**
 * @brief String version Major.Minor.Patch
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#elif (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_GCC)
/**
 * @brief Set compiler name to GCC.
 */
# define MYSTIC_ARCH_COMPILER_NAME "GCC"

/**
 * @brief Set compiler version to Major * 10000 + Minor * 100 + Patch.
 */
# define MYSTIC_ARCH_COMPILER_VERSION \
    __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__

/**
 * @brief Define different level of versions.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR __GNUC__
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR __GNUC_MINOR__
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__

/**
 * @brief String version Major.Minor.Patch
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR \
    MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR) "." MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MAJOR)
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_MINOR)
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR MYSTIC_ARCH_STRINGIFY(MYSTIC_ARCH_COMPILER_VERSION_PATCH)

#else /* if unknown */
/**
 * @brief Set compiler name to UNKNOWN.
 */
# define MYSTIC_ARCH_COMPILER_NAME "UNKNOWN"

/**
 * @brief Set compiler version to 0.
 */
# define MYSTIC_ARCH_COMPILER_VERSION 0

/**
 * @brief Define different level of versions as 0.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR 0
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR 0
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH 0

/**
 * @brief String version UNKNOWN.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_STR "0.0.0"

/**
 * @brief Levels of version in string.
 */
# define MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR "0"
# define MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR "0"
# define MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR "0"

#endif // (MYSTIC_ARCH_COMPILER == MYSTIC_ARCH_COMPILER_HIPCC)

/* =============================================
    Compiler Runtime Logic
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
 * @namespace mystic::architecture::compiler
 * @brief Contains compiler-specific runtime code.
 */
namespace compiler {

/**
 * @brief Returns compiler name in runtime.
 */
constexpr inline const char* get_compiler_name() {
    return MYSTIC_ARCH_COMPILER_NAME;
}

/**
 * @brief Returns compiler version in runtime.
 */
constexpr inline const char* get_compiler_version() {
    return MYSTIC_ARCH_COMPILER_VERSION_STR;
}

/**
 * @brief Returns compiler major version in runtime.
 */
constexpr inline const char* get_compiler_version_major() {
    return MYSTIC_ARCH_COMPILER_VERSION_MAJOR_STR;
}

/**
 * @brief Returns compiler minor version in runtime.
 */
constexpr inline const char* get_compiler_version_minor() {
    return MYSTIC_ARCH_COMPILER_VERSION_MINOR_STR;
}

/**
 * @brief Returns compiler patch version in runtime.
 */
constexpr inline const char* get_compiler_version_patch() {
    return MYSTIC_ARCH_COMPILER_VERSION_PATCH_STR;
}

} // namespace compiler
} // namespace architecture
} // namespace mystic


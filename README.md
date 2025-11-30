# [MysticCore](https://mystic-dev.eu.org/projects/mystic-tools/mystic-core)

## Minimal Foundation Utilities for the Mystic Toolset
**MysticCore** is the foundational, lightweight library that provides core, utilities, platform abstractions, and essential data types used across Mystic Toolset (Like MysticLogger, MysticProfiler, etc).

Its primary goal is to ensure consistency, thread-safety, and maximum portability for high-performance utility development, while keeping its dependency footprint absolutely minimal.

---

## Key Features and Scope
| Catagory | Description |
| :---: | :--- |
| Core Types | Provides platform-agnostic type definitions (e.g., fixed-width integers, specific pointer types) and foundational, high-performance string views. |
| Platform Abstraction | Wraps OS-specific code (Windows, Linux, macOS) for system utilities, ensuring that high lecel tools remain cross-platform clean. |
| Time & Clock | A unified, high-resolution clock interface for querying time stamps, essential for accurate profiling, logging and benchmarking. |
| Concurrency Primitives | Low-level, efficient wrappers for common synchronization objects (e.g., mutexes, spinlocks) where standard library solutions may introduce undesired overhead. |
| Error Handling | Defines status classes, and codes, as we don't exceptions. A unified assertion/dignostic system used across the entire Mystic ecosystem. |

---

## Pre-requisite
1. **C++ Compiler**: A standard C++ compiler (MSVC, Clang or GCC).
2. **CMake**: CMake Version 3.20+.

---

## Building Library
1. **Clone the repository**:
```bash
git clone https://github.com/thedevmystic/MysticCore.git
cd MysticCore
```

2. **Generate build files**:
```bash
cmake -S . -B Build -G "[YOUR BUILD SYSTEM]"
```

3. **Build the library**:
```bash
cmake --build Build
```

After completion static and dynamic library artifacts will be in build directory.
For static (all OSes)
1. MysticCore.a   (static)

For dynamic (OS-specific)
1. MysticCore.dll   (dynamic windows)
2. MysticCore.so    (dynamic linux)
3. MysticCore.dylib (dynamic macOS)

---

## License
This project is licensed under the MIT license - See the `LICENSE` file for details.

*Signing off, thedevmystic*

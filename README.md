# Modern C++ Smart Pointer & Matrix Library (MatrixLib)

A modern **C++20 learning project** designed to demonstrate safe dynamic memory management, RAII (Resource Acquisition Is Initialization), smart pointers, and zero overhead abstractions built using CMake.

> **Note:** This repository is built as an educational step by step project to master modern C++ concepts like `std::unique_ptr`, move semantics (`std::move`), and safe buffer allocations without manual `delete[]` calls.

---

## Key Concepts Learned & Covered

* **Smart Pointers:** Managing dynamic heap memory safely using `std::unique_ptr<double[]>`.
* **RAII:** Tying heap resources to object scopes to prevent memory leaks automatically.
* **Contiguous Memory Layout:** Mapping 2D matrix indices `(row, col)` onto a flat 1D allocation for cache performance.
* **Modern Build Systems:** Using CMake to configure cross-platform target builds.

---

## Project Structure

```text
matrix_lib/
├── CMakeLists.txt     # CMake configuration file
├── include/
│   └── Matrix.hpp     # Matrix class declaration
└── src/
    ├── Matrix.cpp     # Matrix class implementation
    └── main.cpp       # Test driver application

## Prerequisites

Before building and running the project, ensure you have the following installed on your system:

- **C++ Compiler** with C++20 support:
  - **Linux**: GCC 10+ or Clang 10+
  - **macOS**: Apple Clang 12+ (via Xcode Command Line Tools)
  - **Windows**: MSVC 2019+ (Visual Studio) or MinGW-w64
- **CMake**: Version 3.14 or higher
- **Make** or **Ninja** (Linux/macOS)

---

## Project Structure

```text
.
├── CMakeLists.txt
├── include/
│   └── Matrix.h       # (Header files)
└── src/
    ├── Matrix.cpp     # Matrix class implementation
    └── main.cpp       # Main entry point
```

---

## How to Build and Run

### 1. Linux & macOS (Terminal)

Open a terminal in the root directory of the project and execute the following commands:

```bash
# 1. Create and navigate into a build directory
mkdir -p build && cd build

# 2. Generate build files with CMake
cmake ..

# 3. Compile the project
cmake --build .

# 4. Run the executable
./matrix_app
```

---

### 2. Windows (Command Prompt / PowerShell)

#### Using MSVC (Visual Studio):
```cmd
# 1. Create and enter build directory
mkdir build
cd build

# 2. Generate Visual Studio project files
cmake ..

# 3. Compile in Release or Debug mode
cmake --build . --config Release

# 4. Run the executable
.\Release\matrix_app.exe
```

#### Using MinGW:
```powershell
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
.\matrix_app.exe
```

---

### 3. VS Code Quick Start (Cross-Platform)

1. Install the **CMake Tools** extension in VS Code.
2. Open the project folder in VS Code.
3. Select your C++20 compatible compiler kit when prompted.
4. Click **Build** on the status bar (or press `F7`).
5. Click **Run** on the status bar (or press `Shift + F5`).

---

## Cleaning Build Files

If you need to rebuild the project from scratch, simply remove the `build` directory:

- **Linux / macOS**: `rm -rf build`
- **Windows**: `rmdir /s /q build`
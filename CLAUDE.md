# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A learning project for [pybind11](https://pybind11.readthedocs.io/). Exposes C++ classes to Python via compiled extension modules. Requires Python >= 3.12, CMake, and MSVC (Windows).

## Build

```powershell
# First time — builds the C++ extension and installs it into the venv
pip install -e .

# After changing any C++ file, rebuild
pip install -e . --no-build-isolation
```

`scikit-build-core` is the build backend: it invokes CMake, which calls `pybind11_add_module()`, producing `learn_pybind11.pyd` (Windows) that Python can import.

## Run the example

```powershell
python example.py
```

## Architecture

```
src/stateful_multiplier.hpp   # Pure C++ class — no pybind11 dependency
src/bindings.cpp              # The glue: registers C++ types with Python via PYBIND11_MODULE
CMakeLists.txt                # Builds src/bindings.cpp into learn_pybind11.pyd
pyproject.toml                # Declares scikit-build-core as build backend
example.py                    # Python usage of the compiled module
```

### The binding pattern

Every new C++ class needs two things:
1. A header/source with the pure C++ implementation (no pybind11 headers needed there).
2. A `.def(...)` chain inside `PYBIND11_MODULE` in `bindings.cpp` (or a new `*_bindings.cpp` added to `CMakeLists.txt`).

Type conversion (C++ `double` ↔ Python `float`, `std::string` ↔ `str`, etc.) is automatic for primitive types. Complex types (STL containers, NumPy arrays) need additional pybind11 headers (`pybind11/stl.h`, `pybind11/numpy.h`).

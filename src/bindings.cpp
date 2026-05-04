#include <pybind11/pybind11.h>
#include "stateful_multiplier.hpp"

namespace py = pybind11;

// PYBIND11_MODULE(module_name, m) is a macro that defines the C entry point Python
// calls when you do `import simple_pybind11_multiplier_test`. The first arg becomes the .pyd/.so
// filename; it must match exactly. `m` is a py::module_ handle — you register
// everything (classes, functions, constants) on it.
PYBIND11_MODULE(simple_pybind11_multiplier_test, m) {

    // py::class_<CppType>(m, "PythonName") creates a Python class that wraps CppType.
    // The object lives in C++ memory; Python holds a reference-counted handle to it.
    py::class_<StatefulMultiplier>(m, "StatefulMultiplier")

        // py::init<ArgTypes...>() binds a constructor.
        // Python: StatefulMultiplier(2.0)  →  calls StatefulMultiplier(double) in C++.
        // pybind11 converts the Python float to double automatically.
        .def(py::init<double>())

        // .def("python_name", &CppClass::method) binds a member function.
        // pybind11 reads the C++ signature and handles argument/return conversion.
        .def("set_internal_state", &StatefulMultiplier::set_internal_state)
        .def("multiply_by_internal_state", &StatefulMultiplier::multiply_by_internal_state);
}

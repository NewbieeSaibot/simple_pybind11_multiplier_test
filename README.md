# simple_pybind11_multiplier_test

A minimal example of a C++ class exposed to Python via [pybind11](https://pybind11.readthedocs.io/).

## Install

```bash
pip install simple_pybind11_multiplier_test
```

No compiler required — pre-built wheels are available for Windows, Linux, and macOS.

## Usage

```python
import simple_pybind11_multiplier_test

m = simple_pybind11_multiplier_test.StatefulMultiplier(2.0)

print(m.multiply_by_internal_state(3.0))  # 6.0  — state is now 6.0
print(m.multiply_by_internal_state(2.0))  # 12.0 — state is now 12.0

m.set_internal_state(1.0)
print(m.multiply_by_internal_state(5.0))  # 5.0
```

## API

### `StatefulMultiplier(initial_state: float)`
Constructs a multiplier with the given initial internal state.

### `set_internal_state(value: float) -> None`
Replaces the internal state with `value`.

### `multiply_by_internal_state(value: float) -> float`
Multiplies `value` by the internal state, updates the internal state to the result, and returns it.

import simple_pybind11_multiplier_test

m = simple_pybind11_multiplier_test.StatefulMultiplier(2.0)

print(m.multiply_by_internal_state(3.0))   # 6.0   — internal_state is now 6.0
print(m.multiply_by_internal_state(2.0))   # 12.0  — internal_state is now 12.0

m.set_internal_state(1.0)
print(m.multiply_by_internal_state(5.0))   # 5.0   — reset to 1.0, then × 5

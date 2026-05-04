#pragma once

class StatefulMultiplier {
public:
    explicit StatefulMultiplier(double initial_state) : internal_state(initial_state) {}

    void set_internal_state(double value) {
        internal_state = value;
    }

    double multiply_by_internal_state(double value) {
        internal_state *= value;
        return internal_state;
    }

private:
    double internal_state;
};

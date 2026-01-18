#ifndef INPUT_H
#define INPUT_H

enum InputType { LEFT, RIGHT, X, Y };

struct Input {
    InputType type;
    float time;
};

struct ComboBuffer {
    Input inputs[10];
    int count = 0;
};

inline void pushInput(ComboBuffer* combo, InputType type, float time) {
    if (combo->count < 10) {
        combo->inputs[combo->count++] = {type, time};
    }
}

#endif

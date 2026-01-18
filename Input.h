#pragma once

#include <SDL2/SDL.h>

enum InputType { NONE, LEFT, RIGHT, UP, DOWN, X, Y };

struct ComboBuffer {
    InputType inputs[10]; // maks 10 ostatnich komend
    float timestamps[10];
    int count;

    void clear() { count = 0; }
};

void pushInput(ComboBuffer* buffer, InputType input, float time);
InputType getLastInput(const ComboBuffer* buffer);

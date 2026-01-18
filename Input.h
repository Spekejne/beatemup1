#pragma once

enum InputType { NONE, UP, DOWN, LEFT, RIGHT, X, Y };

struct ComboBuffer {
    InputType inputs[10];
    float times[10];
    int count;
};

void pushInput(ComboBuffer* buffer, InputType input, float deltaTime);
void handleInput(class Player* player, SDL_Event& e);

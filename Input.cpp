#include "Input.h"
#include "Player.h"

void pushInput(ComboBuffer* buffer, InputType input, float deltaTime) {
    if (buffer->count < 10) {
        buffer->inputs[buffer->count] = input;
        buffer->times[buffer->count] = deltaTime;
        buffer->count++;
    }
}

void handleInput(Player* player, SDL_Event& e) {
    static ComboBuffer buffer = {{}, {}, 0};
    float dt = 0.016f; // zakładamy 60FPS
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: pushInput(&buffer, UP, dt); break;
            case SDLK_DOWN: pushInput(&buffer, DOWN, dt); break;
            case SDLK_LEFT: pushInput(&buffer, LEFT, dt); break;
            case SDLK_RIGHT: pushInput(&buffer, RIGHT, dt); break;
            case SDLK_x: pushInput(&buffer, X, dt); break;
            case SDLK_y: pushInput(&buffer, Y, dt); break;
        }
    }
    player->processCombo(buffer);
}

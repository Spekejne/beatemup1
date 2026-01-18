#pragma once
#include <SDL2/SDL.h>
#include "Input.h"

class Player {
public:
    Player();
    void init(SDL_Renderer* renderer);
    void update(float dt);
    void render(SDL_Renderer* renderer);
    void processCombo(const ComboBuffer& buffer);

    int x, y;
    int health;
private:
    SDL_Texture* spriteIdle;
    SDL_Texture* spriteWalk;
    SDL_Texture* spriteAttackLight;
    SDL_Texture* spriteAttackHeavy;

    float speed;
};

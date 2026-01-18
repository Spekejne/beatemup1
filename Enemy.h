#pragma once
#include <SDL2/SDL.h>
#include "Player.h"

class Enemy {
public:
    Enemy();
    void init(SDL_Renderer* renderer, int type, int startX, int startY);
    void update(float dt, const Player& player);
    void render(SDL_Renderer* renderer);

    int x, y;
    int health;

private:
    int type;
    SDL_Texture* spriteIdle;
    SDL_Texture* spriteAttack;
};

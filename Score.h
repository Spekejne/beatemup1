#pragma once

#include "Player.h"
#include "Enemy.h"

class Score {
public:
    Score();
    void init();
    void update(const Player& player, Enemy* enemies, int enemyCount);
    void render(SDL_Renderer* renderer, SDL_Renderer* r);

private:
    int points;
};

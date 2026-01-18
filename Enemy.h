#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "Player.h"

enum EnemyType { Aggressive, Ranged };

class Enemy {
public:
    Enemy(int x, int y, EnemyType type);
    void update(float dt, Player& player);
    void render(SDL_Renderer* renderer);
    int getDamage();
    void stun();

private:
    int x, y;
    EnemyType type;
    bool stunned;
};

#endif

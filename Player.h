#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Input.h"
#include "Enemy.h"

class Player {
public:
    void init(SDL_Renderer* renderer);
    void update(float dt);
    void render(SDL_Renderer* renderer);
    void processCombo(const ComboBuffer& combo);

    bool checkHit(const Enemy& enemy);
    void onHit(int damage);

    void moveLeft(float dt);
    void moveRight(float dt);
    void jump(float dt);
    void crouch(float dt);

private:
    int x, y;
    int health;
};

#endif

#include "Enemy.h"
#include <SDL2/SDL_image.h>

Enemy::Enemy() : x(0), y(0), health(50), type(1),
                 spriteIdle(nullptr), spriteAttack(nullptr) {}

void Enemy::init(SDL_Renderer* renderer, int t, int startX, int startY) {
    type = t;
    x = startX;
    y = startY;
    health = 50;

    SDL_Surface* surf = SDL_LoadBMP(type == 1 ? "assets/enemy1_idle.bmp" : "assets/enemy2_idle.bmp");
    spriteIdle = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP(type == 1 ? "assets/enemy1_attack.bmp" : "assets/enemy2_attack.bmp");
    spriteAttack = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
}

void Enemy::update(float dt, const Player& player) {
    // prosty AI
    if (type == 1) { // agresywny
        if (player.x < x) x -= int(100 * dt);
        else x += int(100 * dt);
    } else if (type == 2) { // dystansowy
        if (player.x > x) x += int(150 * dt);
        else x -= int(150 * dt);
    }
}

void Enemy::render(SDL_Renderer* renderer) {
    SDL_Rect dst = { x, y, 64, 64 };
    SDL_RenderCopy(renderer, spriteIdle, NULL, &dst);
}

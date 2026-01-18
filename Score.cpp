#include "Score.h"

Score::Score() : points(0) {}

void Score::init() { points = 0; }

void Score::update(const Player& player, Enemy* enemies, int enemyCount) {
    // np. za trafienie przeciwnika
}

void Score::render(SDL_Renderer* renderer, SDL_Renderer* r) {
    // prosty pasek/tekst
}

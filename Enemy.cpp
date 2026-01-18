#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(int x_, int y_, EnemyType type_) : x(x_), y(y_), type(type_), stunned(false) {}

void Enemy::update(float dt, Player& player) {}

void Enemy::render(SDL_Renderer* renderer) {}

int Enemy::getDamage() { return 10; }

void Enemy::stun() { stunned = true; }

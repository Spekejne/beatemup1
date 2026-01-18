#include "Player.h"

void Player::init(SDL_Renderer* renderer) {
    x = 100; y = 300;
    health = 100;
}

void Player::update(float dt) {}

void Player::render(SDL_Renderer* renderer) {}

void Player::processCombo(const ComboBuffer& combo) {}

bool Player::checkHit(const Enemy& enemy) { return false; }

void Player::onHit(int damage) { health -= damage; }

void Player::moveLeft(float dt) { x -= int(200*dt); }
void Player::moveRight(float dt) { x += int(200*dt); }
void Player::jump(float dt) {}
void Player::crouch(float dt) {}

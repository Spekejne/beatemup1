#include "Player.h"
#include <SDL2/SDL_image.h>

Player::Player() : x(100), y(400), health(100), speed(200),
                   spriteIdle(nullptr), spriteWalk(nullptr),
                   spriteAttackLight(nullptr), spriteAttackHeavy(nullptr) {}

void Player::init(SDL_Renderer* renderer) {
    SDL_Surface* surf = SDL_LoadBMP("assets/player_idle.bmp");
    spriteIdle = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("assets/player_walk.bmp");
    spriteWalk = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("assets/player_attack_light.bmp");
    spriteAttackLight = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    surf = SDL_LoadBMP("assets/player_attack_heavy.bmp");
    spriteAttackHeavy = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
}

void Player::update(float dt) {
    // przykładowe poruszanie
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_LEFT]) x -= int(speed * dt);
    if (keystates[SDL_SCANCODE_RIGHT]) x += int(speed * dt);
}

void Player::render(SDL_Renderer* renderer) {
    SDL_Rect dst = { x, y, 64, 64 };
    SDL_RenderCopy(renderer, spriteIdle, NULL, &dst);
}

void Player::processCombo(const ComboBuffer& buffer) {
    // minimalna implementacja combo
    for (int i = 0; i < buffer.count; ++i) {
        if (buffer.inputs[i] == X) {
            // lekki atak
        } else if (buffer.inputs[i] == Y) {
            // ciężki atak
        }
    }
}

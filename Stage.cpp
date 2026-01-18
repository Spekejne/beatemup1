#include "Stage.h"
#include <SDL2/SDL_image.h>

Stage::Stage() : background(nullptr) {}

void Stage::init(SDL_Renderer* renderer) {
    SDL_Surface* surf = SDL_LoadBMP("assets/background.bmp");
    background = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
}

void Stage::update(float dt) {
    // np. animacja tła
}

void Stage::render(SDL_Renderer* renderer) {
    SDL_Rect dst = { 0, 0, 800, 600 };
    SDL_RenderCopy(renderer, background, NULL, &dst);
}

#include "Menu.h"
#include <SDL2/SDL_image.h>

Menu::Menu() : menuBg(nullptr) {}

void Menu::init(SDL_Renderer* renderer) {
    SDL_Surface* surf = SDL_LoadBMP("assets/stage.bmp");
    menuBg = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
}

void Menu::render(SDL_Renderer* renderer) {
    SDL_Rect dst = { 0, 0, 800, 600 };
    SDL_RenderCopy(renderer, menuBg, NULL, &dst);
}

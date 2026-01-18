#pragma once
#include <SDL2/SDL.h>

class Menu {
public:
    Menu();
    void init(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
private:
    SDL_Texture* menuBg;
};

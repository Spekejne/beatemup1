#pragma once
#include <SDL2/SDL.h>

class Stage {
public:
    Stage();
    void init(SDL_Renderer* renderer);
    void update(float dt);
    void render(SDL_Renderer* renderer);

private:
    SDL_Texture* background;
};

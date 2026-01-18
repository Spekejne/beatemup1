#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    Game game;

    Uint32 lastTime = SDL_GetTicks();
    while (game.isRunning()) {
        Uint32 current = SDL_GetTicks();
        float dt = (current - lastTime) / 1000.0f;
        lastTime = current;

        game.handleEvents();
        game.handleInput(dt);
        game.update(dt);
        game.render();

        SDL_Delay(16); // ~60 FPS
    }

    SDL_Quit();
    return 0;
}

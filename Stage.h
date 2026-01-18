#ifndef STAGE_H
#define STAGE_H

#include <SDL2/SDL.h>
#include "Player.h"

class Stage {
public:
    void loadStage(const char* filename);
    void render(SDL_Renderer* renderer);
    bool isComplete(const Player& player);
};

#endif

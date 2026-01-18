#pragma once
#include <SDL2/SDL.h>
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"
#include "Menu.h"
#include "Input.h"
#include "Score.h"
#include "Config.h"

class Game {
public:
    void handleEvents();
    void handleInput(float dt);
    void handleInputEvent(SDL_Event& e);
    Game();
    ~Game();
    bool init();
    void run();
    void cleanup();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    Player player;
    Enemy* enemies;    // dynamiczna tablica przeciwników
    int enemyCount;
    Stage stage;
    Menu menu;
    Score score;
    Config config;

    void update(float dt);
    void render();
    void loadStage(const char* filename);
};



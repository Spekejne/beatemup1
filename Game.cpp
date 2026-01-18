#include "Game.h"
#include <SDL2/SDL_timer.h>
#include <fstream>

Game::Game() : window(nullptr), renderer(nullptr), running(false),
               enemies(nullptr), enemyCount(0) {}

Game::~Game() {}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        SDL_Log("Unable to init SDL: %s", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow("BeatEmUp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;

    player.init(renderer);
    stage.init(renderer);
    menu.init(renderer);
    score.init();

    loadStage("stages/stage1.cfg"); // przykładowy etap

    return true;
}

void Game::loadStage(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    file >> enemyCount;
    enemies = new Enemy[enemyCount];
    for (int i = 0; i < enemyCount; ++i) {
        int type, x, y;
        file >> type >> x >> y;
        enemies[i].init(renderer, type, x, y);
    }
    file.close();
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();
    while (running) {
        Uint32 current = SDL_GetTicks();
        float dt = (current - lastTime) / 1000.0f;
        lastTime = current;

        handleEvents();
        update(dt);
        render();
        SDL_Delay(16);
    }
}

void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) running = false;
        handleInput(e);
    }

  player.processCombo(combo);
}

void Game::handleInput(float dt) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){

        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_LEFT]) pushInput(&combo, LEFT, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_RIGHT]) pushInput(&combo, RIGHT, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_X]) pushInput(&combo, X, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_Y]) pushInput(&combo, Y, SDL_GetTicks()/1000.0f);
      }
    }
    player.processCombo(combo);
}


void Game::update(float dt) {
    player.update(dt);
    for (int i = 0; i < enemyCount; ++i) enemies[i].update(dt, player);
    stage.update(dt);
    score.update(player, enemies, enemyCount);
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    stage.render(renderer);
    player.render(renderer);
    for (int i = 0; i < enemyCount; ++i) enemies[i].render(renderer);
    score.render(renderer, renderer);
    menu.render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::cleanup() {
    delete[] enemies;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




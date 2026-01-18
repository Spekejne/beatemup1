#include "Game.h"
#include <iostream>
#include <SDL2/SDL_image.h>


Game::Game() : window(nullptr), renderer(nullptr), running(false) {}

Game::~Game() { cleanup(); }

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;
    window = SDL_CreateWindow("BeatEmUp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window || !renderer) return false;

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) return false;

    stage.loadStage("stage1.txt");
    player.init(renderer);

    enemies.push_back(Enemy(400, 300, Aggressive));
    enemies.push_back(Enemy(600, 300, Ranged));

    running = true;
    return true;
}

void Game::run() {
    Uint32 lastTime = SDL_GetTicks();
    while (running) {
        Uint32 current = SDL_GetTicks();
        float dt = (current - lastTime) / 1000.0f;
        lastTime = current;

        handleEvents();
        handleInput(dt);

        player.update(dt);
        for (auto &enemy : enemies) enemy.update(dt, player);

        // kolizje
        for (auto &enemy : enemies) {
            if (player.checkHit(enemy)) {
                player.onHit(enemy.getDamage());
                enemy.stun();
            }
        }

        stage.render(renderer);
        player.render(renderer);
        for (auto &enemy : enemies) enemy.render(renderer);

        SDL_RenderPresent(renderer);
    }
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) running = false;
    }
}

void Game::handleInput(float dt) {
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT]) pushInput(&combo, LEFT, SDL_GetTicks()/1000.0f);
    if (state[SDL_SCANCODE_RIGHT]) pushInput(&combo, RIGHT, SDL_GetTicks()/1000.0f);
    if (state[SDL_SCANCODE_X]) pushInput(&combo, X, SDL_GetTicks()/1000.0f);
    if (state[SDL_SCANCODE_Y]) pushInput(&combo, Y, SDL_GetTicks()/1000.0f);

    player.processCombo(combo);

    if (state[SDL_SCANCODE_A]) player.moveLeft(dt);
    if (state[SDL_SCANCODE_D]) player.moveRight(dt);
    if (state[SDL_SCANCODE_W]) player.jump(dt);
    if (state[SDL_SCANCODE_S]) player.crouch(dt);
}


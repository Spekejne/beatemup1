#include "Game.h"
#include <SDL2/SDL_image.h>
#include <iostream>

// ----------------- Konstruktor / Destruktor -----------------
Game::Game() : running(true) {
    stage.loadStage("stage1.txt");   // przykładowy plik etapu
    player.init(100, 300);           // startowa pozycja
    // tworzymy dwóch wrogów dla demo
    enemies.push_back(Enemy(400, 300, Aggressive));
    enemies.push_back(Enemy(600, 300, Ranged));
}

Game::~Game() {
    // cleanup jeśli trzeba
}

// ----------------- Obsługa eventów -----------------
void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) running = false;
        handleInputEvent(e);  // każdy event trafia do combo/input
    }

    // przetwarzamy combo po wszystkich eventach
    player.processCombo(combo);
}

// pojedynczy event
void Game::handleInputEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
        const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_LEFT])  pushInput(&combo, LEFT, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_RIGHT]) pushInput(&combo, RIGHT, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_X])     pushInput(&combo, X, SDL_GetTicks()/1000.0f);
        if (state[SDL_SCANCODE_Y])     pushInput(&combo, Y, SDL_GetTicks()/1000.0f);
    }
}

// ----------------- Ciągłe ruchy gracza -----------------
void Game::handleInput(float dt) {
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_A]) player.moveLeft(dt);
    if (state[SDL_SCANCODE_D]) player.moveRight(dt);
    if (state[SDL_SCANCODE_W]) player.jump(dt);
    if (state[SDL_SCANCODE_S]) player.crouch(dt);
}

// ----------------- Update logiki gry -----------------
void Game::update(float dt) {
    player.update(dt);

    // prosty AI dla wrogów
    for (auto& enemy : enemies) {
        enemy.update(dt, player); // wrogowie reagują na pozycję gracza
    }

    // kolizje i hitboxy
    for (auto& enemy : enemies) {
        if (player.checkHit(enemy)) {
            player.onHit(enemy.getDamage());
            enemy.stun();
        }
    }

    // sprawdzenie zakończenia etapu
    if (stage.isComplete(player)) {
        std::cout << "Stage complete!\n";
        running = false; // demo
    }
}

// ----------------- Renderowanie -----------------
void Game::render() {
    SDL_Renderer* renderer = stage.getRenderer();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    stage.render(renderer);
    player.render(renderer);

    for (auto& enemy : enemies)
        enemy.render(renderer);

    SDL_RenderPresent(renderer);
}

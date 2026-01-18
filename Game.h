#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"
#include "Input.h"

class Game {
public:
    Game();
    ~Game();

    void handleEvents();               // obsługa wszystkich eventów
    void handleInput(float dt);        // ciągłe ruchy gracza
    void handleInputEvent(SDL_Event& e); // pojedynczy event (combo)
    void update(float dt);
    void render();

    bool isRunning() const { return running; }

private:
    Player player;
    std::vector<Enemy> enemies;
    Stage stage;

    bool running;

    ComboBuffer combo;   // buffer combo dla gracza
};

#endif // GAME_H

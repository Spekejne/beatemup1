#ifndef INPUT_H
#define INPUT_H

// Typy przycisków / inputów
enum InputType { LEFT, RIGHT, X, Y };

// Pojedynczy input
struct Input {
    InputType type;
    float time;
};

// Bufor combo
struct ComboBuffer {
    Input inputs[10];
    int count = 0;
};

// Funkcja dodająca input do bufora
inline void pushInput(ComboBuffer* combo, InputType type, float time) {
    if (combo->count < 10) {
        combo->inputs[combo->count++] = {type, time};
    }
}

// Funkcja zwracająca ostatni input w buforze
inline InputType getLastInput(const ComboBuffer* combo) {
    if (combo->count == 0) return LEFT; // lub inny default
    return combo->inputs[combo->count - 1].type;
}

#endif

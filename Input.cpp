#include "Input.h"
#include <algorithm>

void pushInput(ComboBuffer* buffer, InputType input, float time) {
    if (buffer->count >= 10) { // przesuwamy starsze
        for (int i = 1; i < 10; ++i) {
            buffer->inputs[i - 1] = buffer->inputs[i];
            buffer->timestamps[i - 1] = buffer->timestamps[i];
        }
        buffer->count = 9;
    }
    buffer->inputs[buffer->count] = input;
    buffer->timestamps[buffer->count] = time;
    buffer->count++;
}

InputType getLastInput(const ComboBuffer* buffer) {
    if (buffer->count == 0) return NONE;
    return buffer->inputs[buffer->count - 1];
}

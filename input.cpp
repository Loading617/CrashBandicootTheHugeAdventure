#include <SDL2/SDL.h>

void handleInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
        // Detect key presses and map them to in-game controls
        if (e.key.keysym.sym == SDLK_LEFT) {
            // Move character left
        }
        if (e.key.keysym.sym == SDLK_RIGHT) {
            // Move character right
        }
        if (e.key.keysym.sym == SDLK_SPACE) {
            // Jump
        }
    }
}

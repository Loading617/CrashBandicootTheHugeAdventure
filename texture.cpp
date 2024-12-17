SDL_Texture* loadTexture(const char* filename) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(filename));
    return texture;
}

void renderGame(SDL_Texture* texture) {
    SDL_RenderCopy(renderer, texture, NULL, NULL); // Draw texture to screen
    SDL_RenderPresent(renderer);
}

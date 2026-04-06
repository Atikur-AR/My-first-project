#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void DrawCircle(SDL_Renderer* renderer, float centerX, float centerY, float radius) {
    
    // Logical part start;

    for (float w = -radius; w <= radius; w++) {
        for (float h = -radius; h <= radius; h++) {
            if (w * w + h * h <= radius * radius) {
                SDL_RenderPoint(renderer, centerX + w, centerY + h);
            }
        }
    }
    
    // Logical part end;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Task 101", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black Background
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red Circle
        DrawCircle(renderer, 400.0f, 300.0f, 150.0f); // Radius increased to 150

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
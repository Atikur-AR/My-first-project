#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void DrawCircle(SDL_Renderer* renderer, float centerX, float centerY, float radius) {
    for (float w = -radius; w <= radius; w++) {
        for (float h = -radius; h <= radius; h++) {
            if (w * w + h * h <= radius * radius)
                SDL_RenderPoint(renderer, centerX + w, centerY + h);
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Task 102", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    float radius = 10.0f;
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        // Logical part start;
        
        radius += 1.9f;
        if (radius >= 300.0f) {
            radius = 10.0f;
        }
        
        // Logical part end;

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
        DrawCircle(renderer, 400.0f, 300.0f, radius);

        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
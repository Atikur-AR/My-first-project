#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <math.h>

void DrawCircle(SDL_Renderer* renderer, float x, float y, float r) {
    for (float w = -r; w <= r; w++) {
        for (float h = -r; h <= r; h++) {
            if (w*w + h*h <= r*r) SDL_RenderPoint(renderer, x + w, y + h);
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Task 103: Collision", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    float x1 = 0, y1 = 300, r1 = 80; 
    float x2 = 400, y2 = 300, r2 = 80; 

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        // Logical part start;

        x1 += 1.0f; 
        if (x1 > 880) x1 = -80;

        const bool* keys = SDL_GetKeyboardState(NULL);
        float speed = 2.0f;
        if (keys[SDL_SCANCODE_UP])    y2 -= speed;
        if (keys[SDL_SCANCODE_DOWN])  y2 += speed;
        if (keys[SDL_SCANCODE_LEFT])  x2 -= speed;
        if (keys[SDL_SCANCODE_RIGHT]) x2 += speed;

        float dx = x1 - x2;
        float dy = y1 - y2;
        float distance = sqrt(dx*dx + dy*dy);
        bool collision = (distance < (r1 + r2));
       
        // Logical part end;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
        DrawCircle(renderer, x1, y1, r1);

        if (collision) SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        
        DrawCircle(renderer, x2, y2, r2);

        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
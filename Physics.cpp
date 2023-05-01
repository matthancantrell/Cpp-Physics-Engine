#include <iostream>
#include <glm/glm.hpp>
#include "Externals/SDL2/include/SDL.h"

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create SDL window
    glm::ivec2 screen{ 800, 600 };
    SDL_Window* window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screen.x,
        screen.y,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Wait for user to close window
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    // Clean up SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
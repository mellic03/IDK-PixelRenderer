#include <iostream>

#include "renderer.hpp"


int main()
{
    idk::PixelRenderer ren("window", 1000, 1000, 1000, 1000);

    auto a = SDL_GetTicks();
    auto b = SDL_GetTicks();

    while (1)
    {
        a = SDL_GetTicks();
        auto delta = a - b;

        if (delta > 1000.0/60.0)
        {
            ren.beginFrame();

            ren.frect({350, 500}, {250, 100}, {255, 255, 255});

            ren.endFrame();
            b = SDL_GetTicks();
        }
    }

    return 0;
}


#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <string>

#include "idk_vecn.hpp"


#define RES_Y 1200
#define RES_X 1200
#define WIN_X 1200
#define WIN_Y 1200


namespace idk { class PixelRenderer; };


class idk::PixelRenderer
{
private:

    int             m_res_x, m_res_y, m_win_x, m_win_y;

    SDL_Event       m_event;
    SDL_Window *    m_win;
    SDL_Renderer *  m_ren;
    SDL_Surface *   m_surface, *m_surface2, *m_surface_win_size;


public:
    PixelRenderer(std::string name, int rx, int ry, int wx, int wy);
    ~PixelRenderer();

    void pixel  (ivec2 pos, ivec3 color);
    void frect  (ivec2 pos, ivec2 size, ivec3 color);
    void srect  (ivec2 pos, ivec2 size, ivec3 color);

    void clear();
    void beginFrame();
    void endFrame();
};



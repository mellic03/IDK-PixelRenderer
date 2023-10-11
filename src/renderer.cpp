#include "renderer.hpp"



idk::PixelRenderer::PixelRenderer(std::string name, int rx, int ry, int wx, int wy)
{
    m_res_x = rx;
    m_res_y = ry;
    m_win_x = wx;
    m_win_y = wy;

    SDL_Init(SDL_INIT_VIDEO);

    m_win = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_win_x,
        m_win_y,
        0
    );


    m_surface_win_size = SDL_GetWindowSurface(m_win);
    m_surface2 = SDL_CreateRGBSurface(0, m_res_x/5, m_res_y/5, 32, 0, 0, 0, 0);
    m_surface = SDL_CreateRGBSurface(0,  m_res_x, m_res_y, 32, 0, 0, 0, 0);
}


idk::PixelRenderer::~PixelRenderer()
{
    SDL_DestroyRenderer(m_ren);
    SDL_DestroyWindow(m_win);
    SDL_Quit();
}


void
idk::PixelRenderer::beginFrame()
{
    clear();

    while(SDL_PollEvent(&m_event))
    {
        if ((m_event.type == SDL_WINDOWEVENT && m_event.window.event == SDL_WINDOWEVENT_CLOSE) ||
            (m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_ESCAPE)) 
        {
            exit(0);
        }

        if (m_event.type == SDL_MOUSEBUTTONDOWN)
        {
    
        }
    }

    SDL_PumpEvents();
}


void
idk::PixelRenderer::endFrame()
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = m_res_x;
    src.h = m_res_y;

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = m_win_x;
    dest.h = m_win_y;

    SDL_BlitScaled(m_surface, &src, m_surface_win_size, &dest);

    SDL_UpdateWindowSurface(m_win);
}


void
idk::PixelRenderer::clear()
{
  SDL_FillRect(m_surface, NULL, (Uint32)(0<<16) + (Uint16)(0<<8) + 0);
}


void
idk::PixelRenderer::pixel(ivec2 pos, ivec3 color)
{
    int x = pos.x % m_res_x;
    int y = pos.y % m_res_y;

    Uint8 *const blue  = ((Uint8 *) m_surface->pixels + (y%m_res_y)*4*m_res_x + (x%m_res_x)*4 + 0);
    *blue = color.b;

    Uint8 *const green = ((Uint8 *) m_surface->pixels + (y%m_res_y)*4*m_res_x + (x%m_res_x)*4 + 1);
    *green = color.g;

    Uint8 *const red   = ((Uint8 *) m_surface->pixels + (y%m_res_y)*4*m_res_x + (x%m_res_x)*4 + 2);
    *red = color.r;
}


void
idk::PixelRenderer::frect ( ivec2 pos, ivec2 size, ivec3 color )
{
    for (int y=pos.y; y<pos.y+size.y; y++)
    {
        for (int x=pos.x; x<pos.x+size.x; x++)
        {
            pixel({x, y}, color);
        }
    }
}


void
idk::PixelRenderer::srect ( ivec2 pos, ivec2 size, ivec3 color )
{
    for (int y=pos.y; y<pos.y+size.y; y++)
    {
        pixel({pos.x,        y}, color);
        pixel({pos.x+size.x, y}, color);
    }

    for (int x=pos.x; x<pos.x+size.x; x++)
    {
        pixel({x, pos.y,      }, color);
        pixel({x, pos.y+size.y}, color);
    }
}

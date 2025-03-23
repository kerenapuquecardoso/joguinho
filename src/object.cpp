#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Objeto.hpp"

Objeto::Objeto(float p_x, float p_y, SDL_Texture* p_texture): x(p_x), y(p_y)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}
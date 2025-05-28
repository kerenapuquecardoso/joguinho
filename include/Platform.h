#include "Object.h"
#pragma once
namespace Joguinho 
{
    class Platform : public StaticObject
    {
        public:
        Platform(const Point position, const Vector size, SDL_Texture *texture)
            : StaticObject(position, size, texture) {}
        ~Platform();
        void render(SDL_Renderer* renderer);
    };
}
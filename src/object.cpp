#include "Object.h"

namespace Joguinho
{
    Object::Object(Point position, Vector size, SDL_Texture* texture)
        : mPosition(position), mSize(size), mTexture(texture)
    {
    }
}
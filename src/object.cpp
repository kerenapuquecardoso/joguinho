#include "Object.h"

namespace Joguinho
{
    Object::Object(Point position, Vector size, SDL_Texture* texture)
        : mPosition(position), mSize(size), mTexture(texture)
    {
    }

    // void StaticObject::renderer()
    // {
    //     std::cout << "StaticObject created at position: " << mPosition << std::endl;
    // }

    void DynamicObject::renderer()
    {
        std::cout << "DynamicObject created at position: " << mPosition << std::endl;
    }
}
#include "Object.h"

namespace Joguinho
{
    Object::Object(Point position, Vector size, SDL_Texture* texture)
        : position(position), size(size), texture(texture)
    {
    }

    void StaticObject::renderer()
    {
        std::cout << "StaticObject created at position: " << position << std::endl;
    }

    void DynamicObject::renderer()
    {
        std::cout << "DynamicObject created at position: " << position << std::endl;
    }
}
#include <iostream>

#include "MathTypes.h"
#include "Object.h"
namespace Joguinho
{
    class Character : public DynamicObject
{
    public:
        Character(Point position, Vector velocity, Vector size, SDL_Texture *texture, SDL_Renderer *renderer);
        ~Character();
        void updateCharacter();

    protected:
        SDL_Renderer *renderer;
    };
}
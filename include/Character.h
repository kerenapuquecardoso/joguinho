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
        void verifyKeyboard(SDL_Event event);

    protected:
        SDL_Renderer *renderer;
        int score;
        int lives;
        bool moveToRight;
        bool moveToLeft;
    };
}
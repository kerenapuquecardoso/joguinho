#include <iostream>
#include <array>

#include "MathTypes.h"
#include "Object.h"

namespace Joguinho
{
    class Character : public DynamicObject
    {
    public:
        enum class Button
        {
            Left,
            Right,
            Up,
        };

        Character(Point position, Vector velocity, Vector size, SDL_Texture *texture, std::array<SDL_Keycode, 3> myKeys ) : 
            DynamicObject(position, size, texture, velocity),
            mMyKeys(myKeys),
            mScore(0),
            mLives(3),
            mMoveToRight(false),
            mMoveToLeft(false)
        {
        }; 
        ~Character();
        SDL_Texture* getTexture() { return mTexture; }
        void render();
        void updateCharacter();
        void verifyKeyboard(SDL_Event& event);

    protected:
        int mScore;
        int mLives;
        bool mMoveToRight;
        bool mMoveToLeft;
        std::array<SDL_Keycode, 3> mMyKeys;
    };
}
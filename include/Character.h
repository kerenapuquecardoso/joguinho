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

        Character(Vector position,
			Vector velocity,
			Vector size,
			SDL_Texture* texture,
			std::array<SDL_Keycode, 3> myKeys); 
        ~Character();
        void render();
        void updateCharacter(float deltaTime);
        void verifyKeyboard(SDL_Event& event);

    protected:
        int mScore;
        int mLives;
        bool mMoveToRight;
        bool mMoveToLeft;
        std::array<SDL_Keycode, 3> mMyKeys;
    };
}
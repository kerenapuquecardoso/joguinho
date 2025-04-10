#include <iostream>
#include <utility>

#include "Character.h"
#include "Object.h"


namespace Joguinho
{
    void Character::render()  
    {
        SDL_Rect rect = {static_cast<int>(mPosition.x), static_cast<int>(mPosition.y),
                         static_cast<int>(mSize.x), static_cast<int>(mSize.y)};
        std::cout << "RENDERIZOUUUUUU AQUI, NA position: " << mPosition.x << ", " << mPosition.y << std::endl;
    }
    void Character::updateCharacter()
    {
        if (mMoveToRight)
            mVelocity.x += 0.5f;
        if (mMoveToLeft)
            mVelocity.y -= 0.5f;
        mPosition = Vector(mVelocity.x, mVelocity.y);
    };

    void Character::verifyKeyboard(SDL_Event& event)
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == this->mMyKeys[ std::to_underlying(Button::Left) ])
            {
                mMoveToLeft = true;
                std::cout << "LEFT" << std::endl;

            }
            if (event.key.keysym.sym == this->mMyKeys[ std::to_underlying(Button::Right) ])
            {
                mMoveToRight = true;
                std::cout << "RIGHT" << std::endl;
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == this->mMyKeys[ std::to_underlying(Button::Left) ])
            {
                mMoveToLeft = false;

            }
            if (event.key.keysym.sym == this->mMyKeys[ std::to_underlying(Button::Right) ])
            {
                mMoveToRight = false;
            }
        }
    };

    Character::~Character()
    {
        std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
    }
}


#include <iostream>

#include "Character.h"

namespace Joguinho
{
    void Character::updateCharacter()
    {
        if (moveToRight)
            velocity.x += 0.5f;
        if (moveToLeft)
            velocity.y -= 0.5f;
        position = Vector(velocity.x, velocity.y);
    }

    void Character::verifyKeyboard(SDL_Event event)
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                moveToLeft = true;
            }
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                moveToRight = true;
            }
            if (event.key.keysym.sym == SDLK_a)
            {
                moveToLeft = true;
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                moveToRight = true;
            }
        }
        else if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                moveToLeft = false;
            }
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                moveToRight = false;
            }
            if (event.key.keysym.sym == SDLK_a)
            {
                moveToLeft = false;
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                moveToRight = false;
            }
        }
    }


}


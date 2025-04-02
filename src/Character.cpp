#include <iostream>

#include "Character.h"

namespace Joguinho
{
    void Character::updateCharacter()
    {
        std::cout << "StaticObject created at position: " << position.x << ", " << position.y << std::endl;
    }

}

/*
Character(Point position, Vector velocity, Vector size, SDL_Texture *texture, SDL_Renderer *renderer);
 if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = true;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = true;
                }
if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = false;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = false;
                }
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <list>
#include <iostream>

#include "Platform.h"
#include "VariableGlobal.h"
namespace Joguinho
{
    class GameWorld
    {
    public:
        GameWorld();
        ~GameWorld();
        const char (*chooseTileMap(int i))[MAP_WIDTH + 1];
        void loadPlatformsFromMap(int i, SDL_Texture *texture);
        std::list<Platform> mPlatforms;
    };
}
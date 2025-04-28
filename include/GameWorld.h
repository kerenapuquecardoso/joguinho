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
        void loadPlatformsFromMap(const char tiles[MAP_HEIGHT][MAP_WIDTH + 1], SDL_Texture *texture);
        std::list<Platform> mPlatforms;
    };
}
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <string>

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
        const std::vector<std::string>& chooseTileMap(int i);
        void loadPlatformsFromMap(int i, SDL_Texture *texture);
        std::list<Platform> mPlatforms;
    };
}
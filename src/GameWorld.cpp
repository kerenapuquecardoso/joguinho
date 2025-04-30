
#include "GameWorld.h"
namespace Joguinho
{
    GameWorld::GameWorld()
    {
    
       std::cout << "inicializando GameWorld" << std::endl;
    }

    GameWorld::~GameWorld()
    {
       // std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
    }

    void GameWorld::loadPlatformsFromMap(const char tiles[MAP_HEIGHT][MAP_WIDTH + 1], SDL_Texture *texture)
    {
        for (int y = 0; y < MAP_HEIGHT; ++y) {
            for (int x = 0; x < MAP_WIDTH; ++x) {
                char tile = tiles[y][x];
                if (tile == '1') {
                    Point position = {x * TILE_SIZE, y * TILE_SIZE};
                    Vector size = {TILE_SIZE, TILE_SIZE};
                    mPlatforms.emplace_back(position, size, texture);
                }
            }
        }
    }

}
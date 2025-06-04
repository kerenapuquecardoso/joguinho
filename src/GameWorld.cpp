
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

    const std::vector<std::string> tile_map_1 = {
        "11111111111111111111111111111111",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "1111111111111111111111111......1",
        "1..............................1",
        "1..............................1",
        "1...........................1111",
        "1.......111111111111111111111111",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "111111111111111111111111.......1",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "1...........................1111",
        "11111111111111111111111111111111",
    };

    const std::vector<std::string> tile_map_2 = {
        "11111111111111111111111111111111",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "1......1111111111111111111111111",
        "1..............................1",
        "1..............................1",
        "1111...........................1",
        "111111111111111111111111.......1",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "1.......111111111111111111111111",
        "1..............................1",
        "1..............................1",
        "1..............................1",
        "1111...........................1",
        "11111111111111111111111111111111",
    };

    const std::vector<std::string>& GameWorld::chooseTileMap(int i)
    {
        switch (i)
        {
            case 1: return tile_map_1;
            case 2: return tile_map_2;
            default:
                static const std::vector<std::string> empty_map;
                return empty_map;
        }
    }

    void GameWorld::loadPlatformsFromMap(int i, SDL_Texture *texture)
    {
        const auto& tiles = chooseTileMap(i);

        if (tiles.empty()) {
            std::cerr << "Mapa inválido!"<< std::endl;
            return;
        }

        for (int y = 0; y < MAP_HEIGHT; ++y) {

            if (y >= tiles.size()) { break;}

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
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Character.h"
#include "Object.h"
#include "Collider.h"
#include "VariableGlobal.h"
#include "GameWorld.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    Joguinho::RenderWindow window("Joguinho", 1280, 720);

    SDL_Texture *backgroundTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");

    Joguinho::Character tom({100, 600}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});//gw

    const char tile_map[MAP_HEIGHT][MAP_WIDTH + 1] = { //ir para game world
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

    Joguinho::GameWorld gameWorld;
    gameWorld.loadPlatformsFromMap(tile_map, characterTexture);

    uint32_t currentTime = SDL_GetPerformanceCounter();
    uint32_t lastTime = 0;

    bool isRunning = true;
    while (isRunning)
    {
        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();

        float preDeltaTime = float((currentTime - lastTime) * 1000 / SDL_GetPerformanceFrequency());
        deltaTime = preDeltaTime / 100;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }

            tom.verifyKeyboard(event);
        }

        window.clear();
        // std::cout << "DELTA TIME: " << deltaTime << std::endl;

        tom.update(deltaTime);
		Joguinho::resolveCollision(tom, gameWorld.mPlatforms);
        window.renderBackground(backgroundTexture);

        for (auto &platform : gameWorld.mPlatforms)// gw
        {
            SDL_Rect plataformRect = { 
                static_cast<int>(platform.getPosition().x),
                static_cast<int>(platform.getPosition().y),
                static_cast<int>(platform.getSize().x),
                static_cast<int>(platform.getSize().y)};
            platform.render(renderer, plataformRect);
        }
        SDL_Rect characterRect = {
            static_cast<int>(tom.getPosition().x),
            static_cast<int>(tom.getPosition().y),
            100,
            100};
       
        tom.render(renderer, characterRect);//gw
        window.display();
        SDL_Delay(16);
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
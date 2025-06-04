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

#include "GameManager.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    Joguinho::RenderWindow window("Joguinho", 1280, 720);

    SDL_Texture *backgroundTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");

    Joguinho::Character tom({200, 300}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});//gw

    Joguinho::GameWorld gameWorld;
    gameWorld.loadPlatformsFromMap(1, characterTexture);

    uint32_t lastTime = SDL_GetTicks();

    bool isRunning = true;
    while (isRunning)
    {
        uint32_t currentTime = SDL_GetTicks();

        float preDeltaTime = currentTime - lastTime;
		lastTime = currentTime;
        deltaTime = static_cast<float>(preDeltaTime) / 1000.0f;

		std::cout << "DELTA TIME: " << deltaTime << std::endl;

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
        window.renderBackground(backgroundTexture);
		Joguinho::resolveCollision(tom, gameWorld.mPlatforms);
        
        for (auto &platform : gameWorld.mPlatforms)// gw
        {
            platform.render(renderer);
        }
        
        tom.render(renderer);//gw
        window.display();
        SDL_Delay(20);
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
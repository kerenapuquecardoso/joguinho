#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Character.h"
#include "Object.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    Joguinho::RenderWindow window("Joguinho", 1280, 720);

    SDL_Texture *backgroundTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");
    SDL_Texture *obstacleTexture = window.loadTexture("resources/graphics/image.png");

    Joguinho::Character tom({100, 100}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});
    Joguinho::StaticObject obstacle({300, 400}, {100, 100}, obstacleTexture);
    
    bool isRunning = true;
    while (isRunning)
    {
        
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            
            tom.verifyKeyboard(event);
        }

        tom.updateCharacter();

        window.clear();
        window.renderBackground(backgroundTexture);
        
        SDL_Rect obstacleRect = {
            0, 500,
            1280, 100
        };
        window.renderRectangle(obstacleRect);

        SDL_Rect characterRect = {
            static_cast<int>(tom.getPosition().x),
            static_cast<int>(tom.getPosition().y),
            100,
            100
        };
        window.renderRectangle(characterRect);
        tom.gravity();
        
        window.display();
        
        SDL_Delay(16); 
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
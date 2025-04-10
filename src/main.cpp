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

    SDL_Texture *grassTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");
    SDL_Rect rect = { 0, 0, 100, 100 };
    bool isRunning = true;

    Joguinho::Character tom({0, 0}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});
    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
                

            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            default:
              tom.verifyKeyboard(event);
                break;
            }

            window.clear();
            
            window.renderBackground(tom.getTexture());
            window.renderBackground(grassTexture);
            window.renderRectangle(rect);
            window.display();
        }
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}

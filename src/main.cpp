#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"
#include "Object.h"


    int main(int argc, char **argv) 
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Event event;
        Joguinho::RenderWindow window("Joguinho", 1280, 720);
        SDL_Texture* grassTexture = window.loadTexture("resources/graphics/image.png");

        bool isRunning = true;

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
                }

                window.clear();
                window.renderBackground(grassTexture);
                window.renderRectangle(SDL_Rect{255, 0, 255, 255});
                window.display();
            }
        }
        window.cleanUp();
        SDL_Quit();

        return 0;
    }

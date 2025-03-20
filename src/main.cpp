#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
int main(int argv, char** args)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    RenderWindow window("Joguinho", 1280, 720);
    bool isRunning = true;
    // aqui deve ser instanciado o personagem
    // essas variaveis deverão ser o atributo da Classe Objeto
    float personX = 80;
    float personY = 300;
    float personWidth = 32;
    float personHeight = 32;
    bool isJumping = false, left = false, right = false;

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
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = true;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = true;
                }
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = false;
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = false;
                }
            }


            if (left)
            {
                personX -= 1;
            }
            if (right)
            {
                personX += 1;
            }
            //essa parte vai ter que ficar em um arquivo separado
            //Aqui tenho que chamar a renderização de cada objeto
            
        }
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}
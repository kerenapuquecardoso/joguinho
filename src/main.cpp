#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Object.hpp"
int main(int argv, char** args)
{
    //calcular o delta T, tempo de execução para ser o valor de atualização dos objetos
    // (velocidade * delta t ) + posição = nova posição
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    RenderWindow window("Joguinho", 1280, 720);
    SDL_Texture* grassTexture = window.loadTexture("resources/graphics/image.png");
    
    //Object bob(Point(150, 352), grassTexture);

    bool isRunning = true;
    // aqui deve ser instanciado o personagem
    // essas variaveis deverão ser o atributo da Classe Object
    // float personWidth = 32;
    // float personHeight = 32;
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

           window.clear();
           window.renderBackground(grassTexture);
           window.renderRectangle(grassTexture, SDL_Rect{255, 0, 255, 255});
           window.display();
            
        }
    }
    window.cleanUp();
    SDL_Quit();

    return 0;
}
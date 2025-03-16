#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argv, char** args)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Joguinho", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
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
            glClear(GL_COLOR_BUFFER_BIT); 
            glPushMatrix(); 

                glOrtho(0, 600, 400, 0, -1, 1); 
                glColor4ub(0,0,0,0);

                glBegin(GL_QUADS);
                
                    glVertex2f(personX, personY);
                    glVertex2f(personX+personWidth, personY);
                    glVertex2f(personX+personWidth, personY+personHeight);
                    glVertex2f(personX, personY+personHeight);

                glEnd();
            glPopMatrix();
            SDL_GL_SwapBuffers();
            
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
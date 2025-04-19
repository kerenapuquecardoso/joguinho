#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Character.h"
#include "Object.h"
#include "Collider.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    Joguinho::RenderWindow window("Joguinho", 1280, 720);

    SDL_Texture *backgroundTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");

    Joguinho::Character tom({100, 100}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});
    
    std::list<Joguinho::Platform> platforms;
    platforms.emplace_back(Point{0, 500}, Vector{1280, 100}, backgroundTexture);

    bool isRunning = true;
    while (isRunning)
    {
        
           
        Joguinho::resolveCollision(tom, platforms);
        
       
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            
            tom.verifyKeyboard(event);
        }

        
        window.clear();
        tom.updateCharacter(0.0f);
        window.renderBackground(backgroundTexture);
        for (auto& platform : platforms)
        {
            SDL_Rect plataformRect = {
                static_cast<int>(platform.getPosition().x),
                static_cast<int>(platform.getPosition().y),
                static_cast<int>(platform.getSize().x),
                static_cast<int>(platform.getSize().y)
            };
            window.renderRectangle(plataformRect);
        }
        SDL_Rect characterRect = {
            static_cast<int>(tom.getPosition().x),
            static_cast<int>(tom.getPosition().y),
            100,
            100
        };
        window.renderRectangle(characterRect);
        
        window.display();
        
        SDL_Delay(16); 
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
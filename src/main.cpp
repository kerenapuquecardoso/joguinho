#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Character.h"
#include "Object.h"
#include "Collider.h"
// #include "VariableGlobal.h"

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event event;
    Joguinho::RenderWindow window("Joguinho", 1280, 720);

    SDL_Texture *backgroundTexture = window.loadTexture("resources/graphics/image.png");
    SDL_Texture *characterTexture = window.loadTexture("resources/graphics/tom.png");

    Joguinho::Character tom({100, 100}, {0, 0}, {100, 100}, characterTexture, {SDLK_LEFT, SDLK_RIGHT, SDLK_UP});
    
    std::list<Joguinho::Platform> platforms;
    platforms.emplace_back(Point{250, 130}, Vector{780, 80}, backgroundTexture);
    platforms.emplace_back(Point{0, 330}, Vector{780, 100}, backgroundTexture);
    platforms.emplace_back(Point{0, 550}, Vector{1280, 100}, backgroundTexture);


    uint32_t currentTime = SDL_GetPerformanceCounter();
    uint32_t lastTime = 0;

    bool isRunning = true;
    while (isRunning)
    {
        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        
        float preDeltaTime = float((currentTime - lastTime) * 1000 / SDL_GetPerformanceFrequency());
        float deltaTime = preDeltaTime / 100;   
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
        std::cout << "DELTA TIME: " << deltaTime << std::endl;
        tom.updateCharacter(deltaTime);
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
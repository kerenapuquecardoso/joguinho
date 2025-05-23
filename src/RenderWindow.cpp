#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "VariableGlobal.h"
#include "Object.h"

namespace Joguinho
{
    RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
        : mWindow(NULL), mRenderer(NULL)
    {
        mWindow = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
        if (mWindow == NULL)
        {
            std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
        }
        renderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    }

    SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
    {
        SDL_Texture *texture = NULL;
        texture = IMG_LoadTexture(renderer, p_filePath);
        if (texture == NULL)
        {
            std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
        }
        return texture;
    }

    void RenderWindow::cleanUp()
    {
        SDL_DestroyWindow(mWindow);
        //SDL_DestroyRenderer(mRenderer);
    }

    void RenderWindow::clear()
    {
        SDL_RenderClear(renderer);
    }

    void RenderWindow::renderBackground(SDL_Texture *p_texture)
    {
        SDL_RenderCopy(renderer, p_texture, NULL, NULL);
    }

    void RenderWindow::renderRectangle(SDL_Rect& p_rect)
    {
        SDL_RenderFillRect(renderer, &p_rect);
    }

    void RenderWindow::display()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Renderer* RenderWindow::getRenderer() {
        return renderer;
    }
}

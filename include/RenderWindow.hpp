#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Object.hpp"
class RenderWindow 
{
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        void cleanUp();
        void clear();
        void renderBackground(SDL_Texture* p_texture);
        void renderRectangle(SDL_Texture* p_texture, SDL_Rect p_rect);
        void display();
    private: 
        SDL_Window *window;
        SDL_Renderer *renderer;
};
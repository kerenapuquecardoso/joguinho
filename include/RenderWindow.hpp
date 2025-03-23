#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow 
{
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        void cleanUp();
        void clear();
        void render(SDL_Texture* p_texture);
        void display();
        //SDL_Renderer* getRenderer();
    private: 
        SDL_Window *window;
        SDL_Renderer *renderer;
};
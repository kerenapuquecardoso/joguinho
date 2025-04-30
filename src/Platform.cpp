#include "Platform.h"

namespace Joguinho
{
    Platform::~Platform()
    {
		// std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
    }
    void Platform::render(SDL_Renderer* renderer, SDL_Rect& p_rect)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &p_rect);	
    }
}

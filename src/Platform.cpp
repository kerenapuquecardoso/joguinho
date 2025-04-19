#include "Platform.h"

namespace Joguinho
{
    Platform::~Platform()
    {
		std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
    }
    void Platform::render()
    {
        // SDL_Rect rect = {static_cast<int>(mPosition.x), static_cast<int>(mPosition.y),
        //  static_cast<int>(mSize.x), static_cast<int>(mSize.y)};
        // std::cout << "RENDERIZOUUUUUU AQUI, NA position: " << mPosition.x << ", " << mPosition.y << std::endl;
    }
}

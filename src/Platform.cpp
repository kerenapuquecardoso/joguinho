#include "Platform.h"

namespace Joguinho
{
  Platform::~Platform()
  {
    // std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
  }
  void Platform::render(SDL_Renderer *renderer)
  {
    Vector pos = getPosition();
    Vector size = getSize();
    Vector center = pos + size / 2.0f;

    
    SDL_Rect rect;
    rect.w = static_cast<int>(size.x);
    rect.h = static_cast<int>(size.y);
    rect.x = static_cast<int>(center.x - size.x / 2);
    rect.y = static_cast<int>(center.y - size.y / 2);

    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderFillRect(renderer, &rect);
  }
}


#define SDL_MAIN_HANDLED

#include "GameManager.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Object.h"
#include "Collider.h"
#include "GameWorld.h"
#include "Character.h"
#include "RenderWindow.h"
#include "VariableGlobal.h"

namespace Joguinho
{
    GameManager::GameManager()
    {
       std::cout << "inicializando GameManager" << std::endl;
    }

    GameManager::~GameManager()
    {
       // std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
    }
}
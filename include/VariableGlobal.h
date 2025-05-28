#ifndef VARIABLE_GLOBAL_H
#define VARIABLE_GLOBAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

inline float deltaTime = 0.0f;
inline SDL_Renderer* renderer  = nullptr;

constexpr float gravity = 90.807f;
constexpr int TILE_SIZE = 40;
constexpr int MAP_WIDTH = 1280;
constexpr int MAP_HEIGHT = 720;

#endif
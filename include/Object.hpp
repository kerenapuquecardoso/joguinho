#pragma once
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Criar um arquivo de cabeçalho para essa
#include "header.h"

class Object
{
	public:
		Object(Point p_position, SDL_Texture* p_texture);
		Point getPosition();
		int getWidth();
		int getHeight();
    private: 
		Point position;
		Vector size;
};

	// class StaticObject : public Object
	// {
	// 	Vector a, b, c;
	// 	a = b + c;
	// };


	// 	class Wall : public StaticObject
	// 	{
	// 		//
	// 	};

	// 	class ExitDoor : public StaticObject
	// 	{
	// 		//
	// 	};

	// class DynamicObject : public Object
	// {
	// 	//
	// };

	// 	class Character : public DynamicObject
	// 	{
	// 		//
	// 	};

	// 	class Enemy : public DynamicObject
	// 	{
	// 		//
	// 	};
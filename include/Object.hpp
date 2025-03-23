#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <my-lib/math-vector.h>
using Vector = Mylib::Math::Vector<float, 2>;
using Point = Vector;

class Object
{
	public:
		Object(float p_x, float p_y, SDL_Texture* p_texture);
    private: 
		Point position;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
		int width, height;
};

	class StaticObject : public Object
	{
		Vector a, b, c;
		a = b + c;
	};


		class Wall : public StaticObject
		{
			//
		};

		class ExitDoor : public StaticObject
		{
			//
		};

	class DynamicObject : public Object
	{
		//
	};

		class Character : public DynamicObject
		{
			//
		};

		class Enemy : public DynamicObject
		{
			//
		};
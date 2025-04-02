#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "MathTypes.h"
namespace Joguinho
{
	class Object
	{
	public:
		Object(Point position, Vector size, SDL_Texture *texture);
		Point getPosition();
		Vector getSize();

		virtual void render() = 0;

	protected:
		Point position;
		Vector size;
		SDL_Texture *texture;
	};

	class StaticObject : public Object
	{
	public:
		StaticObject(const Point position, const Vector size, SDL_Texture *texture)
			: Object(position, size,  texture) {}
		virtual ~StaticObject() = default;
		void renderer();
	};

	class DynamicObject : public Object
	{
	public:
		DynamicObject(const Point position, const Vector size, SDL_Texture *texture, const Vector velocity)
		 : Object(position, size,  texture), velocity(velocity) {}
		virtual ~DynamicObject() = default;
		void renderer();
	protected:
		Vector velocity;
	};
}

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
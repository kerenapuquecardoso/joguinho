#pragma once
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
		virtual void render() = 0;

		void setPosition(Point position){
			mPosition = position;
		}

		Vector getPosition() {
			return mPosition;
		}

		Vector getSize(){
			return mSize;
		}

	protected:
		Point mPosition;
		Vector mSize;
		SDL_Texture *mTexture;
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
		 : Object(position, size,  texture), mVelocity(velocity) {}
		virtual ~DynamicObject() = default;
		void renderer();

		Vector getVelocity() {
			return mVelocity;
		}

		void setVelocity(const Vector& velocity) {
			mVelocity = velocity;
		}

	protected:
		Vector mVelocity;
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
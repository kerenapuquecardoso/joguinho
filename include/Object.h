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

		virtual void render(SDL_Renderer* renderer) = 0;

		void setPosition(Point position){
			mPosition = position;
		}

		Vector getPosition() {
			return mPosition;
		}

		Vector getSize(){
			return mSize;
		}
		SDL_Texture* getTexture(){
			return mTexture;
		}

	protected:
		Point mPosition;
		Vector mSize;
		SDL_Texture *mTexture;
		SDL_Renderer *mRenderer;

	private:
		
	};

	class StaticObject : public Object
	{
	public:
		StaticObject(const Point position, const Vector size, SDL_Texture *texture)
			: Object(position, size,  texture) {}
		virtual ~StaticObject() = default;
	};

	class DynamicObject : public Object
	{
	public:
		DynamicObject(const Point position, const Vector size, SDL_Texture *texture, const Vector velocity)
		 : Object(position, size,  texture), mVelocity(velocity) {}
		virtual ~DynamicObject() = default;
		virtual void update(float deltaTime) = 0;

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
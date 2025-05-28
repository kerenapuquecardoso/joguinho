#include <iostream>
#include <utility>

#include "VariableGlobal.h"
#include "Character.h"
#include "Object.h"

namespace Joguinho

{

	Character::Character(Vector position, Vector velocity, Vector size, SDL_Texture *texture, std::array<SDL_Keycode, 3> myKeys)
		: DynamicObject(position, size, texture, velocity),
		  mScore(0), mLives(3), mMoveToRight(false), mMoveToLeft(false), mMyKeys(myKeys) {}

	Character::~Character()
	{
		// std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
	}

	void Character::render(SDL_Renderer *renderer)
	{
		Vector dynamicPosition = getPosition();
		Vector size = getSize();
		
		SDL_Rect dynamicRect = {dynamicPosition.x - size.x / 2, dynamicPosition.y - size.y / 2, size.x, size.y};

//		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//		SDL_RenderFillRect(renderer, &dynamicRect);
	}

	void Character::update(float deltaTime)
	{
		Vector velocity = getVelocity();
		Vector position = getPosition();
		velocity.y += gravity * deltaTime;
		position += velocity * deltaTime;

		setVelocity(velocity);
		setPosition(position);
	};

	void Character::verifyKeyboard(SDL_Event &event)
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Left)])
			{
				mMoveToLeft = true;
				std::cout << "LEFT pressed" << std::endl;
				setVelocity(Vector(-100.0f, 0.0f));
			}
			else if (event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Right)])
			{
				mMoveToRight = true;
				std::cout << "RIGHT pressed" << std::endl;
				setVelocity(Vector(100.0f, 0.0f));
			}
			else if (event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Up)])
			{
				std::cout << "Up pressed" << std::endl;
				if (mMoveToLeft)
				{
					setVelocity(Vector(-30.0f, -2000.0f));
					std::cout << "Up to the LEFT" << std::endl;
				}

				else if (mMoveToRight)
				{
					setVelocity(Vector(30.0f, -40.0f));
					std::cout << "Up to the RIGHT" << std::endl;
				}

				else
				{
					setVelocity(Vector(0.0f, -350.0f));
					std::cout << "Jumping UP" << std::endl;
				}
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Left)] ||
				event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Right)] ||
				event.key.keysym.sym == mMyKeys[static_cast<int>(Button::Up)])
			{
				mMoveToLeft = false;
				mMoveToRight = false;
				std::cout << "Key released" << std::endl;
				setVelocity(Vector(0.0f, 0.0f));
			}
		}
	}
}

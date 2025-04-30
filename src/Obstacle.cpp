#include <iostream>
#include <utility>

#include "VariableGlobal.h"
#include "Character.h"
#include "Object.h"

namespace Joguinho

{
	Obstacle::Obstacle(Vector position, Vector velocity, Vector size, SDL_Texture *texture)
		: DynamicObject(position, size, texture, velocity), {}

	Obstacle::~Obstacle()
	{
		std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
	}

	void Obstacle::render(SDL_Renderer* renderer, SDL_Rect& p_rect)
	{
		SDL_RenderCopy(renderer, mTexture, nullptr, &p_rect);
	}

	void Obstacle::updateObstacle(float deltaTime)
	{
		Vector velocity = getVelocity();
		Vector position = getPosition();
		velocity.y += gravity; // * deltaTime
		position += velocity;  // * deltaTime

		setVelocity(velocity);
		setPosition(position);
	};
}

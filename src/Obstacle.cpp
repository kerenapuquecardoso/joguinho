#include <iostream>
#include <utility>

#include "VariableGlobal.h"
#include "Obstacle.h"
#include "Object.h"

namespace Joguinho

{
	Obstacle::Obstacle(Vector position, Vector velocity, Vector size, SDL_Texture *texture)
		: DynamicObject(position, size, texture, velocity) {}

	Obstacle::~Obstacle()
	{
		std::cout << "LIMPAR VARIAVEIS AQUI" << std::endl;
	}

	void Obstacle::render(SDL_Renderer *renderer)
	{
		Vector pos = getPosition();
		Vector size = getSize();
		Vector center = pos + size / 2.0f;

		SDL_Rect rect;
		rect.w = static_cast<int>(size.x);
		rect.h = static_cast<int>(size.y);
		rect.x = static_cast<int>(center.x - size.x / 2);
		rect.y = static_cast<int>(center.y - size.y / 2);

		SDL_RenderCopy(renderer, mTexture, nullptr, &rect);
	}

	void Obstacle::update(float deltaTime)
	{
		Vector velocity = getVelocity();
		Vector position = getPosition();
		velocity.y += gravity; // * deltaTime
		position += velocity;  // * deltaTime

		setVelocity(velocity);
		setPosition(position);
	};
}

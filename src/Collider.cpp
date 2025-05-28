#include "Collider.h"
#include "VariableGlobal.h"

#include <my-lib/math-vector.h>
namespace Joguinho
{
    std::pair<bool, Vector> checkCollider(StaticObject &staticObject, DynamicObject &dynamicObject)
    {
        Vector collisionVector;

        Vector staticPosition = staticObject.getPosition() + staticObject.getSize() / 2.0f;
        Vector dynamicPosition = dynamicObject.getPosition() + dynamicObject.getSize() / 2.0f;

        Vector distance = dynamicPosition - staticPosition;
        const Vector targetDistance = (staticObject.getSize() + dynamicObject.getSize()) / 2.0f;

        SDL_Rect staticRect = {staticPosition.x - staticObject.getSize().x / 2, staticPosition.y - staticObject.getSize().y / 2, staticObject.getSize().x, staticObject.getSize().y};
        SDL_Rect dynamicRect = {dynamicPosition.x - dynamicObject.getSize().x / 2, dynamicPosition.y - dynamicObject.getSize().y / 2, dynamicObject.getSize().x, dynamicObject.getSize().y};

        // std::cout << "staticRect: (" << staticRect.x << ", " << staticRect.y << ", " << staticRect.w << ", " << staticRect.h << ")\n";
        // std::cout << "dynamicRect: (" << dynamicRect.x << ", " << dynamicRect.y << ", " << dynamicRect.w << ", " << dynamicRect.h << ")\n";
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &staticRect);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &dynamicRect);

        const bool collisionX = std::abs(distance.x) < targetDistance.x;
        collisionVector.x = std::copysign(targetDistance.x - std::abs(distance.x), distance.x);

        // std::cout << "collisionX: " << collisionX << std::endl;
        const bool collisionY = std::abs(distance.y) < targetDistance.y;
        collisionVector.y = std::copysign(targetDistance.y - std::abs(distance.y), distance.y);

        // std::cout << "collisionY: " << collisionY << std::endl;
        return std::pair<bool, Vector>(collisionX && collisionY, collisionVector);
    };

    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms)
    {
        // Vector vel = dynamicObject.getVelocity();
        
        for (auto &platform : platforms)
        {
            const auto [colliding, ds] = checkCollider(platform, dynamicObject);
            const auto abs_ds = Mylib::Math::abs(ds);
            if (colliding)
            {
				Vector dynamicPosition = dynamicObject.getPosition();

                if (abs_ds.y <= abs_ds.x)
                {
                    std::cout << "COLLISION DETECTED IN Y" << std::endl;
                    dynamicPosition.y += ds.y;
                    // vel.y = 0.0f;
                    // dynamicObject.setVelocity({0.0f, dynamicObject.getVelocity().y});
                }
                else if (std::abs(ds.x) <= std::abs(ds.y))
                {
                    std::cout << "COLLISION DETECTED IN X" << std::endl;
                    dynamicPosition.x += ds.x;
                    // vel.x = 0.0f;
                    // dynamicObject.setPosition(dynamicPosition);
                    // dynamicObject.setVelocity({0.0f, dynamicObject.getVelocity().y});
                }

                dynamicObject.setPosition(dynamicPosition);
                // dynamicObject.setVelocity(vel);
            }
        }
    }
}
#include "Collider.h"

namespace Joguinho
{
	std::pair<bool, Vector> checkCollider(StaticObject &staticObject, DynamicObject &dynamicObject)
    {
		Vector staticCenter = staticObject.getPosition() + staticObject.getSize() / 2.0f;
		Vector dynamicCenter = dynamicObject.getPosition() + dynamicObject.getSize() / 2.0f;

		Vector distance = staticCenter - dynamicCenter;
        Vector collisionVector;
        const Vector staticPosition = staticObject.getPosition();
        const Vector dynamicPosition = dynamicObject.getPosition();

        //const Vector distance = staticPosition - dynamicPosition;
        const Vector targetDistance = (staticObject.getSize() + dynamicObject.getSize()) / 2.0f;
        
        const bool collisionX = std::abs(distance.x) < targetDistance.x;
        collisionVector.x = std::copysign(targetDistance.x - std::abs(distance.x), distance.x);

        const bool collisionY = std::abs(distance.y) < targetDistance.y;
        collisionVector.y = std::copysign(targetDistance.y - std::abs(distance.y), distance.y);
        
        return std::pair<bool, Vector>(collisionX && collisionY, collisionVector);
    };
	
    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms)
    {
        //return;
        Vector dynamicPosition = dynamicObject.getPosition();
        Vector dynamicSize = dynamicObject.getSize();
		Vector dynamicVelocity = dynamicObject.getVelocity();

        for (auto &platform : platforms)
        {
            Vector platformPosition = platform.getPosition();
            Vector platformSize = platform.getSize();
            const auto [colliding, ds] = checkCollider(platform, dynamicObject);

			if (colliding)
			{
				std::cout << "ds: (" << ds.x << ", " << ds.y << ")\n";
				Vector pos = dynamicObject.getPosition();
				//pos = pos + ds;
				//dynamicObject.setPosition(pos);

				Vector vel = dynamicObject.getVelocity();

				if (std::abs(ds.x) < std::abs(ds.y)) {
					pos.x += ds.x;
					vel.x = 0;
				} else {
					pos.y += ds.y;
					vel.y = 0;
				}

				dynamicObject.setPosition(pos);
				dynamicObject.setVelocity(vel);
				std::cout << "COLISÃO" << std::endl;
				break;
			}
        }
    }
}
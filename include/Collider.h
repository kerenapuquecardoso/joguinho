#include <list>

#include "Platform.h"
#include "Object.h"
namespace Joguinho
{
    std::pair<bool, Vector> checkCollider(StaticObject &staticObject, DynamicObject &dynamicObject)
    {
        Vector collisionVector;
        const Vector staticPosition = staticObject.getPosition();
        const Vector dynamicPosition = dynamicObject.getPosition();

        const Vector distance = staticPosition - dynamicPosition;
        const Vector targetDistance = (staticObject.getSize() + dynamicObject.getSize()) / 2;
        
        const bool collisionX = std::abs(distance.x) < targetDistance.x;
        collisionVector.x = std::copysign(targetDistance.x - std::abs(distance.x), distance.x);

        const bool collisionY = std::abs(distance.y) < targetDistance.y;
        collisionVector.y = std::copysign(targetDistance.y - std::abs(distance.y), distance.y);
        
        return std::pair<bool, Vector>(collisionX && collisionY, collisionVector);
    };

    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms);
};
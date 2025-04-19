#include "Collider.h"

namespace Joguinho
{
    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms)
    {
        Vector dynamicPosition = dynamicObject.getPosition();
        Vector dynamicSize = dynamicObject.getSize();
        Vector dynamicVelocity = dynamicObject.getVelocity();

        for (auto &platform : platforms)
        {
            Vector platformPosition = platform.getPosition();
            Vector platformSize = platform.getSize();
            if (checkCollider(platform, dynamicObject))
            {
                if (dynamicPosition.y > 0)
                {
                    std::cout << "COLIDINDO AQUI" << std::endl;
                    dynamicPosition.y = platformPosition.y - dynamicSize.y;
                    dynamicObject.setVelocity(Vector(dynamicVelocity.x, 0));
                    dynamicObject.setPosition(dynamicPosition);

                }
            }
        }
       
    }
}
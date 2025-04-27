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
                if (dynamicPosition.y > 0 && dynamicVelocity.y > 0 &&
                    dynamicPosition.y + dynamicSize.y >= platformPosition.y &&
                    dynamicPosition.y < platformPosition.y + platformSize.y)
                {
                    // std::cout << "COLIDINDO AQUI Superior" << std::endl;
                    dynamicPosition.y = platformPosition.y - dynamicSize.y;
                    dynamicObject.setVelocity(Vector(dynamicVelocity.x, 0));
                    dynamicObject.setPosition(dynamicPosition);
                }
                if (dynamicVelocity.y < 0 &&
                    dynamicPosition.y <= platformPosition.y + platformSize.y &&
                    dynamicPosition.y + dynamicSize.y > platformPosition.y)
                {
                    // std::cout << "COLIDINDO AQUI Inferior" << std::endl;
                    dynamicPosition.y = platformPosition.y + dynamicSize.y;
                    dynamicObject.setVelocity(Vector(dynamicVelocity.x, 0));
                    dynamicObject.setPosition(dynamicPosition);
                }

                if (dynamicVelocity.x < 0 &&
                    dynamicPosition.x <= platformPosition.x + platformSize.x &&
                    dynamicPosition.x + dynamicSize.x > platformPosition.x + platformSize.x)
                {
                    std::cout << "COLISÃO LADO DIREITO DA PLATAFORMA" << std::endl;
                    dynamicPosition.x = platformPosition.x + platformSize.x;
                    dynamicObject.setVelocity(Vector(0, dynamicVelocity.y));
                    dynamicObject.setPosition(dynamicPosition);
                }

                if (dynamicVelocity.x > 0 &&
                    dynamicPosition.x + dynamicSize.x >= platformPosition.x &&
                    dynamicPosition.x < platformPosition.x)
                {
                    std::cout << "COLISÃO LADO ESQUERDO DA PLATAFORMA" << std::endl;
                    dynamicPosition.x = platformPosition.x - dynamicSize.x;
                    dynamicObject.setVelocity(Vector(0, dynamicVelocity.y));
                    dynamicObject.setPosition(dynamicPosition);
                }

              
            }
        }
    }
}
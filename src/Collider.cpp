#include "Collider.h"

namespace Joguinho
{
    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms)
    {
        return;
        Vector dynamicPosition = dynamicObject.getPosition();
        Vector dynamicSize = dynamicObject.getSize();

        for (auto &platform : platforms)
        {
            Vector platformPosition = platform.getPosition();
            Vector platformSize = platform.getSize();
            const auto [colliding, ds] = check_collision(platform, dynamicObject);
        }
    }
}
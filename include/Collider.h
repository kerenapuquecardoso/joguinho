#include <list>

#include "Platform.h"
#include "Object.h"
namespace Joguinho
{

    inline bool checkCollider(StaticObject &staticObject, DynamicObject &dynamicObject)
    {
        Vector staticPosition = staticObject.getPosition();
        Vector staticSize = staticObject.getSize();
        Vector dynamicPosition = dynamicObject.getPosition();
        Vector dynamicSize = dynamicObject.getSize();

        return staticPosition.x < dynamicPosition.x + dynamicSize.x &&
               staticPosition.x + staticSize.x > dynamicPosition.x &&
               staticPosition.y < dynamicPosition.y + dynamicSize.y &&
               staticPosition.y + staticSize.y > dynamicPosition.y;
    };

    void resolveCollision(DynamicObject &dynamicObject, std::list<Platform> &platforms);

};
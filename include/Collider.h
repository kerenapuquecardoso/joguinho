#include <list>

#include "Platform.h"
#include "Object.h"
namespace Joguinho
{
	std::pair<bool, Vector> checkCollider(StaticObject& staticObject, DynamicObject& dynamicObject);
    void resolveCollision(DynamicObject& dynamicObject, std::list<Platform>& platforms);
};
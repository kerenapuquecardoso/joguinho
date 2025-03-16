#include <iostream>

class Object
{
	public:
		Object(float p_x, float p_y);
    private: 
		float x, y;
		int width, height;
};

	class StaticObject : public Object
	{
		//
	};


		class Wall : public StaticObject
		{
			//
		};

		class ExitDoor : public StaticObject
		{
			//
		};

	class DynamicObject : public Object
	{
		//
	};

		class Character : public DynamicObject
		{
			//
		};

		class Enemy : public DynamicObject
		{
			//
		};
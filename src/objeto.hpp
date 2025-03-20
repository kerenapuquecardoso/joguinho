#include <iostream>

#include <my-lib/math-vector.h>

using Vector = Mylib::Math::Vector<float, 2>;
using Point = Vector;

class Object
{
	public:
		Object(float p_x, float p_y);
    private: 
		Point position;
		int width, height;
};

	class StaticObject : public Object
	{
		Vector a, b, c;
		a = b + c;
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
#pragma once
#include <iostream>

//can use custom namespace if class name is similar to built in classes
namespace xia
{
	class Point
	{
	private:
		float x, y;

	public:
		//Point() { x = 0; y = 0; } Traditional constructor
		Point() : x{ 0 }, y{ 0 } {} // more modern constructor
		Point(float x, float y) : x{ x }, y{ y } {}


		void Write(std::ostream& ostream);
		friend std::ostream& operator << (std::ostream& ostream, Point& point);

		void Add(Point& point);
		Point& operator + (Point& point);
		Point operator * (float f);



	};
}


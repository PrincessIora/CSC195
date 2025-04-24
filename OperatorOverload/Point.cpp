#include "Point.h"

namespace xia
{
	void Point::Write(std::ostream& ostream)
	{
		ostream << x << " : " << y << std::endl;
	}

	void Point::Add(Point& point)
	{
		x += point.x;
		y += point.y;
	}


	//operator overload outside a class requires the right hand side of the symbol
	Point& Point::operator+(Point& point)
	{
		Point p;
		p.x = x + point.x; // new point = this point + parameter point
		p.y = y + point.y;

		return p;
	}

	Point Point::operator *(float s)
	{
		return Point(x * s, y * s);
	}

	

	 std::ostream& operator<<(std::ostream& ostream, Point& point)
	{
		ostream << point.x << " : " << point.y << std::endl;
		return ostream;
	}

}
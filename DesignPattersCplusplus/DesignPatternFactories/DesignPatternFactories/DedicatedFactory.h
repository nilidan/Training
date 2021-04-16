#pragma once
#include <cmath>

// This has a dedicated code to construction of Point object, allowing us to more
// in terms of separtion for any concerns

// do not need this for factory

enum class PointType
{
	cartesian,
	polar
};

class Point
{
	/*Point(float a, float b, PointType type = PointType::cartesian)
	{
	  if (type == PointType::cartesian)
	  {
		x = a; b = y;
	  }
	  else
	  {
		x = a*cos(b);
		y = a*sin(b);
	  }
	}*/

	// use a factory method
	Point(float x, float y) : x(x), y(y) {}
public:
	float x, y;

	friend class PointFactory; //Breaks open close prinicipal
};

class PointFactory
{
	static Point NewCartesian(float x, float y)
	{
		return Point{ x,y };
	}

	static Point NewPolar(float r, float theta)
	{
		return Point{ r*cos(theta), r*sin(theta) };
	}
};

int main_z()
{
	// will not work
	//Point p{ 1,2 };

}
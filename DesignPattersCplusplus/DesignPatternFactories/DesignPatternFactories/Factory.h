#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

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

	//Constructor only used internally 
	Point(const float x, const float y)
		: x{ x },
		y{ y }
	{
	}

public:
	float x, y;


	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		return os
			<< "x: " << obj.x
			<< " y: " << obj.y;
	}

	//construct a new cartesian point
	static Point NewCartesian(float x, float y)
	{
		return{ x,y };
	}
	//construct a new polar point
	static Point NewPolar(float r, float theta)
	{
		return{ r*cos(theta), r*sin(theta) };
	}
};

int main_z()
{
	// will not work
	//Point p{ 1,2 };

	auto p = Point::NewPolar(5, M_PI_4);
	std::cout << p << std::endl;

	getchar();
	return 0;
}
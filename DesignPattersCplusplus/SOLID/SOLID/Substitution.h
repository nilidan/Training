#pragma once
// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program

#include <iostream>

 class Rectangle
{
protected:
	int width, height;
public:
	Rectangle(const int width, const int height)
		: width{ width }, height{ height } { }

	int get_width() const { return width; }
	virtual void set_width(const int width) { this->width = width; }
	int get_height() const { return height; }
	virtual void set_height(const int height) { this->height = height; }

	//add boolean to tell if rectanle is square
	bool is_square() const
	{
		return width == height;
	}
	int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size, size) {}
	void set_width(const int width) override {
		this->width = height = width;
	}
	void set_height(const int height) override {
		this->height = width = height;
	}
};


//Violates the Liskov princple because any Derive class should be able to use the method
//Because the square class derive from rectangle sets the height, this function can only be applied to the base case.
/*
void process(Rectangle& r)
{
	int w = r.get_width();
	r.set_height(10);

	std::cout << "expected area = " << (w * 10)
		<< ", got " << r.area() << std::endl;
}
*/

//factory approach to creating rectangle and square
 struct RectangleFactory
{
	static Rectangle create_rectangle(int w, int h);
	static Rectangle create_square(int size);
};


 //Uses the new bool method to tell if it is square 
void process(Rectangle& r)
{
	int w = r.get_width();
	if (!r.is_square()) { 
		r.set_height(12);
	};

	int h = r.get_height();
	std::cout << "expected area = " << (w * h)
		<< ", got " << r.area() << std::endl;
}


int substitionMain()
{   
	
	Rectangle r{ 5,10 };
	process(r);
  
	Square s{ 5 };
	process(s);

	getchar();
	return 0;
}
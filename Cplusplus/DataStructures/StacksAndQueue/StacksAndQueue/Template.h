#pragma once
#include <iostream>
using namespace std;

/*Templates allow to have differnt data types for a class
Can be used to create a triplet add another typename
but using the pair, a triplet can be created
Pair<Pair<int,int>, int> p*/
template <typename T,typename V>
class Pair {
	T x;
	V y;

	//cvzxcv bndfasdfdadasfddfadsfadfadfasfd
public: 
	void setX(T x) {
		this->x = x;

	}
	T getX() {
		return x;
	}

	void setY(V y) {
		this->y = y;

	}
	V getY() {
		return Y;
	}
};
int demo()
{
	/*
	Pair<int> p1;
	p1.setX(1);
	p1.setX(2);

	Pair<double> p2;
	p1.setX(1.23);
	p1.setX(2.11);
	*/

	Pair<int, double> p1;
	p1.setX(1.73);
	p1.setY(1.78);

	cout<< p1.getX() << " " << p1.getY() <<endl;
}
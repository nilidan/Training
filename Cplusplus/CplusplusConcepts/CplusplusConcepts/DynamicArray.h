
#pragma once
#include <iostream>

//Stack Memory
//ex int i; 
//Can't allocate memory for Stack at runtime, only at compile time
//less memory
// automatic release of memomry on basis of scope

//Heap Memory
//Dynamic allocation
//large memory
// int * i = new int;
// new will create mem and return address of value in heap
// use pointere to store address.
// no scope for heap memory allocation

using namespace std;

void  heapMain() {

	int *p = new int;
	*p = 10;
	cout << p << endl;
	cout << *p << endl;

	double *d = new double;
	char *c = new char;
	
	// Largest Element;
	int n;
	cin >> n;
	int *a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int largest = -1;
	for (int i = 0; i < n; i++) {
		if(a[i] > largest) {
			largest = a[i];
		}
	}

	//need to manual delete the memory allocated in the heap or
	// else it keep on allocating memeory to the heap until it crash
	// happens for example if declared in a loop.

	int *p = new int;
	delete p;
	
	p = new int;
	delete p;


	//deleting an array in the heap
	p = new int[60];
	delete[]p;
}
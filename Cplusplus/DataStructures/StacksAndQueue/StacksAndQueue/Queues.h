#pragma once
#include <iostream>
/*Queues is abstract data type, Firt In First Out (FIFO)
  Data First in is Data First OUt, think a line of people
  Insert and Delete at the top
*/

using namespace std;

template<typename T>
class Queue {
	T *arr;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

public:

	Queue() {
		capacity = 5;
		arr = new T[5];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		
	}


	Queue(int cap) {
		capacity = cap;
		arr = new T[cap];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(T ele) {
		arr[nextIndex] = ele;
		nextIndex++;
	}
};
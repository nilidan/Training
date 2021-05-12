#pragma once

#include <iostream>

using namespace std;

/*Stack using template
*/

template <typename T>
class Stack {
	T *arr;
	int nextIndex = 0;
	int capacity = 0;

public:
	//default contsrut for stack, had capacity of 4
	Stack() {
		capacity = 4;
		arr = new T[4];
		nextIndex = 0;
	}
	// Dont need for dynamic stack
	/*
	Stack(int cap) {
		capacity = cap;
		arr = new int{ cap };
		nextIndex = 0;
	}*/

	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		return nextIndex == 0;
	}
	
	void push(T val) {

		if (nextIndex == capacity)
		{
			T* newArr = new T[2 * capacity];
			for (int i = 0; i < capacity; i++) {
				newArr[i] = arr[i];

			}
			delete[]arr;
			arr = newArr;
			capacity = 2 * capacity;
		}
		arr[nextIndex] = val;
		nextIndex++;

	}
	void pop() {
		if (isEmpty()) {
			return;
		}
		
			nextIndex--;
		

	}

	T top() {
		if (isEmpty()) {
			cout << "stack is Empty" << endl;
			return 0;
		}
		else {
			return arr[nextIndex - 1];
		}
	}


};


int templateDemo()
{
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;
	s.pop();

	cout << s.top() << endl;
	s.pop();

	cout << s.top() << endl;
	s.pop();

	cout << s.size() << endl;
	cout << s.isEmpty() << endl;

	return 0;
}
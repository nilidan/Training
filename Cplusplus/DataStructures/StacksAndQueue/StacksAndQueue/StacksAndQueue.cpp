// StacksAndQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemplateStack.h"
using namespace std;

/*Stack is abstract data type, Last In First Out (LIFO)
  Data last in is Data First OUt, think stack of chairs
  Insert and Delete at the top
*/
/*
class Stack {
	int *arr;
	int nextIndex=0;
	int capacity=0;

public:
	//default contsrut for stack, had capacity of 4
	Stack() {
		capacity = 4;
		arr = new int[4];
		nextIndex = 0;
	}
	// Dont need for dynamic stack
	/*
	Stack(int cap) {
		capacity = cap;
		arr = new int{ cap };
		nextIndex = 0;
	}

	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		return nextIndex == 0;
	}
	//Push for a predefined or static  stack
	/*
	void push(int val) {
		
		if (nextIndex == capacity)
		{
			cout << "stack is full" << endl;
			return;
		}
		else {
			arr[nextIndex] = val;
			nextIndex++;
		}
	}*/

	//Push for a dynamic stack
	/*1. Create New Arr, where capcity is x times capacity, below is 2 times
	  2. Copy old arr elements to new arr
	  3. delete old arr
	  4. upp arr = new arr
	 */
	/*
	void push(int val) {

		if (nextIndex == capacity)
		{
			int* newArr = new int[2 * capacity];
			for (int i = 0; i < capacity; i++) {
				newArr[i] = arr[i];

			}
			delete  []arr;
			arr = newArr;
			capacity = 2 * capacity;
		}
			arr[nextIndex] = val;
			nextIndex++;
		
	}
	void pop() {
		if (size() == 0) {
			return;
		}
		else {
			nextIndex--;
			return;
		}

	}

	int top() {
		if (size() == 0) {
			cout << "stack is Empty" << endl;
			return -1;
		}
		else {
			return arr[nextIndex - 1];
		}
	}


};*/
int main()
{
	templateDemo();

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

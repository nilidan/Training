#pragma once
#include <iostream>
/*Stack is abstract data type, Last In First Out (LIFO)
  Data last in is Data First OUt, think stack of chairs
  Insert and Delete at the top
*/

using namespace std;
template <typename T>
class Node {
public:
	T data;
	Node *next;

	Node(T data) {
		this->data = data;
		next = NULL;
	}
};


template <typename T>
class Stack {
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	
	Stack() {
		Node *head= NULL;
		Node *tail= NULL;
		int size =0;
	}
	int size() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(T val) {

			Node<T> *n = new Node(val);
			    n->next = head;
				head = n;
				tail = n;
				size++;

	}

	void pop() {

		if (isEmpty()) {
			cout << "Stadck empty" << endl;
			return;
		}
		Node<T> *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		size--;
	}

	T top() {
		if (isEmpty()) {
			cout << "Stadck empty" << endl;
			return;
		}
		else {
			return head->data;
		}
	}



	
	//Push for a predefined or static  stack
	
	

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
	*/

 };
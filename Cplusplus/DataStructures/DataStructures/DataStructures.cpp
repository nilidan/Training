// DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

void print(Node *head) {
	Node *temp = head;
	while (temp!= NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	temp = head;
	cout << endl;
	 // another way is 
	while (head != NULL) {
		cout <<head->data << " ";
		head = head->next;
	}
}
int main()
{
	Node n1(1);
	Node *head = &n1;

	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	//know the head, know the list just iterate
	print(head);

	/*n1.next = &n2;
	cout << n1.data << " " << n2.data << endl;
	Node *head = &n1;
	cout << head->data;

	//Dynamically
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);

	n3->next=n4;*/

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

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



Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;

	while (data != -1) {
		Node *n = new Node(data);

		if (head == NULL) {
			head = n;
			tail = n;
		}
		else {
			tail->next = n; // Inserting at Tail
			tail = n;
		}
		cin >> data;
	}
	return head;
}

//Insert At head
// Uses the -1 to signify end of list
Node* takeInputHead() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;

	while (data != -1) {
		Node *n = new Node(data);

		if (head == NULL) {
			head = n;
			tail = n;
		}
		else {
			/*Node *temp = head;
			head = n; 
			head->next = temp;*/
			n->next = head;
			head = n;
		}
		cin >> data;
	}
	return head;
}



void print(Node *head) {
	Node *temp = head;
	while (temp!= NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	temp = head;
	cout << " NULL";
	cout << endl;
	 // another way is 
	
}


int length(Node *head) {
	int size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}

int lengthRecursion(Node *head) {
	if (head == NULL) return 0;
	int smallAns = lengthRecursion(head->next);
	return 1 + smallAns;
}

bool isPresent(Node *head, int data) {
	Node *curr = head;
	while (curr != NULL) {
		if (curr->data == data) {
			return true;
		}
		curr = curr->next;

	}
	return false;
}
//Recursive way of finding a node;
bool isPresentRecur(Node *head, int data) {
	if (head = NULL) {
		return false;
	}
	Node *curr = head;
	
	if (curr->data == data) {
			return true;
		}
	
	return isPresentRecur(curr->next, data);
}
Node* InsertIthPos(Node *head, int data, int i) {


	int n = length(head);
	if (i < 0 ){
		return head;
	}

	if (i == 0) {
		Node *n = new Node(data);
		n ->next = head;
		head = n;
		return head;
	}
	int cnt = 1;
	
	while (cnt <= i && head != NULL) {
		head = head->next;
		cnt++;
	}

	if (cnt == i) {
		Node *ith = new Node(data);
		Node *temp = head;
		ith->next = temp->next;
		temp->next = ith;
		return head;
	}
		
	
	return head;
}

Node * deleteithNode(Node* head, int i) {
	if (i < 0) {
		return head;
	}

	if (i == 0 && head) {
		//return head->next;
		Node* newHead = head->next;
		head->next = NULL;
		delete head;
		return newHead;
	}

	Node* curr = head;
	int count = 1;
	while (count <= i - 1 && curr != NULL) {
		curr = curr->next;
		count++;
	}

	//Memory Leak without delete and temp node to isolate
	if (curr && curr->next) {
		Node *temp = curr ->next;
		curr->next = curr->next->next;
		temp->next = NULL;
		delete temp;

		return head;
	}
	return head;
}
void printIthNode(Node *head, int i) {
	int n = length(head);
	if (i < 0 || i>n - 1) {
		cout << "-1" << endl;
		return;
	}
	int cnt = 1;
	while (cnt <= i && head!=NULL) {
		head = head->next;
		cnt++;
	}
	if (head != NULL)
	{
		cout << head->data << endl;
	}
	else
	{
		cout << "Null Value Has been reached. Index not Valid" << endl;
	}
}

//T(N)
// solution for LeetCode :https://leetcode.com/problems/middle-of-the-linked-list/
Node* findMid(Node* head) {
	Node* slow = head;
	Node* fast = head->next;


	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL) {
		return slow->next;
	}
	return slow;
}


//T(N)
// solution for LeetCode :https://leetcode.com/problems/reverse-linked-list/submissions/
Node* reverseList(Node* head) {
	Node* curr = head;
	Node* prev = NULL;


	while (curr!=NULL) {
		Node*  n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;

	}
	return prev;
}

// For 2  traversao, find length, then use formula( length - kth +1), kth is the node to be deleted from end of list   
// for one travesal, delete kth node from end of linked list
// 2 pointers are at head
// the 2nd pointer take k jumps
// move one and two until two reaches node
//  Leet code solution for https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
Node* removeNthFromEnd(Node* head, int n) {
	Node* one = head;
	Node* two = head;
	Node* temp = NULL;

	for (int i = 0; i < n; i++) {
		two = two->next;
	}
	if (two == NULL) {
		temp = one;
		one = one->next;
		delete temp;
		return one;
	}
	while (two->next != NULL){
		one = one->next;
	     two = two->next;
	}

one->next = one->next->next;//memomry leak
return head;

}

// Merge two sorted list together
// solution for leetcoode :https://leetcode.com/problems/merge-two-sorted-lists/
Node* mergeTwoLists(Node* l1, Node* l2) {
	if (l1 == NULL) { return l2; }

	if (l2 == NULL) { return l1; }

	Node* mergeListHead = NULL;

	if (l1->data < l2->data) {
		mergeListHead = l1;
		l1 = l1->next;
	}
	else {
		mergeListHead = l2;
		l2 = l2->next;
	}


	Node* temp = mergeListHead;

	while (l1 && l2) {

		if (l1->data < l2->data) {
			temp->next = l1;
			l1 = l1->next;
		}
		else {
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;

	}

	if (l1) {
		temp->next = l1;
	}
	else {
		temp->next = l2;
	}

	return mergeListHead;
}


// Merge two sorted list together recursively

// solution for leetcoode :https://leetcode.com/problems/merge-two-sorted-lists/
Node* mergeTwoListsRecur(Node* l1, Node* l2) {
	if (l1 == NULL) { return l2; }

	if (l2 == NULL) { return l1; }

	Node* mergeListHead = NULL;

	if (l1->data < l2->data) {
		mergeListHead = l1;
		mergeListHead->next = mergeTwoListsRecur(l1->next, l2);
	}
	else {
		mergeListHead = l2;
		mergeListHead->next  = mergeTwoListsRecur(l2->next, l1);
	}


	return mergeListHead;
}

// Merge sort a linke list
// Break list into 2halves
// Mall mergesert on 2 halves recursion
// merge the 2 sorted halves
// leetcode solution for https://leetcode.com/problems/sort-list/

Node* sortList(Node* head) {

	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* one = head;
	Node* two = head->next;

	while (two && two->next) {
	    one = one->next;
		two = two->next->next;
	}

	Node *n = one->next;
	one->next = NULL;
	Node* a = sortList(head);
	Node* b = sortList(n);

	
	head = mergeTwoLists(a, b);
	return head;
}
int main()
{
	/*Node n1(1);
	Node *head = &n1;

	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	*/
	//know the head, know the list just iterate, end input need -1 to signify end of list
	//Node *head = takeInputHead();
	//print(head);
	//cout << endl;
	//cout << "the length is " << length(head)<<endl;

	//cout << endl;
	/*cout << "Enter ith node to Print " <<endl;
	
	int i = 0;
	cin >> i;
	printIthNode(head, i);
	print(head);
	
	head = InsertIthPos(head, 100, 2);
   print(head);
	*/
	Node *head = takeInput();
	//int i = 0;
	//cin >> i;
	//head = deleteithNode(head, i);
	cout << lengthRecursion(head) << endl;
	print(head);
	int data = 0;
	if (isPresent(head, data)){
		cout<<"found"<<endl;
	}
	else {
		cout << "not found" << endl;
	}
	
	/*n1.next = &n2;
	cout << n1.data << " " << n2.data << endl;
	Node *head = &n1;
	n3->next=n4;*/
	//cout << head->data;

	/*
	//Dynamically;
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	n3->next = n4;
	*/

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

// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "charArray.h"
#include "TwoDArrayAndSearchSortAlogrithm.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	//charStrInBuilt();
	//char str[] = "abcd";
	//printAllsuffixes(str);
	//cout << endl;


	//declaring a 2d array rows are optional but columns are mandatory
	//if m or n is greater than what is delcared 0s area addedvvvvvvvvvvvvv
	//int a[][2] = { {1,2} , {3,4} };
	//printArray(a, 2, 2);

	int n=1;
	cout << "Enter lenght of array" << endl;
	cin >> n;
	
	int *b = new int[n];
	cout << "Enter numbers to sort or search"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//selectionSort(b, n);
	//bubbleSort(b, n);

	/*for (int j = 0; j < n; j++) {
		cout << b[j] << " ";
	}*/
	
	//int pos = linearSearchKey(b, n);
	inbuiltSort(b, n); //need for binary search key
	int pos = binarySearchKey(b, n);


	if (pos == -1) {
		cout << " not found"<<endl;
	}
	else {
		cout << b[pos] << " found at index "<<pos<< endl;
	}
	

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

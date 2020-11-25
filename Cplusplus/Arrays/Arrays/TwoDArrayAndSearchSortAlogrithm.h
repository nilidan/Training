#pragma once

//bits/stdc++.h is master header file that encompasses both headers below use this if you want keep writing each header files.It is nonstandard header file
//buts VS has its own stl and have to use necesary standard headers
#include<iostream>
#include<algorithm>

using namespace std;

//print 2d array
//to pass a 2d array to function column are mandatory but rows are optional
//general arrays are pass by reference, what ever is affected in the funtion
//happens  in the main
void printArray(int a[][2], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";

		 }
		cout << endl;
	}
}


//Selection sort are sorted to the right 
//best case  is  O(N)
//worst case is  O(n^2)

void selectionSort(int a[], int n) {

	for (int i = 0; i <= n - 2; i++) {
		int min = i;
		for (int j = i + 1; j < n - 1; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}

		swap(a[i], a[min]);

	}
}


//bubble sort is to the left and compares the next value
//best case  is  O(N) if optomize other wise n^2
//worst case is  O(n^2)
// optomize flag to break if sorted and give us best case
void bubbleSort(int a[], int n) {

		for (int i = 1; i <= n - 1; i++) {
			int flag = 0;
			for (int j = 0; j <= n - 2; j++) {
				if (a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
				}
			}

			
			if(flag==0){ //array already sorted than break
				break;
			}
		}


	}

void inbuiltSort(int a[], int n) {
		sort(a, a + n);

}

//Linear Search 
//Linear Search is O(N) unsorted or sorted
//use this if unsorted

int linearSearchKey(int a[], int n) {

	cout << "Enter key" << endl;
	int key;
	cin >> key;

	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}


//Binary Search
// Search in log(N) if sorted 
// use this if array is sorted
// use the mid = (start + end) /2 to split the sorted array after each iteration
// Thre conditions : 1 a[mid] = key return key
// 2 if a[mid] less than key it on left side and end is the mid -1
// 3 if a[mid] less than key it on right side and the start is mid + 1
// if start > end than key not present

// start + end > INT_MAX cause integer overflow result  in negative.
//to prevent overflow use start + (end-start)/2

int binarySearchKey(int a[], int n) {

	cout << "Enter key" << endl;
	int key;
	cin >> key;

	int start = 0, end = n - 1;
	while(start<=end) {
		//int mid = (start + end) / 2; causes integer overflow
		int mid = start + (end - start) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}



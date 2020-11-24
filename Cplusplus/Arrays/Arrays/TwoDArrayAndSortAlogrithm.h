#pragma once

//bits/stdc++.h is master header file that encompasses both headers below use this if you want keep writing each header files 
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


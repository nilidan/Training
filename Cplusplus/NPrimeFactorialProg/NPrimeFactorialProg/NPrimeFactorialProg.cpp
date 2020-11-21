// NPrimeFactorialProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PrimeFactorialFunc.h"
using namespace std;


int main()
{
	cout << "Enter N" << endl;
	int n;
	cin >> n;


	if (isPrime(n)) {
		cout << "Prime" << endl;

	}
	else {
		cout << "Not Prime" << endl;
	}

	cout << "\nHere is all Prime Numbers until " << n << endl;
	generatePrime(n);

	cout << "\nHere is factorial for "<< n << endl;
	cout << nFactorial(n) << endl;

	cout << "Enter r for nCr " << endl;
	int r;
	cin >> r;

	cout << "\nThe nCr \n"<< nCr(n, r);


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

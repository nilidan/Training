#pragma once
#include <iostream>
#include "PrimeFactorialFunc.h"
using namespace std;

// Function to tell if a number n is Prime or Not
bool isPrime(int n) {

	for (int i = 2; i < n - 1; i++)
	{
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

// Function to generate all the prime number until N
void generatePrime(int n) {

	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
}

int nFactorial(int n) {

	int num = n;

	
	do
	{
		n--;
		num *= n;


	} while (n > 1);

	return num;
}


// function to find binomial coefficients (nCr) 
int nCr(int n, int r) {
	return nFactorial(n) / (nFactorial(n - r)* nFactorial(r));
}
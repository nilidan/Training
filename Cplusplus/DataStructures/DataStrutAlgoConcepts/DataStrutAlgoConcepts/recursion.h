#pragma once

using namespace std;

//recursion is calling a function itself until reach termination condition
//uses a call stack, where each call of function is stacking on top of each other waiting for each call to complete its work
// for this case with n=4 
// fact(0) completes its work of returning 1
// than next call fact(1) times 1 by 1, than fact(2) times this 1 by 2;
// than fact(3) times 2*3 , than fact(4) = (3*2) * 4, gives prod of 24;
int fact(int n) {
	cout << n << endl;

	if (n < 0) return -1; // factorial of neg number is undefined
	if (n == 0) return 1; // 1st step base case in PMI

	int prodAns = fact(n - 1); //2nd Step is assumption
	return n * prodAns;//3rd step is calculation
}

/* Recursion works on Principal of Mathimatical Induction (PMI) 
F(n) is true prove n

1. Prove F(0) or F(1) is true -> base case
2. Induction Hypthosis - Assume F(k) is true for any case
3. Induction steps using 2, prove F(k+1) is true

https://www.codingninjas.com/blog/2020/06/19/learn-recursion-in-c/

Think in PMI terms
1. Base case
2. Assumption about small case
3. Calculation
*/


int fib(int n) {

	if (n == 0) { return 0; }//base code
	if (n == 1) { return 1; }
	
	int out1 = fib(n - 1); //assumption
	int out2 = fib(n - 2);// assumption

	return out1 + out2; // calc


}

int power(int x, int n) {
	if (n == 0) {
		return 1; // base case
	}

	int prod = power(x, n - 1); //assumption

	return x * prod;//calculation;
}

//print all numbers from 1 to N ascending
int printNum(int n) {

	if (n == 1) {
		cout << 1 << endl;
		return 1;
	}
	
	printNum(n - 1);
	cout << n << endl;

}

//Print Descending
void printNumDes(int n) {

	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	cout << n << endl;
	printNumDes(n - 1);
	return;

}

// devide by 10 to count the number of digits in a number
int countDigits(int n) {
	
	if (n == 0)
	{
		return 0;
	}
	int smallAns = countDigits(n / 10);

	return smallAns + 1;
}

int sumDigits(int n) {

	if (n == 0)
	{
		return 0;
	}
	int smallAns = sumDigits(n / 10);

	int lastDigit = n % 10;

	return smallAns + lastDigit;
}


int multiply(int m, int n) {

	if (n == 1)
	{
		return m; //base case
	}
	int smallAns = multiply(m, n-1); //assume m*n-1

	return smallAns + m; // calc

}

int countZero(int n) {

	if (n == 0)
	{
		return 0;
	}
	int smallAns = countZero(n / 10);

	int lastDigit = n % 10;

	if (lastDigit == 0) {
		return 1 + smallAns;
	}
	else {
		return smallAns;
	}
}

double geoSum(int k)
{
	if (k == 0) {
		return 1;
	}
	
	double smallAns = (geoSum(k-1));

	return smallAns + 1.0 / pow(2, k);
}


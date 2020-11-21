#include <iostream>
#include "SampFunc.h"

using namespace std;


int main()
{
	int n;
	cin>> n;


	if (isPrime(n)) {
		cout << "Prime" << endl;

	}
	else {
		cout << "Not Prime" << endl;
	}
}

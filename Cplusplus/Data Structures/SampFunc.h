#pragma once
bool isPrime(int n) {

	for (int i = 2; i < n - 1; i++)
	{
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

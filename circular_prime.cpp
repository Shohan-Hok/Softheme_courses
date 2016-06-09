// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <cmath>
#include <iostream>
#include <utility>

bool is_circular_prime(int prime)//working only with prime number!!!! Other wise, behavior undetermined
{
	if (prime == 2 || prime == 5 || prime == 7 || prime == 3)
		return true;

	int mod;
	while (prime > 10)
	{
		mod = prime % 10;
		switch (mod)
		{
		case 1:
		case 3:
		case 7:
		case 9:
			break;

		default:
			return false;
		}
		prime /= 10;
	}

	switch (prime)
	{
	case 1:
	case 3:
	case 7:
	case 9:
		return true;
	}

	return false;
}

bool is_prime(int n){
	if (n == 1) // 1 - не простое число
		return false;
	// перебираем возможные делители от 2 до sqrt(n)
	for (int d = 2; d*d <= n; d++){
		// если разделилось нацело, то составное
		if (n%d == 0)
			return false;
	}
	// если нет делителей, то простое
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Fermat number states that numbers F= 2^(2^n) + 1 are primes
	//But it works only till 4294967297, as we need to check primes till 1,000,000 that will be enough 
	int circularPrime = 0;
	
	for (int i = 1; i <= 1000000; ++i)
	{
		if (is_prime(i))
		if (is_circular_prime(i))
			++circularPrime;
	}
	
	std::cout << "Number of circular primes untill 1,000,000 is " << circularPrime << std::endl;
	
	return 0;
}


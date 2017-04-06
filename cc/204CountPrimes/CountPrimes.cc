/* 
Count the number of prime numbers less than a non-negative number, n.
*/

#include <iostream>

using namespace std;

// Sieve of Eratosthenes
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int countPrimes(int n) 
{
	bool isPrime[n];
	for (int i = 2; i < n; i++)
		isPrime[i] = true;
	for (int i = 2; i*i < n; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = i*i; j < n; j += i)
		{
			isPrime[j] = false; // cross out
		}
	}
	int count = 0;
	for (int i = 2; i < n; i++)
	{
		if (isPrime[i]) 
		{
			count++;
			cout<<i<<" ";
		}
	}
	return count;
}

int main()
{
	int n = 1000;
	cout<<"\nNumber of primes in "<<n<<": "<<countPrimes(n)<<endl;
	return 0;
}

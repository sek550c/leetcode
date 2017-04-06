/* 
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

int Factorial(int n)
{
	if (n == 1) return 1;
	return n*Factorial(n-1);
}

int trailingZeroes(int n) // count how many factor 5 from 1 to n
{
	int res = 0;
	while (n >= 5) // 25 has two 5's, 125 has 3 5's and so on, hence do it again
	{
		n /= 5;
		res += n;
	}
	return res;
}

int trailingZeroes2(int n) // recursion
{
	return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}

int main()
{
	int n = 15;
	//cout<<n<<"!: "<<Factorial(n)<<endl;
	cout<<"number of trailing zeros: "<<trailingZeroes(n)<<endl;
	return 0;
}

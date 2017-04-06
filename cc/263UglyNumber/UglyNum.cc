/* 
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number. 
*/

#include <iostream>
#include <set>

using namespace std;

bool isUgly(int n)
{
	if (n <= 0) return false;
	while (n%5 == 0)
		n /= 5;
	while (n%3 == 0)
		n /= 3;
	while (n%2 == 0)
		n /= 2;
	
	return n == 1;
}

int main()
{
	int num = 14;
	if (isUgly(num))
		cout<<"YES, a ugly number"<<endl;
	else
		cout<<"NO, not a ugly number"<<endl;
	return 0;
}

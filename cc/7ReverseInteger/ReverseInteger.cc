/* 
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/

#include <iostream>
#include <limits.h> // INT_MAX

using namespace std;

int reverse(int x) // has overflow problem, test 1534236469
{
	int q = x % 10;
	int p = x / 10;
	while (p)
	{
		q *= 10;
		q += p % 10;
		p /= 10;
	}
	return q;
}

int reverse2(int x) {
	long num = abs((long)x); // use long to solve overflow
	long rev_num = 0;
	while(num) // reverse
	{
		rev_num = rev_num*10 + num%10;
		num /= 10;
	}
	if (rev_num > INT_MAX) return 0; // // overflow check
	return (x < 0 ? -1*rev_num : rev_num);
}

int main()
{
	int n = 1534236469;
	//int n = 123;
	//int n = -123;
	cout<<"origin:  "<<n<<endl;
	cout<<"reverse: "<<reverse2(n)<<endl;
	return 0;
}

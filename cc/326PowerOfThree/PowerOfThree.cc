/* 
Given an integer, write a function to determine if it is a power of three. 3^x == n?

Follow up:
Could you do it without using any loop / recursion? 
*/

#include <iostream>
#include <math.h> // log
#include <limits.h> // INT_MAX

using namespace std;

bool PowerOfThree(int num) // recursion
{
	if (num <= 0) return false;
	if (num == 1) return true;
	else if (num%3 == 0) return PowerOfThree(num/3);
	else return false;
}

bool PowerOfThree2(int num) // loop
{
	if (num <= 0) return false;
	while (num > 1)
	{
		if (num%3 == 0)
			num /=3;
		else
			return false;
	}
	return true;
}

bool PowerOfThree3(int num) // math
{
	if (num <= 0) return false;
	auto x = log10(num)/log10(3);
	return x == floor(x); // check if it is an int
}

bool PowerOfThree4(int num) // math
{
	if (num <= 0) return false;
	int max = pow(3, log10(INT_MAX)/log10(3));
	return max%num == 0;
}

int main()
{
	int num = 9;
	if (PowerOfThree4(num))
		cout<<"YES, it is power of three."<<endl;
	else
		cout<<"NO, it isn't power of three."<<endl;
		
	return 0;
}

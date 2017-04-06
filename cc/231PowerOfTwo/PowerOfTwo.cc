/* 
Given an integer, write a function to determine if it is a power of two. 
*/

#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

bool PowerOfTwo(int num) // time: O(1)
{
	return num > 0 && (num & (num-1)) == 0;
}

bool PowerOfTwo2(int num) // math, time: O(1)
{
	if (num <= 0) return false;
	auto x = log10(num)/log10(2);
	return x == floor(x); // check if it is an int
}

bool PowerOfTwo3(int num) // bitset, time: O(1)
{
	return num > 0 && bitset<32>(num).count() == 1; // count how many 1s
}

bool PowerOfTwo4(int num) // math, time: O(1)
{
	// return num > 0 && (((2^30)%num) == 0); // not work because ^ is XOR, NOT power operation 2^30 = 28 (11110 ^ 000010 = 11100)
	// return num > 0 && (pow(2, 30)%num == 0); // compile error because % is only used for int
	return num > 0 && (1073741824%num == 0);
}

int main()
{
	int num = 7;
	if (PowerOfTwo4(num))
		cout<<"YES, it is power of two."<<endl;
	else
		cout<<"NO, it isn't power of two."<<endl;
		
	return 0;
}

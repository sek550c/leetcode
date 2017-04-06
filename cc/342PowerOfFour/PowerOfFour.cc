/* 
Given an integer, write a function to determine if it is a power of four.

Follow up:
Could you do it without using any loop / recursion? 
*/

#include <iostream>
#include <math.h> // log
#include <limits.h> // INT_MAX

using namespace std;

bool PowerOfFour(int n)
{
	if (n <= 0) return false;
	while (n%4 == 0)
		n /= 4;
	return n == 1;
}

bool PowerOfFour2(int n)
{
	if (n <= 0) return false;
	auto x = log10(n)/log10(4);
	return x == floor(x);
}

/*
需满足3个条件：
1.大于0;
2.只有一个1；
3.1出现在奇数位；0x55555555筛选出那些1出现于奇数位
*/
bool PowerOfFour3(int n)
{
	return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
}

int main()
{
	int num = 7;
	if (PowerOfFour3(num))
		cout<<"YES, it is power of four."<<endl;
	else
		cout<<"NO, it isn't power of four."<<endl;
		
	return 0;
}

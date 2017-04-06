/*
	Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
*/
#include<iostream>
using namespace std;

// a^b, XOR: no carry
// a&b, AND: carry
int getSum(int a, int b)
{
	int sum = 0, carry = -1;
	while(carry != 0) // 有进位没算完
	{
		sum = a^b; // 不考虑进位
		carry = (a&b)<<1; // 考虑进位，进位是进到上一位，所以需要左移
		b = carry; // 让下一轮再加 
		a = sum;
	}
	return sum;
}

int main()
{
	int num1 = 1, num2 = -1;
	cout<<num1<<" + "<<num2<<" = "<<getSum(num1, num2)<<endl;
	return 0;
}

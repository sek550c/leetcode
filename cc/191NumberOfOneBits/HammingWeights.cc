/* 
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

#include <iostream>
#include <bitset>

using namespace std;

int HammingWeight(uint32_t n) 
{
	return bitset<32>(n).count();
}

int HammingWeight2(uint32_t n) // n中1的个数=n&(n-1)中1的个数+1
{
	if (n == 0) return 0;
	return HammingWeight(n&(n-1))+1;
}

int HammingWeight3(uint32_t n) // 同方法2，循环写法
{
	int count = 0;
	while (n)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int HammingWeight4(uint32_t n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n = n >> 1;
	}
	return count;
}

int main()
{
	int num = 11;
	cout<<"Number of 1 bits: "<<HammingWeight4(num)<<endl;
	return 0;
}

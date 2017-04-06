/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime? 
*/

#include<iostream>
using namespace std;

// 常规方法
int adddigits(int num)
{
	int lastbit = -1, temp = 0;
	while(num >= 10) // 确保最终结果0~9，如果计算出来大于10，再来
	{
		temp = 0;
		while(num > 0) // 个位没数了，说明加完了
		{
			lastbit = num % 10; // 个位
			temp += lastbit; // 每次将个位加入临时结果
			num = num/10; // 除了个位的其他位
		}
		num = temp;
	}
	return num;
}

// digital root
// formula (x-1)%9+1
/*
this method depends on the truth:
N=(a[0] * 1 + a[1] * 10 + ...a[n] * 10 ^n),and a[0]...a[n] are all between [0,9]
we set M = a[0] + a[1] + ..a[n]
and another truth is that:
1 % 9 = 1, 10 % 9 = 1, 100 % 9 = 1 ...
so N % 9 = a[0] + a[1] + ..a[n]
means M = N % 9
as 9 % 9 = 0,so we can make (n - 1) % 9 + 1 to help us solve the problem when n is 9 or 9 multiple.
as N is 9, ( 9 - 1) % 9 + 1 = 9
*/
int adddigits2(int num)
{
	int ret = (num-1)%9+1;
	return ret? ret:0;
}

int adddigits3(int num)
{
	int ret = 0;
    if (num == 0)
        return 0;
    if (num%9 == 0) // 9的倍数
        return 9;
    return num%9;
}

int main()
{
	int inputnum = 0;
	cout<<"input number is "<<inputnum<<", the digital root is "<<adddigits(inputnum)<<"."<<endl;
	cout<<"input number is "<<inputnum<<", the digital root is "<<adddigits2(inputnum)<<"."<<endl;
}

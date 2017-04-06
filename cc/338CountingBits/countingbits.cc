/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include<iostream>
#include<vector>
using namespace std;

// i&(i - 1)，本来是用来判断一个数是否是2的指数的快捷方法
// ret[i] = ret[i&(i-1)]+1  i中1的个数=（i&i-1）中1的个数+1
vector<int> countBits(int num)
{
	vector<int> ret(num+1, 0); // 0~num: total num+1 numbers
	for (int i = 1; i <= num; ++i)
		ret[i] = ret[i&(i-1)] + 1;
	return ret;
}


// 偶数的1的个数=偶数/2的1的个数；奇数的1的个数=奇数/2的1的个数+1
vector<int> countBits2(int num) 
{
	vector<int> ret(num+1, 0); // 0~num: total num+1 numbers
	
	for (int i = 1; i <= num; ++i)
		if(i%2 == 0) // 偶数
			ret[i] = ret[i/2];
		else // 奇数
			ret[i] = ret[i/2] + 1;
	return ret;
}

int main()
{
	int inputnum = 10;
	vector<int> result(inputnum+1, -1), result2(inputnum+1, -1);
	result = countBits(inputnum);
	result2 = countBits2(inputnum);
	cout<<"result\t[";
	for (int i = 0; i < result.size(); i++)
	{		
		cout<<" "<<result[i];
	}
	cout<<"]"<<endl;
	
	cout<<"result2\t[";
	for (int i = 0; i < result2.size(); i++)
	{		
		cout<<" "<<result2[i];
	}
	cout<<"]"<<endl;
	return 0;
}

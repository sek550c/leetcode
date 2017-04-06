/*
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> ProdExpSelf(vector<int>& nums) // using division
{
	vector<int> ret;
	int product = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		product *= nums[i];
	}
	cout<<"product: "<<product<<endl;
	for (int i = 0; i < nums.size(); i++)
	{
		ret.push_back(product/nums[i]);
	}
	return ret;
}

vector<int> ProdExpSelf2(vector<int>& nums)
{
	int len = nums.size(), front = 1, behind = 1;
	vector<int> ret(len);
	for (int i = 0; i < len; i++)
	{
		ret[i] = front; // 拿到上一次刷的值，所以只算了前半部分的积
		//cout<<front<<endl;
		front *= nums[i]; // 值给下一次
	}
	//cout<<"product: "<<product<<endl;
	for (int i = len-1; i >= 0; i--) // 注意取值
	{
		ret[i] *= behind; // 拿到上一次刷的值，即后半部分的积，再和前半部分的积相乘得到最后结果
		//cout<<behind<<endl;
		behind *= nums[i]; // 值给下一次
	}
	return ret;
}

int main()
{
	vector<int> array = {1, 2, 3, 4}, result;
	cout<<"array: ";
	for (int i = 0; i < array.size(); i++)
	{
		cout<<" "<<array[i];
	}
	cout<<endl;
	
	result = ProdExpSelf2(array);
	
	cout<<"product : ";
	for (int i = 0; i < array.size(); i++)
	{
		cout<<" "<<result[i];
	}
	cout<<endl;
	return 0;
	
	
}

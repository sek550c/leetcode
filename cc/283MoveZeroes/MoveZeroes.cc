/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
*/
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) 
{
	int changed = 0;
	for (int i = 0; i < nums.size()-changed; i++)
	{
		cout<<"nums size: "<<nums.size()<<endl;
		if (nums[i] == 0)
		{
			nums.push_back(nums[i]);
			nums.erase(nums.begin()+i);
			changed++;
			i--; // check twice in case of consecutive 0s
		}
	}
}

void moveZeroes2(vector<int>& nums) 
{
	int cur = 0, zero = 0; // currrent index, zero index
	while (cur < nums.size())
	{
		if (nums[cur] != 0)
		{
			if (cur != zero)
				swap(nums[cur], nums[zero]);
			zero++;
		}
		cur++;
	}
}

void moveZeroes3(vector<int>& nums) 
{
	int cur = 0, zero = 0; // currrent index, zero index
	for (; cur < nums.size(); cur++)
	{
		if (nums[cur] && cur == zero) // if non-zero and same index, skip
		{
			zero++;
		}
		else if (nums[cur]) // non-zero
		{
			swap(nums[cur], nums[zero]);
			zero++;
		}
	}
}

int main()
{
	vector<int> array = {1, 0, 0, 1};
	
	cout<<"original array: ";
	for (int i = 0; i < array.size(); i++)
	{
		cout<<" "<<array[i]<<" ";
	}
	cout<<endl;
	
	moveZeroes3(array);
	
	cout<<"new array: ";
	for (int i = 0; i < array.size(); i++)
	{
		cout<<" "<<array[i]<<" ";
	}
	cout<<endl;
}

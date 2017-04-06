/* 
Given an array and a value, remove all instances of that value in place and return the new size.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new size.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return size = 2, with the first two elements of nums being 2.
*/

#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

int removeElement(vector<int>& nums, int val) 
{
	for (auto i = nums.begin(); i != nums.end(); i++) // NOTE: vector is dynamically changing
	{
		if (*i  == val)
		{
			nums.erase(i);
			i--; // make sure no consecutive element
		}
	}
	return nums.size();
}

int removeElement2(vector<int>& nums, int val) 
{
	int m = 0;
	for (int i = 0; i < nums.size(); i++) // NOTE: It doesn't matter what you leave beyond the new size.
		if (nums[i] != val) // 不等于就加入到新数组（和Q26类似）
			nums[m++] = nums[i];
			
	return m;
}

int main()
{	
	vector<int> nums = {3, 2, 2, 3};
	//vector<int> nums = {2, 2, 2, 2};
	//vector<int> nums;
	int data = 2;
	cout<<"origin: ";
	printvec(nums);
	int new_sz = removeElement2(nums, data);
	cout<<"new: ";
	printvec(nums);
	cout<<"new size: "<<new_sz<<endl;
	return 0;
}

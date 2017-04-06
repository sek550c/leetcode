/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n (n+1 numbers), find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int MissingNumber(vector<int>& nums) // sum difference
{
	int n = nums.size(), sum = 0;
	int total = n*(n+1)/2; // sum of non-missing array
	for (int i:nums) // c++ 11
		sum += i;
	return total-sum;
}

/*
			XOR
	-----------
	0	0	0
	0	1	1
	1	0	1
	1	1	0
*/
int MissingNumber2(vector<int>& nums) // XOR
{
	int n = nums.size();
	vector<int> origin;
	for (int i = 0; i < n+1; i++)
		origin.push_back(i);
	nums.insert(nums.end(), origin.begin(), origin.end()); // concatenation
	for (int i = 1; i < nums.size(); i++)
		nums[0] ^= nums[i]; // XOR
	return nums[0];
}

int MissingNumber3(vector<int>& nums) // another XOR, not construct origin
{
	int n = nums.size();
	for (int i = 0; i < nums.size(); i++) // NOTE: n is changing, NOT use i < n here
	{
		n ^= i; // equivalent origin
		n ^= nums[i];
	}
	return n;
}

int MissingNumber4(vector<int>& nums) // binary search
{
	int left = 0, right = nums.size(), mid = (left+right)/2;
	while (left < right)
	{
		mid = (left+right)/2;
		if (nums[mid] > mid) // missing num in the left part
			right = mid;
		else // otherwise missing num in the right part
			left = mid+1;
	}
	return left;
}

int main()
{
	vector<int> array = {1, 2, 3, 4, 5};
	//vector<int> array = {0, 1, 3};
	cout<<"The missing number: "<<MissingNumber4(array)<<endl;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <unordered_map>
using namespace std;

int MajorityElement(vector<int>& nums) // hash table
{
	unordered_map<int, int> table;
	for (int i = 0; i < nums.size(); i++)
	{
		if(++table[nums[i]] > nums.size()/2)
			return nums[i];
	}
	return 0;
}

int MajorityElement2(vector<int>& nums) // full sort
{
	sort(nums.begin(), nums.end());
	return nums[nums.size()/2];
}

int MajorityElement3(vector<int>& nums) // find nth element
{
	nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
	return nums[nums.size()/2];
}

int MajorityElement4(vector<int>& nums) // random choose
{
	srand((unsigned)time(NULL));
	int sz = nums.size();
	while (true)
	{
		int random = rand()%sz;
		int count = 0;
		for (int i = 0; i < sz; i++)
		{
			if (nums[i] == nums[random])
			{
				count++;
				if (count > sz/2)
					return nums[random];
			}
		}
	}
}

int main()
{
	//vector<int> array = {5, 5, 3, 4, 2, 5, 5, 1, 5, 5, 5};
	vector<int> array = {1, 2, 1};
	for (int i = 0; i < array.size(); i++)
	{
		cout<<array[i]<<" ";
	}
	int res = MajorityElement4(array);
	cout<<"\nmajority element: "<<res<<endl;
}

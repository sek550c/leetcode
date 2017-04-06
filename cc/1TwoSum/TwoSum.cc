/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
	
 Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// brute-force
vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
	return res;
}

// use map
vector<int> twoSum2(vector<int>& nums, int target) 
{
	unordered_map<int, int> table;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int num_to_find = target - nums[i];
		auto idx = table.find(num_to_find);
		if (idx != table.end()) // found
		{
			res.push_back(idx->second);
			res.push_back(i);
			return res;
		}
		else // not found
		{
			table[nums[i]] = i; //store index into map
		}
	}
	return res;
}


int main()
{
	vector<int> vec = {2, 3, 5, 8, 10};
	vector<int> result;
	int tar = 1;
	result = twoSum2(vec, tar);
	if (result.size() > 0) // found 2 index
		cout<<"["<<result[0]<<", "<<result[1]<<"]"<<endl;
	else
		cout<<"not found!"<<endl;
	return 0;
}

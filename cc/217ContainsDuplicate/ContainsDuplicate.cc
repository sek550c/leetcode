/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <unordered_map>
using namespace std;

bool ContainDuplicate(vector<int>& nums) // map
{
	unordered_map<int, int> table;
	for (int i = 0; i < nums.size(); i++)
	{
		if (++table[nums[i]] > 1)
			return true;
	}
	return false;
}

bool ContainDuplicate2(vector<int>& nums) // sort
{
	if (nums.empty())
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] == nums[i+1])
			return true;
	}
	return false;
}

int main()
{
	vector<int> array;
	//vector<int> array = {1, 2, 3, 4, 5};
	//vector<int> array = {1, 2, 3, 4, 4};
	//vector<int> array = {1};
	
	if (ContainDuplicate2(array))
	{
		cout<<"YES, array contains duplicate"<<endl;
	}
	else
	{
		cout<<"NO, array does not contain duplicate"<<endl;
	}
	return 0;
}

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
*/
#include <iostream>
//#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int, int> numtable;
	vector<int> ret;
	for (int i = 0; i < nums.size(); i++)
	{
		int NumToFind = target - nums[i];
		auto pos = numtable.find(NumToFind);
		if (pos != numtable.end()) // found
		{
			ret.push_back(pos->second);
			ret.push_back(i+1); // +1 for not zero-based
			break;
		}
		else // not found then store
		{
			numtable.insert(pair<int, int>(nums[i], i+1)); // +1 for not zero-based
		}
	}
	
	return ret;
}

int main()
{
	vector<int> array = {2, 4, 5, 8, 11, 29}, result;
	int target = 19;
	result = twoSum(array, target);
	cout<<"Index1 = "<<result[0]<<endl;
	cout<<"Index2 = "<<result[1]<<endl;
	return 0;
}

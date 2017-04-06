/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]
*/
#include <iostream>
//#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vecint;
typedef map<int, int> countmap;

vecint singlenum(vecint nums) // use map. element -> count of element
{
	countmap numsmap;
	vecint res;
	// easy implement
	for (int i = 0; i < nums.size(); i++)
		numsmap[nums[i]]++;
	/*	
	for (int i = 0; i < nums.size(); i++)
	{
		auto pos = numsmap.find(nums[i]);
		if (pos != numsmap.end()) // found
			pos-> second += 1;
		else // not found add to map
		{
			numsmap.insert(pair<int, int>(nums[i], 1));
		}
	}
	*/
	for (auto it = numsmap.begin(); it != numsmap.end(); it++)
	{
		if (it->second == 1) // only appear once
			res.push_back(it->first);
	}
	return res;
}

vecint singlenum2(vecint nums) // use set, found and erase
{
	vecint res;
	set<int> numsset;
	for (int i = 0; i < nums.size(); i++)
	{
		auto pos = numsset.find(nums[i]);
		if (pos != numsset.end()) // found and erase
			numsset.erase(pos); 
		else // not found add to set
			numsset.insert(nums[i]);
	}
	for (auto it = numsset.begin(); it != numsset.end(); it++)
	{
		res.push_back(*it);
	}
	return res;
}

vecint singlenum3(vecint nums) // using XOR
{
	vecint res = {0, 0}; // result to return 
	int diff = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		diff = diff^nums[i];
	}
	
	int keepright1bit = diff&(-diff); // 保留最末尾的1，其它位全为0

	for (int i = 0; i < nums.size(); i++)
	{
		//int temp = nums[i]&keepright1bit;
		//cout<<"nums[i]&keepright1bit: "<<temp<<endl;
		if (int(nums[i]&keepright1bit) == 0) // set: bit not set
		{
			cout<<"set 1: "<<nums[i]<<endl;
			res[0] = res[0]^nums[i];
		}
		else  // other set: bit set
		{
			cout<<"set 2: "<<nums[i]<<endl;
			res[1] = res[1]^nums[i];
		}
	}
	return res;
}

int main()
{
	vecint array = {8, 2, 7, 3, 3, 2};
	vecint result = singlenum(array);
	cout<<"["<<result[0]<<", "<<result[1]<<"]"<<endl;
	
	return 0;
}

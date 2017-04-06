/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

#include <iostream>
#include <vector>
#include <set> 
#include <map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) // not efficient enough
{
	int sz = nums.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = max(0, i-k); i != j && j < min(sz, i+k); j++) // search in the range (i-k, i+k)
		{
			if (nums[i] == nums[j])
				return true;
		}
	}
	return false;
}

bool containsNearbyDuplicate2(vector<int>& nums, int k) 
{
	map<int, int> hash;
	for (int i = 0; i < nums.size(); i++)
	{
		auto ifound = hash.find(nums[i]);
		if (ifound != hash.end() && abs(ifound->second-i) <= k) // found and distance less than k
		{
			return true;
		}
		else
		{
			hash[nums[i]] = i; // store the index, this will update old value
		}
	}
	return false;
}

bool containsNearbyDuplicate3(vector<int>& nums, int k)  // sliding window
{
    set<int> window;
    for (int i = 0; i < nums.size(); i++) 
    {
        if (i > k) window.erase(nums[i-k-1]); // window size > k, delete first element
        if (!window.insert(nums[i]).second) return true; // insert element failed => already exist. set::insert return pair<iterator, bool>
    }
    return false;
}

bool containsNearbyDuplicate4(vector<int>& nums, int k)  // same to 3
{
    set<int> window;
    for (int i = 0; i < nums.size(); i++) 
    {
        if (i > k) window.erase(nums[i-k-1]); // window size > k, delete first element
        if (window.find(nums[i]) != window.end()) return true; // found
        else window.insert(nums[i]); // otherwise insert
    }
    return false;
}

int main()
{
	//vector<int> array;
	//vector<int> array = {1, 2, 3, 4, 5};
	vector<int> array = {1, 2, 3, 4, 1, 5, 6};
	//vector<int> array = {1};
	int k = 3;
	
	if (containsNearbyDuplicate4(array, k))
	{
		cout<<"YES, array contains nearby duplicate"<<endl;
	}
	else
	{
		cout<<"NO, array does not contain nearby duplicate"<<endl;
	}
	return 0;
}

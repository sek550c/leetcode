/* 
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	vector<int> res;
	for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); )
	{
		if (nums1[i] < nums2[j])
		{
			i++;
		}
		else if (nums1[i] > nums2[j])
		{
			j++;
		}
		else
		{
			res.push_back(nums1[i]); // not unique
			i++;
			j++;
		}
	}
	return res;
}

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) // map
{
	map<int, int> table;
	vector<int> res;
	for (int num:nums1) // store
		table[num]++;
	for (int i = 0; i < nums2.size(); i++)
	{
		auto idx = table.find(nums2[i]);
		if (idx != table.end() && idx->second != 0) // found
		{
			res.push_back(nums2[i]);
			idx->second--;
		}
	}
	return res;
}

int main()
{
	vector<int> array1 = {1, 2, 2, 1, 2}, array2 = {2, 2}, result = intersection2(array1, array2);
	for (int i = 0; i < result.size(); i++)
	{
		cout<<" "<<result[i];
	}
	cout<<endl;
	
	return 0;
}

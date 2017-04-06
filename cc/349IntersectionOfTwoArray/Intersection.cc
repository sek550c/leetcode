/* 
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
    Each element in the result must be unique.
    The result can be in any order.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) // two index
{
	sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> ret;
    int i = 0,j = 0;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i] < nums2[j])
        {
            i++;
        }
        else if(nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {  
            if(ret.empty()) // empty 
            {
                ret.push_back(nums1[i]);
            }
            else
            {
                if(nums1[i] != *(ret.end()-1)) // make sure it is unique
                    ret.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return ret;
}

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) // set
{
	set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
	vector<int> ret;
	for (auto i = set1.begin(); i != set1.end(); i++)
	{
		auto pos = set2.find(*i);
		if (pos != set2.end()) // found
			ret.push_back(*i);
	}
	return ret;
}

int main()
{
	vector<int> array1 = {1, 2, 3, 2, 4}, array2 = {2, 3, 3}, result = intersection2(array1, array2);
	for (int i = 0; i < result.size(); i++)
	{
		cout<<" "<<result[i];
	}
	cout<<endl;
	
	return 0;
}

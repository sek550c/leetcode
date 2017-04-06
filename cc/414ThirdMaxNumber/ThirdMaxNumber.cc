/* 
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printvec(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

int thirdMax(vector<int>& nums) 
{
	int sz = nums.size(), cur = sz-2, count = 1;
	sort(nums.begin(), nums.end()); // asscending
	while (cur >= 0 && count != 3)
	{
		if (nums[cur] != nums[cur+1]) count++;
		cur--;
	}
	if (count != 3) return nums[sz-1];
	return nums[cur+1];
}

int thirdMax2(vector<int>& nums) 
{
    set<int> top3; // elements in set is ordered
    for (int num : nums) 
    {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin()); // erase smallest
    }
    //return top3.size() == 3 ? *top3.begin() : *top3.rbegin(); // reverse begin
    return top3.size() == 3 ? *top3.begin() : *top3.end();
}

int main()
{
	vector<int> nums = {3, 2, 7, 6, 8, 3, 4, 2, 2};
	cout<<"origin: ";
	printvec(nums);
	sort(nums.begin(), nums.end()); // asscending
	cout<<"sorted: ";
	printvec(nums);
	cout<<"3rd max: "<<thirdMax2(nums)<<endl;
	return 0;
}

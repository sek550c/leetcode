/* 
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
*/

#include <iostream>
#include <vector>
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


/*
 k = 0, 7, 14... :  1 2 3 4 5 6 7 [1 2 3 4 5 6 7]
 k = 1, 8, 15... :  1 2 3 4 5 6 [7 1 2 3 4 5 6] 7
 k = 2, 9, 16... :  1 2 3 4 5 [6 7 1 2 3 4 5] 6 7
 ...
*/
void rotate(vector<int>& nums, int k) // copy and truncate
{
    int sz = nums.size(), step = k%sz;
    nums.insert(nums.end(), nums.begin(), nums.end());
    nums.erase(nums.begin(), nums.begin()+sz-step);
    nums.erase(nums.begin()+sz, nums.end());
}

void rotate2(vector<int>& nums, int k) // assignment
{
    int sz = nums.size(), step = k%sz;
    vector<int> temp(nums);
    for (int i = 0; i < sz; i++)
    	nums[i] = temp[i-step >= 0 ? i-step : sz+i-step];
}

// Swap the last k elements with the first k elements. 
// The last k elements will be in the correct positions
// but we need to rotate the remaining (n - k) elements 
// to the right by k steps.
void rotate3(vector<int>& nums, int k) 
{
    int start = 0, n = nums.size();
    for (; k %= n; n -= k, start += k)
        for (int i = 0; i < k; i++) 
            swap(nums[start + i], nums[start + n - k + i]);
}

void rotate4(vector<int>& nums, int k) 
{
	int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.begin()+n-k); // reverse first half
    reverse(nums.begin()+n-k, nums.begin()+n); // reverse second half
    reverse(nums.begin(), nums.begin()+n); // reverse all
}

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	//vector<int> nums = {-1};
	int k = 3;
	cout<<"origin: ";
	printvec(nums);
	rotate3(nums, k);
	cout<<"rotate: ";
	printvec(nums);
	return 0;
}

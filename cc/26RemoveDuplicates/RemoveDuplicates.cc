/* 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
*/

#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

int removeDuplicates(vector<int>& nums) 
{
    int i = !nums.empty(); // if vecotr is not empty, then i = 1
    for (int n : nums)
        if (n > nums[i-1])
            nums[i++] = n;
    return i;
}

int removeDuplicates2(vector<int>& nums) 
{
	if(nums.size() < 2) return nums.size();
    int id = 1;
    for(int i = 1; i < nums.size(); i++) 
        if(nums[i] != nums[i-1]) // 和上一个不等就加入到新数组
        	nums[id++] = nums[i];
    return id;
}

int main()
{	
	vector<int> nums = {1, 2, 3, 4};
	//vector<int> nums = {2, 2, 2, 2};
	//vector<int> nums;
	cout<<"origin: ";
	printvec(nums);
	int new_sz = removeDuplicates(nums);
	cout<<"new: ";
	printvec(nums);
	cout<<"new size: "<<new_sz<<endl;
	return 0;
}

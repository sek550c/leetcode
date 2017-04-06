/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) // ERROR on leetcode
{
	int i = 0, j = 0, new_sz = m+n;
	// nums1.resize(new_sz);
	while (i < new_sz && j < n)
	{
		if(nums1[i] <= nums2[j])
		{
			i++;
			cout<<"i: "<<i<<endl;
		}
		else
		{
			nums1.insert(nums1.begin()+i, nums2[j]);
			j++;
			cout<<"insert and j: "<<j<<endl;
		}
	}
	if (nums1.size() < new_sz)
		nums1.insert(nums1.end(), nums2.begin()+j, nums2.end());
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) // recommend this method
{
	nums1.resize(m+n); // need to resize, otherwise ERROR: munmap_chunk(): invalid pointer
	int i = m-1, j = n-1, k = m+n-1;
	while(i >= 0 && j>= 0)
	{	
		cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
		if(nums1[i] > nums2[j])
			nums1[k--] = nums1[i--];
		else
			nums1[k--] = nums2[j--];
	}
	while(j >= 0) // 可能num2未完
		nums1[k--] = nums2[j--];
}

void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) // same idea to 2
{
	nums1.resize(m+n);
	int i = m - 1, j = n - 1, tar = m + n - 1;
	while (j >= 0) 
	{
		nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
	}
}

int main()
{
	//vector<int> nums1 = {1, 2, 5, 7}, nums2 = {3, 4, 6, 8, 9};
	//vector<int> nums1 = {1, 2, 5, 7}, nums2 = {1, 2, 5, 7};	
	//vector<int> nums1 = {1, 2, 5, 7}, nums2 = {0, 0, 0, 9, 10};	
	vector<int> nums1 = {1, 2, 5, 7}, nums2 = {0, 0, 0, 9, 10};	
	cout<<"nums1: ";
	printvec(nums1);
	cout<<"nums2: ";
	printvec(nums2);
	merge3(nums1, nums1.size(), nums2, nums2.size());
	cout<<"merged: ";
	printvec(nums1);
	return 0;
}

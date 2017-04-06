/* 
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> data; 

vector<int> topKFrequent(vector<int>& nums, int k) // hash map + bucket sort
{
 	unordered_map<int, int> m;
	for (int num : nums) // store in map
		++m[num];
        
	vector<vector<int>> buckets(nums.size() + 1); // allocate to bucket
	for (auto p : m)
		buckets[p.second].push_back(p.first);
        
	vector<int> ans;
	for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
		for (int num : buckets[i]) { // one bucket has maybe more than 1 element
			ans.push_back(num);
			if (ans.size() == k)
				break;
		}
	}
	return ans;
}

// 比较直观的想法是用Hash Table统计元素个数，然后用堆来找出前K个数量最多的元素。priority_queue默认是大根堆，所以可以将<计数-元素>对直接存入堆中
// http://blog.csdn.net/tstsugeg/article/details/51307441
// map and priority queue
vector<int> topKFrequent2(vector<int>& nums, int k)
{
	unordered_map<int, int> hash;  
	// 定义大根堆（默认），大值排在队列首位
	priority_queue<pair<int,int>> heap; // default: largest at front 
	vector<int> ret;  

	for(int num:nums) // O(n)
		hash[num]++;
		
	for(auto it:hash) // O(nlogn)
		heap.push(make_pair(it.second, it.first)); // <count, element>
		
	for(int i=0; i<k; ++i) 
	{
		ret.push_back(heap.top().second); // store largest element
		heap.pop();  
	}

	return ret;  
}

//虽然解决了题目，但是时间复杂度达到了O(nlogn)，因为建堆的时间复杂度是O(logn)，题目要求时间复杂度优于O(nlogn)，因此还需要优化。这里可以用小根堆取代大根堆，在堆元素超过K时，删除堆顶元素，因为它不可能是数量最多的K个元素之一，遍历完所有数组元素之后堆中剩下的K个元素即是所求结果。优化后时间复杂度为O(nlogK)
vector<int> topKFrequent3(vector<int>& nums, int k)
{
	unordered_map<int, int> hash;
	// 定义小根堆（自定义），最小值排在队首
	priority_queue<data, vector<data>, greater<data>> heap; // use vector to store, smallest at front
	vector<int> ret;

	for(int num:nums)
		hash[num]++;

	for(auto it:hash)
	{
		heap.push(make_pair(it.second, it.first));
		// 将队首（最小值）删除
		if(heap.size() > k) heap.pop(); // if heap size over k, delete smallest. so maintain a heap size of k
	}

	while(!heap.empty())
	{
		ret.push_back(heap.top().second);
		heap.pop();
	}

	return ret;
}
//另外看到有人通过桶排序来解决问题，顺便介绍一下这种方法。桶排序的基本思想就不讲了，不清楚的同学可以问度娘。假设数组共有N个元素，用编号为1~N的N个桶分别存储个数为桶号个的元素，统计完成后从第N个桶开始从后向前依次取桶中元素，直至取够K个元素即得到了结果
vector<int> topKFrequent4(vector<int>& nums, int k) 
{  
	unordered_map<int, int> hash;
	vector<vector<int>> buckets(nums.size()+1);
	vector<int> ret;

	for(int num:nums)
		hash[num]++;

	for(auto it:hash)
		buckets[it.second].push_back(it.first);

	for(int i=buckets.size()-1; i>0; --i)
	{
		for(auto num:buckets[i])
		{
			ret.push_back(num);
			if(ret.size() == k) return ret;
		}
	}
	return ret;  
}  
int main()
{
	int top = 2;
	vector<int> array = {1, 1, 2, 3, 1, 3}, result = topKFrequent4(array, top);
	for (int i = 0; i < result.size(); i++)
	{
		cout<<" "<<result[i];
	}
	cout<<endl;
	
	return 0;
	
}

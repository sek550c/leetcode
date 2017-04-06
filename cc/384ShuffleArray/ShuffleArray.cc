/*
Shuffle a set of numbers without duplicates. 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
	vector<int> nums;
public:
	Solution(vector<int> _nums) // constructor
	{
		nums = _nums;
		srand((unsigned)time(NULL)); // 初始化随机数，不然每次调用程序都是同样的值
	}
	
	vector<int> reset()
	{
		return nums;
	}
	
	vector<int> shuffle()
	{	
		vector<int> ret(nums);
		int sz = ret.size();
		for (int i = 0; i < sz; i++)
		{
			//int random = rand()%(sz-i) + i; // 从后面随机选一个
			int random = rand()%sz; // 数组里面随机选一个，事实上不用从所有数组里选取，只需要从后面选取 see fisher yates shuffle
			swap(ret[i], ret[random]); // 并交换
		}
		return ret;
	}
};

int main()
{
	vector<int> array = {1, 2, 3, 4, 5};
	Solution obj = Solution(array);
	
	//for (int i = 0; i < 100; i++)
	//{
		vector<int> after = obj.shuffle();
		vector<int> original = obj.reset();
		cout<<"after shuffle: ";
		for (int i = 0; i < after.size(); i++)
		{
			cout<<" "<<after[i];
		}
		cout<<endl;
	
		/*
		cout<<"original array: ";
		for (int i = 0; i < original.size(); i++)
		{
			cout<<" "<<original[i];
		}
		cout<<endl;
		*/
	//}
	return 0;
}

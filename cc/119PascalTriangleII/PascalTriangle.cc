/* 
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
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

vector<int> getRow(int rowIndex) 
{
	vector<int> upper = {1}, current = {1};
	for (int k = 1; k <= rowIndex; k++)
	{
		current.clear(); // need to clear before calculate
		current.push_back(1);
		for (int i = 0; i < upper.size()-1; i++)
		{
			current.push_back(upper[i]+upper[i+1]);
		}
		current.push_back(1);
		//upper.clear();
		upper.assign(current.begin(),current.end()); // update
	}
	return current;
}

/* eg. row = 3
	1 0 0 0
	1 1 0 0
	1 2 1 0
	1 3 3 1
*/
vector<int> getRow2(int rowIndex) 
{
    vector<int> res(rowIndex+1, 0); // 创建好结果，全为0
    res[0] = 1;
    for(int i = 1; i <= rowIndex; i++)
        for(int j = i; j >= 1; j--) // 从后往前
            res[j] += res[j-1]; // 更新： 当前值+前一值
    return res;
}

int main()
{	
	int row = 3;
	cout<<"Pascal's Triangle row "<<row<<": ";
	vector<int> res = getRow2(row);
	printvec(res);

	return 0;
}

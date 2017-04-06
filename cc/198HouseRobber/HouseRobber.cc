/* 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) 
{
	int planA = 0, planB = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i%2 == 0)	// either even
			planA = max(planB, planA + nums[i]);
		else			// or odd in order to make sure no adjacent houses
			planB = max(planA, planB + nums[i]);
	}
	return max(planA, planB);
}

int rob2(vector<int>& nums) 
{
	int RobPre = 0; // robbed previous
	int NotRobPre = 0; // didnt rob previous
	for (int i = 0; i < nums.size(); i++)
	{
		int CurRob = NotRobPre + nums[i]; // rob current cell
		int CurNotRob = max(RobPre, NotRobPre); // not rob current cell
		// update for next run
		RobPre = CurRob;
		NotRobPre = CurNotRob;
	}
	return max(RobPre, NotRobPre);
}

int main()
{
	vector<int> houses = {1, 2, 1, 7, 6, 2, 3, 4, 5};
	cout<<"max money: "<<rob2(houses)<<endl;
	return 0;
}

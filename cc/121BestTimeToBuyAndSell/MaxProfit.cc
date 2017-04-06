/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) // work here, but connot pass OJ
{
	int min = *min_element(prices.begin(), prices.end());
	auto minpos = min_element(prices.begin(), prices.end());
	int max = *max_element(minpos, prices.end());
	return max-min;
}

int maxProfit2(vector<int>& prices)
{
	if (prices.empty()) return 0;
	int minPrice = prices[0];
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		maxProfit = max(maxProfit, prices[i]-minPrice);
	}
	return maxProfit;
}

int main()
{
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	//vector<int> prices = {7, 6, 4, 3, 1};
	cout<<"max profit: "<<maxProfit2(prices)<<endl;
	return 0;
}

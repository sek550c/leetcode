/* 
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>

using namespace std;

void printNum(vector<int>& num)
{
	for (int i = 0; i < num.size(); i++)
	{
		cout<<num[i];
	}
	cout<<endl;
}

vector<int> plusOne(vector<int>& digits) 
{
	int sz = digits.size(), carry = 1;
	vector<int> res;
	for (int i = sz-1; i >= 0; i--)
	{
		cout<<"processing: "<<digits[i]<<endl;
		carry += digits[i];
		digits[i] = carry % 10;
		carry /= 10;
	}
	// store result
	if (carry > 0)
		res.push_back(carry);
	for (int i = 0; i < sz; i++)
		res.push_back(digits[i]);
		
	return res;
}

vector<int> plusOne2(vector<int>& digits) 
{
	vector<int> res;
	for (int i = digits.size()-1; i >= 0; i--)
	{
		if (digits[i] == 9)
			digits[i] = 0;
		else
		{
			digits[i] += 1;
			return digits;
		}
	}
	// need to extend one bit
	res.push_back(1);
	for (int i = 0; i < digits.size(); i++)
		res.push_back(digits[i]);
	return res;
}

int main()
{	
	vector<int> num = {8, 9, 9, 9};
	cout<<"Number: ";
	printNum(num);
	vector<int> result = plusOne2(num);
	cout<<"Add one: ";
	printNum(result);
	return 0;
}

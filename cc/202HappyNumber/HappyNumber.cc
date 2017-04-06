/* 
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
*/

#include <iostream>
#include <set>

using namespace std;

int DigitSquareSum(int n)
{
	int sum = 0, tmp;
	while (n)
	{
		tmp = n%10;
		sum += tmp*tmp;
		n /= 10;
	}
	return sum;
}

bool isHappy(int n) // straight forward
{
	set<int> record; // store apperance number
	while (true)
	{
		if (n == 1) return true;
		else if (record.find(n) != record.end()) // found means fall in a loop
			return false;
		else
			record.insert(n); // store
			
		n = DigitSquareSum(n);
	}
}

bool isHappy2(int n) // Floyd Cycle detection algorithm
{
	int slow, fast;
	slow = fast = n;
	do 
	{
		slow = DigitSquareSum(slow);
		fast = DigitSquareSum(fast); // fast goes twice
		fast = DigitSquareSum(fast);
		if (fast == 1) return true;
	} while (slow != fast); // slow will eventually catch up with fast if they are in a loop
	if (slow == 1) return true;
	else return false;
}

// NOTE the fact: 
// Happy numbers follow a sequence that ends in 1. All non-happy numbers follow sequences that reach the cycle:4, 16, 37, 58, 89, 145, 42, 20, 4,...
// reference: https://en.wikipedia.org/wiki/Happy_number#Sequence_behavior
// wiki上证明了所有数最终都会变到100以内，然后100以内的数要么出现1，要么出现4的循环，所以4是判断happy number的标准
bool isHappy3(int n)
{
	if (n == 1) return true;
	if (n == 4) return false;
	return isHappy3(DigitSquareSum(n));
}

int main()
{
	int num = 20;
	if (isHappy(num))
		cout<<"YES, a happy number"<<endl;
	else
		cout<<"NO, not a happy number"<<endl;
	return 0;
}

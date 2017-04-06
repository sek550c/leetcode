/* 
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
*/

#include <iostream>
#include <string>

using namespace std;

// backtrack, 回溯法，深度优先搜索
// 比如n=3
// 第一位为1，第二位为0，第三位穷举2-9（0,1被使用了），返回第二位；第二位为2（1被使用了），第三位穷举0，3-9（1,2被使用了），返回第二位；依次类推
int DFS(int target, int idx, bool* visit) { // target: 总位数， idx: 当前位数， visit: 标记是否访问过
	if (idx == target) // 当前位数等于总位数表示深度搜索到底
	{
		cout<<"pos end and return"<<endl;
		return 1;
	}

	int count = 0;
	for (int i = idx?0:1; i < 10; i++) { // 穷举0-9，检查是否被使用过（首位不为0）
		if (!visit[i]) { //未被使用，即没出现重复的
			visit[i] = true;
			cout<<"at pos "<<idx<<", "<<i<<" not used, use it, go to next pos "<<idx+1<<endl;
			count += DFS(target, idx+1, visit); // 深度优先，即继续往下一位走
			visit[i] = false;
		}
		cout<<i<<" used, try "<<i+1<<endl; // 被使用过，试下一个数字
	}
	return count;
}

int countNumbersWithUniqueDigits(int n) {
	bool visit[10] = {false};
	int count = 0;
	for (int i = 0; i <= min(10,n); i++) // 一位一位的处理
	{
		int temp = DFS(i, 0, visit);
		count += temp;
		cout<<"i"<<"="<<i<<"\tDFS"<<"="<<temp<<"\tcount"<<"="<<count<<endl;
	}
	return count;
}

int countNumbersWithUniqueDigits2(int n) { // dynamic programming f(0)=1, f(1)=9, f(2)=9*9, f(k)=9*9*8*...*(11-k)
	if (n == 0) return 1;
	if (n == 1) return 10;
	int count = 10, product = 9;
	for (int k = 2; k <= min(10, n); k++)
	{
		for (int i = 2; i <= k; i++)
		{
			product *= 11-i;
		}
		count += product;
		product = 9;
	}
	return count;
}

int main()
{
	int n = 4, res = countNumbersWithUniqueDigits2(n);
	cout<<"final result: "<<n<<": "<<res<<endl;
	return 0;
}

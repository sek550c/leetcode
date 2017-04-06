/* 
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) 
{
	string res = "";
	for (int i = a.size()-1, j = b.size()-1, carry = 0; i >= 0 || j >= 0 || carry > 0;)
	{
		int sum = 0;
		if (i >= 0) sum += (a[i--]-'0');
		if (j >= 0)	sum += (b[j--]-'0');
		sum += carry;
		int bit = sum % 2;
		res = to_string(bit) + res;
		if (sum/2 >= 1) carry = 1;
		else carry = 0;
	}
	return res;
}

string addBinary2(string a, string b) // elegant! same idea to 1
{
	string res = "";
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0; // c is carry from last loop
		c += j >= 0 ? b[j--] - '0' : 0;
		res = char(c % 2 + '0') + res; // become one bit, update res
		c /= 2; // update carry
	}
	return res;
}

int main()
{
	string num1 = "101", num2 = "100";
	cout<<num1<<" + "<<num2<<" = "<<addBinary(num1, num2)<<endl;
	return 0;
}

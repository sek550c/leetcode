/* 
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <iostream>
#include <string>

using namespace std;

// related:
// 67 AddBinary
// 258 AddDigits
// 371	GetSum

string AddStrings(string a, string b)
{
	string res = "";
	int c = 0, i = a.size()-1, j = b.size()-1;
	while (i >= 0 || j >= 0 || c > 0)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		//res = to_string(c % 10) + res; // or use below
		res = char(c % 10 + '0') + res;
		c /= 10; // carry
	}
	return res;
}

string AddStrings2(string num1, string num2) 
{
    string addString = "";
    int carry = 0;
    
    for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry > 0;)
    {
        int sum = 0;
        if (i >= 0)
        {
            sum += (int)(num1[i] - '0'); // find the relative position to '0'
            //sum += int(num1[i]); // in ACSII, '0' = 48, '1' = 49, ...
            i--;
        }
        if (j >= 0)
        {
            sum += (int)(num2[j] - '0');
            //sum += int(num2[j]);
            j--;
        }
        if (carry > 0)
        {
            sum += carry;
        }
        
        // update result
        int digitSum = sum % 10;
        addString = to_string(digitSum)+ addString;
        
        // update carry
        if (sum / 10 == 1)
        {
            carry = 1;
        }
        else 
        {
            carry = 0;
        } 
    }
    return addString;
}

int main()
{
	string num1 = "56", num2 = "789";
	cout<<num1<<" + "<<num2<<" = "<<AddStrings(num1, num2)<<endl;
	return 0;
}

/* 
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
Note:
    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed integer.
    You must not use any method provided by the library which converts/formats the number to hex directly.
*/

#include <iostream>
#include <string>
using namespace std;

string toHex(int num)
{
	string res;
    for (int i = 0; num && (i < 8); i++) // i = 8 means 8 * 4 bits = 32 bits
    {
        //int bit = num & 0xF; // or use 15
        int bit = num & 15; // keep last 4 bits using mask: 0000 ... 0000 1111
        if (bit < 10)
            res = char('0' + bit) + res; // last 4 bits convert to char in range 0~9
        else // >= 10
            res = char('a' + bit - 10) + res; // convert to char in range a~f
        num >>= 4; // num = num>>4; // move 4 bits to the right
    }
    return res.empty() ? "0" : res;
}

int main()
{
	for (int i = -16; i < 17; i++)
	{
		cout<<"num: "<<i;
		cout<<"\thex: "<<toHex(i)<<endl;;
	}
	
	return 0;
}

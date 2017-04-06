/* 
Given a roman numeral, convert it to an integer.
1 - 10:
I, II, III, IV, V, VI, VII, VIII, IX, X
L = 50, C = 100, D = 500, M = 1000
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>

using namespace std;

int RomanToInt(string s)
{
	int res = 0;
	for (int i = s.size()-1; i >= 0; i--)
	{
		char c = s[i];
		switch (c) {
		case 'I':
			res += (res >= 5 ? -1 : 1);
			break;
		case 'V':
			res += 5;
			break;
		case 'X':
			res += 10*(res >= 50 ? -1 : 1);
			break;
		case 'L':
			res += 50;
			break;
		case 'C':
			res += 100*(res >= 500 ? -1 : 1);
			break;
		case 'D':
			res += 500;
			break;
		case 'M':
			res += 1000;
			break;
		}
	}
	return res;
}

int main()
{
	string roman = "XII";
	cout<<roman<<": "<<RomanToInt(roman)<<endl;
	return 0;
}

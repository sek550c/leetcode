/* 
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y". 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isVowel(char c)
{
	//if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

string reverseVowels(string s) 
{
	vector<char> vowels;
	for (int i = 0; i < s.size(); i++) // find all vowels
		if (isVowel(s[i]))
			vowels.push_back(s[i]);
	int pos = vowels.size();
	for (int i = 0; i < s.size(); i++) // reverse all vowels
		if (isVowel(s[i]))
			s[i] = vowels[--pos];
	return s;
}

string reverseVowels2(string s) 
{
	if (s.empty()) return s;
	int i = 0, j = s.size()-1;
	while (i < j)
	{
		if (isVowel(s[i]) && isVowel(s[j])) // both
			swap(s[i++], s[j--]);
		else if (isVowel(s[i])) // only i
			j--;
		else if (isVowel(s[j])) // only j
			i++;
		else	// neither
		{
			i++;
			j--;
		}
	}
	return s;
}

int main()
{
	string s = "Aa";
	cout<<"reverse vowels: "<<reverseVowels2(s)<<endl;
	return 0;
}

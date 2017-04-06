/* 
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if  ransom  note can be constructed from the magazines ; otherwise, it will return false. Each letter in the magazine string can only be used once in your ransom note. 
*/

#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
	for (int i = 0; i < ransomNote.size(); i++)
	{
		size_t pos = magazine.find(ransomNote[i]);
		if (pos != string::npos) // found
			magazine.erase(pos, 1); // erase
		else
			return false;
	}
	return true;
}

int main()
{
	string note = "ab", mag = "aabbc";
	if (canConstruct(note, mag))
		cout<<"YES, ransom note can be constructed."<<endl;
	else
		cout<<"NO, ransom note can't be constructed."<<endl;
	return 0;
}

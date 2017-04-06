/* 
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/

#include <iostream>
#include <string>
#include <sstream> // for stringstream 

using namespace std;

int lengthOfLastWord(string s) 
{
	stringstream ss(s);
    string word;
    
    while (ss>>word);
    //if(ss.eof()) return 0;
   	return word.size();
}

int lengthOfLastWord2(string s) // lower level answer
{
	if(s.empty()) return 0;
	int n = s.length();
	while(s[n-1] == ' ') n--; // find last letter 'd'
	int i = n-1; // from last letter of last word
	while(i >= 0 && s[i] != ' ') i--; // 'W'

	return n-1-i;
}

int main()
{
	string s = "hello my name  ";
	cout<<"length of last word: "<<lengthOfLastWord2(s)<<endl;
	return 0;
}

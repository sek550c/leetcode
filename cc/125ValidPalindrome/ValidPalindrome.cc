/* 
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 

Relate:
9 Palindrome Number
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) // not consider space, punctuation(, . :)
{
	int left = 0, right = s.size() - 1;
	while (left < right) {
		while (left < right && !isalnum(s[left])) // not alpha or num (, . : " "), skip
		{	
			cout<<"left: "<<left<<endl;
			++left;
		}
		while (right > left && !isalnum(s[right])) // not alpha or num (, . : " "), skip
		{
			cout<<"right: "<<right<<endl;
			--right;
		}
		cout<<"compare: "<<left<<" "<<right<<endl;
		if (left < right && tolower(s[left++]) != tolower(s[right--])) 
		{		
		    return false;
		}
	}
	return true;
}

int main()
{
	string s = "A man, a plan, a canal: Panama";
	if (isPalindrome(s))
		cout<<"YES, it is palindrome"<<endl;
	else
		cout<<"NO, it isn't palindrome"<<endl;
	
	return 0;
}

/* 
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printmap(unordered_map<char, int>& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
	{
		cout<<i->first<<"->"<<i->second<<endl;
	}
}

int LongestPalindrome(string s) // even: ok, odd: longest ok, others -1 ok
{
	int len = 0;
	bool hasOdd = false;
	unordered_map<char, int> table;
	for (char c:s) // store
		table[c]++;
		
	//printmap(table); // for debug
	
	for (auto i = table.begin(); i != table.end(); i++)
	{
		if (i->second % 2 == 1) // odd
		{
			len += i->second-1;
			hasOdd = true;
		}
		else // even
			len += i->second;
	}
	return hasOdd? len+1:len;
}

int main()
{
	string s =  "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	//string s = "abccccdd";
	cout<<"longest palindrome: "<<LongestPalindrome(s)<<endl;
	return 0;
}

/* 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

void printmap(map<char, char>& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
		cout<<i->first<<"->"<<i->second<<endl;
}

bool isIsomorphic(string s, string t) 
{
	if (s.size() != t.size()) return false;
	map<char, char> table;
	for (int i = 0; i < s.size(); i++)
	{
		if (table.find(s[i]) == table.end()) // not found
			table[s[i]] = t[i];
		else if (table[s[i]] != t[i])
			return false;
	}
	// printmap(table);
	// do it again in case that 2 chars map to 1 value
	table.clear();
	for (int i = 0; i < t.size(); i++)
	{
		if (table.find(t[i]) == table.end()) // not found
			table[t[i]] = s[i];
		else if (table[t[i]] != s[i])
			return false;
	}
	// printmap(table);
	return true;
}

bool isIsomorphic2(string s, string t) {
    int m1[256] = {0}, m2[256] = {0}, n = s.size();
    for (int i = 0; i < n; ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
	//string s = "add", t = "egg";
	//string s = "paper", t = "title";
	string s = "abc", t = "aaa";
	if (isIsomorphic2(s, t))
		cout<<"YES, isomorphic!"<<endl;
	else
		cout<<"NO, not isomorphic!"<<endl;
	return 0;
}

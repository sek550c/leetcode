/* 
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sub_version(const string &s, int &pos) 
{
    auto num = 0;
    while (pos < s.size() && s[pos] != '.')
        num = num * 10 + s[pos++] - '0'; // calculate the int
    ++pos;
    return num;
}

int compareVersion(string s1, string s2) 
{
    int n1 = s1.size(), n2 = s2.size();
    int p1 = 0, p2 = 0;
    while (p1 < n1 || p2 < n2) {
        auto v1 = p1 < n1 ? sub_version(s1, p1) : 0;
        auto v2 = p2 < n2 ? sub_version(s2, p2) : 0;
        if (v1 > v2) return 1;
        if (v1 < v2) return -1;
    }
    return 0;
}

int main()
{
	string v1 = "1.1", v2 = "1.2";
	if (compareVersion(v1, v2) == 1)
		cout<<"v1 > v2"<<endl;
	else if (compareVersion(v1, v2) == -1)
		cout<<"v1 < v2"<<endl;
	else
		cout<<"v1 = v2"<<endl;
	return 0;
}

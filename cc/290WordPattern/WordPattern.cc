/* 
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream> // for stringstream 

using namespace std;

bool wordPattern(string pattern, string str) 
{
	unordered_map<char, string> umap1; // forward map (char -> string)
    unordered_map<string, char> umap2; // bacward map (string -> char), use TWO maps in case of "ab" and "dog dog"
    stringstream ss(str);
    string word; // hold each word (dog, cat, etc)
    for(char c : pattern) // c++ 11
    {
        if(!(ss >> word)) return false;
        if(umap1.find(c) == umap1.end() && umap2.find(word) == umap2.end() ) { // not in the map then store
            umap1[c] = word;
            umap2[word] = c;
        }
        else if(umap1[c] != word || umap2[word] != c) return false; // not match
    }
    if(!ss.eof()) return false; // finish pattern, but there are more words. (eof: end of file)
    return true;
}

int main()
{
	string pattern = "abc", str = "dog cat fish";
	if (wordPattern(pattern, str))
		cout<<"YES, follow the same pattern!"<<endl;
	else
		cout<<"NO, not follow the same pattern!"<<endl;
	return 0;
}

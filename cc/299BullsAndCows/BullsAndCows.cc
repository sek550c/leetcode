/* 
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".

You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getHint(string secret, string guess) // not work for 011 and 110
{
	if (secret.size() != guess.size()) return "0A0B";
	int bulls = 0, cows = 0;
	
	for (int i = 0; i < guess.size(); i++) // calculate bulls
	{
		if (secret[i] == guess[i]) // same value, same position
		{
			bulls++;
			secret[i] = '*';
		}
		else 
		{
			int pos = secret.find(guess[i]);
			if (pos != string::npos) // found
			{
				cows++;
				secret[pos] = '*';
			}
		}
	}
	cout<<"secret: "<<secret<<endl;
	cout<<"guess: "<<guess<<endl;
	string res = to_string(bulls) + "A" + to_string(cows) + "B";
	return res;
}

string getHint2(string secret, string guess) 
{
    int bulls = 0;
    int cows = 0;
    vector<int> sVec(10, 0); // 0 ~ 9 for secret
    vector<int> gVec(10, 0); // 0 ~ 9 for guess 
    if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
    for (int i = 0; i < secret.size(); ++i) {
        char c1 = secret[i]; char c2 = guess[i];
        if (c1 == c2) {
            ++bulls; 
        } else {
            ++sVec[c1-'0']; // store how many char in secret
            ++gVec[c2-'0']; // store how many char in guess
        }
    }
    // count cow 
    for (int i = 0; i < sVec.size(); ++i) {
        cows += min(sVec[i], gVec[i]); // maybe repeat
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
}

int main()
{
	string secret = "1123", guess = "0111";
	cout<<getHint2(secret, guess)<<endl;
	return 0;
}









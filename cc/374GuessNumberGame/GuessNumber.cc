/* 
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:

n = 10, I pick 6.

Return 6.

*/

#include <iostream>

using namespace std;

int pick = 2;

int guess(int num)
{
	if (num > pick) return -1;
	else if (num < pick) return 1;
	else return 0;
}

int guessNumber(int n) 
{	
	if (guess(n) == 0) return n; // NOTE LIMIT!!
	int low = 0, high = n; // bigger range 
	int x = low+(high-low)/2; // Do NOT use (high+low)/2 in case of overflow
	while (guess(x) != 0) // wrong guess
	{		
		if (guess(x) == 1)
		{
			low = x;
			x = x+(high-x)/2; // try higher number	
		}	
		else
		{
			high = x;
			x = low+(x-low)/2; // try lower number
		}		 
	}
	return x;
}

int guessNumber2(int n) 
{
    int high = n, low = 1;
    while (true) {
        int mid = (high - low) / 2 + mid; // Do NOT use (high+low)/2 in case of overflow
        int res = guess(mid);
        if (res == 0) { 
            return mid;
        } else if (res == 1) { // try higher
            low = mid + 1;
        } else // try lower
        { 
            high = mid - 1;
        }
    }
}
int main()
{
	//cout<<"You picked: "<<guessNumber(2)<<endl;
	cout<<"You picked: "<<guessNumber2(2126753390)<<endl;//NOTE: MAX number
	return 0;	
}

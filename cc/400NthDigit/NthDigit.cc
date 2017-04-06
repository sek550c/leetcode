/* 
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3

Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
    we divided numbers into several parts:
    1~9 10~99 100~999 ...
    first, we determine which part the result belongs to.
    the i in the while loop means the ith part.
    then we find the number that the digit belongs to,
    which is res in the code.
    finally we find the position of the digit in the number.
*/
int findNthDigit(int n) 
{
	int i = 0;
	while (n > 0)
	{
		i++; // how-many digits number
		int minus = i*(pow(10,i)-pow(10,i-1));
		if(n-minus > 0) n -= minus;
		else break;
	}
	cout<<"now n: "<<n<<"now i: "<<i<<endl;
	int res = (n+i-1)/i+pow(10,i-1)-1; // actual number
	string result = to_string(res);
	return result[(n+i-1)%i]-'0';
}

int findNthDigit2(int n) 
{
    int length=0;
    //find length
    for(int i=0; i < 10; i++)
    {
        if(n-(pow(10, i+1)-1-pow(10, i)+1)*(i+1)>0)
            n=n-(pow(10,i+1)-1-pow(10,i)+1)*(i+1);
        else{
            length=i+1;
            break;
        }
    }
    n--;
    //find actually number
    int number=pow(10,length-1)+n/length;
    //return digit
    return (int)(number/pow(10,length-1-n%length))%10;
}

int main()
{
	int n = 200;
	cout<<n<<"th digit: "<<findNthDigit(n)<<endl;
	return 0;
}


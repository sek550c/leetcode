/* 
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	p代表正向的，q代表负向的。比如 12321， 第一个循环，p=1232，q=1（q乘以10加上p的最后一位）；第二个循环，p=123，q=12；直到p=1，q=1232。此时，判断p是否为x的个位，q是否为x除个位的其他位，如同时成立，则为回文数。时间复杂度为N(n),n为数字位数
*/
bool isPalindrome(int x) 
{
	if (x < 0) return false;

    int p = x; 
    int q = 0; 
    
    while (p >= 10){
        q *=10; // 乘以10
        cout<<"\nq: "<<q<<endl;
        q += p%10; // 加上p的最后一位，这样可以形成倒序
        cout<<"q: "<<q<<endl;
        p /=10; 
        cout<<"p: "<<p<<endl;
    }
    
    return q == x / 10 && p == x % 10;
}

bool isPalindrome2(int x) 
{
	if (x < 0) return false;

    int p = x; 
    int q = 0; 
    
    while (p){ // 也可以全部倒过来
        q *=10; // 乘以10
        cout<<"\nq: "<<q<<endl;
        q += p%10; // 加上p的最后一位，这样可以形成倒序
        cout<<"q: "<<q<<endl;
        p /=10; 
        cout<<"p: "<<p<<endl;
    }
    cout<<"\nx: "<<x<<endl;
    cout<<"q: "<<q<<endl;
    return q == x;
}

bool isPalindrome3(int x) 
{
	if (x < 0) return false;

    int p = x; 
    int q = 0; 
    
    while (p > q){ // 倒一半过来
        q *=10; // 乘以10
        cout<<"\nq: "<<q<<endl;
        q += p%10; // 加上p的最后一位，这样可以形成倒序
        cout<<"q: "<<q<<endl;
        p /=10; 
        cout<<"p: "<<p<<endl;
    }
    cout<<"\np: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    return p == q/10? true : false;
}

bool isPalindrome4(int x) 
{
	if (x < 0) return false;

    int num = x; 
    int rev = 0; 
    
    while (num > rev){ // 倒一半过来
        rev = rev*10 + num%10; // 乘以10加上最后一位
        num /= 10;
    }
    //cout<<"\nnum: "<<num<<endl;
    //cout<<"rev: "<<rev<<endl;
    return num == rev/10? true : false;
}

int main()
{
	int n = 12321;
	if (isPalindrome4(n))
		cout<<"YES, it is a palindrome number"<<endl;
	else
		cout<<"NO, it isn't a palindrome number"<<endl;
	
	return 0;
}

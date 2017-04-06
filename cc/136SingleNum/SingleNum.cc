#include<iostream>
using namespace std;

int SingleNum(int *num) 
{
	int sz = sizeof(num)/sizeof(num[0]); // NOTE: num becomes a pointer, so sizeof() gives a pointer size rather array size
	cout<<"sizeof(num): "<<sizeof(num)<<endl;
	cout<<"sizeof(num[0]): "<<sizeof(num[0])<<endl;
	cout<<"size: "<<sz<<endl;
	for (int i = 1; i < sz; i++)
		num[0] = num[0]^num[i];
	return num[0];
}

int SingleNum(int *num, int sz) 
{
	for (int i = 1; i < sz; i++)
		num[0] = num[0]^num[i]; // use xor, same bits-> 0, different bits-> 1
	return num[0];
}

int main()
{
	int array[5] = {2, 4, 99, 4, 2}; // single num = 99
	int size = sizeof(array)/sizeof(array[0]);
	cout<<"size in main: "<<size<<endl;
	cout<<"single num is: "<<SingleNum(array, size)<<endl;
	return 0;
}

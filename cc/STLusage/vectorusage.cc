// build: g++ filename.cc -o appname -std=c++11
#include<iostream>
#include<vector>
#include<algorithm> // to use sort

using namespace std;

// 1.2.1 access by array method
void printvec(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

// 1.2.2 access by iterator method
void printvec2(vector<int>& nums)
{
	for (auto ite = nums.begin(); ite != nums.end(); ite++)
	{
		cout<<*ite<<" ";
	}
	cout<<endl;
}

int main()
{
	// 1. vector
	// 1.1 init
	vector<int> vecInt1;
	vector<int> vecInt2(10); // init with 10 elements, default 0s
	vector<int> vecInt3(10, 1); // init with 10 1s 
	vector<int> vecInt4(vecInt3); // init copy
	vector<int> vecInt5 = {1, 2, 3, 4, 5};
	
	// use array method
	cout<<"vecInt1: ";
	printvec(vecInt1);
	cout<<"vecInt2: ";
	printvec(vecInt2);
	// use iterator method
	cout<<"vecInt3: ";
	printvec2(vecInt3);
	cout<<"vecInt4: ";
	printvec2(vecInt4);
	cout<<"vecInt5: ";
	printvec2(vecInt5);
	
	
	// 1.2 access see function printvec and printvec2


	// 1.3 add element
	vecInt1.push_back(1);
	vecInt1.push_back(2);
	vecInt1.push_back(3);
	cout<<"vecInt1 after add: ";
	printvec(vecInt1);
	
	// 1.4 insert element
	vecInt3.insert(vecInt3.begin(), 0); // insert 0 at the beginning
	vecInt3.insert(vecInt3.end(), 3, 0); // insert 3 0s at the end
	cout<<"vecInt3 after add: ";
	printvec(vecInt3);
	
	
	// 1.5 erase element
	vecInt1.pop_back();
	vecInt1.erase(vecInt1.begin() + 1); // erase 2nd element
	cout<<"vecInt1 after erase: ";
	printvec(vecInt1);
	
	// 1.6.1 full sort
	vector<int> vecInt6 = {6, 8, 3, 2, 5, 9, 1, 4, 7}; // NOTE: c++98 do not support this kind of init
	cout<<"vecInt6: ";
	printvec(vecInt6);
	sort(vecInt6.begin(), vecInt6.end());
	cout<<"vecInt6 after sort: ";
	printvec(vecInt6);
	
	// 1.6.2 find nth element
	vector<int> vecInt7 = {6, 8, 3, 2, 5, 9, 1, 4, 7};
	cout<<"vecInt7: ";
	printvec(vecInt7);
	nth_element(vecInt7.begin(), vecInt7.begin()+4, vecInt7.end());
	cout<<"vecInt7 after part sort: ";
	printvec(vecInt7);
	cout<<"5 th element: "<<vecInt7.at(4)<<endl;
	
	// 1.6.3 find element
	vector<int> vecInt8 = {1, 3, 5, 7, 9, 11};
	int want = 7;
	// NOTE auto is not supported in c++98
	auto idx = find(vecInt8.begin(), vecInt8.end(), want); // try to find want
	// check if it is found
	if(idx != vecInt8.end()) // found
	{
		int pos = distance(vecInt8.begin(), idx);
		cout<<"found "<<want<<" at position "<<pos<<endl;
	}
	else
	{
		cout<<want<<" not found!"<<endl;
	}
	
	// 1.7 2-dim vector see 118PascalTriangle

	return 0;
}

#include<iostream>
#include<map>
#include<algorithm> // to use sort

using namespace std;

// 1.3 access
void printmap(map<int, int>& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
		cout<<i->first<<"->"<<i->second<<endl;
}

int main()
{
	// 1. map
	// 1.1 init
	map<int, int> mapIntInt1;
	map<int, int> mapIntInt2(mapIntInt1); // copy
	map<int, int> mapIntInt3(mapIntInt1.begin(), mapIntInt1.end()); // copy
	
	
	// 1.2 insert element
	mapIntInt1.insert(pair<int, int>(1, 1));
	mapIntInt1[2] = 2;
	mapIntInt1[3] = 3;
	cout<<"print mapIntInt1: "<<endl;
	printmap(mapIntInt1);
	
	// 1.4 find element
	auto ifound = mapIntInt1.find(1);
	if (ifound != mapIntInt1.end()) // found
		cout<<"found! "<<ifound->first<<"->"<<ifound->second<<endl;

	// 1.5 erase element
	mapIntInt1.erase(1);
	cout<<"print mapIntInt1 after erase: "<<endl;
	printmap(mapIntInt1);


	return 0;
}

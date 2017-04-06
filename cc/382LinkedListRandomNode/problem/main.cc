/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? 
*/
#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{	
	//cout<<"HINT: using \'Reservoir Sampling\'"<<endl;
	LinkedList mylist;
	
	// create list
	for (int i = 1; i <= 10; i++) 
	{
        Node *node = new Node(i);
        mylist.addNode(node);
    }
	cout<<"length: "<<mylist.length()<<endl;
	
	// show every node's value
	for (int i = 1; i <= mylist.length(); i++) 
	{
        cout<<"node "<<i<<" value: "<<mylist.value(i)<<endl;
    }
    
    // random value
    /*
    for (int i = 1; i <= 10; i++) 
    {
    	cout<<"random value: "<<mylist.getRandom()<<endl;
    }
    */
    	
   	// delete node
   	mylist.deleteNode(2);
   	for (int i = 1; i <= mylist.length(); i++) {
        cout<<"node "<<i<<" value: "<<mylist.value(i)<<endl;
    }
    
    return 0;
}


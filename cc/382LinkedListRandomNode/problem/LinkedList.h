#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//#ifndef NULL
//#define NULL 0

#include "Node.h"

class LinkedList
{
private:
	Node *head;
	int len;
public:
	LinkedList(); // constructor

	~LinkedList(); // destructor

	void addNode(Node *node); // add a node to the last
	
	int length(); // get the length
	
	int value(int pos); // get the value of the node
	
	int getRandom(); // return a random value in the list
	//void insertNode(int pos, int data);
	void deleteNode(int pos); //
		
};

#endif
//#endif

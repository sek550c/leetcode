#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

LinkedList::LinkedList()
{
	head = NULL;
	len = 0;
	srand((unsigned)time(NULL));
}

LinkedList::~LinkedList()
{
	delete head;
}

void LinkedList::addNode(Node *node)
{
	if (head == NULL) // first node
	{
		head = node;
		len++;
		return;
	}
	
	Node *current_node = head;
	while (current_node->next != NULL) // go through list
	{
		current_node = current_node->next;
	}
	current_node->next = node; // add new node at last
	len++;
}

int LinkedList::length()
{
	if (head == NULL) return 0;
	Node *current_node = head;
	int count = 1; // 1 node exist already
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return count;
}

int LinkedList::value(int pos)
{
	if(pos > len) 
	{
		cout<<"ERROR: exceed range!"<<endl;
		return -1; // exceed range
	}
	Node *current_node = head;
	int count = 1;
	while (current_node->next != NULL && count < pos) // go through list
	{
		current_node = current_node->next;
		count++;
	}
	return current_node->data;
}
	
int LinkedList::getRandom() // return value randomly
{
	Node *current_node = head;
	int choice = current_node->data; // choose 1st value
	int count = 2;
	while (current_node->next != NULL) // go through list
	{
		current_node = current_node->next;
		if (rand()%count == 0) // p = 1/count
			choice = current_node->data; // change choice
		count++;
	}
	return choice;
}

void LinkedList::deleteNode(int pos)
{
	if(pos < 1 || pos > len) 
	{
		cout<<"ERROR: exceed range!"<<endl;
		return; // exceed range
	}
	if(pos == len) // last node
	{
		Node *current_node = head;
		int count = 1;
		while (count < len-1) // find second to last
 		{
			current_node = current_node->next;
			count++;
		}
		Node *delete_node = current_node->next;
		current_node->next = NULL;
		delete delete_node;
		len--;
		return;
	}
	
	Node *current_node = head;
	int count = 1;
	while (current_node->next != NULL && count < pos-1) // find node one before the delete node
	{
		current_node = current_node->next;
		count++;
	}
	//cout<<"count: "<<count<<endl;
	if (current_node->next != NULL && count == pos-1)
	{
		//cout<<"running"<<endl;
		Node *delete_node = current_node->next;
		current_node->next = delete_node->next;
		delete delete_node;
		len--;
	}
}

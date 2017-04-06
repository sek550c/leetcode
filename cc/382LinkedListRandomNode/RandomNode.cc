/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? 
*/


#include <iostream>
using namespace std;

// create a linked list class
class Node
{
public:
	int data;
	Node *next;
	Node(int _data)
	{
		data = _data;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node *head;
	int len;
public:
	LinkedList() // constructor
	{
		head = NULL;
		len = 0;
	}
	~LinkedList()
	{
		delete head;
	}
	void addNode(Node *node)
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
	int value(int pos)
	{
		if(pos > len) return -1; // exceed range
		Node *current_node = head;
		int count = 1;
		while (current_node->next != NULL && count < pos) // go through list
		{
			current_node = current_node->next;
			count++;
		}
		return current_node->data;
	}
	int length()
	{
		return len;
	}
	int getRandom() // return value randomly
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
	//void insertNode(int pos, int data);
	//void deleteNode(int pos, int data);
		
};

int main()
{
	//cout<<"test rand(): "<<rand()<<endl;
	cout<<"HINT: using \'Reservoir Sampling\'"<<endl;
	LinkedList mylist;
	for (int i = 1; i <= 10; i++) {
        Node *node = new Node(i);
        mylist.addNode(node);
    }
	cout<<"length: "<<mylist.length()<<endl;
	for (int i = 1; i <= 10; i++) {
        cout<<"node "<<i<<" value: "<<mylist.value(i)<<endl;
    }
    for (int i = 1; i <= 100; i++) 
    	cout<<"random value: "<<mylist.getRandom()<<endl;
}

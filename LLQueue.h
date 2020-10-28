/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
---------------------- Linked List Header ------------------------
------------------------------------------------------------------
*/
#pragma once

#include <stdbool.h>
#include <iostream>
using namespace std;

class LinkedList
{
private:
	// structure that holds the character data and next pointer
	struct node {
		char data;
		int CoordX;
		int CoordY; 
		node* next;
	};
	typedef node* nodeptr;

	nodeptr head; // top of list
	nodeptr tail; // end of list

	int size;

public:
	// Constructor
	LinkedList() {
		head = NULL;
		tail = NULL;                                                     
		size = 0;
	}
	// Destructor
	~LinkedList() {
		nodeptr curr = head;
		nodeptr prev;

		while (curr != NULL) {
			prev = curr;
			curr = curr->next;
			delete prev;
		}
	}
	void AddNode(char x, int xC, int xY); // add a node to list
	void DeleteNode(); // delete first node from list
	char FirstNode(); // return first node of list
	int FirstNodeX(); // return first nodes x coord
	int FirstNodeY(); // return first nodes y coord
	char LastNode(); // return last node of list
	bool IsInList(char x); // True if node with value x is in list
	void Print(); // print each node in list
	int Size(); // return size of list
};

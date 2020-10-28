/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
------------------- Linked List Implentation ---------------------
------------------------------------------------------------------
*/
#include <stdbool.h>
#include <iostream>
#include "LLQueue.h"
using namespace std;

// Function for adding a node to the front of a linked list
void LinkedList::AddNode(char c, int xC, int yC) {
	nodeptr n;
	//allocate
	n = new node;
	n->data = c;
	n->CoordX = xC;
	n->CoordY = yC;
	size++;

	if (head == NULL) {
		head = n;
		tail = head;
	}
	else {
		tail->next = n;
		tail = tail->next;
	}
}
// Function for deleting item x of a linked list
void LinkedList::DeleteNode() {
	nodeptr curr;

	if (head != NULL) {
		curr = head;
		head = head->next;
		delete curr;
		size--;
	}
	
}
// Function for returning first item of a linked list
char LinkedList::FirstNode()
{
	if (head != NULL) {
		return head->data;
	}
}
int LinkedList::FirstNodeX() 
{
	if (head != NULL)
		return head->CoordX;
}
int LinkedList::FirstNodeY() 
{
	if (head != NULL)
		return head->CoordY;
}
char LinkedList::LastNode() {
	if (tail != NULL) {
		return tail->data;
	}
}
// Function for printing the contents of a linked list
void LinkedList::Print()
{
	nodeptr p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
// Function to check if data x is in list
bool LinkedList::IsInList(char x) {
	nodeptr p = head;

	while (p != NULL && x != p->data) {
		p = p->next;
	}
	return (x == p->data);
}
// Function that returns size of list
int LinkedList::Size() {
	return size;
}

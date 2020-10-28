/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
------------------- Queue Class Implentation ---------------------
------------------------------------------------------------------
*/
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include "Queue.h"
using namespace std;

// Constructor for Queue
Queue::Queue() {
	// add something here?
}
// Destructor for Queue
Queue::~Queue() {
	// add something here?
}
// Function to add item to queue
void Queue::Enqueue(QueueItem item, int x, int y) {
	QL.AddNode(item, x, y);
}
// Function that deletes item from queue and returns item 
QueueItem Queue::Dequeue() {
	QueueItem tmp;
	tmp = QL.FirstNode();
	QL.DeleteNode();

	return tmp;
}
// Function for retrieving the first item in the Queue
QueueItem Queue::GetFront() {
	return QL.FirstNode();
}
int Queue::GetX() {
	return QL.FirstNodeX();
}
int Queue::GetY() {
	return QL.FirstNodeY();
}
// Function for retrieving the last item in the Queue
QueueItem Queue::GetEnd() {
	return QL.LastNode();
}
// Function that returns if Queue is empty
bool Queue::IsEmpty() {
	int length = QL.Size();
	return bool(length == 0);
	// note if list is empty returns True or 1
}
// Prints Queue
void Queue::Print() {
	QL.Print();
}
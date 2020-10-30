/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
---------------------- Queue Class Header ------------------------
------------------------------------------------------------------
*/
#pragma once

#include <stdbool.h>
#include <iostream>
#include "LLQueue.h"
using namespace std;

class Queue {

private:
	LinkedList QL; // List of queue items

public:
	Queue(); // Constructor
	~Queue(); // Destructor

	void Enqueue(char item, int x, int y); // Add to Queue
	void Dequeue(); // Remove from Queue
	char GetFront(); // Return first item of Queue
	int GetX(); // return x coord
	int GetY(); // return y coord
	char GetEnd(); // Return last item of Queue
	
	bool IsEmpty(); // Checks if Queue is empty

	void Print(); // Prints the Queue
};
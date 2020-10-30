/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
---------------------- Maze Class Header -------------------------
------------------------------------------------------------------
*/
#pragma once

#include <stdbool.h>
#include <iostream>
#include "LLQueue.h"
using namespace std;

class Maze {

private:
	int collumns, rows; // Dimensions of Maze
	char** Original; // Original Maze
	int startX, startY; // Start coordinates

public:
	Maze() { rows = collumns = startX = startY = 0; Original = NULL; } // Constructor
	~Maze() { DeleteMaze(Original); } // Destructor

	void ReadFile(string file); // Reads in file
	char** AllocateMaze(); // Allocates a 2D char array
	int** Allocate2D(); // Allocate a 2D int array
	void GenerateVisit(int** ptr2D); // Generates an array with 0's
	char** MarkVisited(int** ptr2I); // Marks visited cells in original maze
	char** GetMaze(string name); // Returns 2D array
	int GetStartX() { return startX; } // returns start coord x
	int GetStartY() { return startY; } // returns start coord y
	int GetRows() { return rows; } // returns rows
	int GetCollumns() { return collumns; } // returns collumns
	void DeleteMaze(char** ptr2D); // Deletes a 2D char array
	void Delete2D(int** ptr2D); // Deletes a 2D int array
	void PrintC(char** ptr2D); // Prints 2D array chars
	void PrintI(int** ptr2I); // Prints 2D array ints

};
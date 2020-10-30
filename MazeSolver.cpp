/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
--------------------- Maze Solver Main File ----------------------
------------------------------------------------------------------
	To compile use g++ MazeSolver.cpp Maze.cpp Queue.cpp LLQueue.cpp -o MazeSolver

	To run use ./MazeSolver maze1.txt
*/
#include <iostream>
#include <string>
#include "Maze.h"
#include <queue>
using namespace std;

// Protptypes
void MazeSolver(char** mazeptr, Maze* M); // Solves the maze one step at a time
bool CheckAdjEnd(Maze* M2, char** mazeptr2, int x, int y); // Checks if adjacent to end

struct node {
	char data;
	int CoordX;
	int CoordY; 
	node* next;
	node(char c, int i, int i2) {
		data = c;
		CoordX = i;
		CoordY = i2;
	}
};
typedef node* nodeptr;

int main(int argc, char** argv) {
	// Reads in file name from command line and saves it
	string inFile = "";
	if (argc == 2)
		inFile = argv[1];
	else {
		cout << "Error with inputing file try again.\n";
		exit(-1);
	}

	// Testing Maze 
	Maze* M1 = new Maze;
	char** testptr;

	// Reading file and saving 2D Maze
	M1->ReadFile(inFile);

	// Set testptr to mazeptr 
	testptr = M1->GetMaze("start");

	// Printing Maze
	cout << "Maze at Start : \n";
	M1->PrintC(testptr);

	// Uses Breadth search to traverse maze
	MazeSolver(testptr, M1);

	// cleanup
	delete M1;
	exit(0);
}

void MazeSolver(char** mazeptr, Maze* M) {
	queue<nodeptr> Q;
	int currX = M->GetStartX(), currY = M->GetStartY(); // Mark S as current cell
	int rows = M->GetRows(), colls = M->GetCollumns(); // Sets collumns and rows
	int** Visit;
	Visit = M->Allocate2D(); // allocate visit

	//	cout << "Cells Visited Before (0 represents not visited) :\n";
	//	M->PrintI(Visit);

	bool empty = false;
	
	// Start Loop
	while(empty != true){
		// Step 1 Marks current cell as visited
		Visit[currY][currX] = 1;
		// Step 2 Add adjacent cells to Queue
		// Adds the North Cell to Queue if conditions true
		if (currY != 0 && Visit[currY - 1][currX] == 0 && mazeptr[currY - 1][currX] != '#'){
			Q.push(new node(mazeptr[currY - 1][currX], currX, currY - 1));
			if (currX == 0 && currY-1 == 2)
				cout << "Bad \n";
		}
		// Adds the East Cell to Queue if conditions true
		if (currX != colls - 1 && Visit[currY][currX + 1] == 0 && mazeptr[currY][currX + 1] != '#'){
			Q.push(new node(mazeptr[currY][currX + 1], currX + 1, currY));
			if (currX + 1 == 0 and currY == 2)
				cout << "Bad \n";
		}
		// Adds the South Cell to Queue if conditions true
		if (currY != rows - 1 && Visit[currY + 1][currX] == 0 && mazeptr[currY + 1][currX] != '#'){
			Q.push(new node(mazeptr[currY + 1][currX], currX, currY + 1));
			if (currX == 0 && currY + 1 == 2)
				cout << "Bad \n";
		}
		// Adds the West Cell to Queue if conditions true
		if (currX != 0 && Visit[currY][currX - 1] == 0 && mazeptr[currY][currX - 1] != '#'){
				Q.push(new node(mazeptr[currY][currX - 1], currX - 1, currY));
				if (currX-1 == 0 and currY == 2)
					cout << "Bad \n";
		}
		// checks if Queue is empty
		if (Q.empty()) {
			empty = true;
			break;
		}		
		// Step 3 Remove next item from Queue and make it the current cell
		nodeptr tmp = Q.front();
		currX = tmp->CoordX;
		currY = tmp->CoordY;
		Q.pop();
		// Step 4 Check if at end
		if (CheckAdjEnd(M, mazeptr, currX, currY) == true){
			Visit[currY][currX] = 1;
			empty = true; // exits loop
			break;
		}

	}
	
	// cout << "Cells Visited (1 represents visited) : \n";
	// M->PrintI(Visit);

	// Mark visited cells in char maze
	mazeptr = M->MarkVisited(Visit);

	cout << "Maze After Traversal (V represents visited) : \n";
	M->PrintC(mazeptr);
	
	exit(0);
}

// Function to check if next to end cell
bool CheckAdjEnd(Maze* M2, char** mazeptr2, int x, int y) {
	if (y != 0) {
		if (mazeptr2[y - 1][x] == 'G') // checks north cell
			return true;
	}
	if (x != M2->GetCollumns() - 1) {
		if (mazeptr2[y][x + 1] == 'G') // checks east cell
			return true;
	}
	if(y != M2->GetRows() - 1){
		if (mazeptr2[y + 1][x] == 'G') // checks south cell
			return true;
	}
	if (x != 0) {
		if (mazeptr2[y][x - 1] == 'G') // checks west cell
			return true;
	}
	return false;
}


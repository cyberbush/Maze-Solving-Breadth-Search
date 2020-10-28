/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
--------------------- Maze Solver Main File ----------------------
------------------------------------------------------------------
	To compile use g++ MazeSolver.cpp Maze.cpp Queue.cpp LLQueue.cpp -o MazeSolver

	To run use ./MazeSolver maze1.txt
*/
#include <iostream>
#include "Queue.h"
#include "Maze.h"
using namespace std;

// Protptypes
char** MazeSolver(char** mazeptr, Maze* M); // Solves the maze one step at a time
bool CheckAdjEnd(Maze* M, char** mazeptr, int x, int y); // Checks if adjacent to end


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
	char** testptr = NULL;
	char** solveptr = NULL;
	solveptr = M1->AllocateMaze();
	// Reading file and saving 2D Maze
	M1->ReadFile(inFile);
	// Set testptr to mazeptr 
	testptr = M1->GetMaze("start");
	// Printing Maze
	cout << "Starting Maze : \n";
	M1->PrintC(testptr);

	// Uses Breadth search to traverse maze
	solveptr = MazeSolver(testptr, M1);

	cout << "This is the maze after traversal (v represents visited) : \n";
	M1->PrintC(solveptr);

	// Solver
	/*char** solveptr = NULL;
	solveptr = M1->AllocateMaze();
	solveptr = MazeSolver(testptr, M1);
	M1->Print(solveptr);
	*/
}

char** MazeSolver(char** mazeptr, Maze* M) {
	Queue Q; // Item of Queue Class
	int currX = M->GetStartX(), currY = M->GetStartY(); // Mark S as current cell
	int** Visit = NULL;
	char** MazeV = NULL;
	Visit = M->Allocate2D(); // allocate visit
	cout << "Visit start\n";
	M->PrintI(Visit);
	bool empty = false;
	// Start Loop
	do{
		
		// Step 1 Marks current cell as visited
		Visit[currY][currX] = 1;

		// Step 2 Add adjacent cells to Queue
		// Adds the North Cell to Queue if conditions true
		if (currY != 0 && Visit[currY - 1][currX] == 0 && mazeptr[currY - 1][currX] != '#') // North Cell 
			Q.Enqueue(mazeptr[currY - 1][currX], currX, currY - 1);
		// Adds the East Cell to Queue if conditions true
		if (currX != M->GetCollumns()-1 && Visit[currY][currX + 1] == 0 && mazeptr[currY][currX + 1] != '#')
			Q.Enqueue(mazeptr[currY][currX + 1], currX + 1, currY);
		// Adds the South Cell to Queue if conditions true
		if (currY != M->GetRows()-1 && Visit[currY + 1][currX] == 0 && mazeptr[currY + 1][currX] != '#')
			Q.Enqueue(mazeptr[currY + 1][currX], currX, currY + 1);
		// Adds the West Cell to Queue if conditions true
		if (currX != 0 && Visit[currY][currX - 1] == 0 && mazeptr[currY][currX - 1] != '#')
			Q.Enqueue(mazeptr[currY][currX - 1], currX - 1, currY);

		// Step 3 Remove next item from Queue and make it the current cell
		currX = Q.GetX();
		currY = Q.GetY();
		Q.Dequeue();

		// Step 4 Check if at end
		if (CheckAdjEnd(M, mazeptr, currX, currY) == true) {
			empty = true; // exits loop
			Visit[currY][currX] = 1;
		}
		// checks if Queue is empty
		if (Q.IsEmpty())
			empty = true;

	}while (empty != true);

	cout << "These are the cells visited (1 represents visited) : \n";
	M->PrintI(Visit);

	// Mark visited cells in char maze
	char** mazeVptr = NULL;
	cout << "hi";
	mazeVptr = M->AllocateMaze();
	mazeVptr = M->MarkVisited(Visit);
	return mazeVptr;
}
// Function to check if next to end cell
bool CheckAdjEnd(Maze* M, char** mazeptr, int x, int y) {
	if (y != 0) {
		if (mazeptr[y - 1][x] == 'G') // checks north cell
			return true;
	}
	if (x != M->GetCollumns() - 1) {
		if (mazeptr[y][x + 1] == 'G') // checks east cell
			return true;
	}
	if(y != M->GetRows() - 1){
		if (mazeptr[y + 1][x] == 'G') // checks south cell
			return true;
	}
	if (x != 0) {
		if (mazeptr[y][x - 1] == 'G') // checks west cell
			return true;
	}
	return false;
}


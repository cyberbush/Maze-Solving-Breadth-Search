/* David Bush, Maze Solver Assignment 3, CS 121, Bolden, 10/24/20
------------------------------------------------------------------
------------------- Maze Class Implentation ----------------------
------------------------------------------------------------------
*/
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;
// Function that reads in file
void Maze::ReadFile(string file) {
	ifstream inputFile;
	char input;
	inputFile.open(file);
	// Read's in dimensions of maze first	
	inputFile >> collumns; // width
	inputFile >> rows; // height
	// Only can allocate after we have the dimensions
	Original = AllocateMaze();
	// Set 2D array values from file
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			inputFile >> input;
			if (input == 'S') {
				startX = j;
				startY = i;
			}

			Original[i][j] = input;
		}
	}
	inputFile.close();
}
// Function that allocates a 2D array of chars and returns it
char** Maze::AllocateMaze() {
	char** ptr2D = new char* [rows];
	for (int i = 0; i < rows; i++)
		ptr2D[i] = new char[collumns];
	return ptr2D;
}
// Function that allocates a 2D array of ints and returns it
int** Maze::Allocate2D() {
	int** ptr2D = new int* [rows];
	for (int i = 0; i < rows; i++)
		ptr2D[i] = new int[collumns];
	GenerateVisit(ptr2D);
	return ptr2D;
}
// Function fills array with 0's
void Maze::GenerateVisit(int** ptr2D) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			ptr2D[i][j] = 0;
		}
	}
}
// Function that marks visited cells in char 2D array using int 2D array
char** Maze::MarkVisited(int** ptr2I) {
	char** ptr2C = NULL;
	ptr2C = Original;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			if (ptr2I[i][j] == 1)
				ptr2C[i][j] = 'v';
			if (i == startY && j == startX) {
				ptr2C[i][j] = 'S';
			}
		}
	}
	return ptr2C;
}

// Function for deleting all pointers in the array
void Maze::DeleteMaze(char** ptr2D) {
	for (int i = 0; i < rows; i++)
		delete ptr2D[i];
	delete ptr2D;
}
// Function for deleting all pointers in the array
void Maze::Delete2D(int** ptr2D) {
	for (int i = 0; i < rows; i++)
		delete ptr2D[i];
	delete ptr2D;
}
// Function that takes a 2D array of chars and prints contents
void Maze::PrintC(char** ptr2D) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++)
			cout << ptr2D[i][j] << " ";
		cout << "\n";
	}
}
// Function that takes a 2D array of ints and prints contents
void Maze::PrintI(int** ptr2I) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			cout << ptr2I[i][j] << " ";	
		}
		cout << "\n";
	}

}
// Function that returns Maze array
char** Maze::GetMaze(string name) {
	if (name == "start")
		return Original;
	else if (NULL) {
		// place holder
	}
}
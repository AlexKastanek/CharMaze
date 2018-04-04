#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include "CharMaze.h"

using namespace std;

int main(int argc, char* argv[])
{

	string inputFile;
	CharMaze maze;
	
	//ask for maze input of size between 5x5 and 90x90
	if (argc == 2)
	{
		inputFile = argv[1];
	}
	else if (argc > 2)
	{
		cout << "ERROR: Too many arguments" << endl;
		return -1;
	}
	
	//if no input given, generate maze at random size between 5x5 and 90x90
	maze.generateMaze();
	
	//test output of maze
	maze.printMaze();


}

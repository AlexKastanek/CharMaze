#ifndef CHAR_MAZE
#define CHAR_MAZE

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Coordinate.h"

using namespace std;

class CharMaze
{

    public:
        
        CharMaze();
        CharMaze(string);
        ~CharMaze();
        
        void generateMaze();
        void generateMaze(int);
        void resetMaze();
        
        int getAdjCount(int, int, char);
        
        void printMaze();
        
    private:
    	
    	bool usingFile = false;
    	
    	int n;
    	int startPos[2];
    	int targetPos[2];
    	static int playerPos[2];
    	
    	char** maze;
    	
    	vector<Coordinate> setPath;
    	
    	const char start = 'S';
    	const char target = 'T';
    	const char path = '*';
    	const char barrier = '/';
    	
    	string fileName;

};

#endif

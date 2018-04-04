#ifndef CHAR_MAZE
#define CHAR_MAZE

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class CharMaze
{

    public:
        
        CharMaze();
        CharMaze(string);
        ~CharMaze();
        
        void generateMaze();
        void generateMaze(int);
        
        int getAdjPathCount(int, int);
        
        void printMaze();
        
    private:
    	
    	bool usingFile = false;
    	
    	int n;
    	int startPos[2];
    	int targetPos[2];
    	static int playerPos[2];
    	
    	char** maze;
    	
    	const char start = 'S';
    	const char target = 'T';
    	const char path = '*';
    	const char barrier = '/';
    	
    	string fileName;

};

#endif

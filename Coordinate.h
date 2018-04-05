#ifndef COORDINATE
#define COORDINATE

#include <iostream>
#include <fstream>
//#include "CharMaze.h"

using namespace std;

class Coordinate
{

	public:
		
		Coordinate();
		~Coordinate();
		
		//int* getPos();
		int getXPos();
		int getYPos();
		char getContent();
		
		void setPos(int, int);
		void setXPos(int);
		void setYPos(int);
		void setContent(char);
		
		void operator=(Coordinate);
		
		bool operator==(Coordinate);
	
	private:
	
		int xPos, yPos;
		char content;

};
#endif

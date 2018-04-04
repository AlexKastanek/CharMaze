#include "CharMaze.h"

CharMaze::CharMaze()
{

	usingFile = false;

}

CharMaze::CharMaze(string fileNameSource)
{

	usingFile = true;
	fileName = fileNameSource;

}

CharMaze::~CharMaze()
{

	delete maze;

}

void CharMaze::generateMaze()
{

	//generate maze with following params
		//maze must be nxn size
		//maze must be outlined with barriers
			//an nxn maze would be constrained to n-1xn-1 for this reason
		//starting position must in a corner of the mxm matrix where m = n-1
		//target position must be in a position of random value with constraints:
			//matrix of possible positions will be of size txt where t = m/2
			//matrix will be in location opposite of starting position
				//this matrix will be in the opposite corner
				//implement algorithm to return the correct corner coordinates
		//generate barriers that will always allow a path from start to target
	
	
	//generate n	
	srand (time(NULL));
	n = rand() % 25 + 5;
	
	//generate maze area with size nxn
	maze = new char*[n];
	//set each coordinate in the maze to ' '
	for (int i = 0; i < n; i++)
	{
	
		maze[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
		
			//set the barriers of the maze
			if (i == 0 || j == 0 || i == n-1 || j == n-1)
			{
				maze[i][j] = barrier;
			}
			else maze[i][j] = ' ';
		
		}
	
	}
	
	int m = n - 1;
	
	//generate starting position S and get end quadrant
	//srand (time(NULL));
	int startQuadrant = rand() % 4 + 1;
	int endQuadrant;
	switch (startQuadrant)
	{
	
		case 1:
			startPos[0] = 1;
			startPos[1] = 1;
			endQuadrant = 4;
		break;
		
		case 2:
			startPos[0] = m-1;
			startPos[1] = 1;
			endQuadrant = 3;
		break;
		
		case 3:
			startPos[0] = 1;
			startPos[1] = m-1;
			endQuadrant = 2;
		break;
		
		case 4:
			startPos[0] = m-1;
			startPos[1] = m-1;
			endQuadrant = 1;
		break;
		
		default:
			cout << "ERROR: starting position generator failed. Invalid quadrant" << endl;
			return;
	
	}
	cout << "Starting position set to: [" 
		 << startPos[0] << "," 
		 << startPos[1] << "] where n is " 
		 << n << endl;
	maze[startPos[0]][startPos[1]] = start;
	
	//generate target position T
	//T will be located in opposite quadrant as S
	//srand (time(NULL));
	int localTargetPosX = rand() % (m/2 - 1) + 1;
	//srand (time(NULL));
	int localTargetPosY = rand() % (m/2 - 1) + 1;
	switch (endQuadrant)
	{
	
		case 1:
			targetPos[0] = localTargetPosX;
			targetPos[1] = localTargetPosY;
		break;
		
		case 2:
			targetPos[0] = localTargetPosX + m/2;
			targetPos[1] = localTargetPosY;
		break;
		
		case 3:
			targetPos[0] = localTargetPosX;
			targetPos[1] = localTargetPosY + m/2;
		break;
		
		case 4:
			targetPos[0] = localTargetPosX + m/2;
			targetPos[1] = localTargetPosY + m/2;
		break;
		
		default:
			cout << "ERROR: ending position generator failed. Invalid quadrant" << endl;
			return;
	
	}
	cout << "Target position set to: [" 
		 << targetPos[0] << "," 
		 << targetPos[1] << "] where n is " 
		 << n << endl;
	maze[targetPos[0]][targetPos[1]] = target;
	
	//generate path from S to T
	int pathPos[2] = {startPos[0], startPos[1]};
	int direction = 0, lastDirection = 0, directionCount = 4;
	bool availDirections[4] = {1,1,1,1};
	while (maze[pathPos[0]][pathPos[1]] != target)
	{
	
		for (int i = 0; i < 4; i++)
		{
			availDirections[i] = true;
		}
		directionCount = 4;
	
		//pick direction
		bool validDirection = false;
		int nextPathPos[2];
		while (!validDirection)
		{
		
			nextPathPos[0] = pathPos[0];
			nextPathPos[1] = pathPos[1];
		

			int directionIndex = rand() % directionCount;
			//if direction not available, increment until available direction is found
			while (!availDirections[directionIndex])
			{
				directionIndex = (directionIndex + 1) % 4;
				//cout << directionIndex << endl;
			}
			direction = directionIndex + 1;
			cout << direction << endl;
			
			switch (direction)
			{
			
				case 1: //UP
					nextPathPos[0]++;
					//cout << "moving up to {" << nextPathPos[0] << "," << nextPathPos[1] 
					//	 << "}" << endl;
				break;
				
				case 2: //DOWN
					nextPathPos[0]--;
					//cout << "moving down to {" << nextPathPos[0] << "," << nextPathPos[1] 
					//	 << "}" << endl;
				break;
				
				case 3: //RIGHT
					nextPathPos[1]++;
					//cout << "moving right to {" << nextPathPos[0] << "," << nextPathPos[1] 
					//	 << "}" << endl;
				break;
				
				case 4: //LEFT
					nextPathPos[1]--;
					//cout << "moving left to {" << nextPathPos[0] << "," << nextPathPos[1] 
					//	 << "}" << endl;
				break;
				
				default:
					cout << "ERROR: invalid direction generated while generating path" 
						 << endl;
					return;
			
			}
			
			//determine if direction is valid
			if (maze[nextPathPos[0]][nextPathPos[1]] == barrier)
			{
				validDirection = false;
				//cout << "hit a barrier, resetting..." << endl;
			}
			else if (getAdjPathCount(nextPathPos[0], nextPathPos[1]) > 1)
			{
				validDirection = false;
				//cout << "too many adjacent paths, resetting..." << endl;
			}
			else validDirection = true;
			
			//if direction is not valid, determine if any available directions remain
			if (!validDirection)
			{
				availDirections[direction-1] = false;
				directionCount--;
				bool noAvailDir = false;
				for (int i = 0; i < 4; i++)
				{
					if (availDirections[i])
					{
						noAvailDir = false;
						break;
					}
					else noAvailDir = true;
				}
				//if no available directions remain, backtrack until there is an opening
				if (noAvailDir)
				{
					//begin backtracking
					
				}	
			}
			lastDirection = direction;
		
		}
		
		pathPos[0] = nextPathPos[0];
		pathPos[1] = nextPathPos[1];
		if (maze[pathPos[0]][pathPos[1]] != target && maze[pathPos[0]][pathPos[1]] != start)
		{
			maze[pathPos[0]][pathPos[1]] = path;
		}
		
	}
	

}

int CharMaze::getAdjPathCount(int x, int y)
{

	int adjPathCount = 0;
	
	if (maze[x+1][y] == path)
	{
		adjPathCount++;
	}
	if (maze[x-1][y] == path)
	{
		adjPathCount++;
	}
	if (maze[x][y+1] == path)
	{
		adjPathCount++;
	}
	if (maze[x][y-1] == path)
	{
		adjPathCount++;
	}
	
	return adjPathCount;

}

void CharMaze::printMaze()
{

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}

}
















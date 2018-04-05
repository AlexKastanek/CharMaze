all: solveMaze
solveMaze: mainDriver.o CharMaze.o Coordinate.o
	g++ -std=c++11 mainDriver.o CharMaze.o Coordinate.o -o solveMaze
mainDriver.o: mainDriver.cpp
	g++ -std=c++11 -c mainDriver.cpp
CharMaze.o: CharMaze.cpp
	g++ -std=c++11 -c CharMaze.cpp
Coordinate.o: Coordinate.cpp
	g++ -std=c++11 -c Coordinate.cpp
clean:
	rm -rf *.o solveMaze

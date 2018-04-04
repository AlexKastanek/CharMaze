all: solveMaze
solveMaze: mainDriver.o CharMaze.o
	g++ -std=c++11 mainDriver.o CharMaze.o -o solveMaze
mainDriver.o: mainDriver.cpp
	g++ -std=c++11 -c mainDriver.cpp
CharMaze.o: CharMaze.cpp
	g++ -std=c++11 -c CharMaze.cpp
clean:
	rm -rf *.o solveMaze

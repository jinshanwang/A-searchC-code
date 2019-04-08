all: main.cpp node.cpp pathfinder.cpp mapBuilder.cpp fileReader.cpp node.h Pathfinder.h mapBuilder.h fileReader.h
	g++ -std=c++11 -o robotplanner *.cpp
clean:
	rm robotplanner
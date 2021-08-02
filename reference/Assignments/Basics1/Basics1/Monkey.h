//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#ifndef MONKEY_H
#define MONKEY_H

// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big four operators
// Do not add extra data in class
// Do not add code (that goes in *.cpp)

class Monkey
{
public:

	// insert your code here

	// accessors
	int getX();
	int getY();
	char *getStatus();
	void printStatus();

	// global variables (incremented each creation or destruction)
	static int numStringsCreated;
	static int numStringsDestroyed;

private:
	int x;
	int y;
	char *pStatus;
};


#endif

// End of file

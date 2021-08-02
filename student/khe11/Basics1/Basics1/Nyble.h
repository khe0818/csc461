//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#ifndef NYBLE_H
#define NYBLE_H
#include <stdio.h>
// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big four operators
// Do not add extra data in class
// Do not add code (that goes in *.cpp)

class Nyble
{
public:
	// insert your code here
	Nyble();
	Nyble(unsigned int);
	Nyble operator = (const Nyble &);
	Nyble(const Nyble &);
	~Nyble();


	Nyble operator+(const Nyble &);
	Nyble operator+(const int);
	friend Nyble operator+(int, const Nyble &);
	Nyble operator+=(const Nyble &);
	
	
    Nyble operator~();
	friend Nyble operator+(const Nyble &);
	operator unsigned int();
	Nyble operator ++();
	Nyble operator++(int);
	friend Nyble operator<<(const Nyble &, int);
	unsigned char getData();

private:
	unsigned char data;

};

#endif

// End of file

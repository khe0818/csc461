//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef ALIGN_DATA_H
#define ALIGN_DATA_H

// Add default constructor to each structure
// Initialize all variable to 0

struct A
{
	int  a0;
	char a1;
};

struct B
{
	float b0;
	float b1;
	float b2;
};

struct C
{
	double c0;
	char   c1;
};

struct D
{
	A      a;
	double d;
	B      b;
	C      c;
};

#endif

// ---  End of File ---------------

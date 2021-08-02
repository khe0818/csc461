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
	A() {
		a0 = 0;
		a1 = 0;
	};
};

struct B
{
	float b0;
	float b1;
	float b2;
	B() {
		b0 = 0;
		b1 = 0;
		b2 = 0;
	};
};

struct C
{
	double c0;
	char   c1;
	C() {
		c0 = 0;
		c1 = 0;

	};
};

struct D
{
	A      a;
	double d;
	B      b;
	C      c;
	D(){
		d = 0;
	};
};

#endif

// ---  End of File ---------------

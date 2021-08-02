//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef B_H
#define B_H

#include "UnitTestBufferManager.h"
#include "A.h"

// ----------------------------------------------------------------------
//
// Problem 1
//
// Related files:  A.h, B.h
//
// Rules: 
//     FIX class A to prevent the memory leak in the unit tests
//
//     1) Only modify class A
//     2) Do NOT modify class B in any way
//
// ----------------------------------------------------------------------

// -----------------------------------------------------
// DO NOT MODIFY this FILE
// -----------------------------------------------------

class B : public A
{
public:
	B();

	~B();


private:
	int y;
	int *buffer;
};

#endif

// End of File

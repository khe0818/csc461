//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "J.h"

// ----------------------------------------------------------------------
//
// J - Project
//
// Rules: Fix the code to correctly print the predicted output
//        no memory leak
//
// ----------------------------------------------------------------------

Dog::Dog(int val):pVal(new int)
{
	
	*pVal = val;
	
}

Dog::~Dog()
{
	
}

// Do not modify this method
int Dog::GetVal(Dog d)
{
	return *(d.pVal);
}

// End of File

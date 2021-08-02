//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "H.h"

// ----------------------------------------------------------------------
//
// H - Project
//
// Rules: Expected to sum the numbers from 1 to 9, 
//        fixed the getNum() function
//        As ugly as this function is..., keep the same logic
//
// ----------------------------------------------------------------------

// Function getNum(), returns true/false, increments n
bool getNum(int n)
{
	n = n + 1;

	if (n < 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// End of File
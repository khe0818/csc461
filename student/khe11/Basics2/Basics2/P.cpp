//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "P.h"

// Add code here if needed

P::P()
	: d(44)
{
}

P::P(int aVal, int bVal, int cVal, int dVal):M(aVal),O(aVal,cVal), N(aVal, bVal), d(dVal)
{
	
}

void P::foo()
{
}

//-- End of File -------------------------------------------------------------- 
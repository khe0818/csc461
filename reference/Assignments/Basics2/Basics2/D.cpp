//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "D.h"

// Add code here if needed

D::D()
	: z(55)
{
}

D::D(int xVal, int yVal, int zVal)
{
	STUBBED_VAR(xVal);
	STUBBED_VAR(yVal);
	z = zVal;
}

int D::getZ()
{
	return this->z;
}

//-- End of File -------------------------------------------------------------- 
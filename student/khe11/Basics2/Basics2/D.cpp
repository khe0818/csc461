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

D::D(int xVal, int yVal, int zVal) : C(xVal
	, yVal), z(zVal) {

};


int D::getZ()
{
	return this->z;
}

//-- End of File -------------------------------------------------------------- 
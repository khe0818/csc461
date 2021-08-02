//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "N.h"

// Add code here if needed

N::N()
	: b(22)
{
}

N::N(int aVal, int bVal)
	:  b(bVal)
{
	M::M(aVal);
}

N::N(int bVal):b(bVal) {

}

void N::foo()
{
}

//-- End of File -------------------------------------------------------------- 
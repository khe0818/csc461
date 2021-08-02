//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "O.h"

// Add code here if needed

O::O()
	: c(33)
{
}

O::O(int aVal, int cVal)
	:  c(cVal)
{	
	M::M(aVal);
}

O::O(int cVal) : c(cVal) {

}

void O::foo()
{
}

//-- End of File -------------------------------------------------------------- 
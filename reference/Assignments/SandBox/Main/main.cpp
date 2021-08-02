//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"

int main()
{
	// Toggle memory tracking on... goto MemTracker.h line 75

	float x = 55.0f;

	printf("Value: %f \n", x);

	Trace::out("--------- \n");
	Trace::out("Value: %f \n", x);

}

// End of File
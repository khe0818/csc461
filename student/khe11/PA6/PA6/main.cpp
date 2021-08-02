//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

// User headers
#include "Framework.h"
#include "PerformanceTest.h"

int main()
{
	// execute the tests
	TestRegistry::RunTests();

	// Run the performance tests
	PerformanceTest();
}

// ---  End of File ---------------

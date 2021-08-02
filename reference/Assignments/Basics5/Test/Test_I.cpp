//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "I.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_I_Enable
TEST(Test_I, ProgramTestsGroup, Test_I_Enable)
{
	// initialize the array
	PrepareArray();

	//compute the Nth Triangular Number
	int sum = GetTriangularSum();

	CHECK(sum == 45);
} TEST_END
#endif

// End of File
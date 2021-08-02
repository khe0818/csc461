//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "A.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_A_Enable
TEST(Test_A, ProgramTestsGroup, Test_A_Enable)
{
	A data(32);

	CHECK(data.getFirst() == 33);
	CHECK(data.getSecond() == 32);
} TEST_END
#endif

// End of File
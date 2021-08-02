//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "B.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_B_Enable
TEST(Test_B, ProgramTestsGroup, Test_B_Enable)
{
	StPatricks x;

	CHECK( strcmp( x.GetDay(), "March 17") == 0 );
} TEST_END
#endif

// End of file
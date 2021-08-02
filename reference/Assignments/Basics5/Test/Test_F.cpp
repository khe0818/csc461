//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "F.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------
#if Test_F_Enable
TEST(Test_F, ProgramTestsGroup, Test_F_Enable)
{
	CHECK(FindBitsInNibble(0x5F3) == 8);
}	TEST_END
#endif

// End of File
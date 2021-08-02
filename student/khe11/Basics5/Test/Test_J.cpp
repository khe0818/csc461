//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "J.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------
#if Test_J_Enable
TEST(Test_J, ProgramTestsGroup, Test_J_Enable)
{
	Dog fido(20);
	CHECK(Dog::GetVal(fido) == 20);

	Dog rex(21);
	CHECK(Dog::GetVal(fido) == 20);
	CHECK(Dog::GetVal(rex) == 21);
} TEST_END
#endif

// End of File
//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "E.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_E_Enable
TEST(Test_E, ProgramTestsGroup, Test_E_Enable)
{
	Dog fido;

	CHECK(strcmp(fido.GetAction(fido), "bark") == 0);
}	TEST_END
#endif
	
// End of File
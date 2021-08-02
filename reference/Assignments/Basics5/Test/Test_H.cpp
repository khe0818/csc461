//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "H.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------
#if Test_H_Enable
TEST(Test_H, ProgramTestsGroup, Test_H_Enable)
{
	// init the variables
	int n = 0;
	int sum = 0;

	// sum up the numbers
	while (getNum(n) && n)
	{
		sum += n;
	}

	CHECK(sum == 45);
}	TEST_END
#endif

// End of File
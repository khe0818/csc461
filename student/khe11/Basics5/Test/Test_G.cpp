//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "G.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_G_Enable
TEST(Test_G, ProgramTestsGroup, Test_G_Enable)
{
	// Create the array
	int *pData = ArrayOfInt(10);

	// initialize the array
	for (int i = 0; i < 10; i++)
	{
		pData[i] = i;
	} 

	// print the array members
	for (int i = 0; i < 10; i++)
	{
		CHECK(i == pData[i]);
	}

	delete pData;
} TEST_END
#endif
	
// End of File
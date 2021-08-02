//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "D.h"

#if Test_D_Test_Enable
TEST(Test_D, Template_Tests, Test_D_Test_Enable)
{
	// Fix D.h to have the correct behavior

	int val = 0;
	val = minD(42, 7, 68);
	CHECK(val == 7);

	const char *  const s0 = "CSC";
	const char *  const s1 = "461";
	const char *  const s2 = "Optimized C++";

	const char *s = 0;
	s = minD(s0, s1, s2);
	CHECK(strcmp(s, "461") == 0);

} TEST_END

#endif

// ---  End of File ---------------

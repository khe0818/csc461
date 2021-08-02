//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "B.h"

#if Test_B_Test_Enable
TEST(Test_B, Template_Tests, Test_B_Test_Enable)
{
	// Modifiy B.cpp to correct for error

	int val = B();
	CHECK(val == 4);

} TEST_END

#endif

// ---  End of File ---------------

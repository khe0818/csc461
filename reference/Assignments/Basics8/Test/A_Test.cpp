//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "A.h"

#if Test_A_Test_Enable
TEST( Test_A, Template_Tests, Test_A_Test_Enable)
{
	// Modifiy A.cpp to correct for error

	double val = A();
	CHECK(val == 4.2);

} TEST_END

#endif

// ---  End of File ---------------

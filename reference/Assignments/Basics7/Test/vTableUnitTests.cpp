//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "answerRegistry.h"

#include "A.h"
#include "C.h"
#include "E.h"
#include "M.h"

// This is here only as a place holder, 
// Ignore the errors generated!

// This file will be replaced for grading (by Keenan)
#if vtable1_A_test_enable
TEST( vtable1_A, vTableTests, vtable1_A_test_enable)
{
	CHECK_EQUAL(Answer::getAnswer(0), 9);
} TEST_END
#endif

// ---  End of File ---------------

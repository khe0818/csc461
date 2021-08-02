//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Monkey.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//   Modifying tests is an academic integrity violation
// ---------------------------------------------------------------------------------

#if Monkey_SpecializedConstructorWithDefault_Test_Enable

TEST(SpecializedConstructorWithDefault, MonkeyGroup, Monkey_SpecializedConstructorWithDefault_Test_Enable)
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK(Monkey::numStringsCreated == 0);
	CHECK(Monkey::numStringsDestroyed == 0);

	Monkey blue_mono(333);

	CHECK(blue_mono.getX() == 333);
	CHECK(blue_mono.getY() == 666);
	CHECK(strcmp(blue_mono.getStatus(), "Initialized by user!") == 0);
	CHECK(Monkey::numStringsCreated == 1);
	CHECK(Monkey::numStringsDestroyed == 0);

} TEST_END

#endif

// End of file

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

#if Monkey_Scope_Test_Enable

TEST( Scope, MonkeyGroup, Monkey_Scope_Test_Enable )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	if (1) 
	{
		Monkey	red_mono;

		CHECK( red_mono.getX() == 222 );
		CHECK( red_mono.getY() == 333 );
		CHECK( strcmp(red_mono.getStatus(),"Initialized with default!") == 0) ; 
		CHECK( Monkey::numStringsCreated == 1 );
		CHECK( Monkey::numStringsDestroyed == 0 );
	}

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );

} TEST_END

#endif

// End of file

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

#if Monkey_CopyConstructor_Test_Enable 

TEST( CopyConstructor, MonkeyGroup, Monkey_CopyConstructor_Test_Enable )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey blue_mono(777,888);

	CHECK( blue_mono.getX() == 777 );
	CHECK( blue_mono.getY() == 888 );
	CHECK( strcmp(blue_mono.getStatus(),"Initialized by user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	Monkey green_mono( blue_mono );

	CHECK( green_mono.getX() == 777 );
	CHECK( green_mono.getY() == 888 );
	CHECK( strcmp(green_mono.getStatus(),"Initialized by user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 2 );
	CHECK( Monkey::numStringsDestroyed == 0 );

} TEST_END

#endif

// End of file

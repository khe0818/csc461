//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Monkey.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//   Modifying tests is an academic integrity violation
// ---------------------------------------------------------------------------------

Monkey *pRed_mono = nullptr;

#if Monkey_NewFunction_Test_Enable

TEST_WITH_TEARDOWN( NewFunction, MonkeyGroup, Monkey_NewFunction_Test_Enable )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	pRed_mono = new Monkey();

	CHECK( pRed_mono->getX() == 222 );
	CHECK( pRed_mono->getY() == 333 );
	CHECK( strcmp(pRed_mono->getStatus(),"Initialized with default!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	delete pRed_mono;
	pRed_mono = nullptr;

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );

} TEST_END

TEST_TEARDOWN(NewFunction, MonkeyGroup)
{
	delete pRed_mono;
} 

#endif

// End of file

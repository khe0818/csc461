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

Monkey *pYellow_mono = nullptr;

#if Monkey_AssignmentOp_Test_Enable

TEST_WITH_TEARDOWN( AssignmentOp, MonkeyGroup, Monkey_AssignmentOp_Test_Enable )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	pYellow_mono = new Monkey( 444, 555 );

	CHECK( pYellow_mono->getX() == 444 );
	CHECK( pYellow_mono->getY() == 555 );
	CHECK( strcmp(pYellow_mono->getStatus(),"Initialized by user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	*pYellow_mono = *pYellow_mono;

	CHECK( pYellow_mono->getX() == 444 );
	CHECK( pYellow_mono->getY() == 555 );
	CHECK( strcmp(pYellow_mono->getStatus(),"Initialized by user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	delete pYellow_mono;
	pYellow_mono = nullptr;

	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 1 );

} TEST_END

TEST_TEARDOWN(AssignmentOp, MonkeyGroup)
{
	delete pYellow_mono;
}

#endif

// End of file

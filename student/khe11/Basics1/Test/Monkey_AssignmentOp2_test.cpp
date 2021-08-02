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

Monkey *pGreen_mono = nullptr;
Monkey *pBlue_mono = nullptr;

#if Monkey_AssignmentOp2_Test_Enable

TEST_WITH_TEARDOWN( AssignmentOp2, MonkeyGroup, Monkey_AssignmentOp2_Test_Enable )
{
	// reset
	Monkey::numStringsCreated = 0;
	Monkey::numStringsDestroyed = 0;

	CHECK( Monkey::numStringsCreated == 0 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	pGreen_mono = new Monkey();

	CHECK( pGreen_mono->getX() == 222 );
	CHECK( pGreen_mono->getY() == 333 );
	CHECK( strcmp(pGreen_mono->getStatus(),"Initialized with default!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 1 );
	CHECK( Monkey::numStringsDestroyed == 0 );
	
	pBlue_mono = new Monkey( 444, 555 );

	CHECK( pBlue_mono->getX() == 444 );
	CHECK( pBlue_mono->getY() == 555 );
	CHECK( strcmp(pBlue_mono->getStatus(),"Initialized by user!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 2 );
	CHECK( Monkey::numStringsDestroyed == 0 );

	*pBlue_mono = *pGreen_mono;

	CHECK( pBlue_mono->getX() == 222 );
	CHECK( pBlue_mono->getY() == 333 );
	CHECK( strcmp(pBlue_mono->getStatus(),"Initialized with default!") == 0) ; 
	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 1 );

	delete pBlue_mono;
	pBlue_mono = nullptr;

	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 2 );

	delete pGreen_mono;
	pGreen_mono = nullptr;

	CHECK( Monkey::numStringsCreated == 3 );
	CHECK( Monkey::numStringsDestroyed == 3 );

} TEST_END

TEST_TEARDOWN(AssignmentOp2, MonkeyGroup)
{
	delete pGreen_mono;
	delete pBlue_mono;
}

#endif

// End of file

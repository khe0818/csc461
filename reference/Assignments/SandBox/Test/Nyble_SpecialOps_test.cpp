//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Nyble.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!  
//   Modifying tests is an academic integrity violation!
// ---------------------------------------------------------------------------------

#if Nyble_SpecialOps_Test_Enable

TEST( SpecialOps, NybleGroup, Nyble_SpecialOps_Test_Enable )
{	
	Nyble A(5);
	Nyble B;

	B = ~A;

	CHECK( A.getData() == 5 );
	CHECK( B.getData() == 0xA );

	Nyble C(0xC);
	Nyble D;

	D = ~C;

	CHECK(C.getData() == 0xC);
	CHECK(D.getData() == 3);

} TEST_END

#endif

// End of file

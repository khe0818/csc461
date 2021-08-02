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

#if Nyble_AddOp_Test_Enable

TEST( AddOp, NybleGroup, Nyble_AddOp_Test_Enable )
{
	Nyble A(3);
	Nyble B(4);
	Nyble C;

	CHECK( A.getData() == 3 );
	CHECK( B.getData() == 4 );
	CHECK( C.getData() == 0 );

	C = A + B;

	CHECK( A.getData() == 3 );
	CHECK( B.getData() == 4 );
	CHECK( C.getData() == 7 );

	Nyble D(5);
	Nyble E(13);

	D += E;

	CHECK( D.getData() == 2 );
	CHECK( E.getData() == 13);

	Nyble F(8);
	Nyble G;

	G = F + 3;

	CHECK( F.getData() == 8 );
	CHECK( G.getData() == 11 );

	Nyble H(14);
	Nyble I;

	I = 7 + H;

	CHECK( H.getData() == 14 );
	CHECK( I.getData() == 5 );

} TEST_END

#endif

// End of file

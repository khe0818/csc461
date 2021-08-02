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

#if Nyble_Simple_Test_Enable

TEST( Simple, NybleGroup, Nyble_Simple_Test_Enable )
{
	// default
	Nyble A;

	CHECK( A.getData() == 0 );

	// copy
	Nyble B(5);
	Nyble C(B);

	CHECK( B.getData() == 5 );
	CHECK( C.getData() == 5 );

	// Assign
	Nyble D;
	Nyble E(13);

	D = E;

	CHECK( D.getData() == 13 );
	CHECK( E.getData() == 13 );

	// quick walk
	for( unsigned int i = 0; i < 20; i++)
	{
		Nyble K(i);
		CHECK ( K.getData() < 16 );
	}

	// Random check
	Nyble F(4);
	Nyble G(15);
	Nyble H(16);
	Nyble I(17);
	Nyble J(33);

	CHECK( F.getData() == 4 );
	CHECK( G.getData() == 0xF );
	CHECK( H.getData() == 0 );
	CHECK( I.getData() == 1 );
	CHECK( J.getData() == 1 );

} TEST_END

#endif

// End of file

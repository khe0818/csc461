//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Nyble.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!  (yes you)
//   Modifying tests is an academic integrity violation!
// ---------------------------------------------------------------------------------

#if Nyble_SpecialOps2_Test_Enable

TEST(SpecialOps2, NybleGroup, Nyble_SpecialOps2_Test_Enable )
{
	Nyble C(7);
	Nyble D;

	D = +C;

	CHECK(C.getData() == 7);
	CHECK(D.getData() == 9);

} TEST_END

#endif

// End of file

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

#if Nyble_SpecialOps3_Test_Enable

TEST(SpecialOps3, NybleGroup, Nyble_SpecialOps3_Test_Enable )
{
	// You have to use the casting operator for the next code segment below
	// Do not use another technique, please single step through your code

	// For academic purposes, 
	//     please have your casting operator add 3 to the converted value
	Nyble E(13);
	unsigned int MonkeyVal(0);

	MonkeyVal = E;

	CHECK(MonkeyVal == 16);
	CHECK(E.getData() == 13);

} TEST_END

#endif

// End of file

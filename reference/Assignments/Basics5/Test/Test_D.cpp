//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "D.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_D_Enable
TEST(Test_D, ProgramTestsGroup, Test_D_Enable)
{
	Audi *pCar = new Audi();

	CHECK(pCar->color == Volkswagon::Color::Black);
	CHECK(pCar->numDoors == 4);
	CHECK(pCar->wheelDrive == 4);
	CHECK(pCar->wings == 0);

	delete pCar;
} TEST_END
#endif

// End of File
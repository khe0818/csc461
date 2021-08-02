//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include <string.h>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "C.h"

// ---------------------------------------------------------------------------------
// Do NOT modify this File!
//
//   Modifying tests is an academic integrity violation
//
// Do NOT change anything in this  file
//             or DIE (evil laughter....)
// ---------------------------------------------------------------------------------

#if Test_C_Enable
TEST(Test_C, ProgramTestsGroup, Test_C_Enable)
{
	Student *p;

	// hello goodbye in Spanish	
	p = new Spanish;
	CHECK(strcmp(Student::greeting, "Hola!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Adios!") == 0);


	// hello goodbye in French
	p = new French;
	CHECK(strcmp(Student::greeting, "Bonjour!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Au revoir!") == 0);


	// hello goodbye in Italian
	p = new Italian;
	CHECK(strcmp(Student::greeting, "Ciao!") == 0);
	delete p;
	CHECK(strcmp(Student::greeting, "Arrivederci!") == 0);

} TEST_END
#endif

// End of File
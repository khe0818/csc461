//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "SortStrings.h"

static char *r1 = 0;
static char *r2 = 0;
static char *r3 = 0;
static char *t1 = 0;
static char *t2 = 0;
static char *t3 = 0;

#if sort_strings_test_enable
TEST_WITH_TEARDOWN(sort_strings, s4, sort_strings_test_enable)
{
	char *s1 = "everclear cider bier daiquiri bacardi";
	char *s2 = "pug beagle chihuahua akita doberman";
	char *s3 = "blue azul rojo red green verde blanco white noir black";

	char *a1 = "bacardi bier cider daiquiri everclear";
	char *a2 = "akita beagle chihuahua doberman pug";
	char *a3 = "azul black blanco blue green noir red rojo verde white";

	r1 = new char[strlen(s1) + 1];
	r2 = new char[strlen(s2) + 1];
	r3 = new char[strlen(s3) + 1];

	t1 = new char[strlen(s1) + 2];
	t1[strlen(s1) + 1] = 0xE;
	t2 = new char[strlen(s2) + 2];
	t2[strlen(s2) + 1] = 0xE;
	t3 = new char[strlen(s3) + 2];
	t3[strlen(s3) + 1] = 0xE;

	ReorderAlphabetical(s1, r1);
	CHECK(strcmp(r1, a1) == 0);

	// concatenation overrun check
	ReorderAlphabetical(s1, t1);
	CHECK(strcmp(t1, a1) == 0);
	CHECK(t1[strlen(s1) + 1] == 0xE);

	ReorderAlphabetical(s2, r2);
	CHECK(strcmp(r2, a2) == 0);

	// concatenation overrun check
	ReorderAlphabetical(s2, t2);
	CHECK(strcmp(t2, a2) == 0);
	CHECK(t2[strlen(s2) + 1] == 0xE);

	ReorderAlphabetical(s3, r3);
	CHECK(strcmp(r3, a3) == 0);

	// concatenation overrun check
	ReorderAlphabetical(s3, t3);
	CHECK(strcmp(t3, a3) == 0);
	CHECK(t3[strlen(s3) + 1] == 0xE);

} TEST_END


TEST_TEARDOWN(sort_strings, s4)
{
	delete r1;
	delete r2;
	delete r3;

	delete t1;
	delete t2;
	delete t3;
}
#endif

// ---  End of File ---------------

//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "ComparingStrings.h"

#if compare_strings_test_enable
TEST(compare_strings, s1, compare_strings_test_enable)
{
	char *s1 = "asf;ldj2";
	char *s2 = "asf;ldk2";
	char *s3 = "asf;lde2";
	char *s4 = "asf;lde21";

	CHECK(StringCompare_1(s1, s1) == 0);
	CHECK(StringCompare_2(s1, s1) == 0);
	CHECK(StringCompare_3(s1, s1) == 0);

	CHECK(StringCompare_1(s1, s2) == -1);
	CHECK(StringCompare_2(s1, s2) == -1);
	CHECK(StringCompare_3(s1, s2) == -1);

	CHECK(StringCompare_1(s1, s3) == 1);
	CHECK(StringCompare_2(s1, s3) == 1);
	CHECK(StringCompare_3(s1, s3) == 1);

	CHECK(StringCompare_1(s1, s4) == 1);
	CHECK(StringCompare_2(s1, s4) == 1);
	CHECK(StringCompare_3(s1, s4) == 1);

} TEST_END
#endif

// ---  End of File ---------------
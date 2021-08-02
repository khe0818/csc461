//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "LengthOfStrings.h"

#if strings_len_test_enable
TEST(strings_len, s6, strings_len_test_enable)
{
	char *s1 = "12480973";
	char *s0 = "";
	char s4[] = { '\0' };
	char s3[20] = "2233";

	CHECK(LengthOfString_1(s1) == 8);
	CHECK(LengthOfString_2(s1) == 8);

	CHECK(LengthOfString_1(s3) == 4);
	CHECK(LengthOfString_2(s3) == 4);

	CHECK(LengthOfString_1(s0) == 0);
	CHECK(LengthOfString_2(s0) == 0);

	CHECK(LengthOfString_1(s4) == 0);
	CHECK(LengthOfString_2(s4) == 0);

	// I HATE string.h lack of protection for null
	// --> WOW
	// strlen( 0 );

} TEST_END
#endif

// ---  End of File ---------------
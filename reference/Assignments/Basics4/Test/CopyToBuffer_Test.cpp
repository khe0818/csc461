//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "CopyToBuffer.h"

#if copy_to_buffer_test_enable
TEST(Copy_to_Buffer, s3, copy_to_buffer_test_enable)
{
	Dog fido;
	char *s1 = "MonkeyBra";
	char *s2 = "Mono";
	char *s3 = "";
	char *s4 = "MonkeyBrai";
	char *s;

	fido.SetMessage("MonkeyBrainsAreYummy");
	s = fido.GetMessage();
	CHECK(strcmp(s, s1) == 0);
	CHECK(strcmp(s, s2) == -1);
	CHECK(strcmp(s, s4) == -1);
	CHECK(strcmp(s4, s) == 1);
	Trace::out("\n");
	fido.Print();

	fido.SetMessage("Mono");
	s = fido.GetMessage();
	CHECK(strcmp(s, s2) == 0);
	fido.Print();

	fido.SetMessage(0);
	s = fido.GetMessage();
	CHECK(strcmp(s, s3) == 0);
	fido.Print();

} TEST_END
#endif

// ---  End of File ---------------
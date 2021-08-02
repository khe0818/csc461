//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "AlignData.h"
#include "Align.h"

static char *pBuff = 0;

#if Print_Alignment_Test_Enable
TEST_WITH_TEARDOWN(Print, Alignment, Print_Alignment_Test_Enable)
{
	Align::Info Info;

	// Create a tmp buffer
	const unsigned int BUFF_SIZE = 256;
	pBuff = new char[BUFF_SIZE];
	assert(pBuff != 0);
	
	//-------------------------------------------
	// Structure A:
	//-------------------------------------------

	// Fill tmp buffer with 0xAA
	memset(pBuff, 0xAA, BUFF_SIZE);

	// Construct structure in the memory
	A *pA = placement_new(pBuff, A);

	// Print it
	Trace::out("\n");
	Info = Align::PrintME(pA, sizeof(A), "data A");
	Trace::out("\n");

	CHECK(Info.NumTotalBytes == 8);
	CHECK(Info.NumBytesOfPadding == 3);

	//-------------------------------------------
	// Structure B:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);
	B *pB = placement_new(pBuff, B);
	Info = Align::PrintME(pB, sizeof(B), "data B");
	Trace::out("\n");

	CHECK(Info.NumTotalBytes == 12);
	CHECK(Info.NumBytesOfPadding == 0);

	//-------------------------------------------
	// Structure C:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);
	C *pC = placement_new(pBuff, C);
	Info = Align::PrintME(pC, sizeof(C), "data C");
	Trace::out("\n");

	CHECK(Info.NumTotalBytes == 16);
	CHECK(Info.NumBytesOfPadding == 7);

	//-------------------------------------------
	// Structure D:
	//-------------------------------------------

	memset(pBuff, 0xAA, BUFF_SIZE);
	D *pD = placement_new(pBuff, D);
	Info = Align::PrintME(pD, sizeof(D), "data D");
	Trace::out("\n");

	CHECK(Info.NumTotalBytes == 48);
	CHECK(Info.NumBytesOfPadding == 14);


} TEST_END



TEST_TEARDOWN(Print, Alignment)
{
	delete[] pBuff;
}
#endif

// ---  End of File ---------------

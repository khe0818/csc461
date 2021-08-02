//----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------
// UnitTest v.2.0.0
//---------------------------------------------------------------------------- 

#include "UnitTest.h"

Test::Test(const char * pTestName)
	:SLink()
{
	// initialized data
	this->pName = pTestName;
	this->testFunc = this;

	// register it
	TestRegistry::AddTest(this);

}
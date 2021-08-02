//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "B.h"

// -----------------------------------------------------
// DO NOT MODIFY this FILE
// -----------------------------------------------------

B::B()
	: y(33)
{
	this->buffer = new int[100];
	UnitTestBufferManager::getInstance()->increment();
}

B::~B()
{
	delete[] this->buffer;
	UnitTestBufferManager::getInstance()->decrement();
}

//-- End of File -------------------------------------------------------------- 
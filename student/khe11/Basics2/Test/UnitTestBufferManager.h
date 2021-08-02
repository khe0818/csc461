//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef UNIT_TEST_BUFFER_MANAGER_H
#define UNIT_TEST_BUFFER_MANAGER_H

// ----------------------------------------------------------------------------
//
// Singleton to track the number of allocations (needed to detect leaks)
//
// Do NOT modify this file
//
// ----------------------------------------------------------------------------

class UnitTestBufferManager
{
public:
	static UnitTestBufferManager *getInstance()
	{
		return privGetInstance();
	}

	void increment()
	{
		this->numBuffers++;
	}

	void decrement()
	{
		this->numBuffers--;
	}

	int getCount()
	{
		return this->numBuffers;
	}

private:
	static UnitTestBufferManager *privGetInstance()
	{
		static UnitTestBufferManager instance;
		return &instance;
	}

	UnitTestBufferManager()
		: numBuffers(0)
	{
	}

	int numBuffers;
};

#endif

// End of File

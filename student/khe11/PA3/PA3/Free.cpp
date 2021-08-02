//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

#include "Used.h"
#include "Free.h"
#include "Block.h"

// Add magic here
Free::Free(uint32_t blockSize):pFreeNext(nullptr),pFreePrev(nullptr), mBlockSize(blockSize), mType(Block::Free), mAboveBlockFree(false), pad(0)
{
	

}
// ---  End of File ---------------

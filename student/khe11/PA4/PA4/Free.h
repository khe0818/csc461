//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef FREE_H
#define FREE_H

#include "Types.h"
#include "Block.h"

class Used;

class Free
{
public:

	Free() = delete;
	Free(const Free &) = delete;
	Free & operator = (const Free &) = delete;
	~Free() = default;
	Free(uint32_t blockSize);

	Free        *pFreeNext;       // next free block
	Free        *pFreePrev;       // prev free block
	uint32_t    mBlockSize;       // size of block
	Block       mType;            // block type 
	bool        mAboveBlockFree;  // AboveBlock flag
	                              //    if(AboveBlock is type free) -> true 
	                              //    if(AboveBlock is type used) -> false 
	uint16_t    pad;              // future use


};

#endif 

// ---  End of File ---------------

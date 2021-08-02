//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Mem.h"

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 
#define UNUSED_VAR(p) ((void *)p)

#if Mem2_Allocate_Everything_Test_Enable
TEST(Allocate_Everything, MemoryShakeOut, Mem2_Allocate_Everything_Test_Enable)
{
	FileIO::Open("Student_", "Test_02");

	fprintf(FileIO::GetHandle(), "Test2: \n\n");

	fprintf(FileIO::GetHandle(), "1) allocate the biggest block               \n");

	fprintf(FileIO::GetHandle(), "     Mem mem;                         \n");
	fprintf(FileIO::GetHandle(), "     mem.initialize();                \n");
	fprintf(FileIO::GetHandle(), "     void *p = mem.malloc( 0xc7c0 );        \n");
	fprintf(FileIO::GetHandle(), "     mem.dump();                            \n");

	Mem mem;
	mem.initialize();
	void *p = mem.malloc(0xc7c0);

	mem.dump();

	FileIO::Close();


	// ----  GENERAL CHECK ------------------------------------------------------

		Heap *h = mem.getHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Heap Start / Heap Bottom
		CHECK_EQUAL(PTR_FIX(h->mStats.heapTopAddr), 0x30);
		CHECK_EQUAL(PTR_FIX(h->mStats.heapBottomAddr), Mem::HEAP_SIZE);

		// Used / Free
		CHECK_EQUAL(h->pFreeHead, 0);
		CHECK_EQUAL(h->pNextFit, 0);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x30);

	// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->mStats.peakNumUsed, 1);
		CHECK_EQUAL(h->mStats.peakUsedMemory, 0xc7c0);

		CHECK_EQUAL(h->mStats.currNumUsedBlocks, 1);
		CHECK_EQUAL(h->mStats.currUsedMem, 0xc7c0);

		CHECK_EQUAL(h->mStats.currNumFreeBlocks, 0);
		CHECK_EQUAL(h->mStats.currFreeMem, 0x0);

		CHECK_EQUAL(h->mStats.sizeHeap, 0xc800);

		CHECK_EQUAL(PTR_FIX(h->mStats.heapTopAddr), 0x30);
		CHECK_EQUAL(PTR_FIX(h->mStats.heapBottomAddr), 0xc800);

	// ---- Heap Walk ------------------------------------------------------

		// ---- Heap Hdr -------------------------------------------------------

			// HeapHdr Start
			CHECK_EQUAL(PTR_FIX((uint32_t)h->mStats.heapTopAddr - sizeof(Heap)), 0);
			// HeapHdr End
			CHECK_EQUAL(PTR_FIX(h->mStats.heapTopAddr), sizeof(Heap));

		// ----  Block walk ------------------------------------------------------

			uint32_t hdrStart;
			uint32_t hdrEnd;
			uint32_t blkStart;
			uint32_t blkEnd;

		// ---- HDR -------------------------------------------

			// Check type
			Used *used = (Used *)h->mStats.heapTopAddr;
			// Should be USED
			CHECK_EQUAL(used->mType, Block::Used);
			// Above Free
			CHECK_EQUAL(used->mAboveBlockFree, false);

			hdrStart = (uint32_t)used;
			hdrEnd = (uint32_t)used + sizeof(Used);

			// Hdr Start
			CHECK_EQUAL(PTR_FIX(hdrStart), 0x30);
			// Hdr End
			CHECK_EQUAL(PTR_FIX(hdrEnd), 0x40);
			// Prev
			CHECK_EQUAL(used->pUsedPrev, 0);
			// Next
			CHECK_EQUAL(used->pUsedNext, 0);
			// Hdr Size
			CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		// ---- BLOCK ----------------------------------------------------

			blkStart = hdrEnd;
			blkEnd = blkStart + used->mBlockSize;

			CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
			CHECK_EQUAL(PTR_FIX(p), PTR_FIX(hdrEnd));
			CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
			CHECK_EQUAL(used->mBlockSize, 0xc7c0);

}  TEST_END
#endif

// ---  End of File ---------------

//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <malloc.h>
#include <new>

#include "Framework.h"

#include "Mem.h"
#include "Heap.h"
#include "Block.h"

#define STUB_PLEASE_REPLACE(x) (x)

// To help with coalescing... not required
struct SecretPtr
{
	Free *pFree;
};

void Mem::initialize()
{
	// Add magic here
	Heap *pHeapTmp = this->getHeap();
	//Trace::out("top address 1111:%x\n", pHeapTmp->mStats.heapTopAddr);
	Free *pFreeStart = (Free *)(pHeapTmp + 1);
//	Trace::out("freestarter:%x\n", pFreeStart);
	Free *pFreeEnd = pFreeStart + 1;
//	Trace::out("pFreeEnd:%x\n", pFreeEnd);
	uint32_t blockSize = (uint32_t)pHeapTmp->mStats.heapBottomAddr - (uint32_t) pFreeEnd;
	Free *pFree = placement_new(pFreeStart, Free, blockSize);

	pHeapTmp->pFreeHead = pFree;
	pHeapTmp->pUsedHead = nullptr;
	pHeapTmp->pNextFit = pFree;
	Heap::Stats *pStats = &pHeapTmp->mStats;

	pStats->currFreeMem = blockSize;
	pStats->currNumFreeBlocks = 1;
}

void *Mem::malloc( const uint32_t size )
{
	//STUB_PLEASE_REPLACE(size);
	//return STUB_PLEASE_REPLACE(0);
	Heap *pHeapTmp = this->getHeap();
	
	Free *pFree = this->foundFreeBlock(size);
	void *pUsedBlock = nullptr;
	

	if (pFree != nullptr) {
		if (pFree->mBlockSize == size) {
			this->removeFreeBlock(pFree);
			this->removeFreeAdjustStats(pFree);
			this->pHeap->pNextFit = this->pHeap->pFreeHead;
			Used *pUsed = placement_new(pFree, Used, pFree->mBlockSize);
			this->AddUsedToFront(pUsed);
			this->addUsedAdjustStats(pUsed);
			pUsedBlock = this->getBlockPtr(pUsed);
			assert(pUsedBlock != nullptr);
			
		}
		else if(pFree->mBlockSize > size) {
					
			Used *pUsed = placement_new(pFree, Used, size);
			pHeapTmp->mStats.peakNumUsed++;
			pHeapTmp->mStats.peakUsedMemory += size;

			//this->AddUsedToFront(pUsed);
			this->pHeap->pUsedHead = pUsed;
			//Trace::out("%x  %x %x\n", pUsed->mBlockSize, pUsed->pUsedNext, pUsed->pUsedPrev);
			Free* pFreeStart = (Free *)((uint32_t)pUsed + size + sizeof(Used));
			pFreeStart->mBlockSize = this->pHeap->mStats.currFreeMem - size - sizeof(Free);
			Free *pFreeTemp = placement_new(pFreeStart, Free, pFreeStart->mBlockSize);
			//Trace::out("%d  %x %x\n", pFreeStart->mBlockSize, pFreeTemp->pFreeNext, pFreeTemp->pFreePrev);
			pFreeTemp->pFreePrev = nullptr;
			pFreeTemp->pFreeNext = nullptr;
			this->getHeap()->pFreeHead = pFreeTemp;
			this->getHeap()->pNextFit = this->getHeap()->pFreeHead;
			
			
			//uint32_t freeSpace = pFree->mBlockSize - size;
			
			
			pHeapTmp->mStats.currNumUsedBlocks++;
			pHeapTmp->mStats.currUsedMem += size;
			pHeapTmp->mStats.currFreeMem -= size + sizeof(Free);
			pUsedBlock = this->getBlockPtr(pUsed);
		//	Trace::out("pss:%x\n", size);
		}
		else {
			
		}
	}
	else {
		return NULL;
	}

	return pUsedBlock; 
}

Free *Mem::foundFreeBlock(const uint32_t size) const {
	Free *pFreeTmp = this->pHeap->pNextFit;
	Free *pFreeFound = nullptr;
	while (pFreeTmp != nullptr) {
		if (pFreeTmp->mBlockSize >= size) {
		//	Trace::out("%x\n", pFreeTmp->mBlockSize);
			pFreeFound = pFreeTmp;
			break;
		}
		pFreeFound = pFreeTmp->pFreeNext;
	}


	return pFreeFound;
}
 
void Mem::removeFreeBlock(const Free * pFree) const {
	assert(pFree != nullptr);
	//Trace::out("next:%x\n", pFree->mBlockSize);
	if (pFree->pFreeNext == nullptr && pFree->pFreePrev == nullptr) {
		this->pHeap->pFreeHead = nullptr;
	}
	


}

void Mem::removeFreeAdjustStats(const Free * pFree) const {
	assert(pFree != nullptr);
	if (pFree->pFreeNext == nullptr && pFree->pFreePrev == nullptr) {
		this->pHeap->mStats.currFreeMem -= pFree->mBlockSize;
		this->pHeap->mStats.currNumFreeBlocks--;
		
	}
	else {
		//Trace::out("sdsds");
		this->pHeap->mStats.currFreeMem -= pFree->mBlockSize;
	}

}
void Mem::AddUsedToFront(Used *pUsed) const {
	assert(pUsed != nullptr);
	pUsed->pUsedNext = nullptr;
	pUsed->pUsedPrev = nullptr;
	this->pHeap->pUsedHead = pUsed; 
}

void Mem::addUsedAdjustStats(const Used *pUsed) const {
	assert(pUsed != nullptr);
	this->pHeap->mStats.currUsedMem += pUsed->mBlockSize;
	this->pHeap->mStats.currNumUsedBlocks += 1;
	this->pHeap->mStats.peakNumUsed = this->pHeap->mStats.currNumUsedBlocks;
	this->pHeap->mStats.peakUsedMemory = this->pHeap->mStats.currUsedMem;

}

void *Mem::getBlockPtr(const Used *pUsed) const {
	assert(pUsed != nullptr);
	void* p = (void *)(pUsed + 1);
	return p;
}


void Mem::free( void * const data )
{
	assert(data != nullptr);
	//Heap *pHeapTmp = this->getHeap();
	//Free *pFreeStart = (Free *)pUsed;
	//Free *pFreeEnd = pFreeStart + 1;
	Used *pUsed = ((Used *)((uint32_t)data - sizeof(Used)));
	
	//pUsed->pUsedNext = nullptr;
	//pUsed->pUsedPrev = nullptr;

	
	//STUB_PLEASE_REPLACE(data);
	
	uint32_t totalFree = this->getHeap()->mStats.currFreeMem + this->getHeap()->mStats.currUsedMem;
	
	if (pUsed->pUsedNext == nullptr && pUsed->pUsedPrev == nullptr) {
		if (totalFree == pUsed->mBlockSize) {
			this->getHeap()->pUsedHead = nullptr;
		

			this->getHeap()->mStats.currUsedMem -= pUsed->mBlockSize;
			this->getHeap()->mStats.currFreeMem += pUsed->mBlockSize;
			this->getHeap()->mStats.currNumFreeBlocks++;
			this->getHeap()->mStats.currNumUsedBlocks--;
			this->getHeap()->pFreeHead = (Free *)(this->getHeap() + 1);
			this->getHeap()->pNextFit = (Free *)(this->getHeap() + 1);
			//pUsed->mAboveBlockFree = false;
			pUsed->mType = Block::Free;
		}
		else {
		
			this->getHeap()->pUsedHead = nullptr;
			//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem,(uint32_t)(this->getHeap()->mStats.heapTopAddr)- (uint32_t)(this->getHeap()->mStats.heapBottomAddr));
			this->getHeap()->mStats.currUsedMem -= pUsed->mBlockSize;
			
			this->getHeap()->mStats.currFreeMem += pUsed->mBlockSize + sizeof(Used);
			//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem, this->getHeap()->mStats.heapBottomAddr);
			this->getHeap()->mStats.currNumUsedBlocks--;
			this->getHeap()->pFreeHead = (Free *)pUsed;
			this->getHeap()->pFreeHead->mBlockSize = this->getHeap()->mStats.currFreeMem;
			this->getHeap()->pNextFit = (Free *)pUsed;
			//this->getHeap()->pFreeHead->pFreeNext = nullptr;

			//uint32_t freeSpace = pFree->mBlockSize - size;

			pUsed->mType = Block::Free;
			//Free *free = (Free *)h->mStats.heapTopAddr;
			//uint32_t hdrStart = (uint32_t)free;
			//uint32_t hdrEnd = (uint32_t)free + sizeof(Free);
			//uint32_t blkStart = hdrEnd;
			//uint32_t blkEnd = blkStart + free->mBlockSize;
			//Trace::out("number   %x %x %x %x\n", this->getHeap()->pFreeHead->mBlockSize, this->getHeap()->mStats.currUsedMem, h->mStats.currFreeMem,h->mStats.heapBottomAddr);
			//pUsed->mAboveBlockFree = false;
			
		}
	}
	else{
	
	
	
	
	}
}

void Mem::freeAllHeap(Heap *pHeapTmp, Used *pUsed) const{
	Free *pFree = placement_new((Free *)(pHeapTmp + 1), Free, pUsed->mBlockSize);
	pHeapTmp->pUsedHead = 0;
	pHeapTmp->pFreeHead = pFree;
	pHeapTmp->pNextFit = pFree;
	pHeapTmp->mStats.currFreeMem += pFree->mBlockSize;
	pHeapTmp->mStats.currUsedMem -= pUsed->mBlockSize;
	pHeapTmp->mStats.currNumUsedBlocks--;
	pHeapTmp->mStats.currNumFreeBlocks++;
}


// ---  End of File ---------------

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
	//Trace::out("top address 1111:%x\n", *pHeapTmp);
	Free *pFreeStart = (Free *)(pHeapTmp + 1);
	//	Trace::out("freestarter:%x\n", pFreeStart);
	Free *pFreeEnd = pFreeStart + 1;
	//	Trace::out("pFreeEnd:%x\n", pFreeEnd);
	uint32_t blockSize = (uint32_t)pHeapTmp->mStats.heapBottomAddr - (uint32_t)pFreeEnd;
	Free *pFree = placement_new(pFreeStart, Free, blockSize);

	pHeapTmp->pFreeHead = pFree;
	pHeapTmp->pUsedHead = nullptr;
	pHeapTmp->pNextFit = pFree;
	Heap::Stats *pStats = &pHeapTmp->mStats;

	pStats->currFreeMem = blockSize;
	pStats->currNumFreeBlocks = 1;

	Free **secretPtr = (Free **)((uint32_t)pHeap->mStats.heapBottomAddr - 32);
	*secretPtr = pFree;
}

void *Mem::malloc(const uint32_t size)
{
	//STUB_PLEASE_REPLACE(size);
	//return STUB_PLEASE_REPLACE(0);
	//locate to heap header
	Heap *pHeapTmp = this->getHeap();
	//Trace::out("top address 2222:%x\n", *pHeapTmp);
	//find nextfit free block space
	Free *pFree = this->foundFreeBlock(size);
	//assign used block 
	void *pUsedBlock = nullptr;


	if (pFree != nullptr) {
		
		if (pFree->mBlockSize == size) {
			// only one free size and malloc the whole free
			this->removeFreeBlock(pFree);
			this->removeFreeAdjustStats(pFree);
			pHeapTmp->pNextFit = pHeapTmp->pFreeHead;
			Used *pUsed = placement_new(pFree, Used, pFree->mBlockSize);
			this->AddUsedToFront(pUsed);
			this->addUsedAdjustStats(pUsed);
			pUsedBlock = this->getBlockPtr(pUsed);
			assert(pUsedBlock != nullptr);

		}
		else if (pFree->mBlockSize > size) {
			//create a used block with given size
			this->removeFreeBlock(pFree);
			this->removeFreeAdjustStats(pFree);
			Free *pFreeStart = (Free *)((uint32_t)pFree + size + sizeof(Used));
			Free *PFreeEnd = pFreeStart + 1;
			uint32_t pFreeNewSize = (uint32_t)pHeapTmp->mStats.heapBottomAddr - (uint32_t)PFreeEnd;
			Free *pFreeNew = placement_new(pFreeStart, Free, pFreeNewSize);
			pHeapTmp->mStats.currFreeMem += pFreeNew->mBlockSize;
			pHeapTmp->mStats.currNumFreeBlocks++;
			pHeapTmp->pNextFit = pFreeNew;
			pHeapTmp->pFreeHead = pFreeNew;
			Free **secretPtr = (Free **)((uint32_t)pFree + pFree->mBlockSize + sizeof(Free) - sizeof(Free *));
			*secretPtr = pHeapTmp->pFreeHead;
		//	Trace::out("malloc%x\n", pHeapTmp->pFreeHead);
			Used *pUsed = placement_new(pFree, Used, size);
			this->AddUsedToFront(pUsed);
			this->addUsedAdjustStats(pUsed);
			pUsedBlock = this->getBlockPtr(pUsed);
			assert(pUsedBlock != nullptr);
		
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
	if (pFree->pFreeNext == nullptr && pFree->pFreePrev == nullptr)
	{
		this->pHeap->pFreeHead = nullptr;
	}
	else if (pFree->pFreeNext != nullptr && pFree->pFreePrev == nullptr) 
	{
		this->pHeap->pFreeHead = pFree->pFreeNext;
		this->pHeap->pFreeHead->pFreePrev = nullptr;
	}


}

void Mem::removeFreeAdjustStats(const Free * pFree) const {
	assert(pFree != nullptr);
	if (pFree->pFreeNext == nullptr && pFree->pFreePrev == nullptr) {
		this->pHeap->mStats.currFreeMem -= pFree->mBlockSize;
		this->pHeap->mStats.currNumFreeBlocks--;
	}
	else if (pFree->pFreeNext != nullptr && pFree->pFreePrev == nullptr)
	{
		this->pHeap->mStats.currFreeMem -= pFree->mBlockSize;
	}


}
void Mem::AddUsedToFront(Used *pUsed) const {
	assert(pUsed != nullptr);
	// there is a usedblock before insert used block
	if (this->pHeap->pUsedHead != nullptr) {
		Used *tmp = this->pHeap->pUsedHead;
		this->pHeap->pUsedHead = pUsed;
		this->pHeap->pUsedHead->pUsedNext = tmp;
		this->pHeap->pUsedHead->pUsedNext->pUsedPrev = this->pHeap->pUsedHead;
		
	}
	else {
		//it's the first used block to insert
		this->pHeap->pUsedHead = pUsed;
		this->pHeap->pUsedHead->pUsedNext = nullptr;
	}
}

void Mem::addUsedAdjustStats(const Used *pUsed) const {
	assert(pUsed != nullptr);
	
	this->pHeap->mStats.currUsedMem += pUsed->mBlockSize;
	this->pHeap->mStats.currNumUsedBlocks += 1;
	
	//when current used mem greater than last peak used memory

		this->pHeap->mStats.peakUsedMemory += pUsed->mBlockSize;
		this->pHeap->mStats.peakNumUsed++;
//	Trace::out("peak used memory %x %x %x %x\n", this->pHeap->mStats.peakUsedMemory, this->pHeap->mStats.currUsedMem, this->pHeap->mStats.currNumUsedBlocks, this->pHeap->mStats.currNumUsedBlocks);
}



void *Mem::getBlockPtr(const Used *pUsed) const {
	assert(pUsed != nullptr);
	void* p = (void *)(pUsed + 1);
	return p;
}
void Mem::removeUsedBlock(const Used *pUsed) const
{
	assert(pUsed != nullptr);
	if (pUsed->pUsedNext == nullptr && pUsed->pUsedPrev == nullptr)
	{
		this->pHeap->pUsedHead = nullptr;
	}
}
void Mem::removeUsedAdjustStats(const Used* pUsed) const 
{
	if (pUsed->pUsedNext == nullptr && pUsed->pUsedPrev == nullptr)
	{
		this->pHeap->mStats.currUsedMem -= pUsed->mBlockSize;
		this->pHeap->mStats.currNumUsedBlocks -= 1;
	}
	else {
		this->pHeap->mStats.currUsedMem -= pUsed->mBlockSize;
		this->pHeap->mStats.currNumUsedBlocks -= 1;
	}
}

void Mem::addFreeToFront(Free *pFree) const
{
	assert(pFree != nullptr);
	if (this->pHeap->pFreeHead == nullptr) {
		this->pHeap->pFreeHead = pFree;
	}

}

void Mem::addFreeAdjustStats(const Free *pFree) const
{
	this->pHeap->mStats.currFreeMem += pFree->mBlockSize;
	//Trace::out("currFreeMem %x\n", this->pHeap->mStats.currFreeMem);
	this->pHeap->mStats.currNumFreeBlocks++;

}
Free *Mem::mergeFreeBlock(const Free* pFree) const
{
	Free *Temp = (Free*)pFree;
	uint32_t blockSize = pFree->mBlockSize + sizeof(Free) + this->pHeap->pFreeHead->mBlockSize;
	Free *pFreeNew = placement_new(Temp, Free, blockSize);
	this->pHeap->mStats.currNumFreeBlocks--;
//	Trace::out("free blocks %x\n", this->pHeap->mStats.currNumFreeBlocks);
	this->pHeap->mStats.currFreeMem -= this->pHeap->pFreeHead->mBlockSize;
	this->pHeap->pFreeHead = pFreeNew;
	//Trace::out("%x %x\n", this->pHeap->pFreeHead, this->pHeap->pFreeHead->mBlockSize);
	return pFreeNew;
}

void Mem::free( void * const data )
{
	//Trace::out("Block\n");
	Heap *pHeapTmp = this->getHeap(); 
	assert(data != nullptr);
	Used *pUsed = ((Used *)((uint32_t)data - sizeof(Used)));
	Free *free = (Free*)pUsed;
	//void *pFreeBlock = nullptr;
	//STUB_PLEASE_REPLACE(data);
	

	//Trace::out("pfree head%x\n", pUsed->mBlockSize);
	uint32_t totalFree = this->getHeap()->mStats.currFreeMem + this->getHeap()->mStats.currUsedMem;
	if (pUsed->pUsedNext == nullptr && pUsed->pUsedPrev == nullptr) {
		if (totalFree == pUsed->mBlockSize) {
			this->removeUsedBlock(pUsed);
			this->removeUsedAdjustStats(pUsed);		
			Free *pFree = placement_new(pUsed , Free, pUsed->mBlockSize);
			this->pHeap->pNextFit = pFree;
			this->addFreeToFront(pFree);
			this->addFreeAdjustStats(pFree);
			pHeapTmp->pNextFit = (Free *)pFree;
		}
		else {
		//	Trace::out("2\n");
			this->removeUsedBlock(pUsed);
			this->removeUsedAdjustStats(pUsed);
			Free *pFree = placement_new(pUsed, Free, pUsed->mBlockSize);
			this->mergeFreeBlock(pFree);
			this->pHeap->pNextFit = pFree;
			this->addFreeToFront(pFree);
			this->addFreeAdjustStats(pFree);
			pHeapTmp->pNextFit = (Free *)pFree;

		}
	}
	else if(pUsed->pUsedNext != nullptr && pUsed->pUsedPrev == nullptr){
		
	//	Trace::out("3\n");
			this->getHeap()->pUsedHead = this->getHeap()->pUsedHead->pUsedNext;
			if (this->getHeap()->pUsedHead != nullptr) {
				this->getHeap()->pUsedHead->pUsedPrev = nullptr;
			}
			//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem,(uint32_t)(this->getHeap()->mStats.heapTopAddr)- (uint32_t)(this->getHeap()->mStats.heapBottomAddr));
			this->getHeap()->mStats.currUsedMem -= pUsed->mBlockSize;

			this->getHeap()->mStats.currFreeMem += pUsed->mBlockSize + sizeof(Used);
			//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem, this->getHeap()->mStats.heapBottomAddr);
			this->getHeap()->mStats.currNumUsedBlocks--;
			//this->getHeap()->mStats.currNumFreeBlocks++;
			this->getHeap()->pFreeHead = free;
			 this->getHeap()->pFreeHead->pFreeNext = nullptr;
			 this->getHeap()->pFreeHead->pFreePrev = nullptr;
		//	Trace::out("new free head %x \n", this->getHeap()->pFreeHead);
			this->getHeap()->pFreeHead->mBlockSize = this->getHeap()->mStats.currFreeMem;
			this->getHeap()->pNextFit = (Free *)pUsed;
			//this->getHeap()->pFreeHead->pFreeNext = nullptr;

			//uint32_t freeSpace = pFree->mBlockSize - size;
		///	Trace::out("%x %d %d\n ",this->getHeap()->pFreeHead, sizeof(uint32_t), sizeof(Free));
			Free **secretPtr = (Free **)((uint32_t)free + free->mBlockSize + sizeof(Free) - sizeof(Free *));
			*secretPtr = this->getHeap()->pFreeHead;
		//	Trace::out("%x\n", secretPtr);
			pUsed->mType = Block::Free;
			//Free *free = (Free *)h->mStats.heapTopAddr;
			//uint32_t hdrStart = (uint32_t)free;
			//uint32_t hdrEnd = (uint32_t)free + sizeof(Free);
			//uint32_t blkStart = hdrEnd;
			//uint32_t blkEnd = blkStart + free->mBlockSize;
			//Trace::out("number   %x %x %x %x\n", this->getHeap()->pFreeHead->mBlockSize, this->getHeap()->mStats.currUsedMem, h->mStats.currFreeMem,h->mStats.heapBottomAddr);
			//pUsed->mAboveBlockFree = false;
	}
	else {
	//	Trace::out("4\n");
		//this->getHeap()->pUsedHead = this->getHeap()->pUsedHead->pUsedNext;
	//	if (this->getHeap()->pUsedHead != nullptr) {
	//		this->getHeap()->pUsedHead->pUsedPrev = nullptr;
	//Trace::out("before %x\n", pUsed->mBlockSize);
		Free* Temp = this->pHeap->pFreeHead;
	//	Trace::out("before11 %x\n", pUsed->mBlockSize);
		this->pHeap->pFreeHead = (Free*)(this->getHeap() + 1);
		this->pHeap->pFreeHead->pFreeNext = Temp;
		
		//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem,(uint32_t)(this->getHeap()->mStats.heapTopAddr)- (uint32_t)(this->getHeap()->mStats.heapBottomAddr));
		
		this->getHeap()->mStats.currUsedMem -= pUsed->mBlockSize;
		this->getHeap()->mStats.currNumUsedBlocks--;
		this->getHeap()->mStats.currNumFreeBlocks++;
		//Trace::out("freee block free               %x \n", free->mAboveBlockFree);
		//Trace::out("after %x\n", this->getHeap()->mStats.currUsedMem);
		this->getHeap()->mStats.currFreeMem += pUsed->mBlockSize;
		this->pHeap->pFreeHead->pFreePrev = nullptr;
		this->pHeap->pFreeHead->pFreeNext = Temp;

		//Trace::out("pused                               %x\n", this->pHeap->pFreeHead->pFreeNext);
		pUsed->pUsedNext = nullptr;
		//Used * temps = pUsed->pUsedPrev;
	//	Trace::out("ptemps                               %x\n", temps);
		
		//Trace::out("number   %x %x %x %x\n", pUsed->mBlockSize, this->getHeap()->mStats.currUsedMem, this->getHeap()->mStats.currFreeMem, this->getHeap()->mStats.heapBottomAddr);
		//Trace::out("new free head %x \n", this->getHeap()->pFreeHead);
		//this->getHeap()->pNextFit = (Free *)pUsed;
		//this->getHeap()->pFreeHead->pFreeNext = nullptr;
		//uint32_t freeSpace = pFree->mBlockSize - size;
		Free **secretPtr = (Free **)((uint32_t)free + free->mBlockSize + sizeof(Free) -32);
		*secretPtr = free;
		//Trace::out("%x %x\n", *secretPtr,free);
		//Trace::out("left peak memory %x\n", this->getHeap()->mStats.currFreeMem);
		pUsed->mType = Block::Free;
		this->mergeFreeBlock(free);
		//Free *free = (Free *)h->mStats.heapTopAddr;
		//uint32_t hdrStart = (uint32_t)free;
		//uint32_t hdrEnd = (uint32_t)free + sizeof(Free);
		//uint32_t blkStart = hdrEnd;
		//uint32_t blkEnd = blkStart + free->mBlockSize;
		//Trace::out("number   %x %x %x %x\n", this->getHeap()->pFreeHead->mBlockSize, this->getHeap()->mStats.currUsedMem, h->mStats.currFreeMem,h->mStats.heapBottomAddr);
		//pUsed->mAboveBlockFree = false;
	}

	//Trace::out("pused % x, phead %x\n", this->getHeap()->pUsedHead, this->pHeap->pFreeHead);
	
}





// ---  End of File ---------------

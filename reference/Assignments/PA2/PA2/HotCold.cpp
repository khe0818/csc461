//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"

#define STUB_PLEASE_REPLACE(x) (x)

HotCold::HotCold(const Bloated * const pBloated)
{
	STUB_PLEASE_REPLACE(pBloated);
}

HotCold::~HotCold()
{
	// HINT - do something here
}

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	STUB_PLEASE_REPLACE(key);
	STUB_PLEASE_REPLACE(pFoundColdNode);
	STUB_PLEASE_REPLACE(pFoundHotNode);
	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---------------

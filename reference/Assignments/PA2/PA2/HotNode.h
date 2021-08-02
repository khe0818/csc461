//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef HOT_NODE_H
#define HOT_NODE_H

class ColdNode;

class HotNode
{
public:
	HotNode		*pNext;
	HotNode		*pPrev;
	int			key;
	ColdNode	*pCold;
};

#endif

// ---  End of File ---------------

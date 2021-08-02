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
	
	this->pHotHead = 0;
	this->pColdHead = 0;
	this->Size = pBloated->GetSize();
	int numbers = (int)this->Size;
	HotNode *p = new  HotNode[this->Size];
	ColdNode *Cold = new ColdNode[this->Size];
	this->pHotHead = p;
	this->pColdHead = Cold;
	HotNode *pFirst = p;
	HotNode *pLast = p + numbers - 1;
	HotNode *pCurr = pFirst;

	Node *n = pBloated->GetListHead();
	for (int i = 0; i < numbers; i++)
	{
		//pCurr->pCold = this->pColdHead;
		pCurr->pCold = Cold;
		pCurr->pCold->pHot = pCurr;
		pCurr->pCold->A = n->A;
		pCurr->pCold->B = n->B;
		pCurr->pCold->C = n->C;
		pCurr->pCold->MA = n->MA;
		pCurr->pCold->MB = n->MB;
		pCurr->pCold->MC = n->MC;
		pCurr->pCold->MD = n->MD;
		pCurr->pCold->x = n->x;
		pCurr->pCold->y = n->y;
		pCurr->pCold->z = n->z;
		pCurr->key = n->key;
		memcpy(pCurr->pCold->name, n->name, n->NAME_SIZE);
		pCurr->pNext = pCurr + 1;
		pCurr->pPrev = pCurr - 1;
		pCurr++;
		Cold++;
		n++;
	}

	pLast->pNext = 0;
	pFirst->pPrev = 0;
	



}

HotCold::~HotCold()
{
	delete[] this->pHotHead;
	delete[] this->pColdHead;
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
	//STUB_PLEASE_REPLACE(key);
	//STUB_PLEASE_REPLACE(pFoundColdNode);
	//STUB_PLEASE_REPLACE(pFoundHotNode);
	HotNode *p = HotCold::GetHotHead();
	//ColdNode *c = p->pCold;
	//Trace::out("hothead %x\n", p);
	bool flag = false;
	while (p != nullptr) {
		if (p->key == key) {
			//Trace::out("key %x\n", p->key);
			pFoundHotNode = p;
			//Trace::out("pFoundHotNode %x\n", pFoundHotNode->key);
			pFoundColdNode = p->pCold;
			//Trace::out("pFoundColdNode %x\n", pFoundColdNode->pHot->key);

			flag = true;
			break;
		}

		p = p->pNext;

	}
	return flag;

}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---------------

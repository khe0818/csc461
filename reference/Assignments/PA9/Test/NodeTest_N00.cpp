//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Boustrophedonic.h"
#include "Tree.h"

static Tree *pTree = nullptr;

#if Delete00_Test_Enable

TEST_WITH_TEARDOWN(Delete00, Basic, Delete00_Test_Enable)
{
	pTree = new Tree();

	DataNode *pN00, *pN01, *pN02, *pN03;
	DataNode *pN10, *pN11, *pN12, *pN13;
	DataNode *pN20, *pN21, *pN22, *pN23;

	pTree->GetPointers(pTree->pHead,
					   pN00, pN01, pN02, pN03,
					   pN10, pN11, pN12, pN13,
					   pN20, pN21, pN22, pN23);

	pTree->SkipThisOne = Tree::SkipDelete::N00;

	// Make sure we have a good initial tree

	//-----------------------------------
	CHECK_EQUAL(pN00->pNorth, nullptr);
	CHECK_EQUAL(pN00->pSouth, nullptr);
	CHECK_EQUAL(pN00->pEast, pN01);
	CHECK_EQUAL(pN00->pWest, nullptr);

	CHECK_EQUAL(pN01->pNorth, nullptr);
	CHECK_EQUAL(pN01->pSouth, pN11);
	CHECK_EQUAL(pN01->pEast, pN02);
	CHECK_EQUAL(pN01->pWest, nullptr);

	CHECK_EQUAL(pN02->pNorth, nullptr);
	CHECK_EQUAL(pN02->pSouth, nullptr);
	CHECK_EQUAL(pN02->pEast, pN03);
	CHECK_EQUAL(pN02->pWest, nullptr);

	CHECK_EQUAL(pN03->pNorth, nullptr);
	CHECK_EQUAL(pN03->pSouth, pN13);
	CHECK_EQUAL(pN03->pEast, nullptr);
	CHECK_EQUAL(pN03->pWest, nullptr);

	//---------------------------------
	CHECK_EQUAL(pN13->pNorth, nullptr);
	CHECK_EQUAL(pN13->pSouth, nullptr);
	CHECK_EQUAL(pN13->pEast, nullptr);
	CHECK_EQUAL(pN13->pWest, pN12);

	CHECK_EQUAL(pN12->pNorth, pN02);
	CHECK_EQUAL(pN12->pSouth, pN22);
	CHECK_EQUAL(pN12->pEast, nullptr);
	CHECK_EQUAL(pN12->pWest, pN11);

	CHECK_EQUAL(pN11->pNorth, nullptr);
	CHECK_EQUAL(pN11->pSouth, nullptr);
	CHECK_EQUAL(pN11->pEast, nullptr);
	CHECK_EQUAL(pN11->pWest, pN10);

	CHECK_EQUAL(pN10->pNorth, pN00);
	CHECK_EQUAL(pN10->pSouth, pN20);
	CHECK_EQUAL(pN10->pEast, nullptr);
	CHECK_EQUAL(pN10->pWest, nullptr);

	//---------------------------------------
	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, nullptr);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, nullptr);
	CHECK_EQUAL(pN23->pEast, nullptr);
	CHECK_EQUAL(pN23->pWest, nullptr);

	//---- TEST below here --------------------

	Trace::out("remove:---> (0,0) \n");
	Node *p = pTree->pHead;
	Remove(p, 0, 0);

	// ------- CHECK HEAD ---------------------

	DataNode *pData = (DataNode *)p;
	CHECK_EQUAL(pData, pN01);

	// CHECK the first Row

	//-----------------------------------
	//CHECK_EQUAL(pN00->pNorth, nullptr);
	//CHECK_EQUAL(pN00->pSouth, nullptr);
	//CHECK_EQUAL(pN00->pEast, pN01);
	//CHECK_EQUAL(pN00->pWest, nullptr);

	CHECK_EQUAL(pN01->pNorth, nullptr);
	CHECK_EQUAL(pN01->pSouth, pN11);
	CHECK_EQUAL(pN01->pEast, pN02);
	CHECK_EQUAL(pN01->pWest, nullptr);

	CHECK_EQUAL(pN02->pNorth, nullptr);
	CHECK_EQUAL(pN02->pSouth, nullptr);
	CHECK_EQUAL(pN02->pEast, pN03);
	CHECK_EQUAL(pN02->pWest, nullptr);

	CHECK_EQUAL(pN03->pNorth, nullptr);
	CHECK_EQUAL(pN03->pSouth, pN13);
	CHECK_EQUAL(pN03->pEast, nullptr);
	CHECK_EQUAL(pN03->pWest, nullptr);

	//---------------------------------
	CHECK_EQUAL(pN13->pNorth, nullptr);
	CHECK_EQUAL(pN13->pSouth, nullptr);
	CHECK_EQUAL(pN13->pEast, nullptr);
	CHECK_EQUAL(pN13->pWest, pN12);

	CHECK_EQUAL(pN12->pNorth, pN02);
	CHECK_EQUAL(pN12->pSouth, pN22);
	CHECK_EQUAL(pN12->pEast, nullptr);
	CHECK_EQUAL(pN12->pWest, pN11);

	CHECK_EQUAL(pN11->pNorth, nullptr);
	CHECK_EQUAL(pN11->pSouth, nullptr);
	CHECK_EQUAL(pN11->pEast, nullptr);
	CHECK_EQUAL(pN11->pWest, pN10);

	CHECK_EQUAL(pN10->pNorth, nullptr);
	CHECK_EQUAL(pN10->pSouth, pN20);
	CHECK_EQUAL(pN10->pEast, nullptr);
	CHECK_EQUAL(pN10->pWest, nullptr);

	//---------------------------------------
	CHECK_EQUAL(pN20->pNorth, nullptr);
	CHECK_EQUAL(pN20->pSouth, nullptr);
	CHECK_EQUAL(pN20->pEast, pN21);
	CHECK_EQUAL(pN20->pWest, nullptr);

	CHECK_EQUAL(pN21->pNorth, pN11);
	CHECK_EQUAL(pN21->pSouth, nullptr);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, nullptr);
	CHECK_EQUAL(pN23->pEast, nullptr);
	CHECK_EQUAL(pN23->pWest, nullptr);

} TEST_END

TEST_TEARDOWN(Delete00, Basic)
{
	delete pTree;
}

#endif

// ---  End of File ---------------

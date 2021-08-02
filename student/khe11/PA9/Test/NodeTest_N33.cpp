//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Boustrophedonic.h"
#include "Tree.h"

static Tree *pTree = nullptr;

#if Delete33_Test_Enable
TEST_WITH_TEARDOWN(Delete33, Basic, Delete33_Test_Enable)
{
	pTree = new Tree();

	DataNode *pN00, *pN01, *pN02, *pN03;
	DataNode *pN10, *pN11, *pN12, *pN13;
	DataNode *pN20, *pN21, *pN22, *pN23;
	DataNode *pN30, *pN31, *pN32, *pN33;

	pTree->GetPointers(pTree->pHead,
					   pN00, pN01, pN02, pN03,
					   pN10, pN11, pN12, pN13,
					   pN20, pN21, pN22, pN23,
					   pN30, pN31, pN32, pN33);

	pTree->SkipThisOne = Tree::SkipDelete::N33;

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
	CHECK_EQUAL(pN21->pSouth, pN31);
	CHECK_EQUAL(pN21->pEast, pN22);
	CHECK_EQUAL(pN21->pWest, nullptr);

	CHECK_EQUAL(pN22->pNorth, nullptr);
	CHECK_EQUAL(pN22->pSouth, nullptr);
	CHECK_EQUAL(pN22->pEast, pN23);
	CHECK_EQUAL(pN22->pWest, nullptr);

	CHECK_EQUAL(pN23->pNorth, pN13);
	CHECK_EQUAL(pN23->pSouth, pN33);
	CHECK_EQUAL(pN23->pEast, nullptr);
	CHECK_EQUAL(pN23->pWest, nullptr);

	//---------------------------------------

	CHECK_EQUAL(pN30->pNorth, pN20);
	CHECK_EQUAL(pN30->pSouth, nullptr);
	CHECK_EQUAL(pN30->pEast, nullptr);
	CHECK_EQUAL(pN30->pWest, nullptr);

	CHECK_EQUAL(pN31->pNorth, nullptr);
	CHECK_EQUAL(pN31->pSouth, nullptr);
	CHECK_EQUAL(pN31->pEast, nullptr);
	CHECK_EQUAL(pN31->pWest, pN30);

	CHECK_EQUAL(pN32->pNorth, pN22);
	CHECK_EQUAL(pN32->pSouth, nullptr);
	CHECK_EQUAL(pN32->pEast, nullptr);
	CHECK_EQUAL(pN32->pWest, pN31);

	CHECK_EQUAL(pN33->pNorth, nullptr);
	CHECK_EQUAL(pN33->pSouth, nullptr);
	CHECK_EQUAL(pN33->pEast, nullptr);
	CHECK_EQUAL(pN33->pWest, pN32);



	//---- TEST below here --------------------

	Trace::out("remove:---> (3,3) \n");
	Node *p = pTree->pHead;
	Remove(p, 3, 3);

	// ------- CHECK HEAD ---------------------

	DataNode *pData = (DataNode *)p;
	CHECK_EQUAL(pData, pTree->pHead);

	// CHECK the first Row

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
	CHECK_EQUAL(pN21->pSouth, pN31);
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

	//---------------------------------------

	CHECK_EQUAL(pN30->pNorth, pN20);
	CHECK_EQUAL(pN30->pSouth, nullptr);
	CHECK_EQUAL(pN30->pEast, nullptr);
	CHECK_EQUAL(pN30->pWest, nullptr);

	CHECK_EQUAL(pN31->pNorth, nullptr);
	CHECK_EQUAL(pN31->pSouth, nullptr);
	CHECK_EQUAL(pN31->pEast, nullptr);
	CHECK_EQUAL(pN31->pWest, pN30);

	CHECK_EQUAL(pN32->pNorth, pN22);
	CHECK_EQUAL(pN32->pSouth, nullptr);
	CHECK_EQUAL(pN32->pEast, nullptr);
	CHECK_EQUAL(pN32->pWest, pN31);

	//CHECK_EQUAL(pN33->pNorth, nullptr);
	//CHECK_EQUAL(pN33->pSouth, nullptr);
	//CHECK_EQUAL(pN33->pEast, nullptr);
	//CHECK_EQUAL(pN33->pWest, pN32);

} TEST_END

TEST_TEARDOWN(Delete33, Basic)
{
	delete pTree;
}
#endif

// ---  End of File ---------------

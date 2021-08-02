//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
// ONLY used in the test code.
// DO NOT MODIFY
//-----------------------------------------------------------------------------

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include "DataNode.h"

struct Tree
{
public:
		
	enum SkipDelete
	{
		N00,
		N01,
		N02,
		N03,
		N10,
		N11,
		N12,
		N13,
		N20,
		N21,
		N22,
		N23
	};


	Tree();
	Tree(const Tree &) = delete;
	Tree &operator = (const Tree &) = delete;
	~Tree();

	DataNode *pN00;
	DataNode *pN01;
	DataNode *pN02;
	DataNode *pN03;
	DataNode *pN10;
	DataNode *pN11;
	DataNode *pN12;
	DataNode *pN13;
	DataNode *pN20;
	DataNode *pN21;
	DataNode *pN22;
	DataNode *pN23;

	SkipDelete SkipThisOne;

	void GetPointers(DataNode *pHead,
					 DataNode *&pN00,
					 DataNode *&pN01,
					 DataNode *&pN02,
					 DataNode *&pN03,
					 DataNode *&pN10,
					 DataNode *&pN11,
					 DataNode *&pN12,
					 DataNode *&pN13,
					 DataNode *&pN20,
					 DataNode *&pN21,
					 DataNode *&pN22,
					 DataNode *&pN23
					 );


private:
	DataNode *privCreateTree();

public:
	DataNode *pHead;
};

#endif

// ---  End of File ---------------

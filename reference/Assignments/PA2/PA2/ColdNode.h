//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef COLD_NODE_H
#define COLD_NODE_H

class Node;
class HotNode;

class ColdNode
{
public:
	HotNode	*pHot;
	float	x;
	float	y;
	float	z;
	Vect	A;
	Vect	B;
	Vect	C;
	Matrix	MA;
	Matrix	MB;
	Matrix	MC;
	Matrix	MD;
	char	name[Node::NAME_SIZE];
};


#endif

// ---  End of File ---------------


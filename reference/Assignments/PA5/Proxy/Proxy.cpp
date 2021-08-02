//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Proxy.h"

// Modify This File

Vect2D Vect2D::operator + (const Vect2D &tmp) const
{
	Vect2D sum;

	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;

	return (sum);
};

// ---  End of File ---------------

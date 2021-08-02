//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "No_Proxy.h"

// DO NOT CHANGE THIS FILE

Vect2D_No_Proxy Vect2D_No_Proxy::operator + (const Vect2D_No_Proxy &tmp) const
{
	Vect2D_No_Proxy sum;

	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;

	return (sum);
};

// ---  End of File ---------------

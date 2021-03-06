//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <vector>
#include <algorithm>

#include "Framework.h"
#include "D.h"
#include "Vect.h"

// USED for Unit Tests
std::vector< Vect > UnitTest_V_orig;
std::vector< Vect > UnitTest_V_sort;

Vect V[] =
{
	{3,5,6},
	{6,5,3},
	{3,4,7},
	{7,2,5},
	{1,3,5},
	{3,2,5},
	{2,3,4},
	{3,5,5},
	{7,3,2},
	{4,3,2},
	{1,7,1}
};

Vect JunkDataD{ 0xa,0xb,0x3 };

// ADD CODE HERE if needed:
bool weakOrdering(Vect m, Vect n) {
	if (m.a != n.a) {
		return m.a < n.a;
	}
	else if (m.b != n.b) {
		return m.b < n.b;
	}
	else {
		return m.c < n.c;
	}
}

void Problem_4( )
{	
	// ----------------------------------------------------
	// a) Load the V[] data into a vector
	//    Name the vector: v
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::vector<Vect> v(V, V + sizeof(V)/sizeof(Vect));  // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_V_orig.assign(v.begin(), v.end());

	// ----------------------------------------------------
	// b) Sort the new STL vector with strict weak ordering
	//    Don't know what strict weak ordering is... Look it up
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::sort(v.begin(), v.end(), weakOrdering);

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_V_sort.assign(v.begin(), v.end());
}


// End of File

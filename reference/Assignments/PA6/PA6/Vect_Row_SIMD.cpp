//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

#define UNUSED_VAR(X) ((void )X)

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

Vect_Row_SIMD Vect_Row_SIMD::operator * ( const Matrix_Row_SIMD &ma)
{
	// replace everything... 
	// stub to shut up warnings
	UNUSED_VAR(ma);
	return Vect_Row_SIMD();
};


// ---  End of File ---------------



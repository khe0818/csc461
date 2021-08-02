//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

#define UNUSED_VAR(X) ((void )X)

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	// replace everything... 
	// stub to shut up warnings
	UNUSED_VAR(ma);
	return Vect_vM_SIMD();
};


// ---  End of File ---------------



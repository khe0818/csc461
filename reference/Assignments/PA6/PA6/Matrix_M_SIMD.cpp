//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

#define UNUSED_VAR(X) ((void )X)

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	// replace everything... 
	// stub to shut up warnings
	UNUSED_VAR(mb);
	return Matrix_M_SIMD();
}


// ---  End of File ---------------

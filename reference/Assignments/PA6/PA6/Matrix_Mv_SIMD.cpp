//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

#define UNUSED_VAR(X) ((void )X)

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{
	// replace everything... 
	// stub to shut up warnings
	UNUSED_VAR(v);
	return Vect_Mv_SIMD();
}


// ---  End of File ---------------

//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

#define UNUSED_VAR(X) ((void )X)

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Col_SIMD Matrix_Col_SIMD::operator * (const Vect_Col_SIMD &vb)
{
	UNUSED_VAR(vb);
	return Vect_Col_SIMD();
}

Matrix_Col_SIMD Matrix_Col_SIMD::operator * (const Matrix_Col_SIMD &mb)
{
	UNUSED_VAR(mb);
	return Matrix_Col_SIMD();
}



// ---  End of File ---------------

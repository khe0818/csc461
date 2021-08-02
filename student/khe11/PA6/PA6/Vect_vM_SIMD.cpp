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
	Vect_vM_SIMD Sum0, Sum1, Res;
	Sum0._m = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->x), ma.v0._m), _mm_mul_ps(_mm_set1_ps(this->y), ma.v1._m));
	Sum1._m = _mm_add_ps(Sum0._m, _mm_mul_ps(_mm_set1_ps(this->z), ma.v2._m));
	Res._m = _mm_add_ps(Sum1._m, _mm_mul_ps(_mm_set1_ps(this->w), ma.v3._m));

	return Res;
};




// ---  End of File ---------------



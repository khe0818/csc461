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
	Vect_Mv_SIMD Res;
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps(this->v3.x, this->v2.x, this->v1.x, this->v0.x), _mm_set_ps1(v.x)), _mm_mul_ps(_mm_set_ps(this->v3.y, this->v2.y, this->v1.y, this->v0.y), _mm_set_ps1(v.y))), _mm_mul_ps(_mm_set_ps(this->v3.z, this->v2.z, this->v1.z, this->v0.z), _mm_set_ps1(v.z))), _mm_mul_ps(_mm_set_ps(this->v3.w, this->v2.w, this->v1.w, this->v0.w), _mm_set_ps1(v.w)));

	return Res;
}


// ---  End of File ---------------

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
	Matrix_M_SIMD Res;
	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v0.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v0.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v0.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v1.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v1.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v1.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v2.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v2.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v2.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v3.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v3.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v3.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v3.w)));

	return Res;
}


// ---  End of File ---------------

//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"
#include "Framework.h"
#define UNUSED_VAR(X) ((void )X)

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

//Vect_Col_SIMD Matrix_Col_SIMD::operator * (const Vect_Col_SIMD &vb)
//{
//	/*Vect_Col_SIMD Sum0, Sum1, Res;
//	Sum0._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps(this->m12, this->m8, this->m4, this->m0), _mm_set_ps1(vb.x)), _mm_mul_ps(_mm_set_ps(this->m13, this->m9, this->m5, this->m1), _mm_set_ps1(vb.y)));
//	Sum1._m = _mm_add_ps(Sum0._m, _mm_mul_ps(_mm_set_ps(this->m14, this->m10, this->m6, this->m2), _mm_set_ps1(vb.z)));
//	Res._m = _mm_add_ps(Sum1._m, _mm_mul_ps(_mm_set_ps(this->m3, this->m7, this->m11, this->m15), _mm_set_ps1(vb.w)));
//
//	return Res;*/
//
//	Vect_Col_SIMD Res;
//	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(vb.x), _mm_set_ps(this->m12, this->m8, this->m4, this->m0)), _mm_mul_ps(_mm_set_ps1(vb.y), _mm_set_ps(this->m13, this->m9, this->m5, this->m1))), _mm_mul_ps( _mm_set_ps1(vb.z), _mm_set_ps(this->m14, this->m10, this->m6, this->m2))), _mm_mul_ps(_mm_set_ps1(vb.w), _mm_set_ps(this->m15, this->m11, this->m7, this->m3)));
//
//	return Res;
//}
//
//Matrix_Col_SIMD Matrix_Col_SIMD::operator * (const Matrix_Col_SIMD &mb)
//{
//	/*Matrix_Col_SIMD Res;
//	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v0.x)), _mm_mul_ps( mb.v1._m, _mm_set1_ps(this->v0.y))), _mm_mul_ps( mb.v2._m, _mm_set1_ps(this->v0.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v0.w)));
//	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v1.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v1.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v1.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v1.w)));
//	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v2.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v2.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v2.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v2.w)));
//	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v3.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v3.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v3.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v3.w)));
//
//	return Res;*/
//
//}
 MmulM::operator Matrix_Col_SIMD() {
	Matrix_Col_SIMD Res;
		Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v2.v0._m, _mm_set1_ps(this->v1.v0.x)), _mm_mul_ps(v2.v1._m, _mm_set1_ps(this->v1.v0.y))), _mm_mul_ps(v2.v2._m, _mm_set1_ps(this->v1.v0.z))), _mm_mul_ps(v2.v3._m, _mm_set1_ps(this->v1.v0.w)));
		Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v2.v0._m, _mm_set1_ps(this->v1.v1.x)), _mm_mul_ps(v2.v1._m, _mm_set1_ps(this->v1.v1.y))), _mm_mul_ps(v2.v2._m, _mm_set1_ps(this->v1.v1.z))), _mm_mul_ps(v2.v3._m, _mm_set1_ps(this->v1.v1.w)));
		Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v2.v0._m, _mm_set1_ps(this->v1.v2.x)), _mm_mul_ps(v2.v1._m, _mm_set1_ps(this->v1.v2.y))), _mm_mul_ps(v2.v2._m, _mm_set1_ps(this->v1.v2.z))), _mm_mul_ps(v2.v3._m, _mm_set1_ps(this->v1.v2.w)));
		Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v2.v0._m, _mm_set1_ps(this->v1.v3.x)), _mm_mul_ps(v2.v1._m, _mm_set1_ps(this->v1.v3.y))), _mm_mul_ps(v2.v2._m, _mm_set1_ps(this->v1.v3.z))), _mm_mul_ps(v2.v3._m, _mm_set1_ps(this->v1.v3.w)));
	
		return Res;
}
MmulMmulM::operator Matrix_Col_SIMD() {
	Matrix_Col_SIMD Res;
	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v3.v0._m, _mm_set1_ps(this->v2.v0.x)), _mm_mul_ps(v3.v1._m, _mm_set1_ps(this->v2.v0.y))), _mm_mul_ps(v3.v2._m, _mm_set1_ps(this->v2.v0.z))), _mm_mul_ps(v3.v3._m, _mm_set1_ps(this->v2.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v3.v0._m, _mm_set1_ps(this->v2.v1.x)), _mm_mul_ps(v3.v1._m, _mm_set1_ps(this->v2.v1.y))), _mm_mul_ps(v3.v2._m, _mm_set1_ps(this->v2.v1.z))), _mm_mul_ps(v3.v3._m, _mm_set1_ps(this->v2.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v3.v0._m, _mm_set1_ps(this->v2.v2.x)), _mm_mul_ps(v3.v1._m, _mm_set1_ps(this->v2.v2.y))), _mm_mul_ps(v3.v2._m, _mm_set1_ps(this->v2.v2.z))), _mm_mul_ps(v3.v3._m, _mm_set1_ps(this->v2.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v3.v0._m, _mm_set1_ps(this->v2.v3.x)), _mm_mul_ps(v3.v1._m, _mm_set1_ps(this->v2.v3.y))), _mm_mul_ps(v3.v2._m, _mm_set1_ps(this->v2.v3.z))), _mm_mul_ps(v3.v3._m, _mm_set1_ps(this->v2.v3.w)));

	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v3.w)));

	return Res;
}
MmulMmulMmulM::operator Matrix_Col_SIMD() {
	Matrix_Col_SIMD Res;
	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v4.v0._m, _mm_set1_ps(this->v3.v0.x)), _mm_mul_ps(v4.v1._m, _mm_set1_ps(this->v3.v0.y))), _mm_mul_ps(v4.v2._m, _mm_set1_ps(this->v3.v0.z))), _mm_mul_ps(v4.v3._m, _mm_set1_ps(this->v3.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v4.v0._m, _mm_set1_ps(this->v3.v1.x)), _mm_mul_ps(v4.v1._m, _mm_set1_ps(this->v3.v1.y))), _mm_mul_ps(v4.v2._m, _mm_set1_ps(this->v3.v1.z))), _mm_mul_ps(v4.v3._m, _mm_set1_ps(this->v3.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v4.v0._m, _mm_set1_ps(this->v3.v2.x)), _mm_mul_ps(v4.v1._m, _mm_set1_ps(this->v3.v2.y))), _mm_mul_ps(v4.v2._m, _mm_set1_ps(this->v3.v2.z))), _mm_mul_ps(v4.v3._m, _mm_set1_ps(this->v3.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v4.v0._m, _mm_set1_ps(this->v3.v3.x)), _mm_mul_ps(v4.v1._m, _mm_set1_ps(this->v3.v3.y))), _mm_mul_ps(v4.v2._m, _mm_set1_ps(this->v3.v3.z))), _mm_mul_ps(v4.v3._m, _mm_set1_ps(this->v3.v3.w)));


	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v3.w)));

	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v3.w)));

	return Res;
}
MmulMmulMmulMmulM::operator Matrix_Col_SIMD() {
	Matrix_Col_SIMD Res;
	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v5.v0._m, _mm_set1_ps(this->v4.v0.x)), _mm_mul_ps(v5.v1._m, _mm_set1_ps(this->v4.v0.y))), _mm_mul_ps(v5.v2._m, _mm_set1_ps(this->v4.v0.z))), _mm_mul_ps(v5.v3._m, _mm_set1_ps(this->v4.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v5.v0._m, _mm_set1_ps(this->v4.v1.x)), _mm_mul_ps(v5.v1._m, _mm_set1_ps(this->v4.v1.y))), _mm_mul_ps(v5.v2._m, _mm_set1_ps(this->v4.v1.z))), _mm_mul_ps(v5.v3._m, _mm_set1_ps(this->v4.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v5.v0._m, _mm_set1_ps(this->v4.v2.x)), _mm_mul_ps(v5.v1._m, _mm_set1_ps(this->v4.v2.y))), _mm_mul_ps(v5.v2._m, _mm_set1_ps(this->v4.v2.z))), _mm_mul_ps(v5.v3._m, _mm_set1_ps(this->v4.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v5.v0._m, _mm_set1_ps(this->v4.v3.x)), _mm_mul_ps(v5.v1._m, _mm_set1_ps(this->v4.v3.y))), _mm_mul_ps(v5.v2._m, _mm_set1_ps(this->v4.v3.z))), _mm_mul_ps(v5.v3._m, _mm_set1_ps(this->v4.v3.w)));

	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v3.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v3.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v3.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v3.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v3.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v3.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v3.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v3.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v3.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v3.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v3.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v3.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v3.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v3.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v3.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v3.v3.w)));


	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v2.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v2.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v2.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v2.v3.w)));

	Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v0.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v0.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v0.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v0.w)));
	Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v1.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v1.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v1.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v1.w)));
	Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v2.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v2.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v2.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v2.w)));
	Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(Res.v0._m, _mm_set1_ps(this->v1.v3.x)), _mm_mul_ps(Res.v1._m, _mm_set1_ps(this->v1.v3.y))), _mm_mul_ps(Res.v2._m, _mm_set1_ps(this->v1.v3.z))), _mm_mul_ps(Res.v3._m, _mm_set1_ps(this->v1.v3.w)));

	return Res;
}
MmulMmulMmulMmulMmulV::operator Vect_Col_SIMD() {
	Vect_Col_SIMD Res;
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(this->v6.x), _mm_set_ps(this->v5.m12, this->v5.m8, this->v5.m4, this->v5.m0)), _mm_mul_ps(_mm_set_ps1(this->v6.y), _mm_set_ps(this->v5.m13, this->v5.m9, this->v5.m5, this->v5.m1))), _mm_mul_ps(_mm_set_ps1(this->v6.z), _mm_set_ps(this->v5.m14, this->v5.m10, this->v5.m6, this->v5.m2))), _mm_mul_ps(_mm_set_ps1(this->v6.w), _mm_set_ps(this->v5.m15, this->v5.m11, this->v5.m7, this->v5.m3)));
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(Res.x), _mm_set_ps(this->v4.m12, this->v4.m8, this->v4.m4, this->v4.m0)), _mm_mul_ps(_mm_set_ps1(Res.y), _mm_set_ps(this->v4.m13, this->v4.m9, this->v4.m5, this->v4.m1))), _mm_mul_ps(_mm_set_ps1(Res.z), _mm_set_ps(this->v4.m14, this->v4.m10, this->v4.m6, this->v4.m2))), _mm_mul_ps(_mm_set_ps1(Res.w), _mm_set_ps(this->v4.m15, this->v4.m11, this->v4.m7, this->v4.m3)));
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(Res.x), _mm_set_ps(this->v3.m12, this->v3.m8, this->v3.m4, this->v3.m0)), _mm_mul_ps(_mm_set_ps1(Res.y), _mm_set_ps(this->v3.m13, this->v3.m9, this->v3.m5, this->v3.m1))), _mm_mul_ps(_mm_set_ps1(Res.z), _mm_set_ps(this->v3.m14, this->v3.m10, this->v3.m6, this->v3.m2))), _mm_mul_ps(_mm_set_ps1(Res.w), _mm_set_ps(this->v3.m15, this->v3.m11, this->v3.m7, this->v3.m3)));
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(Res.x), _mm_set_ps(this->v2.m12, this->v2.m8, this->v2.m4, this->v2.m0)), _mm_mul_ps(_mm_set_ps1(Res.y), _mm_set_ps(this->v2.m13, this->v2.m9, this->v2.m5, this->v2.m1))), _mm_mul_ps(_mm_set_ps1(Res.z), _mm_set_ps(this->v2.m14, this->v2.m10, this->v2.m6, this->v2.m2))), _mm_mul_ps(_mm_set_ps1(Res.w), _mm_set_ps(this->v2.m15, this->v2.m11, this->v2.m7, this->v2.m3)));
	Res._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(Res.x), _mm_set_ps(this->v1.m12, this->v1.m8, this->v1.m4, this->v1.m0)), _mm_mul_ps(_mm_set_ps1(Res.y), _mm_set_ps(this->v1.m13, this->v1.m9, this->v1.m5, this->v1.m1))), _mm_mul_ps(_mm_set_ps1(Res.z), _mm_set_ps(this->v1.m14, this->v1.m10, this->v1.m6, this->v1.m2))), _mm_mul_ps(_mm_set_ps1(Res.w), _mm_set_ps(this->v1.m15, this->v1.m11, this->v1.m7, this->v1.m3)));

	return Res;
}


// ---  End of File ---------------

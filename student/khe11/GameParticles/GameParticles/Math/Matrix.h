//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"
#include "Vect4D.h"
// forward declare
class Vect4D;

// class
class Matrix
{
public:

	// local enumerations
	enum MatrixRowEnum
	{
		MATRIX_ROW_0,
		MATRIX_ROW_1,
		MATRIX_ROW_2,
		MATRIX_ROW_3
	};
	Matrix::Matrix()
	{	// constructor for the matrix
		this->v0._m = _mm_set1_ps(0.0f);
		this->v1._m = _mm_set1_ps(0.0f);
		this->v2._m = _mm_set1_ps(0.0f);
		this->v3._m = _mm_set1_ps(0.0f);
	}
	Matrix::Matrix(const Vect4D &a, const Vect4D &b, const Vect4D &c, const Vect4D &d):v0(a),v1(b),v2(c),v3(d)
	{
	}
	Matrix::~Matrix()
	{
		// nothign to delete
	}
	Matrix::Matrix(const Matrix& t):v0(t.v0), v1(t.v1), v2(t.v2), v3(t.v3)
{ // copy constructor
	

}
	Matrix Matrix::operator * (const Matrix &mb) const
	{
		Matrix Res;
		Res.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v0.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v0.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v0.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v0.w)));
		Res.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v1.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v1.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v1.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v1.w)));
		Res.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v2.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v2.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v2.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v2.w)));
		Res.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(mb.v0._m, _mm_set1_ps(this->v3.x)), _mm_mul_ps(mb.v1._m, _mm_set1_ps(this->v3.y))), _mm_mul_ps(mb.v2._m, _mm_set1_ps(this->v3.z))), _mm_mul_ps(mb.v3._m, _mm_set1_ps(this->v3.w)));

		return Res;
	}



	void Matrix::setIdentMatrix()
	{ 
		this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
		this->v1._m = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
		this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
		this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
	}

	void Matrix::setTransMatrix(const Vect4D *t)
	{ 
		this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, 1.0f);
		this->v1._m = _mm_set_ps(0.0f, 0.0f, 1.0f, 0.0f);
		this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
		this->v3._m = _mm_set_ps(1.0f, t->z, t->y, t->x);
	}
	
	void Matrix::set(const MatrixRowEnum row, const Vect4D *const t)
	{
		// initialize the rows of the matrix
		this->v3._m = _mm_set_ps(t->w, t->z, t->y, t->x);
	}

	

	void Matrix::get( Vect4D * t) const
	{ // get a row of the matrix
	
			t->_m = this->v3._m;
	}



	Matrix& Matrix::operator/=(const float rhs)
	{
		// divide each element by a value
		// using inverse multiply trick, faster that individual divides
		__m128 tmp;
		tmp = _mm_set1_ps(1.0f / rhs);
		this->v0._m = _mm_mul_ps(this->v0._m, tmp);
		this->v1._m = _mm_mul_ps(this->v1._m, tmp);
		this->v2._m = _mm_mul_ps(this->v2._m, tmp);
		this->v3._m = _mm_mul_ps(this->v3._m, tmp);
		return *this;
	}

	//float Matrix::Determinant()
	//{
	//	// A = { a,b,c,d / e,f,g,h / j,k,l,m / n,o,p,q }
	//	// A = { 0,1,2,3 / 4,5,6,7 / 8,9,10,11 / 12,13,14,15 }

	//	// det(A) = a*det( { f,g,h / k,l,m / o,p,q } )
	//	//			- b*det( { e,g,h / j,l,m / n,p,q } )
	//	//			+ c*det( { e,f,h / j,k,m / n,o,q } )
	//	//			- d*det( { e,f,g / j,k,l / n,o,p } )

	//	// det(A) = (a (f (lq - mp) - g (kq - mo) + h (kp - lo) ) )
	//	//			- (b (e (lq - mp) - g (jq - mn) + h (jp - ln) ) )
	//	//			+ (c (e (kq - mo) - f (jq - mn) + h (jo - kn) ) )
	//	//			- (d (e (kp - lo) - f (jp - ln) + g (jo - kn) ) )

	//	// ta = (lq - mp)
	//	float ta = (m10 * m15) - (m11 * m14);
	//	// tb = (kq - mo)
	//	float tb = (m9 * m15) - (m11 * m13);
	//	// tc = (kp - lo)
	//	float tc = (m9 * m14) - (m10 * m13);
	//	// td = (jq - mn)
	//	float td = (m8 * m15) - (m11 * m12);
	//	// te = (jo - kn)
	//	float te = (m8 * m13) - (m9 *  m12);
	//	// tf = (jp - ln)
	//	float tf = (m8 * m14) - (m10 * m12);

	//	// det(A) = (a (f*ta  - g*tb + h*tc) )      
	//	//			- (b (e*ta - g*td + h*tf) )     
	//	//			+ (c (e*tb - f*td + h*te) )     
	//	//			- (d (e*tc - f*tf + g*te) )     
	//	return ((m0 * ((m5 * ta) - (m6 * tb) + (m7 * tc)))
	//		- (m1 * ((m4 * ta) - (m6 * td) + (m7 * tf)))
	//		+ (m2 * ((m4 * tb) - (m5 * td) + (m7 * te)))
	//		- (m3 * ((m4 * tc) - (m5 * tf) + (m6 * te))));

	//}

	//Matrix Matrix::GetAdjugate()
	//{

	//	Matrix tmp;

	//	// load		ABC		(3)		ABC--
	//	/*float t1 = (m10*m15) - (m11*m14);
	//	float t2 = (m9*m15) - (m11*m13);
	//	float t3 = (m9*m14) - (m10*m13);*/

	//	// a = f(ta) - g(tb) + h(tc)
	//	/*tmp.m0 = (m5*t1) - (m6*t2) + (m7*t3);*/
	//	tmp.m0 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m14)))), _mm_mul_ps(_mm_set1_ps(m6), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m13))))), _mm_mul_ps(_mm_set1_ps(m7), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m13))))));

	//	// b = -( b(ta) - c(tb) + d(tc))          
	//	/*tmp.m1 = -((m1*t1) - (m2*t2) + (m3*t3));*/

	//	tmp.m1 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m13)))), _mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m14))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m13))))));
	//	// load		JK		(5)		ABCJK
	//	/*float t4 = (m8*m15) - (m11*m12);
	//	float t5 = (m8*m14) - (m10*m12);*/

	//	// e = - ( e(ta) - g(tj) + h(tk))
	//	//tmp.m4 = -((m4*t1) - (m6*t4) + (m7*t5));
	//	tmp.m4 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m6), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m12)))), _mm_mul_ps(_mm_set1_ps(m4), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m14))))), _mm_mul_ps(_mm_set1_ps(m7), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m12))))));
	//	// f = a(ta) - c(tj) + d(tk)
	//	/*tmp.m5 = (m0*t1) - (m2*t4) + (m3*t5);*/
	//	tmp.m5 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m14)))), _mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m12))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m12))))));
	//	// unload	AJ		(3)		-BC-K
	//	// load		P		(4)		PBC-K
	//	//t1 = (m8*m13) - (m9*m12);
	//	// n = -( e(tc) - f(tk) + g(tp))
	//	/*tmp.m12 = -((m4*t3) - (m5*t5) + (m6*t1));*/
	//	tmp.m12 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m12)))), _mm_mul_ps(_mm_set1_ps(m4), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m13))))), _mm_mul_ps(_mm_set1_ps(m6), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m12))))));
	//	// o = a(tc) - b(tk) + c(tp)


	//	//tmp.m13 = (m0*t3) - (m1*t5) + (m2*t1);
	//	tmp.m13 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m13)))), _mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m10), _mm_set1_ps(m12))))), _mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m12))))));
	//	// unload	KC		(2)		PB---
	//	// load		J		(3)		PBJ--
	//	/*t3 = (m8*m15) - (m11*m12);*/
	//	__m128 t7 = _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m12)));
	//	// j = e(tb) - f(tj) + h(tp)
	//	/*tmp.m8 = (m4*t2) - (m5*t3(t7) + (m7*t1(t6));*/
	//	tmp.m8 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m13)))), _mm_mul_ps(_mm_set1_ps(m5), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m12))))), _mm_mul_ps(_mm_set1_ps(m7), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m12))))));
	//	// k = - ( a(tb) - b(tj) + d(tp))
	//	/*tmp.m9 = -((m0*t2) - (m1*t3) + (m3*t1));*/
	//	tmp.m9 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m12)))), _mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m11), _mm_set1_ps(m13))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m8), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m9), _mm_set1_ps(m12))))));

	//	// unload	BPJ		(0)		-----
	//	// load		DLM		(3)		DLM--
	//	/*t1 = (m6*m15) - (m7*m14);
	//	t2 = (m4*m15) - (m7*m12);
	//	t3 = (m4*m14) - (m6*m12);*/

	//	// g = - ( a(td) - c(tl) + d(tm))
	//	/*tmp.m6 = -((m0*t1) - (m2*t2) + (m3*t3));*/
	//	tmp.m6 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m12)))), _mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m14))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m12))))));

	//	// load		FR		(5)		DLMFR
	//	/*t4 = (m5*m14) - (m6*m13);
	//	t5 = (m4*m13) - (m5*m12);*/
	//	// p = - ( a(tf) - b(tm) + c(tr))
	//	//tmp.m14 = -((m0*t4) - (m1*t3) + (m3*t5));
	//	tmp.m14 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m12)))), _mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m13))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m12))))));
	//	// unload	M		(4)		DL-FR    
	//	// load		E		(5)		DLEFR    
	//	/*t3 = (m5*m15) - (m7*m13);*/
	//	// l = a(te) - b(tl) + d(tr)
	//	/*tmp.m10 = (m0*t3) - (m1*t2) + (m3*t5);*/
	//	tmp.m10 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m13)))), _mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m12))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m13)), _mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m12))))));
	//	// unload	LR		(3)		D-EF-
	//	// c = b(td) - c(te) + d(tf)
	//	/*tmp.m2 = (m1*t1) - (m2*t3) + (m3*t4);*/
	//	tmp.m2 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m14)))), _mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m15)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m13))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m14)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m13))))));
	//	// unload	DEF		(0)		-----
	//	// load		GHI		(3)		GHI--
	//	/*t1 = (m6*m11) - (m7*m10);
	//	t2 = (m5*m11) - (m7*m9);
	//	t3 = (m5*m10) - (m6*m9);*/

	//	// d = -( b(tg) - c(th) + d(ti) )
	//	/*tmp.m3 = -((m1*t1) - (m2*t2) + (m3*t3));*/
	//	tmp.m3 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m9)))), _mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m10))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m10)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m9))))));
	//	// load		NO		(5)		GHINO
	//	/*t4 = (m4*m11) - (m7*m8);
	//	t5 = (m4*m10) - (m6*m8);*/

	//	// h = a(tg) - c(tn) + d(to)
	//	/*tmp.m7 = (m0*t1) - (m2*t4) + (m3*t5);*/
	//	tmp.m7 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m10)))), _mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m8))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m10)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m8))))));
	//	// unload	G		(4)		-HINO
	//	// load		Q		(5)		QHINO
	///*	t1 = (m4*m9) - (m5*m8);  */
	//	// m = -( a(th) - b(tn) + d(tq))
	//	//tmp.m11 = -((m0*t2) - (m1*t4) + (m3*t1));
	//	tmp.m11 = _mm_cvtss_f32(_mm_sub_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m8)))), _mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m11)), _mm_mul_ps(_mm_set1_ps(m7), _mm_set1_ps(m9))))), _mm_mul_ps(_mm_set1_ps(m3), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m9)), _mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m8))))));
	//	// unload	HN		(3)		Q-I-O
	//	// q = a(ti) - b(to) + c(tq)
	//	//tmp.m15 = (m0*t3) - (m1*t5) + (m2*t1);
	//	tmp.m15 = _mm_cvtss_f32(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m0), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m10)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m9)))), _mm_mul_ps(_mm_set1_ps(m1), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m10)), _mm_mul_ps(_mm_set1_ps(m6), _mm_set1_ps(m8))))), _mm_mul_ps(_mm_set1_ps(m2), _mm_sub_ps(_mm_mul_ps(_mm_set1_ps(m4), _mm_set1_ps(m9)), _mm_mul_ps(_mm_set1_ps(m5), _mm_set1_ps(m8))))));
	//	return tmp;
	//}

	//void Matrix::Inverse(Matrix &out)
	//{
	//	Matrix tmp;
	//	float det = Determinant();
	//	if (fabs(det) >= 0.0001f)
	//	{
	//		tmp = GetAdjugate();
	//		tmp /= det;
	//		// do nothing, Matrix is not invertable
	//	}

	//	out = tmp;
	//}


	void Matrix::setScaleMatrix(const Vect4D *scale)
	{
		//	{	sx		0		0		0	}        
		//	{	0		sy		0		0	}        
		//	{	0		0		sz		0	}        
		//	{	0		0		0		1	}        

		this->v0._m = _mm_set_ps(0.0f, 0.0f, 0.0f, scale->x);
		this->v1._m = _mm_set_ps(0.0f, 0.0f, scale->y, 0.0f);
		this->v2._m = _mm_set_ps(0.0f, scale->z, 0.0f, 0.0f);
		this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
	}

	void Matrix::setRotZMatrix(const float az)
	{
		//	{	cos		-sin    	0		0	}       
		//	{	sin		cos		0		0	}       
		//	{	0		0		1		0	}       
		//	{	0		0		0		1	}       
		this->v0._m = _mm_set_ps(0.0f, 0.0f, -sin(az), cos(az));
		this->v1._m = _mm_set_ps(0.0f, 0.0f, cos(az), sin(az));
		this->v2._m = _mm_set_ps(0.0f, 1.0f, 0.0f, 0.0f);
		this->v3._m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
	}

	union
	{
		struct
		{
			Vect4D v0;
			Vect4D v1;
			Vect4D v2;
			Vect4D v3;
		};

		struct
		{

			// ROW 0
			float m0;
			float m1;
			float m2;
			float m3;

			// ROW 1
			float m4;
			float m5;
			float m6;
			float m7;

			// ROW 2
			float m8;
			float m9;
			float m10;
			float m11;

			// ROW 3
			float m12;
			float m13;
			float m14;
			float m15;
		} ;
	};
};

#endif 

// End of File


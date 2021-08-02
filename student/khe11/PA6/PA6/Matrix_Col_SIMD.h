//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"
   
// -----------------------------------------------------------------------
// Rules: 
//    Implement for Col Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline MM operator * (const Matrix_Col_SIMD &m, const Matrix_Col_SIMD &n)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
					const Vect_Col_SIMD &tV1,
					const Vect_Col_SIMD &tV2,
					const Vect_Col_SIMD &tV3);
 
	//Matrix_Col_SIMD operator * (const Matrix_Col_SIMD &n);
	//Vect_Col_SIMD operator * (const Vect_Col_SIMD &n);

	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

struct MmulM
{
	const Matrix_Col_SIMD &v1;
	const Matrix_Col_SIMD &v2;

	MmulM(const Matrix_Col_SIMD &t1, const Matrix_Col_SIMD &t2)
		: v1(t1), v2(t2)
	{
	};

	operator Matrix_Col_SIMD();
	const MmulM & operator = (const MmulM &r) = delete;

};




struct MmulMmulM
{
	const Matrix_Col_SIMD &v1;
	const Matrix_Col_SIMD &v2;
	const Matrix_Col_SIMD &v3;

	MmulMmulM(const MmulM &t1, const Matrix_Col_SIMD &t2)
		: v1(t1.v1), v2(t1.v2),v3(t2)
	{
	};

	operator Matrix_Col_SIMD();

	const MmulMmulM& operator = (const MmulMmulM & r) = delete;
};



struct  MmulMmulMmulM
{
	const Matrix_Col_SIMD &v1;
	const Matrix_Col_SIMD &v2;
	const Matrix_Col_SIMD &v3;
	const Matrix_Col_SIMD &v4;

	MmulMmulMmulM(const MmulMmulM &t1, const Matrix_Col_SIMD &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t2)
	{
	};

	operator Matrix_Col_SIMD();
	const MmulMmulMmulM& operator=(const MmulMmulMmulM &r) = delete;
};



struct MmulMmulMmulMmulM
{
	const Matrix_Col_SIMD &v1;
	const Matrix_Col_SIMD &v2;
	const Matrix_Col_SIMD &v3;
	const Matrix_Col_SIMD &v4;
	const Matrix_Col_SIMD &v5;

	MmulMmulMmulMmulM(const MmulMmulMmulM &t1, const Matrix_Col_SIMD &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t2)
	{
	};

	operator Matrix_Col_SIMD();
	const MmulMmulMmulMmulM& operator=(const MmulMmulMmulMmulM &r) = delete;
};

struct MmulMmulMmulMmulMmulV
{
	const Matrix_Col_SIMD &v1;
	const Matrix_Col_SIMD &v2;
	const Matrix_Col_SIMD &v3;
	const Matrix_Col_SIMD &v4;
	const Matrix_Col_SIMD &v5;
	const Vect_Col_SIMD &v6;

	MmulMmulMmulMmulMmulV(const MmulMmulMmulMmulM &t1, const Vect_Col_SIMD &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t2)
	{
	};

	operator Vect_Col_SIMD();

	const MmulMmulMmulMmulMmulV& operator=(const MmulMmulMmulMmulMmulV &r) = delete;
};


inline MmulM operator * (const Matrix_Col_SIMD &t1, const Matrix_Col_SIMD &t2)
{
	return MmulM(t1, t2);
};
inline MmulMmulM operator * (const MmulM &t1, const Matrix_Col_SIMD &t2)
{
	return MmulMmulM(t1, t2);
};
inline MmulMmulMmulM operator * (const MmulMmulM &t1, const Matrix_Col_SIMD &t2)
{
	return MmulMmulMmulM(t1, t2);
};
inline MmulMmulMmulMmulM operator * (const MmulMmulMmulM &t1, const Matrix_Col_SIMD &t2)
{
	return MmulMmulMmulMmulM(t1, t2);
};
inline MmulMmulMmulMmulMmulV operator * (const MmulMmulMmulMmulM &t1, const Vect_Col_SIMD &t2)
{
	return MmulMmulMmulMmulMmulV(t1, t2);
};



#endif

// ---  End of File ---------------
